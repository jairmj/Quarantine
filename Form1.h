#pragma once
#include "Juego.h"
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			obj = new Juego();
			//********************************* sprites **********************************
			//Jugador
			img_jugador = gcnew Bitmap("jugador_principal.png");
			//Enemigos saludables
			img_adversario_saludable = gcnew Bitmap("Infectado_saludable_normal_v2.png");
			img_adversario_saludable_marcado = gcnew Bitmap("Infectado_saludable_verde.png");
			//Enemigos asintomáticos
			//img_adversario_asintomatico = gcnew Bitmap("Infectado_asintomatico_normal.png");
			img_adversario_asintomatico_marcado = gcnew Bitmap("Infectado_asintomatico_rojo.png");
			//Policía


			//Proyectiles y vehículos
			img_proyectiles = gcnew Bitmap("sprite_balas.png");
			img_ambulancia = gcnew Bitmap("ambulancia_sprite.png");

			//******************************************************************************

			//Mapas
			mapa_1_sjl = gcnew Bitmap("mapa_sjl.png");
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Juego* obj;

		// Sprites
		Bitmap^ img_jugador;

		Bitmap^ img_adversario_saludable;
		Bitmap^ img_adversario_saludable_marcado;

		Bitmap^ img_adversario_asintomatico;
		Bitmap^ img_adversario_asintomatico_marcado;


		Bitmap^ img_proyectiles;
		Bitmap^ img_ambulancia;
		//*************************************************


		//Mapas
		Bitmap^ mapa_1_sjl;

		//**************Contador
		String^ segundero;
		String^ minutero;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 859);
			this->Name = L"Form1";
			this->Text = L"Quarantine";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//Buffer**********************************************************************************
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espaciobuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espaciobuffer->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		//****************************************************************************************

		//Mapa************************************************************************************
		Rectangle porcion_dibujo = Rectangle(0, 0, mapa_1_sjl->Width, mapa_1_sjl->Height);
		buffer->Graphics->DrawImage(mapa_1_sjl, 0, 0, porcion_dibujo, GraphicsUnit::Pixel);
		//****************************************************************************************
		
		//Juego***********************************************************************************
		obj->dinamica_juego(buffer->Graphics, img_jugador, img_proyectiles,
			img_ambulancia, img_adversario_saludable, segundero, minutero);

		//Prueba escribir en pantalla*************************************************************


		//****************************************************************************************

		//Buffer**********************************************************************************
		buffer->Render(g);
		delete buffer;
		delete espaciobuffer;
		delete g;
		//****************************************************************************************


		
	}
	private: System::Void Form1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		/*
		0 = arriba
		1 = abajo
		2 = izquierda
		3 = derecha
		4 = neutro
		*/
		if (e->KeyChar == 119)//arriba
			obj->cambiar_direccion(0);
		if (e->KeyChar == 115)//abajo
			obj->cambiar_direccion(1);
		if (e->KeyChar == 97)//izquierda
			obj->cambiar_direccion(2);
		if (e->KeyChar == 100)//derecha
			obj->cambiar_direccion(3);
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space)obj->disparar();
	}
};
}
