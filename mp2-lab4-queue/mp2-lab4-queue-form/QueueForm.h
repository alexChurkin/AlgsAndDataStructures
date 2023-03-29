#pragma once
#include <msclr\marshal_cppstd.h>
#include "TextBoxFilters.h"
#include "..\mp2-lab4-queue\TQueue.h"

namespace mp2lab4queueform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	TQueue<int> queue;
	int MaxQueueSize = -1;
	int QueueStartSize = -1;
	float PushProb = -1.0F;
	float PopProb = -1.0F;

	int pushStat = 0;
	int popStat = 0;

	int angleStart = 0;
	int angleFinish = 0;

	bool IsRunning = false;

	bool FocusRecolorEnabled = true;


	public ref class QueueForm : public System::Windows::Forms::Form
	{
	private:
		Random^ rand;

	public:
		QueueForm(void)
		{
			InitializeComponent();
			SetTransparency();
			label1->Select();

			timer->Interval = 400;
			rand = gcnew Random();
		}

	protected:
		~QueueForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pbBackground;
	private: System::Windows::Forms::Label^ labelPopped;

	private: System::Windows::Forms::Label^ labelPushed;


	private: System::Windows::Forms::TextBox^ tbPopProb;
	private: System::Windows::Forms::TextBox^ tbSize;
	private: System::Windows::Forms::TextBox^ tbMaxSize;
	private: System::Windows::Forms::TextBox^ tbPushProb;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Button^ btnStartStop;
	private: System::Windows::Forms::Label^ labelQueueSize;



	private: System::ComponentModel::IContainer^ components;

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QueueForm::typeid));
			this->pbBackground = (gcnew System::Windows::Forms::PictureBox());
			this->labelPopped = (gcnew System::Windows::Forms::Label());
			this->labelPushed = (gcnew System::Windows::Forms::Label());
			this->tbPopProb = (gcnew System::Windows::Forms::TextBox());
			this->tbSize = (gcnew System::Windows::Forms::TextBox());
			this->tbMaxSize = (gcnew System::Windows::Forms::TextBox());
			this->tbPushProb = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStartStop = (gcnew System::Windows::Forms::Button());
			this->labelQueueSize = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// pbBackground
			// 
			this->pbBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBackground.Image")));
			this->pbBackground->Location = System::Drawing::Point(0, 0);
			this->pbBackground->Name = L"pbBackground";
			this->pbBackground->Size = System::Drawing::Size(430, 555);
			this->pbBackground->TabIndex = 0;
			this->pbBackground->TabStop = false;
			this->pbBackground->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &QueueForm::pbBackground_Paint);
			// 
			// labelPopped
			// 
			this->labelPopped->AutoSize = true;
			this->labelPopped->BackColor = System::Drawing::Color::Transparent;
			this->labelPopped->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPopped->ForeColor = System::Drawing::Color::MediumOrchid;
			this->labelPopped->Location = System::Drawing::Point(267, 515);
			this->labelPopped->Name = L"labelPopped";
			this->labelPopped->Size = System::Drawing::Size(24, 26);
			this->labelPopped->TabIndex = 11;
			this->labelPopped->Text = L"0";
			this->labelPopped->Visible = false;
			// 
			// labelPushed
			// 
			this->labelPushed->AutoSize = true;
			this->labelPushed->BackColor = System::Drawing::Color::Transparent;
			this->labelPushed->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPushed->ForeColor = System::Drawing::Color::MediumOrchid;
			this->labelPushed->Location = System::Drawing::Point(267, 487);
			this->labelPushed->Name = L"labelPushed";
			this->labelPushed->Size = System::Drawing::Size(24, 26);
			this->labelPushed->TabIndex = 1;
			this->labelPushed->Text = L"0";
			this->labelPushed->Visible = false;
			// 
			// tbPopProb
			// 
			this->tbPopProb->BackColor = System::Drawing::Color::DimGray;
			this->tbPopProb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPopProb->ForeColor = System::Drawing::Color::White;
			this->tbPopProb->Location = System::Drawing::Point(312, 142);
			this->tbPopProb->MaxLength = 8;
			this->tbPopProb->Name = L"tbPopProb";
			this->tbPopProb->Size = System::Drawing::Size(100, 29);
			this->tbPopProb->TabIndex = 5;
			this->tbPopProb->Text = L"0.6";
			this->tbPopProb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPopProb->Enter += gcnew System::EventHandler(this, &QueueForm::tbPopProb_Enter);
			this->tbPopProb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbPopProb_KeyPress);
			this->tbPopProb->Leave += gcnew System::EventHandler(this, &QueueForm::tbPopProb_Leave);
			// 
			// tbSize
			// 
			this->tbSize->BackColor = System::Drawing::Color::DimGray;
			this->tbSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbSize->ForeColor = System::Drawing::Color::White;
			this->tbSize->Location = System::Drawing::Point(312, 62);
			this->tbSize->MaxLength = 8;
			this->tbSize->Name = L"tbSize";
			this->tbSize->Size = System::Drawing::Size(100, 29);
			this->tbSize->TabIndex = 3;
			this->tbSize->Text = L"20";
			this->tbSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbSize->Enter += gcnew System::EventHandler(this, &QueueForm::tbSize_Enter);
			this->tbSize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbSize_KeyPress);
			this->tbSize->Leave += gcnew System::EventHandler(this, &QueueForm::tbSize_Leave);
			// 
			// tbMaxSize
			// 
			this->tbMaxSize->BackColor = System::Drawing::Color::DimGray;
			this->tbMaxSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbMaxSize->ForeColor = System::Drawing::Color::White;
			this->tbMaxSize->Location = System::Drawing::Point(312, 22);
			this->tbMaxSize->MaxLength = 8;
			this->tbMaxSize->Name = L"tbMaxSize";
			this->tbMaxSize->Size = System::Drawing::Size(100, 29);
			this->tbMaxSize->TabIndex = 2;
			this->tbMaxSize->Text = L"100";
			this->tbMaxSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbMaxSize->Enter += gcnew System::EventHandler(this, &QueueForm::tbMaxSize_Enter);
			this->tbMaxSize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbMaxSize_KeyPress);
			this->tbMaxSize->Leave += gcnew System::EventHandler(this, &QueueForm::tbMaxSize_Leave);
			// 
			// tbPushProb
			// 
			this->tbPushProb->BackColor = System::Drawing::Color::DimGray;
			this->tbPushProb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPushProb->ForeColor = System::Drawing::Color::White;
			this->tbPushProb->Location = System::Drawing::Point(312, 102);
			this->tbPushProb->MaxLength = 8;
			this->tbPushProb->Name = L"tbPushProb";
			this->tbPushProb->Size = System::Drawing::Size(100, 29);
			this->tbPushProb->TabIndex = 4;
			this->tbPushProb->Text = L"0.4";
			this->tbPushProb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPushProb->Enter += gcnew System::EventHandler(this, &QueueForm::tbPushProb_Enter);
			this->tbPushProb->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QueueForm::tbPushProb_KeyPress);
			this->tbPushProb->Leave += gcnew System::EventHandler(this, &QueueForm::tbPushProb_Leave);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label6->Location = System::Drawing::Point(146, 515);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 26);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Извлечено:";
			this->label6->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label5->Location = System::Drawing::Point(146, 487);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(118, 26);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Добавлено:";
			this->label5->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label4->Location = System::Drawing::Point(18, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(241, 26);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Вероятность извлечения:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label3->Location = System::Drawing::Point(18, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 26);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Вероятность добавления:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label2->Location = System::Drawing::Point(18, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(248, 26);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Исходная длина очереди:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 11.89565F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::MediumOrchid;
			this->label1->Location = System::Drawing::Point(18, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 26);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Максимальная длина очереди:";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &QueueForm::timer_Tick);
			// 
			// btnStartStop
			// 
			this->btnStartStop->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnStartStop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStartStop->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 18.15652F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartStop->ForeColor = System::Drawing::Color::White;
			this->btnStartStop->Location = System::Drawing::Point(18, 193);
			this->btnStartStop->Name = L"btnStartStop";
			this->btnStartStop->Size = System::Drawing::Size(393, 56);
			this->btnStartStop->TabIndex = 1;
			this->btnStartStop->Text = L"Запуск";
			this->btnStartStop->UseVisualStyleBackColor = false;
			this->btnStartStop->Click += gcnew System::EventHandler(this, &QueueForm::btnStartStop_Click);
			// 
			// labelQueueSize
			// 
			this->labelQueueSize->BackColor = System::Drawing::Color::Transparent;
			this->labelQueueSize->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 23.7913F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelQueueSize->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelQueueSize->Location = System::Drawing::Point(159, 351);
			this->labelQueueSize->Name = L"labelQueueSize";
			this->labelQueueSize->Size = System::Drawing::Size(121, 55);
			this->labelQueueSize->TabIndex = 13;
			this->labelQueueSize->Text = L"0";
			this->labelQueueSize->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelQueueSize->Visible = false;
			this->labelQueueSize->Click += gcnew System::EventHandler(this, &QueueForm::labelQueueSize_Click);
			// 
			// QueueForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 555);
			this->Controls->Add(this->labelQueueSize);
			this->Controls->Add(this->btnStartStop);
			this->Controls->Add(this->labelPopped);
			this->Controls->Add(this->labelPushed);
			this->Controls->Add(this->tbPopProb);
			this->Controls->Add(this->tbSize);
			this->Controls->Add(this->tbMaxSize);
			this->Controls->Add(this->tbPushProb);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbBackground);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"QueueForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Queue Visualizer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBackground))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void SetTransparency()
		{
			label1->Parent = pbBackground;
			label2->Parent = pbBackground;
			label3->Parent = pbBackground;
			label4->Parent = pbBackground;
			label5->Parent = pbBackground;
			label6->Parent = pbBackground;
			labelPushed->Parent = pbBackground;
			labelPopped->Parent = pbBackground;
			tbMaxSize->Parent = pbBackground;
			tbSize->Parent = pbBackground;
			tbPushProb->Parent = pbBackground;
			tbPopProb->Parent = pbBackground;
			labelQueueSize->Parent = pbBackground;
		}


		/* UI events handling */

		Void tbMaxSize_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			TextBoxFilters::NaturalNumber(sender, e);
		}
		Void tbSize_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			TextBoxFilters::NaturalNumber(sender, e);
		}
		Void tbPushProb_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			TextBoxFilters::NonNegativeDecimalNumber(sender, e);
		}
		Void tbPopProb_KeyPress(Object^ sender, KeyPressEventArgs^ e)
		{
			TextBoxFilters::NonNegativeDecimalNumber(sender, e);
		}
		System::Void btnStartStop_Click(Object^ sender, EventArgs^ e)
		{
			if (!IsRunning) Start();
			else Stop();
		}

		Void tbMaxSize_Enter(System::Object^ sender, System::EventArgs^ e)
		{
			if(FocusRecolorEnabled)
				label1->ForeColor = Color::DodgerBlue;
		}
		Void tbMaxSize_Leave(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label1->ForeColor = Color::MediumOrchid;
		}

		Void tbSize_Enter(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label2->ForeColor = Color::DodgerBlue;
		}
		Void tbSize_Leave(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label2->ForeColor = Color::MediumOrchid;
		}

		Void tbPushProb_Enter(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label3->ForeColor = Color::DodgerBlue;
		}
		Void tbPushProb_Leave(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label3->ForeColor = Color::MediumOrchid;
		}

		Void tbPopProb_Enter(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label4->ForeColor = Color::DodgerBlue;
		}
		Void tbPopProb_Leave(System::Object^ sender, System::EventArgs^ e)
		{
			if (FocusRecolorEnabled)
				label4->ForeColor = Color::MediumOrchid;
		}

		Void labelQueueSize_Click(Object^ sender, EventArgs^ e)
		{
			if (timer->Interval == 400)
			{
				timer->Interval = 200;
			}
			else if (timer->Interval == 200)
			{
				timer->Interval = 50;
			}
			else if (timer->Interval == 50)
			{
				timer->Interval = 20;
			}
			else if (timer->Interval == 20)
			{
				timer->Interval = 400;
			}
		}

		void Start()
		{
			FocusRecolorEnabled = false;

			if (!ProcessInput()) return;

			IsRunning = true;
			labelQueueSize->Visible = true;
			label5->Visible = true;
			label6->Visible = true;
			labelPushed->Visible = true;
			labelPopped->Visible = true;
			tbMaxSize->ReadOnly = true;
			tbSize->ReadOnly = true;
			tbPushProb->ReadOnly = true;
			tbPopProb->ReadOnly = true;
			btnStartStop->Text = "Остановить";

			if (queue.GetMaxSize() != MaxQueueSize)
				queue = TQueue<int>(MaxQueueSize);

			for (int i = 0; i < QueueStartSize; i++)
				queue.Push(1);

			UpdateQueueView();
			timer->Start();
		}

		void Stop()
		{
			timer->Stop();
			IsRunning = false;
			queue.Clear();

			angleStart = 0;
			angleFinish = 0;
			pbBackground->Invalidate();

			labelQueueSize->Visible = false;
			labelQueueSize->Text = "0";
			label5->Visible = false;
			label6->Visible = false;
			labelPushed->Visible = false;
			labelPushed->Text = "0";
			pushStat = 0;
			labelPopped->Visible = false;
			labelPopped->Text = "0";
			popStat = 0;
			tbMaxSize->ReadOnly = false;
			tbSize->ReadOnly = false;
			tbPushProb->ReadOnly = false;
			tbPopProb->ReadOnly = false;
			btnStartStop->Text = "Запуск";

			FocusRecolorEnabled = true;
		}

		/* User input checks */
		bool ProcessInput()
		{
			bool incorrect1 = false, incorrect2 = false;
			bool incorrect3 = false, incorrect4 = false;

			int _MaxQueueSize = -1;
			int _QueueSize = -1;
			float _PushProb = -1;
			float _PopProb = -1;

			try
			{
				_MaxQueueSize = stoi(msclr::interop::marshal_as<std::string>(tbMaxSize->Text));
				if (_MaxQueueSize <= 1)
				{
					incorrect1 = true;
					label1->ForeColor = ForeColor.Red;
				}
				else
				{
					label1->ForeColor = ForeColor.MediumOrchid;
				}
			}
			catch (...)
			{
				incorrect1 = true;
				label1->ForeColor = ForeColor.Red;
			}


			try
			{
				_QueueSize = stoi(msclr::interop::marshal_as<std::string>(tbSize->Text));
				if (!incorrect1 && _QueueSize > _MaxQueueSize)
				{
					incorrect2 = true;
					label2->ForeColor = ForeColor.Red;
				}
				else label2->ForeColor = ForeColor.MediumOrchid;
			}
			catch (...)
			{
				incorrect2 = true;
				label2->ForeColor = ForeColor.Red;
			}

			try
			{
				_PushProb = stof(msclr::interop::marshal_as<std::string>(tbPushProb->Text));
				if (_PushProb > 1.0)
				{
					incorrect3 = true;
					label3->ForeColor = ForeColor.Red;
				}
				else label3->ForeColor = ForeColor.MediumOrchid;
			}
			catch (...)
			{
				incorrect3 = true;
				label3->ForeColor = ForeColor.Red;
			}

			try
			{
				_PopProb = stof(msclr::interop::marshal_as<std::string>(tbPopProb->Text));
				if (_PopProb > 1.0)
				{
					incorrect4 = true;
					label4->ForeColor = ForeColor.Red;
				}
				else label4->ForeColor = ForeColor.MediumOrchid;
			}
			catch (...)
			{
				incorrect4 = true;
				label4->ForeColor = ForeColor.Red;
			}

			if (incorrect1) tbMaxSize->Select();
			else if (incorrect2) tbSize->Select();
			else if (incorrect3) tbPushProb->Select();
			else if (incorrect4) tbPopProb->Select();

			bool iscorrect = !(incorrect1 || incorrect2 || incorrect3 || incorrect4);
			if (iscorrect)
			{
				MaxQueueSize = _MaxQueueSize;
				QueueStartSize = _QueueSize;
				PushProb = _PushProb;
				PopProb = _PopProb;
			}
			return iscorrect;
		}

		/* Timer update */
		System::Void timer_Tick(Object^ sender, EventArgs^ e)
		{
			bool ShouldPush = rand->NextDouble() < PushProb;
			bool ShouldPop = rand->NextDouble() < PopProb;
			bool Changed = false;

			if (ShouldPush && queue.IsNotFull())
			{
				Changed = true;
				queue.Push(1);
				pushStat++;
			}
			if (ShouldPop && queue.IsNotEmpty())
			{
				Changed = true;
				queue.Pop();
				popStat++;
			}

			if (Changed) UpdateQueueView();
		}

		/* Queue view painting */
		void UpdateQueueView()
		{
			labelPushed->Text = msclr::interop::marshal_as<String^>(std::to_string(pushStat));
			labelPopped->Text = msclr::interop::marshal_as<String^>(std::to_string(popStat));
			labelQueueSize->Text = msclr::interop::marshal_as<String^>(std::to_string(queue.GetCount()));

			angleStart = 360.0f * ((float)queue.GetHead() / (float)queue.GetMaxSize());
			angleFinish = 360.0f * ((float)queue.GetCount() / (float)queue.GetMaxSize());

			pbBackground->Invalidate();
		}

		Void pbBackground_Paint(Object^ sender, PaintEventArgs^ e)
		{
			Graphics^ gr;
			gr = pbBackground->CreateGraphics();

			Pen^ ColoredPen = gcnew Pen(Color::DodgerBlue);
			ColoredPen->Width = 13.0F;

			gr->DrawArc(ColoredPen, 136, 300, 160, 160, angleStart, angleFinish);
		}
};
}