#pragma once
#include "MyForm_instrucciones.h"
#include "Form1.h"

namespace MenuJuego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm_Menu
	/// </summary>
	public ref class MyForm_Menu : public System::Windows::Forms::Form
	{
	public:
		MyForm_Menu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonJugar;
	private: System::Windows::Forms::Button^ buttonInstrucciones;
	private: System::Windows::Forms::TextBox^ textBoxNombreUsuario;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBoxNivel;
	private: System::Windows::Forms::ComboBox^ comboBoxNumeroVidas;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBoxTiempodeJuego;
	private: System::Windows::Forms::Label^ label5;



	protected:


	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			Bitmap^ background = gcnew Bitmap("portada_img.jpg");
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm_Menu::typeid));
			this->buttonJugar = (gcnew System::Windows::Forms::Button());
			this->buttonInstrucciones = (gcnew System::Windows::Forms::Button());
			this->textBoxNombreUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBoxNivel = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxNumeroVidas = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxTiempodeJuego = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->BackgroundImage = background;
			this->SuspendLayout();
			// 
			// buttonJugar
			// 
			this->buttonJugar->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonJugar->Font = (gcnew System::Drawing::Font(L"Consolas", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonJugar->ForeColor = System::Drawing::Color::White;
			this->buttonJugar->Location = System::Drawing::Point(112, 467);
			this->buttonJugar->Name = L"buttonJugar";
			this->buttonJugar->Size = System::Drawing::Size(150, 55);
			this->buttonJugar->TabIndex = 0;
			this->buttonJugar->Text = L"Jugar";
			this->buttonJugar->UseVisualStyleBackColor = false;
			this->buttonJugar->Click += gcnew System::EventHandler(this, &MyForm_Menu::buttonJugar_Click);
			// 
			// buttonInstrucciones
			// 
			this->buttonInstrucciones->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonInstrucciones->Font = (gcnew System::Drawing::Font(L"Consolas", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonInstrucciones->ForeColor = System::Drawing::Color::White;
			this->buttonInstrucciones->Location = System::Drawing::Point(511, 467);
			this->buttonInstrucciones->Name = L"buttonInstrucciones";
			this->buttonInstrucciones->Size = System::Drawing::Size(220, 55);
			this->buttonInstrucciones->TabIndex = 1;
			this->buttonInstrucciones->Text = L"Instrucciones";
			this->buttonInstrucciones->UseVisualStyleBackColor = false;
			this->buttonInstrucciones->Click += gcnew System::EventHandler(this, &MyForm_Menu::button2_Click);
			// 
			// textBoxNombreUsuario
			// 
			this->textBoxNombreUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxNombreUsuario->Location = System::Drawing::Point(413, 239);
			this->textBoxNombreUsuario->MaxLength = 32;
			this->textBoxNombreUsuario->Name = L"textBoxNombreUsuario";
			this->textBoxNombreUsuario->Size = System::Drawing::Size(210, 23);
			this->textBoxNombreUsuario->TabIndex = 2;
			this->textBoxNombreUsuario->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(199, 239);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 23);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Escriba su nombre:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(17, 297);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(219, 23);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nivel de dificultad";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(448, 297);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(175, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Número de vidas";
			// 
			// comboBoxNivel
			// 
			this->comboBoxNivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxNivel->FormattingEnabled = true;
			this->comboBoxNivel->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Principiante", L"Avanzado" });
			this->comboBoxNivel->Location = System::Drawing::Point(242, 297);
			this->comboBoxNivel->Name = L"comboBoxNivel";
			this->comboBoxNivel->Size = System::Drawing::Size(121, 24);
			this->comboBoxNivel->TabIndex = 6;
			// 
			// comboBoxNumeroVidas
			// 
			this->comboBoxNumeroVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->comboBoxNumeroVidas->FormattingEnabled = true;
			this->comboBoxNumeroVidas->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"3", L"4", L"5" });
			this->comboBoxNumeroVidas->Location = System::Drawing::Point(629, 296);
			this->comboBoxNumeroVidas->Name = L"comboBoxNumeroVidas";
			this->comboBoxNumeroVidas->Size = System::Drawing::Size(121, 24);
			this->comboBoxNumeroVidas->TabIndex = 7;
			this->comboBoxNumeroVidas->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm_Menu::comboBox2_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(167, 363);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(296, 23);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Tiempo de juego en minutos";
			// 
			// comboBoxTiempodeJuego
			// 
			this->comboBoxTiempodeJuego->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->comboBoxTiempodeJuego->FormattingEnabled = true;
			this->comboBoxTiempodeJuego->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"3", L"4", L"5" });
			this->comboBoxTiempodeJuego->Location = System::Drawing::Point(469, 363);
			this->comboBoxTiempodeJuego->Name = L"comboBoxTiempodeJuego";
			this->comboBoxTiempodeJuego->Size = System::Drawing::Size(121, 24);
			this->comboBoxTiempodeJuego->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(471, 573);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(301, 14);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Creado por Cesar Moraña y Jefferson Ortega";
			// 
			// MyForm_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 596);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxTiempodeJuego);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBoxNumeroVidas);
			this->Controls->Add(this->comboBoxNivel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxNombreUsuario);
			this->Controls->Add(this->buttonInstrucciones);
			this->Controls->Add(this->buttonJugar);
			this->Name = L"MyForm_Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Quarentine.exe";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		MyForm_Instrucciones1^ formulario_abre_instrucciones = gcnew MyForm_Instrucciones1();
		formulario_abre_instrucciones->ShowDialog();


	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonJugar_Click(System::Object^ sender, System::EventArgs^ e) {

		CppCLRWinformsProjekt::Form1^ formulario_juego = gcnew CppCLRWinformsProjekt::Form1();
		formulario_juego->EstablecerVidas(comboBoxNumeroVidas->SelectedIndex + 3);
		formulario_juego->EstablecerDificultad(comboBoxNivel->SelectedIndex);
		formulario_juego->EstablecerTiempo(comboBoxTiempodeJuego->SelectedIndex + 3);
		formulario_juego->ShowDialog();

		//Close();
	}
};
}
