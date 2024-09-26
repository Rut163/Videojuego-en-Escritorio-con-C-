#pragma once
#include"FormYouLose.h"
#include"FormYouWin.h"
#include <iostream>
#include <ctime>
#include "CControlador.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class FormJuego : public System::Windows::Forms::Form
	{
	public:
		FormJuego(int tiempo, int aliados, int agentes, int habitantes, int nivel)
		{
			InitializeComponent();
			
			srand(time(NULL));
			this->Tiempo = tiempo;
			this->nAgentes = agentes;
			this->nAliados = aliados;
			this->nHabitantes = habitantes;
			this->nivel = nivel;
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			n = 0;
			spMusicGame = gcnew SoundPlayer("AudioJuego.wav");
			bmpLapida = gcnew Bitmap("lapida.png");

			switch (nivel) {
			case 1:
				bmpAliados = gcnew Bitmap("SpriteAliadoSalud.png");
				bmpMap = gcnew Bitmap("MapSalud.png");
				bmpLider = gcnew Bitmap("SpriteLiderSalud.png");
				bmpHabitante = gcnew Bitmap("SpriteHabitanteSalud.png");
				bmpAgentes = gcnew Bitmap("SpriteAgenteSalud.png");
				bmpSuministro1 = gcnew Bitmap("curita.png");
				bmpSuministro2 = gcnew Bitmap("jarabe.png");
				bmpSuministro3 = gcnew Bitmap("botiquin.png");
				NewGame = new CControlador(bmpLider, bmpAliados, bmpHabitante, bmpAgentes, bmpTanque, bmpMolesto, Tiempo, nAliados, nAgentes, nHabitantes, nivel);
				break;
			case 2:
				bmpMap = gcnew Bitmap("MapSeguridad.jpeg");
				bmpAliados = gcnew Bitmap("SpriteAliadoSeguridad.png");
				bmpHabitante = gcnew Bitmap("SpriteHabitanteSeguridad.png");
				bmpLider = gcnew Bitmap("SpriteLiderSeguridad.png");
				bmpAgentes = gcnew Bitmap("SpriteAgenteSeguridad.png");
				bmpSuministro1 = gcnew Bitmap("alimentos.png");
				bmpSuministro2 = gcnew Bitmap("megafono.png");
				bmpSuministro3 = gcnew Bitmap("soborno.png");
				bmpTanque = gcnew Bitmap("tanque.png");
				bmpMolesto = gcnew Bitmap("molesto.png");
				NewGame = new CControlador(bmpLider, bmpAliados, bmpHabitante, bmpAgentes, bmpTanque, bmpMolesto, Tiempo, nAliados, nAgentes, nHabitantes, nivel);
				break;
			}
		}

	protected:
		~FormJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::ComponentModel::IContainer^ components;

	private:
		Int32 nAliados, nAgentes, nHabitantes, Tiempo, nivel;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpMap;
		Bitmap^ bmpAliados;
		Bitmap^ bmpLider;
		Bitmap^ bmpHabitante;
		Bitmap^ bmpAgentes;
		Bitmap^ bmpLapida;
		Bitmap^ bmpSuministro1;
		Bitmap^ bmpSuministro2;
		Bitmap^ bmpSuministro3;
		Bitmap^ bmpTanque;
		Bitmap^ bmpMolesto;
		CControlador* NewGame;
		SoundPlayer^ spMusicGame;
		FormYouLose^ PerdioPartida;
		FormYouWin^ GanoPartida;
		int n;
	private: System::Windows::Forms::Label^ lblPuntaje;
	private: System::Windows::Forms::Label^ lblAliados;
		   int r;
#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblAliados = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblAliados);
			this->panel1->Controls->Add(this->lblPuntaje);
			this->panel1->Controls->Add(this->lblTiempo);
			this->panel1->Location = System::Drawing::Point(1, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1060, 580);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormJuego::panel1_Paint);
			// 
			// lblAliados
			// 
			this->lblAliados->AutoSize = true;
			this->lblAliados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAliados->Location = System::Drawing::Point(333, 10);
			this->lblAliados->Name = L"lblAliados";
			this->lblAliados->Size = System::Drawing::Size(136, 20);
			this->lblAliados->TabIndex = 2;
			this->lblAliados->Text = L"Aliados usados ";
			// 
			// lblPuntaje
			// 
			this->lblPuntaje->AutoSize = true;
			this->lblPuntaje->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntaje->Location = System::Drawing::Point(885, 10);
			this->lblPuntaje->Name = L"lblPuntaje";
			this->lblPuntaje->Size = System::Drawing::Size(98, 20);
			this->lblPuntaje->TabIndex = 1;
			this->lblPuntaje->Text = L"PUNTAJE: ";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(8, 10);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(77, 20);
			this->lblTiempo->TabIndex = 0;
			this->lblTiempo->Text = L"Tiempo: ";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormJuego::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FormJuego::timer2_Tick);
			// 
			// FormJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 561);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FormJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juega";
			this->Load += gcnew System::EventHandler(this, &FormJuego::FormJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormJuego::FormJuego_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);

		NewGame->DibujarTodo(buffer->Graphics, bmpLider, bmpAliados, bmpHabitante, bmpAgentes, bmpTanque, bmpMolesto);
		NewGame->MoverTodo(buffer->Graphics);
		NewGame->verificarAliados();
		NewGame->Colision(buffer->Graphics, bmpLapida);

		r = rand() % 3;
		switch (r) {
		case 0:
			NewGame->ColisionAliadoHabitante(buffer->Graphics, bmpSuministro1, r); break;
		case 1:
			NewGame->ColisionAliadoHabitante(buffer->Graphics, bmpSuministro2, r); break;
		case 2:
			NewGame->ColisionAliadoHabitante(buffer->Graphics, bmpSuministro3, r); break;
		}

		lblPuntaje->Text = "PUNTAJE: " + NewGame->get_puntaje();
		lblAliados->Text = "ALIADOS USADOS: " + n;

		//Condiciones para poner fin al juego

		if (NewGame->get_tiempo() == 0 || NewGame->get_numAliados() == 0) {
			timer1->Enabled = false;
			timer2->Enabled = false;
			PerdioPartida = gcnew FormYouLose();
			spMusicGame->Stop();
			PerdioPartida->ShowDialog();
			this->Close();
		}
		else if (NewGame->get_puntaje() >= 100) {
			timer1->Enabled = false;
			timer2->Enabled = false;
			GanoPartida = gcnew FormYouWin();
			spMusicGame->Stop();
			GanoPartida->ShowDialog();
			this->Close();
		}
		else {
			buffer->Render(g);
		}

	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		NewGame->DisminuirTiempo();
		lblTiempo->Text = "TIEMPO: " + NewGame->get_tiempo();
	}
	private: System::Void FormJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::P:
			if (n < nAliados) {
				n++;
				NewGame->AddAliado(bmpAliados->Width / 4, bmpAliados->Height / 4);
			}
			break;
		case Keys::Up:
			NewGame->getLider()->mover(buffer->Graphics, Arriba); break;
		case Keys::Down:
			NewGame->getLider()->mover(buffer->Graphics, Abajo); break;
		case Keys::Left:
			NewGame->getLider()->mover(buffer->Graphics, Izquierda); break;
		case Keys::Right:
			NewGame->getLider()->mover(buffer->Graphics, Derecha); break;
		case Keys::Space:
			NewGame->repartirSuministros(); break;
		case Keys::T:
			if (nivel == 2) {
				if (NewGame->getMueveAgente()) {
					NewGame->setMueveAgente(false);
					NewGame->bajarPuntaje();
				}
				else if (!NewGame->getMueveAgente()) {
					NewGame->setMueveAgente(true);
				}
			}
			break;
		}
	}
	private: System::Void FormJuego_Load(System::Object^ sender, System::EventArgs^ e) {
		spMusicGame->PlayLooping();
	}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
