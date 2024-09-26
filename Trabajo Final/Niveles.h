#pragma once
#include "FormJuego.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class Niveles : public System::Windows::Forms::Form
	{
	public:
		Niveles(int tiempo, int aliados, int agentes, int habitantes)
		{
			InitializeComponent();
			
			this->Tiempo = tiempo;
			this->nAliados = aliados;
			this->nAgentes = agentes;
			this->nHabitantes = habitantes;

			canva = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(canva, this->ClientRectangle);
			bmpfondo = gcnew Bitmap("tarde.jpg");
		}

	protected:
		
		~Niveles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::PictureBox^ picBoxLevel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ canva;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		Bitmap^ bmpfondo;
		FormJuego^ NuevoJuego;
		Int32 nAliados, nAgentes, nHabitantes, Tiempo, nivel;
#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Niveles::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->picBoxLevel1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxLevel1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Niveles::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(135, 319);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 19);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Nivel Salud";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Goldenrod;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(533, 319);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 19);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Nivel Seguridad";
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
			this->btnBack->Location = System::Drawing::Point(12, 444);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(98, 44);
			this->btnBack->TabIndex = 7;
			this->btnBack->Text = L"Volver";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &Niveles::btnBack_Click);
			// 
			// picBoxLevel1
			// 
			this->picBoxLevel1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxLevel1.Image")));
			this->picBoxLevel1->Location = System::Drawing::Point(51, 65);
			this->picBoxLevel1->Name = L"picBoxLevel1";
			this->picBoxLevel1->Size = System::Drawing::Size(296, 221);
			this->picBoxLevel1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBoxLevel1->TabIndex = 10;
			this->picBoxLevel1->TabStop = false;
			this->picBoxLevel1->Click += gcnew System::EventHandler(this, &Niveles::picBoxLevel1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(455, 65);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(296, 221);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Niveles::pictureBox1_Click);
			// 
			// Niveles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->picBoxLevel1);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Niveles";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Niveles";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxLevel1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void picBoxLevel1_Click(System::Object^ sender, System::EventArgs^ e) {
		//LanzamientoLevel1
		nivel = 1;
		NuevoJuego = gcnew FormJuego(Tiempo, nAliados, nAgentes, nHabitantes, nivel);
		timer1->Enabled = false;
		this->Hide();
		NuevoJuego->ShowDialog();
		timer1->Enabled = true;
		this->Show();
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		//LanzamientoLevel 2
		nivel = 2;
		NuevoJuego = gcnew FormJuego(Tiempo, nAliados, nAgentes, nHabitantes, nivel);
		timer1->Enabled = false;
		this->Hide();
		NuevoJuego->ShowDialog();
		timer1->Enabled = true;
		this->Show();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(bmpfondo, 0, 0, this->Width, this->Height);
		buffer->Render(canva);
	}
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		this->~Niveles();
		this->Close();
	}
};
}
