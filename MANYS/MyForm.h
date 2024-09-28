#pragma once
#include <iostream>
#include "TSet.h"
#include <string>
#include <vector>

void NumToStr(std::string str, std::vector <int> num) {
	int k = 0, i = 0, st, sz, ch=0;
	while (i < str.size()) {
		if (str[i] != ' ') {
			st = i;
			while (str[i] != ' ' || i < str.size()) {
				i++;
			}
			sz = i-st;
			ch = 0;
			for (int j = 0; j < sz; j++)
				ch += (str[sz - 1 - j] - '0') * pow(10, j);
			num.push_back(ch);
		}
		i++;
	}
}


namespace MANYS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Graphics^ g;
		TSet* A;
	private: System::Windows::Forms::Button^ SAVE;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ RESULT;
	public:
		TSet* B;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ SIZE;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SIZE = (gcnew System::Windows::Forms::TextBox());
			this->SAVE = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->RESULT = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SIZE
			// 
			this->SIZE->Location = System::Drawing::Point(939, 59);
			this->SIZE->Name = L"SIZE";
			this->SIZE->Size = System::Drawing::Size(181, 26);
			this->SIZE->TabIndex = 0;
			this->SIZE->TextChanged += gcnew System::EventHandler(this, &MyForm::SIZE_TextChanged);
			// 
			// SAVE
			// 
			this->SAVE->Location = System::Drawing::Point(522, 59);
			this->SAVE->Name = L"SAVE";
			this->SAVE->Size = System::Drawing::Size(137, 99);
			this->SAVE->TabIndex = 1;
			this->SAVE->Text = L"Сохранить значения";
			this->SAVE->UseVisualStyleBackColor = true;
			this->SAVE->Click += gcnew System::EventHandler(this, &MyForm::SAVE_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(114, 251);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(545, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(114, 342);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(545, 26);
			this->textBox2->TabIndex = 3;
			// 
			// RESULT
			// 
			this->RESULT->Location = System::Drawing::Point(110, 434);
			this->RESULT->Name = L"RESULT";
			this->RESULT->Size = System::Drawing::Size(1054, 103);
			this->RESULT->TabIndex = 4;
			this->RESULT->Text = L"Пусто";
			this->RESULT->Click += gcnew System::EventHandler(this, &MyForm::RESULT_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1220, 568);
			this->Controls->Add(this->RESULT);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->SAVE);
			this->Controls->Add(this->SIZE);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void SIZE_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void SAVE_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ sz = this->SIZE->Text;
		String^ sA = this->textBox1->Text;
		String^ sB = this->textBox2->Text;
		int numsz = 0, numA=0;
		for (int i = 0; i < sz->Length; i++)
			numsz += (sz[sz->Length - 1 - i] - '0') * pow(10, i);

		

		TSet C(numsz);
		A = new TSet(C);
		A->Add(5);
		B = new TSet(C);
		//std::string s = A->TSetToString();
		this->RESULT->Text += Convert::ToString(numsz);
	}
	private: System::Void RESULT_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
