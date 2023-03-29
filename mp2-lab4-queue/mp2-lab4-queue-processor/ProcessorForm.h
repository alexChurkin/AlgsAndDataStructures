#pragma once
#include "TextBoxFilters.h"
#include "Convertex.h"
#include "DataStructs.h"
#include "..\mp2-lab4-queue\TQueue.h"
#include "ProcFarm.h"

namespace mp2lab4queueprocessor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ProcessorForm : public System::Windows::Forms::Form
	{
	private:
		cli::array<Button^>^ procBtns = nullptr;
		ProcFarm^ pFarm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Logs;
		   ToolTip^ toolTip;

	public:
		ProcessorForm(void)
		{
			InitializeComponent();
			this->dgLogs->MouseWheel += gcnew MouseEventHandler(this, &ProcessorForm::dgLogs_MouseWheel);
			this->dgActive->MouseWheel += gcnew MouseEventHandler(this, &ProcessorForm::dgActive_MouseWheel);
			this->dgQueue->MouseWheel += gcnew MouseEventHandler(this, &ProcessorForm::dgQueue_MouseWheel);
			toolTip = gcnew ToolTip();

			SetTransparency();
			selProcNumber->SelectedIndex = 15;
			label1->Select();
			DrawProcessors(16);
		}

	protected:
		~ProcessorForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::PictureBox^ pbBackground;
	private: System::Windows::Forms::Button^ btnStartStop;
	private: System::Windows::Forms::Button^ btnPauseResume;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbTaskP;
	private: System::Windows::Forms::TextBox^ tbCCDur;
	private: System::Windows::Forms::TextBox^ tbMinProcForTask;
	private: System::Windows::Forms::TextBox^ tbMaxProcForTask;
	private: System::Windows::Forms::ComboBox^ selProcNumber;
	private: System::Windows::Forms::TextBox^ tbMinCC;
	private: System::Windows::Forms::TextBox^ tbMaxCC;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::DataGridView^ dgLogs;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::DataGridView^ dgActive;

	private: System::Windows::Forms::Label^ lActiveTasks;
	private: System::Windows::Forms::Label^ lQueueCount;
	private: System::Windows::Forms::Label^ lTotalCC;
	private: System::Windows::Forms::Label^ lWaitingCC;
	private: System::Windows::Forms::Label^ lTotalTasks;
	private: System::Windows::Forms::Label^ lFinishedTasks;

	private: System::Windows::Forms::Label^ lAverageLoad;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ lCurrentLoad;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::DataGridView^ dgQueue;
	private: System::Windows::Forms::Timer^ pTimer;
	private: System::Windows::Forms::Panel^ panelProcessors;

	private: System::ComponentModel::IContainer^ components;

	private:
#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProcessorForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pbBackground = (gcnew System::Windows::Forms::PictureBox());
			this->btnStartStop = (gcnew System::Windows::Forms::Button());
			this->btnPauseResume = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbTaskP = (gcnew System::Windows::Forms::TextBox());
			this->tbCCDur = (gcnew System::Windows::Forms::TextBox());
			this->tbMinProcForTask = (gcnew System::Windows::Forms::TextBox());
			this->tbMaxProcForTask = (gcnew System::Windows::Forms::TextBox());
			this->selProcNumber = (gcnew System::Windows::Forms::ComboBox());
			this->tbMinCC = (gcnew System::Windows::Forms::TextBox());
			this->tbMaxCC = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->dgLogs = (gcnew System::Windows::Forms::DataGridView());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->dgActive = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lActiveTasks = (gcnew System::Windows::Forms::Label());
			this->lQueueCount = (gcnew System::Windows::Forms::Label());
			this->lTotalCC = (gcnew System::Windows::Forms::Label());
			this->lWaitingCC = (gcnew System::Windows::Forms::Label());
			this->lTotalTasks = (gcnew System::Windows::Forms::Label());
			this->lFinishedTasks = (gcnew System::Windows::Forms::Label());
			this->lAverageLoad = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->lCurrentLoad = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->dgQueue = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelProcessors = (gcnew System::Windows::Forms::Panel());
			this->Logs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgLogs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgActive))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgQueue))->BeginInit();
			this->SuspendLayout();
			// 
			// pbBackground
			// 
			this->pbBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBackground.Image")));
			this->pbBackground->Location = System::Drawing::Point(0, 0);
			this->pbBackground->Name = L"pbBackground";
			this->pbBackground->Size = System::Drawing::Size(1226, 731);
			this->pbBackground->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbBackground->TabIndex = 0;
			this->pbBackground->TabStop = false;
			// 
			// btnStartStop
			// 
			this->btnStartStop->BackColor = System::Drawing::Color::Teal;
			this->btnStartStop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStartStop->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.89565F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartStop->ForeColor = System::Drawing::Color::PaleGreen;
			this->btnStartStop->Location = System::Drawing::Point(16, 20);
			this->btnStartStop->Name = L"btnStartStop";
			this->btnStartStop->Size = System::Drawing::Size(156, 38);
			this->btnStartStop->TabIndex = 1;
			this->btnStartStop->Text = L"Старт";
			this->btnStartStop->UseVisualStyleBackColor = false;
			this->btnStartStop->Click += gcnew System::EventHandler(this, &ProcessorForm::btnStartStop_Click);
			// 
			// btnPauseResume
			// 
			this->btnPauseResume->BackColor = System::Drawing::Color::Teal;
			this->btnPauseResume->Enabled = false;
			this->btnPauseResume->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPauseResume->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.89565F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnPauseResume->ForeColor = System::Drawing::Color::PaleGreen;
			this->btnPauseResume->Location = System::Drawing::Point(179, 20);
			this->btnPauseResume->Name = L"btnPauseResume";
			this->btnPauseResume->Size = System::Drawing::Size(156, 38);
			this->btnPauseResume->TabIndex = 2;
			this->btnPauseResume->Text = L"Пауза";
			this->btnPauseResume->UseVisualStyleBackColor = false;
			this->btnPauseResume->Click += gcnew System::EventHandler(this, &ProcessorForm::btnPauseResume_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::PaleGreen;
			this->label1->Location = System::Drawing::Point(12, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Процессоров:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::PaleGreen;
			this->label2->Location = System::Drawing::Point(12, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Один такт (мс):";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::PaleGreen;
			this->label3->Location = System::Drawing::Point(12, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(215, 24);
			this->label3->TabIndex = 5;
			this->label3->Text = L"P поступления задачи:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::PaleGreen;
			this->label4->Location = System::Drawing::Point(12, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(228, 24);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Процессоров на задачу:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::PaleGreen;
			this->label5->Location = System::Drawing::Point(12, 296);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(170, 24);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Тактов на задачу:";
			// 
			// tbTaskP
			// 
			this->tbTaskP->BackColor = System::Drawing::Color::Teal;
			this->tbTaskP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.77391F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbTaskP->ForeColor = System::Drawing::Color::White;
			this->tbTaskP->Location = System::Drawing::Point(235, 127);
			this->tbTaskP->MaxLength = 6;
			this->tbTaskP->Name = L"tbTaskP";
			this->tbTaskP->Size = System::Drawing::Size(100, 32);
			this->tbTaskP->TabIndex = 8;
			this->tbTaskP->Text = L"0.15";
			this->tbTaskP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbTaskP->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessorForm::tbNonNegativeDecimal_KeyPress);
			// 
			// tbCCDur
			// 
			this->tbCCDur->BackColor = System::Drawing::Color::Teal;
			this->tbCCDur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.77391F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbCCDur->ForeColor = System::Drawing::Color::White;
			this->tbCCDur->Location = System::Drawing::Point(235, 169);
			this->tbCCDur->MaxLength = 6;
			this->tbCCDur->Name = L"tbCCDur";
			this->tbCCDur->Size = System::Drawing::Size(100, 32);
			this->tbCCDur->TabIndex = 9;
			this->tbCCDur->Text = L"250";
			this->tbCCDur->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbCCDur->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessorForm::tbNatural_KeyPress);
			// 
			// tbMinProcForTask
			// 
			this->tbMinProcForTask->BackColor = System::Drawing::Color::Teal;
			this->tbMinProcForTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.77391F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->tbMinProcForTask->ForeColor = System::Drawing::Color::White;
			this->tbMinProcForTask->Location = System::Drawing::Point(16, 257);
			this->tbMinProcForTask->MaxLength = 3;
			this->tbMinProcForTask->Name = L"tbMinProcForTask";
			this->tbMinProcForTask->Size = System::Drawing::Size(100, 32);
			this->tbMinProcForTask->TabIndex = 10;
			this->tbMinProcForTask->Text = L"1";
			this->tbMinProcForTask->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMinProcForTask->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessorForm::tbNatural_KeyPress);
			// 
			// tbMaxProcForTask
			// 
			this->tbMaxProcForTask->BackColor = System::Drawing::Color::Teal;
			this->tbMaxProcForTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.77391F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->tbMaxProcForTask->ForeColor = System::Drawing::Color::White;
			this->tbMaxProcForTask->Location = System::Drawing::Point(145, 257);
			this->tbMaxProcForTask->MaxLength = 3;
			this->tbMaxProcForTask->Name = L"tbMaxProcForTask";
			this->tbMaxProcForTask->Size = System::Drawing::Size(100, 32);
			this->tbMaxProcForTask->TabIndex = 11;
			this->tbMaxProcForTask->Text = L"16";
			this->tbMaxProcForTask->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMaxProcForTask->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessorForm::tbNatural_KeyPress);
			// 
			// selProcNumber
			// 
			this->selProcNumber->BackColor = System::Drawing::Color::Teal;
			this->selProcNumber->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->selProcNumber->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->selProcNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->selProcNumber->ForeColor = System::Drawing::Color::White;
			this->selProcNumber->FormattingEnabled = true;
			this->selProcNumber->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"25", L"32", L"36", L"48", L"64", L"256"
			});
			this->selProcNumber->Location = System::Drawing::Point(235, 85);
			this->selProcNumber->Name = L"selProcNumber";
			this->selProcNumber->Size = System::Drawing::Size(100, 32);
			this->selProcNumber->TabIndex = 12;
			this->selProcNumber->SelectedIndexChanged += gcnew System::EventHandler(this, &ProcessorForm::selProcNumber_SelectedIndexChanged);
			// 
			// tbMinCC
			// 
			this->tbMinCC->BackColor = System::Drawing::Color::Teal;
			this->tbMinCC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.77391F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMinCC->ForeColor = System::Drawing::Color::White;
			this->tbMinCC->Location = System::Drawing::Point(16, 327);
			this->tbMinCC->MaxLength = 3;
			this->tbMinCC->Name = L"tbMinCC";
			this->tbMinCC->Size = System::Drawing::Size(100, 32);
			this->tbMinCC->TabIndex = 13;
			this->tbMinCC->Text = L"1";
			this->tbMinCC->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMinCC->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessorForm::tbNatural_KeyPress);
			// 
			// tbMaxCC
			// 
			this->tbMaxCC->BackColor = System::Drawing::Color::Teal;
			this->tbMaxCC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.77391F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMaxCC->ForeColor = System::Drawing::Color::White;
			this->tbMaxCC->Location = System::Drawing::Point(145, 327);
			this->tbMaxCC->MaxLength = 3;
			this->tbMaxCC->Name = L"tbMaxCC";
			this->tbMaxCC->Size = System::Drawing::Size(100, 32);
			this->tbMaxCC->TabIndex = 14;
			this->tbMaxCC->Text = L"4";
			this->tbMaxCC->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMaxCC->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProcessorForm::tbNatural_KeyPress);
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::PaleGreen;
			this->label6->Location = System::Drawing::Point(119, 256);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(25, 32);
			this->label6->TabIndex = 15;
			this->label6->Text = L"–";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::PaleGreen;
			this->label7->Location = System::Drawing::Point(119, 326);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(25, 32);
			this->label7->TabIndex = 16;
			this->label7->Text = L"–";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::PaleGreen;
			this->label8->Location = System::Drawing::Point(15, 394);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(203, 24);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Текущее состояние";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label9->Location = System::Drawing::Point(15, 576);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(182, 24);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Выполнено тактов:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label10->Location = System::Drawing::Point(15, 632);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(168, 24);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Поступило задач:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label11->Location = System::Drawing::Point(15, 660);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(173, 24);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Выполнено задач:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label13->Location = System::Drawing::Point(15, 455);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(191, 24);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Выполняется задач:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label14->Location = System::Drawing::Point(15, 483);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(168, 24);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Задач в очереди:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->ForeColor = System::Drawing::Color::PaleGreen;
			this->label15->Location = System::Drawing::Point(15, 543);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(124, 24);
			this->label15->TabIndex = 24;
			this->label15->Text = L"Статистика";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label16->Location = System::Drawing::Point(15, 688);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(177, 24);
			this->label16->TabIndex = 25;
			this->label16->Text = L"Средняя нагрузка:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label17->Location = System::Drawing::Point(15, 604);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(173, 24);
			this->label17->TabIndex = 26;
			this->label17->Text = L"Тактов ожидания:";
			// 
			// dgLogs
			// 
			this->dgLogs->AllowUserToAddRows = false;
			this->dgLogs->AllowUserToDeleteRows = false;
			this->dgLogs->AllowUserToResizeColumns = false;
			this->dgLogs->AllowUserToResizeRows = false;
			this->dgLogs->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.139131F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::MenuHighlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlDarkDark;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgLogs->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgLogs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgLogs->ColumnHeadersVisible = false;
			this->dgLogs->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Logs });
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.765218F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgLogs->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgLogs->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dgLogs->Location = System::Drawing::Point(351, 576);
			this->dgLogs->MultiSelect = false;
			this->dgLogs->Name = L"dgLogs";
			this->dgLogs->ReadOnly = true;
			this->dgLogs->RowHeadersVisible = false;
			this->dgLogs->RowHeadersWidth = 49;
			this->dgLogs->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->dgLogs->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dgLogs->RowTemplate->Height = 24;
			this->dgLogs->RowTemplate->ReadOnly = true;
			this->dgLogs->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dgLogs->Size = System::Drawing::Size(859, 136);
			this->dgLogs->TabIndex = 27;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.01739F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->ForeColor = System::Drawing::Color::PaleGreen;
			this->label18->Location = System::Drawing::Point(1001, 17);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(91, 20);
			this->label18->TabIndex = 28;
			this->label18->Text = L"В работе:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.01739F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::PaleGreen;
			this->label19->Location = System::Drawing::Point(1108, 17);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(89, 20);
			this->label19->TabIndex = 29;
			this->label19->Text = L"Очередь:";
			// 
			// dgActive
			// 
			this->dgActive->AllowUserToAddRows = false;
			this->dgActive->AllowUserToDeleteRows = false;
			this->dgActive->AllowUserToResizeColumns = false;
			this->dgActive->AllowUserToResizeRows = false;
			this->dgActive->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->dgActive->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgActive->ColumnHeadersVisible = false;
			this->dgActive->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dataGridViewTextBoxColumn1 });
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.765218F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgActive->DefaultCellStyle = dataGridViewCellStyle4;
			this->dgActive->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dgActive->Location = System::Drawing::Point(1005, 44);
			this->dgActive->MultiSelect = false;
			this->dgActive->Name = L"dgActive";
			this->dgActive->ReadOnly = true;
			this->dgActive->RowHeadersVisible = false;
			this->dgActive->RowHeadersWidth = 49;
			this->dgActive->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->dgActive->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dgActive->RowTemplate->Height = 24;
			this->dgActive->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dgActive->Size = System::Drawing::Size(100, 486);
			this->dgActive->TabIndex = 30;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Лог процессорной";
			this->dataGridViewTextBoxColumn1->MaxInputLength = 1000;
			this->dataGridViewTextBoxColumn1->MinimumWidth = 97;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->Width = 97;
			// 
			// lActiveTasks
			// 
			this->lActiveTasks->AutoSize = true;
			this->lActiveTasks->BackColor = System::Drawing::Color::Transparent;
			this->lActiveTasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lActiveTasks->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lActiveTasks->Location = System::Drawing::Point(210, 455);
			this->lActiveTasks->Name = L"lActiveTasks";
			this->lActiveTasks->Size = System::Drawing::Size(20, 24);
			this->lActiveTasks->TabIndex = 32;
			this->lActiveTasks->Text = L"0";
			// 
			// lQueueCount
			// 
			this->lQueueCount->AutoSize = true;
			this->lQueueCount->BackColor = System::Drawing::Color::Transparent;
			this->lQueueCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lQueueCount->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lQueueCount->Location = System::Drawing::Point(210, 483);
			this->lQueueCount->Name = L"lQueueCount";
			this->lQueueCount->Size = System::Drawing::Size(20, 24);
			this->lQueueCount->TabIndex = 33;
			this->lQueueCount->Text = L"0";
			// 
			// lTotalCC
			// 
			this->lTotalCC->AutoSize = true;
			this->lTotalCC->BackColor = System::Drawing::Color::Transparent;
			this->lTotalCC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lTotalCC->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lTotalCC->Location = System::Drawing::Point(210, 576);
			this->lTotalCC->Name = L"lTotalCC";
			this->lTotalCC->Size = System::Drawing::Size(20, 24);
			this->lTotalCC->TabIndex = 34;
			this->lTotalCC->Text = L"0";
			// 
			// lWaitingCC
			// 
			this->lWaitingCC->AutoSize = true;
			this->lWaitingCC->BackColor = System::Drawing::Color::Transparent;
			this->lWaitingCC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lWaitingCC->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lWaitingCC->Location = System::Drawing::Point(210, 604);
			this->lWaitingCC->Name = L"lWaitingCC";
			this->lWaitingCC->Size = System::Drawing::Size(20, 24);
			this->lWaitingCC->TabIndex = 35;
			this->lWaitingCC->Text = L"0";
			// 
			// lTotalTasks
			// 
			this->lTotalTasks->AutoSize = true;
			this->lTotalTasks->BackColor = System::Drawing::Color::Transparent;
			this->lTotalTasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lTotalTasks->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lTotalTasks->Location = System::Drawing::Point(210, 632);
			this->lTotalTasks->Name = L"lTotalTasks";
			this->lTotalTasks->Size = System::Drawing::Size(20, 24);
			this->lTotalTasks->TabIndex = 36;
			this->lTotalTasks->Text = L"0";
			// 
			// lFinishedTasks
			// 
			this->lFinishedTasks->AutoSize = true;
			this->lFinishedTasks->BackColor = System::Drawing::Color::Transparent;
			this->lFinishedTasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lFinishedTasks->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lFinishedTasks->Location = System::Drawing::Point(210, 660);
			this->lFinishedTasks->Name = L"lFinishedTasks";
			this->lFinishedTasks->Size = System::Drawing::Size(20, 24);
			this->lFinishedTasks->TabIndex = 37;
			this->lFinishedTasks->Text = L"0";
			// 
			// lAverageLoad
			// 
			this->lAverageLoad->AutoSize = true;
			this->lAverageLoad->BackColor = System::Drawing::Color::Transparent;
			this->lAverageLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lAverageLoad->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lAverageLoad->Location = System::Drawing::Point(210, 688);
			this->lAverageLoad->Name = L"lAverageLoad";
			this->lAverageLoad->Size = System::Drawing::Size(35, 24);
			this->lAverageLoad->TabIndex = 39;
			this->lAverageLoad->Text = L"0/8";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->BackColor = System::Drawing::Color::Transparent;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label28->Location = System::Drawing::Point(15, 427);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(173, 24);
			this->label28->TabIndex = 40;
			this->label28->Text = L"Текущая нагрузка:";
			// 
			// lCurrentLoad
			// 
			this->lCurrentLoad->AutoSize = true;
			this->lCurrentLoad->BackColor = System::Drawing::Color::Transparent;
			this->lCurrentLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lCurrentLoad->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->lCurrentLoad->Location = System::Drawing::Point(210, 427);
			this->lCurrentLoad->Name = L"lCurrentLoad";
			this->lCurrentLoad->Size = System::Drawing::Size(35, 24);
			this->lCurrentLoad->TabIndex = 41;
			this->lCurrentLoad->Text = L"0/8";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->BackColor = System::Drawing::Color::Transparent;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label30->ForeColor = System::Drawing::Color::PaleGreen;
			this->label30->Location = System::Drawing::Point(347, 543);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(102, 24);
			this->label30->TabIndex = 42;
			this->label30->Text = L"События:";
			// 
			// dgQueue
			// 
			this->dgQueue->AllowUserToAddRows = false;
			this->dgQueue->AllowUserToDeleteRows = false;
			this->dgQueue->AllowUserToResizeColumns = false;
			this->dgQueue->AllowUserToResizeRows = false;
			this->dgQueue->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->dgQueue->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgQueue->ColumnHeadersVisible = false;
			this->dgQueue->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dataGridViewTextBoxColumn2 });
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.765218F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)));
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::LightSkyBlue;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgQueue->DefaultCellStyle = dataGridViewCellStyle6;
			this->dgQueue->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dgQueue->Location = System::Drawing::Point(1112, 44);
			this->dgQueue->MultiSelect = false;
			this->dgQueue->Name = L"dgQueue";
			this->dgQueue->ReadOnly = true;
			this->dgQueue->RowHeadersVisible = false;
			this->dgQueue->RowHeadersWidth = 49;
			this->dgQueue->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->dgQueue->RowsDefaultCellStyle = dataGridViewCellStyle7;
			this->dgQueue->RowTemplate->Height = 24;
			this->dgQueue->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dgQueue->Size = System::Drawing::Size(100, 486);
			this->dgQueue->TabIndex = 43;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Лог процессорной";
			this->dataGridViewTextBoxColumn2->MaxInputLength = 1000;
			this->dataGridViewTextBoxColumn2->MinimumWidth = 97;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn2->Width = 97;
			// 
			// pTimer
			// 
			this->pTimer->Interval = 400;
			this->pTimer->Tick += gcnew System::EventHandler(this, &ProcessorForm::pTimer_Tick);
			// 
			// panelProcessors
			// 
			this->panelProcessors->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->panelProcessors->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelProcessors->Location = System::Drawing::Point(351, 20);
			this->panelProcessors->Name = L"panelProcessors";
			this->panelProcessors->Size = System::Drawing::Size(640, 510);
			this->panelProcessors->TabIndex = 44;
			// 
			// Logs
			// 
			this->Logs->HeaderText = L"Лог процессорной";
			this->Logs->MaxInputLength = 1000;
			this->Logs->MinimumWidth = 856;
			this->Logs->Name = L"Logs";
			this->Logs->ReadOnly = true;
			this->Logs->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Logs->Width = 856;
			// 
			// ProcessorForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1226, 731);
			this->Controls->Add(this->panelProcessors);
			this->Controls->Add(this->dgQueue);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->lCurrentLoad);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->lAverageLoad);
			this->Controls->Add(this->lFinishedTasks);
			this->Controls->Add(this->lTotalTasks);
			this->Controls->Add(this->lWaitingCC);
			this->Controls->Add(this->lTotalCC);
			this->Controls->Add(this->lQueueCount);
			this->Controls->Add(this->lActiveTasks);
			this->Controls->Add(this->dgActive);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->dgLogs);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbMaxCC);
			this->Controls->Add(this->tbMinCC);
			this->Controls->Add(this->selProcNumber);
			this->Controls->Add(this->tbMaxProcForTask);
			this->Controls->Add(this->tbMinProcForTask);
			this->Controls->Add(this->tbCCDur);
			this->Controls->Add(this->tbTaskP);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnPauseResume);
			this->Controls->Add(this->btnStartStop);
			this->Controls->Add(this->pbBackground);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ProcessorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Процессорная";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgLogs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgActive))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgQueue))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		bool IsRunning = false, IsPaused = false;

		int procNumberSelIndex = 5;

		int procNumber = 8;

		float newTaskP = 0.15F;
		int ccDur = 400;
		int minProcForTask = 1;
		int maxProcForTask = 8;
		int minCC = 1;
		int maxCC = 4;

		void SetTransparency()
		{
			label1->Parent = pbBackground;
			label2->Parent = pbBackground;
			label3->Parent = pbBackground;
			label4->Parent = pbBackground;
			label5->Parent = pbBackground;
			label6->Parent = pbBackground;
			label7->Parent = pbBackground;
			label8->Parent = pbBackground;
			label9->Parent = pbBackground;
			label10->Parent = pbBackground;
			label11->Parent = pbBackground;
			label13->Parent = pbBackground;
			label14->Parent = pbBackground;
			label15->Parent = pbBackground;
			label16->Parent = pbBackground;
			label17->Parent = pbBackground;
			label18->Parent = pbBackground;
			label19->Parent = pbBackground;
			lActiveTasks->Parent = pbBackground;
			lQueueCount->Parent = pbBackground;
			lTotalCC->Parent = pbBackground;
			lWaitingCC->Parent = pbBackground;
			lTotalTasks->Parent = pbBackground;
			lFinishedTasks->Parent = pbBackground;
			lAverageLoad->Parent = pbBackground;
			label28->Parent = pbBackground;
			lCurrentLoad->Parent = pbBackground;
			label30->Parent = pbBackground;
		}

		Void dgLogs_MouseWheel(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Delta > 0 && (dgLogs->FirstDisplayedScrollingRowIndex > 0))
			{
				dgLogs->FirstDisplayedScrollingRowIndex--;
			}
			else if (e->Delta < 0)
			{
				dgLogs->FirstDisplayedScrollingRowIndex++;
			}
		}

		Void dgActive_MouseWheel(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Delta > 0 && (dgActive->FirstDisplayedScrollingRowIndex > 0))
			{
				dgActive->FirstDisplayedScrollingRowIndex--;
			}
			else if (e->Delta < 0)
			{
				dgActive->FirstDisplayedScrollingRowIndex++;
			}
		}

		Void dgQueue_MouseWheel(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Delta > 0 && (dgQueue->FirstDisplayedScrollingRowIndex > 0))
			{
				dgQueue->FirstDisplayedScrollingRowIndex--;
			}
			else if (e->Delta < 0)
			{
				dgQueue->FirstDisplayedScrollingRowIndex++;
			}
		}

		Void selProcNumber_SelectedIndexChanged(Object^ sender, EventArgs^ e)
		{
			if (!IsRunning)
			{
				procNumberSelIndex = selProcNumber->SelectedIndex;

				procNumber = Convertex::StringTo_int(
					selProcNumber->GetItemText(selProcNumber->SelectedItem));
				lCurrentLoad->Text = "0/" + procNumber;
				lAverageLoad->Text = "0/" + procNumber;

				try
				{
					int _maxProcForTask = Convertex::Read_int(tbMaxProcForTask);
					if (_maxProcForTask > procNumber)
						tbMaxProcForTask->Text = Convertex::intTo_String(procNumber);
				}
				catch (...) {}

				DrawProcessors(procNumber);
			}
			else selProcNumber->SelectedIndex = procNumberSelIndex;
		}

		Void tbNonNegativeDecimal_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			TextBoxFilters::NonNegativeDecimalNumber(sender, e);
		}

		Void tbNatural_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			TextBoxFilters::NaturalNumber(sender, e);
		}

		Void btnStartStop_Click(Object^ sender, EventArgs^ e)
		{
			if (!IsRunning)
			{
				if (ProcessInput())
				{
					Start();
				}
			}
			else
			{
				Stop();
			}
		}

		bool ProcessInput()
		{

			float _newTaskP = -1.0F;
			int _ccDur = -1;
			int _minProcForTask = -1;
			int _maxProcForTask = -1;
			int _minCC = -1;
			int _maxCC = -1;

			//Проверки ввода:

			//Вероятность поступления задачи (-1.0F, если некорректна)
			try
			{
				_newTaskP = Convertex::Read_float(tbTaskP);
				if (_newTaskP != 0.0F && _newTaskP <= 1.0F)
				{
					label3->ForeColor = Color::PaleGreen;
				}
				else
				{
					_newTaskP = -1.0F;
					label3->ForeColor = Color::Red;
				}
			}
			catch (...)
			{
				label3->ForeColor = Color::Red;
			}

			//Длительность такта (-1, если некорректна)
			try
			{
				_ccDur = Convertex::Read_int(tbCCDur);
				if (_ccDur >= 1)
				{
					label2->ForeColor = Color::PaleGreen;
				}
				else
				{
					_ccDur = -1;
					label2->ForeColor = Color::Red;
				}
			}
			catch (...)
			{
				_ccDur = -1;
				label2->ForeColor = Color::Red;
			}


			//Минимум процессоров на задачу (-1, если некорректно)
			try
			{
				_minProcForTask = Convertex::Read_int(tbMinProcForTask);
				if (_minProcForTask >= 1 && _minProcForTask <= procNumber)
				{
					label4->ForeColor = Color::PaleGreen;
				}
				else
				{
					_minProcForTask = -1;
					label4->ForeColor = Color::Red;
				}
			}
			catch (...)
			{
				_minProcForTask = -1;
				label4->ForeColor = Color::Red;
			}

			//Максимум процессоров на задачу (-1, если некорректно)
			try
			{
				_maxProcForTask = Convertex::Read_int(tbMaxProcForTask);
				if (_maxProcForTask >= 1 && _maxProcForTask <= procNumber)
				{
					if (_minProcForTask != -1 && _minProcForTask <= _maxProcForTask)
					{
						label4->ForeColor = Color::PaleGreen;
					}
					else
					{
						_maxProcForTask = -1;
						label4->ForeColor = Color::Red;
					}
				}
				else
				{
					_maxProcForTask = -1;
					label4->ForeColor = Color::Red;
				}
			}
			catch (...)
			{
				_maxProcForTask = -1;
				label4->ForeColor = Color::Red;
			}

			//Минимум тактов на задачу
			try
			{
				_minCC = Convertex::Read_int(tbMinCC);
				if (_minCC >= 1)
				{
					label5->ForeColor = Color::PaleGreen;
				}
				else
				{
					_minCC = -1;
					label5->ForeColor = Color::Red;
				}
			}
			catch (...)
			{
				_minCC = -1;
				label5->ForeColor = Color::Red;
			}

			//Максимум тактов на задачу
			try
			{
				_maxCC = Convertex::Read_int(tbMaxCC);
				if (_maxCC >= 1)
				{
					if (_minCC != -1 && _minCC <= _maxCC)
					{
						label5->ForeColor = Color::PaleGreen;
					}
					else
					{
						_maxCC = -1;
						label5->ForeColor = Color::Red;
					}
				}
				else
				{
					_maxCC = -1;
					label5->ForeColor = Color::Red;
				}
			}
			catch (...)
			{
				_maxCC = -1;
				label5->ForeColor = Color::Red;
			}

			bool correct = _newTaskP > 0.0F && _ccDur != -1 &&
				_minProcForTask != -1 && _maxProcForTask != -1 &&
				_minCC != -1 && _maxCC != -1;

			if (_newTaskP <= 0.0F) tbTaskP->Select();
			else if (_ccDur == -1) tbCCDur->Select();
			else if (_minProcForTask == -1) tbMinProcForTask->Select();
			else if (_maxProcForTask == -1) tbMaxProcForTask->Select();
			else if (_minCC == -1) tbMinCC->Select();
			else if (_maxCC == -1) tbMaxCC->Select();

			if (correct)
			{
				newTaskP = _newTaskP;
				ccDur = _ccDur;
				minProcForTask = _minProcForTask;
				maxProcForTask = _maxProcForTask;
				minCC = _minCC;
				maxCC = _maxCC;
			}

			return correct;
		}

		Void btnPauseResume_Click(Object^ sender, EventArgs^ e)
		{
			if (IsRunning)
			{
				if (!IsPaused)
				{
					IsPaused = true;
					Pause();
					btnPauseResume->Text = "Продолжить";
				}
				else
				{
					IsPaused = false;
					Resume();
					btnPauseResume->Text = "Пауза";
				}
			}
		}


		//Обновление процессоров на панели процессоров
		void DrawProcessors(int n)
		{
			//Удаление предыдущих процессоров с формы
			if (procBtns != nullptr)
			{
				for (int i = 0; i < procBtns->Length; i++)
					this->panelProcessors->Controls->Remove(procBtns[i]);
			}

			//Добавление новых процессоров

			procBtns = gcnew array<Button^>(n);

			int startX = 80, startY = 15;

			//1 процессор
			if (n == 1)
			{
				DrawProcTable(startX, startY, 480, -1, 1, 1, 1);
			}
			//2-3-4 процессора
			else if (n <= 4)
			{
				if (n == 2)
				{
					DrawProcTable(startX, startY + 115 + 9, 230, 20, 2, 2, n);
				}
				else
				{
					DrawProcTable(startX, startY, 230, 20, 2, 2, n);
				}
			}
			//5-6-7-8-9
			else if (n <= 9)
			{
				if (n <= 6)
				{
					DrawProcTable(startX, startY + 85, 148, 18, 3, 3, n);
				}
				else
				{
					DrawProcTable(startX, startY, 148, 18, 3, 3, n);
				}
			}
			//10-11-12-13-14-15-16
			else if (n <= 16)
			{
				DrawProcTable(startX, startY, 111, 12, 4, 4, n);
			}
			//25
			else if (n <= 25)
			{
				DrawProcTable(startX, startY, 84, 15, 5, 5, n);
			}
			//32, 36
			else if (n <= 36)
			{
				DrawProcTable(startX, startY, 70, 12, 6, 6, n);
			}
			else if (n <= 64)
			{
				DrawProcTable(startX, startY, 53, 8, 8, 8, n);
			}
			else if (n == 256)
			{
				DrawProcTable(startX, startY, 15, 16, 16, 16, n);
			}
		}


		void DrawProcTable(int startX, int startY, int wh, int spaceX, int spaceY, int m, int n, int count)
		{
			int counter = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (counter == count) break;
					Button^ procBtn = MakeProcButton(wh, wh,
						startX + (wh + spaceX) * j, startY + (wh + spaceY) * i);
					this->panelProcessors->Controls->Add(procBtn);
					procBtns[counter] = procBtn;
					counter++;
				}
			}
		}
		void DrawProcTable(int startX, int startY, int wh, int space, int m, int n, int count)
		{
			DrawProcTable(startX, startY, wh, space, space, m, n, count);
		}

		//Создание кнопки. На вход: ширина, высота, позиция на экране
		Button^ MakeProcButton(int w, int h, int cX, int cY)
		{
			Button^ procBtn = gcnew Button();

			procBtn->BackColor = System::Drawing::Color::FromArgb(51, 51, 51);

			procBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			procBtn->Font = (
				gcnew System::Drawing::Font(L"Microsoft Sans Serif",
					23.7913F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
			procBtn->ForeColor = System::Drawing::Color::White;
			procBtn->Location = System::Drawing::Point(cX, cY);
			procBtn->Size = System::Drawing::Size(w, h);
			procBtn->UseVisualStyleBackColor = false;
			procBtn->ForeColor = System::Drawing::Color::FromArgb(120, 120, 120);
			return procBtn;
		}


		//Один такт
		Void pTimer_Tick(Object^ sender, EventArgs^ e)
		{
			pFarm->Tick(procBtns, dgLogs, dgActive, dgQueue, toolTip);
			lCurrentLoad->Text = pFarm->GetCurrentLoad() + "/" + procNumber;
			lActiveTasks->Text = Convert::ToString(pFarm->GetActiveTasksCount());
			lQueueCount->Text = Convert::ToString(pFarm->GetQueueTasksCount());
			lTotalCC->Text = Convert::ToString(pFarm->GetTotalCCs());
			lWaitingCC->Text = Convert::ToString(pFarm->GetTotalWaitingCCs());
			lTotalTasks->Text = Convert::ToString(pFarm->GetReceivedTasksCount());
			lFinishedTasks->Text = Convert::ToString(pFarm->GetCompletedTasksCount());
			lAverageLoad->Text = pFarm->GetAverageLoad() + "/" + procNumber;
		}

		void Start()
		{
			IsRunning = true;

			btnStartStop->Text = "Стоп";
			btnPauseResume->Enabled = true;

			tbTaskP->ReadOnly = true;
			tbCCDur->ReadOnly = true;
			tbMinProcForTask->ReadOnly = true;
			tbMaxProcForTask->ReadOnly = true;
			tbMinCC->ReadOnly = true;
			tbMaxCC->ReadOnly = true;

			pFarm = gcnew ProcFarm(procNumber);
			pFarm->SetNewTaskP(newTaskP);
			pFarm->SetProcForTaskRange(minProcForTask, maxProcForTask);
			pFarm->SetCCRange(minCC, maxCC);

			pTimer->Interval = ccDur;
			pTimer->Start();
		}

		void Stop()
		{
			pTimer->Stop();
			IsRunning = false;
			IsPaused = false;
			pFarm = nullptr;

			btnStartStop->Text = "Старт";
			btnPauseResume->Text = "Пауза";
			btnPauseResume->Enabled = false;

			tbTaskP->ReadOnly = false;
			tbCCDur->ReadOnly = false;
			tbMinProcForTask->ReadOnly = false;
			tbMaxProcForTask->ReadOnly = false;
			tbMinCC->ReadOnly = false;
			tbMaxCC->ReadOnly = false;

			lCurrentLoad->Text = "0/" + procNumber;
			lActiveTasks->Text = "0";
			lQueueCount->Text = "0";
			lTotalCC->Text = "0";
			lWaitingCC->Text = "0";
			lTotalTasks->Text = "0";
			lFinishedTasks->Text = "0";
			lAverageLoad->Text = "0/" + procNumber;

			dgLogs->Rows->Clear();
			dgActive->Rows->Clear();
			dgQueue->Rows->Clear();

			for (int i = 0; i < procBtns->Length; i++)
			{
				procBtns[i]->BackColor = System::Drawing::Color::FromArgb(51, 51, 51);
				procBtns[i]->Text = "";
				
				toolTip->SetToolTip(procBtns[i], "");
			}
		}

		void Pause()
		{
			pTimer->Stop();
		}

		void Resume()
		{
			pTimer_Tick(nullptr, nullptr);
			pTimer->Start();
		}
	};
}