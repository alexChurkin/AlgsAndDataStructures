#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "TSet.h"

namespace AlgebraOfSets {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace std;
	using namespace msclr::interop;

	TSet A, B, C;

	public ref class AOSForm : public System::Windows::Forms::Form
	{
	public:
		AOSForm(void)
		{
			InitializeComponent();

			SetInputsVisible(false);
			SetupTransparency();
		}

	protected:
		~AOSForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txbA;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txbB;
	private: System::Windows::Forms::TextBox^ txbRes;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txbN;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnUnite;
	private: System::Windows::Forms::Button^ btnIntersect;
	private: System::Windows::Forms::Button^ btnDeny;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AOSForm::typeid));
			this->txbA = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txbB = (gcnew System::Windows::Forms::TextBox());
			this->txbRes = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txbN = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnUnite = (gcnew System::Windows::Forms::Button());
			this->btnIntersect = (gcnew System::Windows::Forms::Button());
			this->btnDeny = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txbA
			// 
			this->txbA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->txbA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->txbA->ForeColor = System::Drawing::Color::White;
			this->txbA->Location = System::Drawing::Point(90, 170);
			this->txbA->Name = L"txbA";
			this->txbA->Size = System::Drawing::Size(806, 53);
			this->txbA->TabIndex = 0;
			this->txbA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AOSForm::txbA_KeyPress);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Mono", 20, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(905, 51);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Алгебра множеств";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(25, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 52);
			this->label2->TabIndex = 2;
			this->label2->Text = L"A:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(26, 274);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 52);
			this->label3->TabIndex = 3;
			this->label3->Text = L"B:";
			// 
			// txbB
			// 
			this->txbB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->txbB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->txbB->ForeColor = System::Drawing::Color::White;
			this->txbB->Location = System::Drawing::Point(90, 273);
			this->txbB->Name = L"txbB";
			this->txbB->Size = System::Drawing::Size(806, 53);
			this->txbB->TabIndex = 4;
			this->txbB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AOSForm::txbB_KeyPress);
			// 
			// txbRes
			// 
			this->txbRes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->txbRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->txbRes->ForeColor = System::Drawing::Color::White;
			this->txbRes->Location = System::Drawing::Point(34, 580);
			this->txbRes->Name = L"txbRes";
			this->txbRes->ReadOnly = true;
			this->txbRes->Size = System::Drawing::Size(862, 53);
			this->txbRes->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(27, 520);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(221, 46);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Результат:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(643, 85);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 52);
			this->label5->TabIndex = 8;
			this->label5->Text = L"N =";
			// 
			// txbN
			// 
			this->txbN->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->txbN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->txbN->ForeColor = System::Drawing::Color::White;
			this->txbN->Location = System::Drawing::Point(742, 84);
			this->txbN->MaxLength = 6;
			this->txbN->Name = L"txbN";
			this->txbN->Size = System::Drawing::Size(154, 53);
			this->txbN->TabIndex = 7;
			this->txbN->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txbN->TextChanged += gcnew System::EventHandler(this, &AOSForm::txbN_TextChanged);
			this->txbN->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AOSForm::txbN_KeyDown);
			this->txbN->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AOSForm::txbN_KeyPress);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(932, 666);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// btnUnite
			// 
			this->btnUnite->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->btnUnite->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUnite.BackgroundImage")));
			this->btnUnite->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnUnite->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUnite->Location = System::Drawing::Point(149, 368);
			this->btnUnite->Name = L"btnUnite";
			this->btnUnite->Size = System::Drawing::Size(174, 132);
			this->btnUnite->TabIndex = 10;
			this->btnUnite->UseVisualStyleBackColor = false;
			this->btnUnite->Click += gcnew System::EventHandler(this, &AOSForm::btnUnite_Click);
			// 
			// btnIntersect
			// 
			this->btnIntersect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->btnIntersect->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIntersect.BackgroundImage")));
			this->btnIntersect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnIntersect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIntersect->Location = System::Drawing::Point(379, 368);
			this->btnIntersect->Name = L"btnIntersect";
			this->btnIntersect->Size = System::Drawing::Size(174, 132);
			this->btnIntersect->TabIndex = 11;
			this->btnIntersect->UseVisualStyleBackColor = false;
			this->btnIntersect->Click += gcnew System::EventHandler(this, &AOSForm::btnIntersect_Click);
			// 
			// btnDeny
			// 
			this->btnDeny->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(111)));
			this->btnDeny->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDeny.BackgroundImage")));
			this->btnDeny->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnDeny->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeny->Location = System::Drawing::Point(612, 368);
			this->btnDeny->Name = L"btnDeny";
			this->btnDeny->Size = System::Drawing::Size(174, 132);
			this->btnDeny->TabIndex = 12;
			this->btnDeny->UseVisualStyleBackColor = false;
			this->btnDeny->Click += gcnew System::EventHandler(this, &AOSForm::btnDeny_Click);
			// 
			// AOSForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(932, 666);
			this->Controls->Add(this->btnDeny);
			this->Controls->Add(this->btnIntersect);
			this->Controls->Add(this->btnUnite);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txbN);
			this->Controls->Add(this->txbRes);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txbB);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txbA);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"AOSForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Алгебра множеств";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txbN_KeyPress(Object^ sender, KeyPressEventArgs^ e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
		{
			e->Handled = true;
		}

		if (e->KeyChar == 127) e->Handled = true;
	}
	private: System::Void txbN_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			bool v = !String::IsNullOrEmpty(txbN->Text) && Convert::ToInt32(txbN->Text) != 0;
			if (v)
				SetInputsVisible(v);
		}
	}
	private: System::Void txbN_TextChanged(Object^ sender, EventArgs^ e) {
		txbRes->Text = "";

		bool isNIncorrect = true;
		try {
			isNIncorrect = Convert::ToInt32(txbN->Text) == 0;
		}
		catch (...) {
		}

		if (String::IsNullOrEmpty(txbN->Text) || isNIncorrect) {
			SetInputsVisible(false);
		}
	}
	private: System::Void txbA_KeyPress(Object^ sender, KeyPressEventArgs^ e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && e->KeyChar != ',')
		{
			e->Handled = true;
		}
		if (e->KeyChar == 127) e->Handled = true;
	}
	private: System::Void txbB_KeyPress(Object^ sender, KeyPressEventArgs^ e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && e->KeyChar != ',')
		{
			e->Handled = true;
		}
		if (e->KeyChar == 127) e->Handled = true;
	}

	private: void SetupTransparency() {
		label1->Parent = pictureBox1;
		label2->Parent = pictureBox1;
		label3->Parent = pictureBox1;
		label4->Parent = pictureBox1;
		label5->Parent = pictureBox1;
	}

	private: void SetInputsVisible(bool v) {
		label2->Visible = v;
		label3->Visible = v;
		txbA->Visible = v;
		txbB->Visible = v;
		txbRes->Visible = v;
		label4->Visible = v;
		btnUnite->Visible = v;
		btnIntersect->Visible = v;
		btnDeny->Visible = v;
	}
	private: System::Void btnUnite_Click(Object^ sender, EventArgs^ e) {
		ReadAB_Input();
		ShowNormalizedInput();
		C = A.operatorV(B);

		txbRes->Text = marshal_as<String^>(C.TSetToString(", "));
	}
	private: System::Void btnIntersect_Click(Object^ sender, EventArgs^ e) {
		ReadAB_Input();
		ShowNormalizedInput();
		C = A.operatorv(B);
		txbRes->Text = marshal_as<String^>(C.TSetToString(", "));
	}
	private: System::Void btnDeny_Click(Object^ sender, EventArgs^ e) {
		ReadAB_Input();
		ShowNormalizedInput();
		TSet notA = ~A;
		TSet notB = ~B;
		C = notA.operatorv(notB);
		txbRes->Text = marshal_as<String^>(C.TSetToString(", "));
	}

	private: void ReadAB_Input() {
		//Считывание размера универса, а также A и B из полей ввода
		int USize;
		try {
			USize = Convert::ToInt32(txbN->Text);
		}
		catch (...) {
			return;
		}

		string aText = marshal_as<std::string>(txbA->Text);
		string bText = marshal_as<std::string>(txbB->Text);

		A = TSet(USize, aText);
		B = TSet(USize, bText);
	}

	private: void ShowNormalizedInput() {
		txbA->Text = marshal_as<String^>(A.TSetToString());
		txbB->Text = marshal_as<String^>(B.TSetToString());
	}
	};
}
