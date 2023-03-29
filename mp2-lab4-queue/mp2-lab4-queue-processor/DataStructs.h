#pragma once
struct Processor
{
	int taskId = -1;	   //Current task id
	int ccCount = 0;	   //Processor cycles (tasks execution)
	int ccWaiting = 0;	   //Processor cycles (waiting)
	int ccOfTaskCount = 0; //Cycles of task left
	bool isWaiting = true;
};

struct Task
{
	int id;		  //id
	int procCount;//Processors required
	int ccTotal;  //Clock cycles required
};

struct Stat {
	int currentLoad = 0;
	int tasksActive = 0;
	int tasksQueue = 0;

	//Total cycles (tasks execution)
	int totalCCs = 0;
	//Total cycles (waiting)
	int totalWaitingCCs = 0;

	int tasksReceived = 0;
	int tasksCompleted = 0;

	//Processors loaded (average value)
	double averageLoad = 0;
};