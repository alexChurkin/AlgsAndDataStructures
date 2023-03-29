#pragma once
#include "Randomex.h"
#include "DataStructs.h"
#include "..\queue-with-list\TLQueue.h"
#include "DataGridViewExtensions.h"
#include <vector>
#include <algorithm>

ref class ProcFarm
{
private:
	Randomex^ randomex;

	//Farm settings
	int n;
	float newTaskP = 0.15f;
	int minProcForTask = 1, maxProcForTask = 16;
	int minCC = 1, maxCC = 4;

	//Farm statistics
	Stat* stat;
	int ticksCount = 0;

	//Farm processors
	Processor* processors;

	//Last assigned id
	int lastTaskId = 0;

	//Tasks queue
	TLQueue<Task>* qTasks = new TLQueue<Task>();
	//Ids of active (executing) tasks
	std::vector<int>* activeTasksIds = new std::vector<int>(n);

public:
	ProcFarm(int _n)
	{
		randomex = gcnew Randomex();
		n = _n;
		processors = new Processor[n];
		stat = new Stat();
	}

	~ProcFarm()
	{
		delete[] processors;
		delete stat;

		delete qTasks;
		delete activeTasksIds;
	}

	int GetCurrentLoad()
	{
		return stat->currentLoad;
	}

	int GetActiveTasksCount()
	{
		return stat->tasksActive;
	}

	int GetQueueTasksCount()
	{
		return qTasks->GetSize();
	}

	int GetTotalCCs()
	{
		return stat->totalCCs;
	}

	int GetTotalWaitingCCs()
	{
		return stat->totalWaitingCCs;
	}

	int GetReceivedTasksCount()
	{
		return stat->tasksReceived;
	}

	int GetCompletedTasksCount()
	{
		return stat->tasksCompleted;
	}

	int GetAverageLoad()
	{
		return (int) stat->averageLoad;
	}

	void SetNewTaskP(float _newTaskP)
	{
		newTaskP = _newTaskP;
	}

	void SetProcForTaskRange(int _minProcForTask, int _maxProcForTask)
	{
		minProcForTask = _minProcForTask;
		maxProcForTask = _maxProcForTask;
	}

	void SetCCRange(int _minCC, int _maxCC)
	{
		minCC = _minCC, maxCC = _maxCC;
	}


	void Tick(cli::array<System::Windows::Forms::Button^>^ procViews,
		System::Windows::Forms::DataGridView^ dgLogs,
		System::Windows::Forms::DataGridView^ dgActive,
		System::Windows::Forms::DataGridView^ dgQueue,
		System::Windows::Forms::ToolTip^ toolTip)
	{
		int prevTicksCount = ticksCount;
		ticksCount++;
		//1. Updating progress of current tasks; removing finished

		for (int i = 0; i < n; i++)
		{
			//Processor is waiting
			if (processors[i].isWaiting)
			{
				processors[i].ccWaiting++;
				stat->totalWaitingCCs++;

				toolTip->SetToolTip(procViews[i],
					"Процессор " + (i + 1) + ": ожидает\n" +
					"Тактов работы: " + processors[i].ccCount +"\n"
					"Тактов ожидания: " + processors[i].ccWaiting);
			}

			//Processor is executing some task
			else
			{
				stat->totalCCs++;

				processors[i].ccCount++;
				processors[i].ccOfTaskCount--;

				auto it = std::find(
					activeTasksIds->begin(),
					activeTasksIds->end(),
					processors[i].taskId);

				//Is still executing
				if (processors[i].ccOfTaskCount > 0)
				{
					_int64 index = std::distance(activeTasksIds->begin(), it);

					dgActive->Rows[index]->Cells[0]->Value =
						processors[i].taskId + " : " + processors[i].ccOfTaskCount;

					toolTip->SetToolTip(procViews[i],
						"Процессор " + (i + 1) + ": выполняет задачу " + processors[i].taskId + "\n" +
						"Тактов работы: " + processors[i].ccCount + "\n" +
						"Тактов ожидания: " + processors[i].ccWaiting);
				}
				//Finished
				else
				{
					if (it != activeTasksIds->end())
					{
						stat->tasksCompleted++;

						_int64 index = std::distance(activeTasksIds->begin(), it);
						activeTasksIds->erase(it);
						stat->tasksActive--;

						dgActive->Rows->RemoveAt((int) index);

						AddRowWithScroll(dgLogs, System::Drawing::Color::Aquamarine,
							"Задача " + std::to_string(processors[i].taskId) + " успешно выполнена.");
					}


					stat->currentLoad--;
					processors[i].taskId = -1;
					processors[i].isWaiting = true;
					procViews[i]->BackColor = System::Drawing::Color::FromArgb(51, 51, 51);

					toolTip->SetToolTip(procViews[i],
						"Процессор " + (i + 1) + ": ожидает" + "\n" +
						"Тактов работы: " + processors[i].ccCount + "\n" +
						"Тактов ожидания: " + processors[i].ccWaiting);
				}
			}
		}

		//2. New task generation with P probability
		if (randomex->RandBool(newTaskP))
		{
			stat->tasksReceived++;

			Task newTask{};
			newTask.id = ++lastTaskId;
			newTask.procCount = randomex->RandInt(minProcForTask, maxProcForTask);
			newTask.ccTotal = randomex->RandInt(minCC, maxCC);
			qTasks->Push(newTask);

			AddRow(dgQueue, Randomex::RandColor(),
				newTask.id + " : " + newTask.procCount + " : " + newTask.ccTotal);
		}

		//3. Getting and processing the next task from the queue
		if (qTasks->IsNotEmpty())
		{
			Task t = qTasks->Pop();

			auto tColor = dgQueue->Rows[0]->DefaultCellStyle->ForeColor;
			dgQueue->Rows->RemoveAt(0);

			//Can be launched immediately
			if ((n - stat->currentLoad) >= t.procCount)
			{
				stat->currentLoad += t.procCount;
				stat->tasksActive++;

				activeTasksIds->push_back(t.id);

				AddRowWithScroll(dgActive, tColor, t.id + " : " + t.ccTotal);

				AddRowWithScroll(dgLogs, System::Drawing::Color::DeepSkyBlue,
					"Задача " + t.id + " успешно отправлена на процессоры.");

				for (int i = 0, selCount = 0; selCount < t.procCount; i++)
				{
					if (processors[i].isWaiting)
					{
						selCount++;

						processors[i].isWaiting = false;
						processors[i].taskId = t.id;
						processors[i].ccOfTaskCount = t.ccTotal;

						procViews[i]->BackColor = tColor;

						toolTip->SetToolTip(procViews[i],
							"Процессор " + (i + 1) + ": выполняет задачу " + processors[i].taskId + "\n" +
							"Тактов работы: " + processors[i].ccCount + "\n"
							"Тактов ожидания: " + processors[i].ccWaiting);
					}
				}
			}
			//Can't be launched immediately
			//(not enough waiting processors on farm)
			else
			{
				qTasks->Push(t);

				AddRowWithScroll(dgLogs, System::Drawing::Color::Orange,
					"Задача " + t.id + " отложена (недостаточно свободных процессоров).");
				AddRow(dgQueue, tColor, t.id + " : " + t.procCount + " : " + t.ccTotal);
			}
		}

		stat->averageLoad =
			stat->averageLoad * (((double)prevTicksCount) / ticksCount)
				+ ((double) stat->currentLoad / ticksCount);
	}
};