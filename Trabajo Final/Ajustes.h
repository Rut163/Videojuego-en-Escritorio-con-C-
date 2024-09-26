#pragma once
#include "MenuAnimado.h"
#include"Niveles.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Ajustes : public System::Windows::Forms::Form
	{
	public:
		Ajustes(void)
		{
			InitializeComponent();
			canva = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(canva, this->ClientRectangle);
			bmpFondoAjustes = gcnew Bitmap("unnamed.png");
			bmpCaminando = gcnew Bitmap("sombraCaminando.png");
			bmpSaltando = gcnew Bitmap("sombraSaltando.png");
			bmpConCapa = gcnew Bitmap("sombraConCapa.png");
			sombraCaminando = new MovingMap(210, 238, 378, 378, 7, 0.16);
			sombraSaltando = new MovingMap(550, 40, 480, 480, 4, 0.13);
			sombraConCapa = new MovingMap(520, 210, 309, 309, 11, 0.35);
		}

	protected:
		~Ajustes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ nudTiempo;
	private: System::Windows::Forms::NumericUpDown^ nudAgentes;
	private: System::Windows::Forms::NumericUpDown^ nudHabitantes;
	private: System::Windows::Forms::NumericUpDown^ nudAliados;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ canva;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		Niveles^ muestraNiveles;
		Bitmap^ bmpFondoAjustes;
		Bitmap^ bmpCaminando;
		Bitmap^ bmpSaltando;
		Bitmap^ bmpConCapa;
		MovingMap* sombraCaminando;
		MovingMap* sombraSaltando;
		MovingMap* sombraConCapa;
		Int32 nAliados, nAgentes, nHabitantes, Tiempo;
	private: System::Windows::Forms::Label^ label5;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nudTiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAgentes = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudHabitantes = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAliados = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudTiempo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAgentes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudHabitantes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAliados))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->label1->Location = System::Drawing::Point(59, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 19);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Tiempo:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->label2->Location = System::Drawing::Point(59, 300);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 19);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Habitantes:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->label3->Location = System::Drawing::Point(393, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 19);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Agentes:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->label4->Location = System::Drawing::Point(393, 300);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 19);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Aliados:";
			// 
			// nudTiempo
			// 
			this->nudTiempo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->nudTiempo->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudTiempo->ForeColor = System::Drawing::Color::SaddleBrown;
			this->nudTiempo->Location = System::Drawing::Point(183, 102);
			this->nudTiempo->Name = L"nudTiempo";
			this->nudTiempo->Size = System::Drawing::Size(120, 20);
			this->nudTiempo->TabIndex = 11;
			this->nudTiempo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// nudAgentes
			// 
			this->nudAgentes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->nudAgentes->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudAgentes->ForeColor = System::Drawing::Color::SaddleBrown;
			this->nudAgentes->Location = System::Drawing::Point(526, 103);
			this->nudAgentes->Name = L"nudAgentes";
			this->nudAgentes->Size = System::Drawing::Size(120, 20);
			this->nudAgentes->TabIndex = 12;
			this->nudAgentes->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// nudHabitantes
			// 
			this->nudHabitantes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->nudHabitantes->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudHabitantes->ForeColor = System::Drawing::Color::SaddleBrown;
			this->nudHabitantes->Location = System::Drawing::Point(183, 299);
			this->nudHabitantes->Name = L"nudHabitantes";
			this->nudHabitantes->Size = System::Drawing::Size(120, 20);
			this->nudHabitantes->TabIndex = 13;
			this->nudHabitantes->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// nudAliados
			// 
			this->nudAliados->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->nudAliados->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nudAliados->ForeColor = System::Drawing::Color::SaddleBrown;
			this->nudAliados->Location = System::Drawing::Point(526, 299);
			this->nudAliados->Name = L"nudAliados";
			this->nudAliados->Size = System::Drawing::Size(120, 20);
			this->nudAliados->TabIndex = 14;
			this->nudAliados->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::DarkOrange;
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBack->FlatAppearance->BorderSize = 4;
			this->btnBack->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack->Location = System::Drawing::Point(63, 444);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(98, 44);
			this->btnBack->TabIndex = 15;
			this->btnBack->Text = L"Volver";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &Ajustes::btnBack_Click);
			// 
			// btnNext
			// 
			this->btnNext->BackColor = System::Drawing::Color::DarkOrange;
			this->btnNext->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnNext->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnNext->Enabled = false;
			this->btnNext->FlatAppearance->BorderSize = 4;
			this->btnNext->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
			this->btnNext->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNext->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNext->Location = System::Drawing::Point(548, 444);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(98, 44);
			this->btnNext->TabIndex = 16;
			this->btnNext->Text = L"Seguir";
			this->btnNext->UseVisualStyleBackColor = false;
			this->btnNext->Click += gcnew System::EventHandler(this, &Ajustes::btnNext_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Ajustes::timer1_Tick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(143)));
			this->label5->Location = System::Drawing::Point(59, 125);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(217, 14);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Mínimo 30 seg y máximo 100 seg";
			// 
			// Ajustes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->nudAliados);
			this->Controls->Add(this->nudHabitantes);
			this->Controls->Add(this->nudAgentes);
			this->Controls->Add(this->nudTiempo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Ajustes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ajustes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudTiempo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAgentes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudHabitantes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAliados))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//movimiento automático
		sombraCaminando->anima();
		sombraSaltando->anima();
		sombraConCapa->anima();
		//dibuja
		buffer->Graphics->DrawImage(bmpFondoAjustes, 0, 0, this->Width, this->Height);
		sombraCaminando->dibujar(buffer->Graphics, bmpCaminando);
		sombraSaltando->dibujar(buffer->Graphics, bmpSaltando);
		sombraConCapa->dibujar(buffer->Graphics, bmpConCapa);
		//renderizar 
		buffer->Render(canva);
		Tiempo = Convert::ToInt32(nudTiempo->Value);
		nAgentes = Convert::ToInt32(nudAgentes->Value);
		nAliados = Convert::ToInt32(nudAliados->Value);
		nHabitantes = Convert::ToInt32(nudHabitantes->Value);
		if (Tiempo >= 30 && nAgentes > 0 && nAliados > 0 && nHabitantes > 0) {
			btnNext->Enabled = true;
		}
	}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
	this->~Ajustes();
	this->Close();
}
private: System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
	muestraNiveles = gcnew Niveles(Tiempo, nAliados, nAgentes, nHabitantes);
	timer1->Enabled = false;
	this->Hide();
	muestraNiveles->ShowDialog();
	timer1->Enabled = true;
	this->Show();
}
};
}
