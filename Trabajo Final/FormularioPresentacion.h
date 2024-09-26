#pragma once
#include"MenuAnimado.h"
#include"FormularioCreditos.h"
#include"Ajustes.h"
#include"Instrucciones.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	
	public ref class FormularioPresentacion : public System::Windows::Forms::Form
	{
	public:
		FormularioPresentacion(void)
		{
			InitializeComponent();
			canva = panel1->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(canva, panel1->ClientRectangle);
			bmpFondo = gcnew Bitmap("BlueCity.png");
			mapa = new MovingMap(0, 0, 250, 500, 88, 2.0);
			spBackgroundMusic = gcnew SoundPlayer("AudioInicio.wav");
		}

	protected:
		
		~FormularioPresentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnCredits;
	private: System::Windows::Forms::Button^ btnInstruccionss;
	private: System::Windows::Forms::Button^ btnPlay;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		MovingMap* mapa;
		Graphics^ canva;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ buffer;
		Bitmap^ bmpFondo;
		SoundPlayer^ spBackgroundMusic;
		Ajustes^ eligeAjustes;
		Instrucciones^ MostrarInstrucciones;
	private: System::Windows::Forms::Button^ btnClose;
		   

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnCredits = (gcnew System::Windows::Forms::Button());
			this->btnInstruccionss = (gcnew System::Windows::Forms::Button());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnClose);
			this->panel1->Controls->Add(this->btnCredits);
			this->panel1->Controls->Add(this->btnInstruccionss);
			this->panel1->Controls->Add(this->btnPlay);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 500);
			this->panel1->TabIndex = 0;
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::OrangeRed;
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClose->FlatAppearance->BorderSize = 4;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClose->Location = System::Drawing::Point(12, 430);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(83, 44);
			this->btnClose->TabIndex = 4;
			this->btnClose->Text = L"Salir";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &FormularioPresentacion::btnClose_Click);
			// 
			// btnCredits
			// 
			this->btnCredits->BackColor = System::Drawing::Color::DarkOrange;
			this->btnCredits->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnCredits->FlatAppearance->BorderSize = 4;
			this->btnCredits->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
			this->btnCredits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCredits->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCredits->Location = System::Drawing::Point(325, 299);
			this->btnCredits->Name = L"btnCredits";
			this->btnCredits->Size = System::Drawing::Size(143, 44);
			this->btnCredits->TabIndex = 3;
			this->btnCredits->Text = L"Créditos";
			this->btnCredits->UseVisualStyleBackColor = false;
			this->btnCredits->Click += gcnew System::EventHandler(this, &FormularioPresentacion::btnCredits_Click);
			// 
			// btnInstruccionss
			// 
			this->btnInstruccionss->BackColor = System::Drawing::Color::DarkOrange;
			this->btnInstruccionss->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnInstruccionss->FlatAppearance->BorderSize = 4;
			this->btnInstruccionss->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
			this->btnInstruccionss->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInstruccionss->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstruccionss->Location = System::Drawing::Point(325, 249);
			this->btnInstruccionss->Name = L"btnInstruccionss";
			this->btnInstruccionss->Size = System::Drawing::Size(143, 44);
			this->btnInstruccionss->TabIndex = 2;
			this->btnInstruccionss->Text = L"Instrucciones";
			this->btnInstruccionss->UseVisualStyleBackColor = false;
			this->btnInstruccionss->Click += gcnew System::EventHandler(this, &FormularioPresentacion::btnInstruccionss_Click);
			// 
			// btnPlay
			// 
			this->btnPlay->BackColor = System::Drawing::Color::DarkOrange;
			this->btnPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnPlay->FlatAppearance->BorderSize = 4;
			this->btnPlay->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
			this->btnPlay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPlay->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlay->Location = System::Drawing::Point(325, 199);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(143, 44);
			this->btnPlay->TabIndex = 1;
			this->btnPlay->Text = L"Jugar";
			this->btnPlay->UseVisualStyleBackColor = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &FormularioPresentacion::btnPlay_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormularioPresentacion::timer1_Tick);
			// 
			// FormularioPresentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"FormularioPresentacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Presentación";
			this->Load += gcnew System::EventHandler(this, &FormularioPresentacion::FormularioPresentacion_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		mapa->anima();
		mapa->dibujar(buffer->Graphics, bmpFondo);
		buffer->Render(canva);
	}
private: System::Void FormularioPresentacion_Load(System::Object^ sender, System::EventArgs^ e) {
	spBackgroundMusic->PlayLooping();
}
private: System::Void btnCredits_Click(System::Object^ sender, System::EventArgs^ e) {
	FormularioCreditos^ MostrarCreditos = gcnew FormularioCreditos();
	timer1->Enabled = false;
	MostrarCreditos->ShowDialog();
	timer1->Enabled = true;
}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
	this->Hide();
	eligeAjustes = gcnew Ajustes();
	eligeAjustes->ShowDialog();
	timer1->Enabled = true;
	this->Show();
}
private: System::Void btnInstruccionss_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
	this->Hide();
	MostrarInstrucciones = gcnew Instrucciones();
	MostrarInstrucciones->ShowDialog();
	timer1->Enabled = true;
	this->Show();
}
};
}
