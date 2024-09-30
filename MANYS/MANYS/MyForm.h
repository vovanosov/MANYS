#pragma once
#include <iostream>
#include "TSet.h"
#include <string>
#include <vector>
#include <stdlib.h>
//#include <msclr\marshal_cppstd.h>

//using namespace msclr::interop;

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
		

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ RESULT;
	private: System::Windows::Forms::Button^ AND;
	private: System::Windows::Forms::Button^ OR;
	private: System::Windows::Forms::Button^ NOTA;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ NOTB;
	public:
		
		void StrToNum(String^ str, std::vector <unsigned _int32>& num) {
			int k = 0, i = 0, st, sz, ch = 0;
			str += " ";
			while (i < str->Length) {
				if (str[i] >= '0' && str[i] <= '9') {
					st = i;
					while (str[i] >= '0' && str[i] <= '9') {
						i++;
					}
					sz = i - st;
					ch = 0;
					for (int j = st; j < i; j++) {
						ch += (str[i - 1 - j + st] - '0') * pow(10, j - st);
					}
					num.push_back(ch);
				}
				i++;//
			}
		}

		System::String^ StdStringToUTF16(std::string s) {

			cli::array<System::Byte>^ a = gcnew cli::array<System::Byte>(s.length());
			int i = s.length();
			while (i-- > 0)
			{
				a[i] = s[i];
			}

			return System::Text::Encoding::UTF8->GetString(a);
		}

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->RESULT = (gcnew System::Windows::Forms::Label());
			this->AND = (gcnew System::Windows::Forms::Button());
			this->OR = (gcnew System::Windows::Forms::Button());
			this->NOTA = (gcnew System::Windows::Forms::Button());
			this->NOTB = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(114, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(545, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(114, 206);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(545, 26);
			this->textBox2->TabIndex = 3;
			// 
			// RESULT
			// 
			this->RESULT->Location = System::Drawing::Point(110, 434);
			this->RESULT->Name = L"RESULT";
			this->RESULT->Size = System::Drawing::Size(1680, 1000);
			this->RESULT->TabIndex = 4;
			this->RESULT->Click += gcnew System::EventHandler(this, &MyForm::RESULT_Click);
			// 
			// AND
			// 
			this->AND->Location = System::Drawing::Point(114, 305);
			this->AND->Name = L"AND";
			this->AND->Size = System::Drawing::Size(71, 64);
			this->AND->TabIndex = 5;
			this->AND->Text = L"AND";
			this->AND->UseVisualStyleBackColor = true;
			this->AND->Click += gcnew System::EventHandler(this, &MyForm::AND_Click);
			// 
			// OR
			// 
			this->OR->Location = System::Drawing::Point(237, 305);
			this->OR->Name = L"OR";
			this->OR->Size = System::Drawing::Size(71, 64);
			this->OR->TabIndex = 6;
			this->OR->Text = L"OR";
			this->OR->UseVisualStyleBackColor = true;
			this->OR->Click += gcnew System::EventHandler(this, &MyForm::OR_Click);
			// 
			// NOTA
			// 
			this->NOTA->Location = System::Drawing::Point(391, 305);
			this->NOTA->Name = L"NOTA";
			this->NOTA->Size = System::Drawing::Size(71, 64);
			this->NOTA->TabIndex = 7;
			this->NOTA->Text = L"NOT A";
			this->NOTA->UseVisualStyleBackColor = true;
			this->NOTA->Click += gcnew System::EventHandler(this, &MyForm::NOTA_Click);
			// 
			// NOTB
			// 
			this->NOTB->Location = System::Drawing::Point(542, 305);
			this->NOTB->Name = L"NOTB";
			this->NOTB->Size = System::Drawing::Size(71, 64);
			this->NOTB->TabIndex = 8;
			this->NOTB->Text = L"NOT B";
			this->NOTB->UseVisualStyleBackColor = true;
			this->NOTB->Click += gcnew System::EventHandler(this, &MyForm::NOTB_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(77, 209);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"B";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(848, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Size_U";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1484, 691);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NOTB);
			this->Controls->Add(this->NOTA);
			this->Controls->Add(this->OR);
			this->Controls->Add(this->AND);
			this->Controls->Add(this->RESULT);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
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
		
	}
	private: System::Void RESULT_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void AND_Click(System::Object^ sender, System::EventArgs^ e) {
		TSet A, B;
		String^ sz = this->SIZE->Text;

		String^ sA = this->textBox1->Text;
		String^ sB = this->textBox2->Text;

		int numsz = 0, numA = 0;
		for (int i = 0; i < sz->Length; i++)
			numsz += (sz[sz->Length - 1 - i] - '0') * pow(10, i);

		std::vector<unsigned _int32> nA, nB;
		StrToNum(sA, nA);
		StrToNum(sB, nB);

		TSet C(numsz);
		A = C;
		B = C;

		for (int i = 0; i < nA.size(); i++)
			A.Add(nA[i]);
		for (int i = 0; i < nB.size(); i++)
			B.Add(nB[i]);

		C = A & B;
		this->RESULT->Text = StdStringToUTF16(C.TSetToString());
	}

	private: System::Void OR_Click(System::Object^ sender, System::EventArgs^ e) {
		TSet A, B;
		String^ sz = this->SIZE->Text;

		String^ sA = this->textBox1->Text;
		String^ sB = this->textBox2->Text;

		int numsz = 0, numA = 0;
		for (int i = 0; i < sz->Length; i++)
			numsz += (sz[sz->Length - 1 - i] - '0') * pow(10, i);

		std::vector<unsigned _int32> nA, nB;
		StrToNum(sA, nA);
		StrToNum(sB, nB);

		TSet C(numsz);
		A = C;
		B = C;

		for (int i = 0; i < nA.size(); i++)
			A.Add(nA[i]);
		for (int i = 0; i < nB.size(); i++)
			B.Add(nB[i]);

		C = A | B;
		this->RESULT->Text = StdStringToUTF16(C.TSetToString());
	}
	private: System::Void NOTA_Click(System::Object^ sender, System::EventArgs^ e) {
		TSet A, B;
		String^ sz = this->SIZE->Text;

		String^ sA = this->textBox1->Text;
		String^ sB = this->textBox2->Text;

		int numsz = 0, numA = 0;
		for (int i = 0; i < sz->Length; i++)
			numsz += (sz[sz->Length - 1 - i] - '0') * pow(10, i);

		std::vector<unsigned _int32> nA, nB;
		StrToNum(sA, nA);
		StrToNum(sB, nB);

		TSet C(numsz);
		A = C;
		B = C;

		for (int i = 0; i < nA.size(); i++)
			A.Add(nA[i]);
		for (int i = 0; i < nB.size(); i++)
			B.Add(nB[i]);

		C = ~A;
		this->RESULT->Text = StdStringToUTF16(C.TSetToString());
	}
	private: System::Void NOTB_Click(System::Object^ sender, System::EventArgs^ e) {
		TSet A, B;
		String^ sz = this->SIZE->Text;

		String^ sA = this->textBox1->Text;
		String^ sB = this->textBox2->Text;

		int numsz = 0, numA = 0;
		for (int i = 0; i < sz->Length; i++)
			numsz += (sz[sz->Length - 1 - i] - '0') * pow(10, i);

		std::vector<unsigned _int32> nA, nB;
		StrToNum(sA, nA);
		StrToNum(sB, nB);

		TSet C(numsz);
		A = C;
		B = C;

		for (int i = 0; i < nA.size(); i++)
			A.Add(nA[i]);
		for (int i = 0; i < nB.size(); i++)
			B.Add(nB[i]);

		C = ~B;
		this->RESULT->Text = StdStringToUTF16(C.TSetToString());
	}
};
}
