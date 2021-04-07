#pragma once
#include <ctime>
#include <string>

namespace laba1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ñôîðìèðîâàòü ïàðîëü";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(12, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Èäåíòèôèêàòîð";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(136, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(107, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 19);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Q=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(143, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(175, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 19);
			this->label4->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(295, 167);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		char symbol[] = { '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '\0' };
		char ru_letters[] = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
		char num[] = "0123456789";

		String^ source = textBox1->Text;		// Присваиваем получаемые данные из тексбокса в строку

		if (source->Length == 0) {			// Проверяем не пустой ли textbox
			MessageBox::Show("Ââåäèòå ñòðîêó", "Îøèáêà", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox1->Focus();
			return;
		}

		int N = source->Length;				// Получаем длину строки 
		int Q = N % 5;

		label3->Text = Q.ToString();			// Вывод остатка Q 

		const int pass_len = 9;				// Требуемое кол-во символов - 9
		char password[pass_len];			// Строка-пароль

		srand(time(NULL));				// Инициализируем генератор случайных чисел
		
		password[0] = symbol[rand() % 10];		// b1
		password[1] = symbol[rand() % 10];		// b2
		password[pass_len] = '\0';			// Терминирующий ноль, конец строки 

		int i = 2;

		for (; i < pass_len; i++) {
			if (Q > 1) 
				for (; i <= Q; i++)		// b1+Q
					password[i] = symbol[rand() % 10];

			password[i] = ru_letters[rand() % 33];

			if (i == 8) password[i] = num[rand() % 10]; // b9 случайная цифра
		}
			
		System::String^ res = gcnew System::String(password);
		label4->Text = res->Replace("&", "&&");	// Вывод строки с паролем
		// Replace("&", "&&") нужен для корректного вывода этого символа...
		
	}
	};
}
