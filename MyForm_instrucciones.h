#pragma once

namespace MenuJuego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm_Instrucciones1
	/// </summary>
	public ref class MyForm_Instrucciones1 : public System::Windows::Forms::Form
	{
	public:
		MyForm_Instrucciones1(void)
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
		~MyForm_Instrucciones1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ Alexander_picture;
	private: System::Windows::Forms::PictureBox^ saludable_picture;
	protected:

	protected:

	private: System::Windows::Forms::PictureBox^ asintomatico_picture;

	private: System::Windows::Forms::PictureBox^ policia_picture;
	private: System::Windows::Forms::PictureBox^ ambulancia_picture;


	private: System::Windows::Forms::PictureBox^ ladron_picture;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm_Instrucciones1::typeid));
			this->Alexander_picture = (gcnew System::Windows::Forms::PictureBox());
			this->saludable_picture = (gcnew System::Windows::Forms::PictureBox());
			this->asintomatico_picture = (gcnew System::Windows::Forms::PictureBox());
			this->policia_picture = (gcnew System::Windows::Forms::PictureBox());
			this->ambulancia_picture = (gcnew System::Windows::Forms::PictureBox());
			this->ladron_picture = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Alexander_picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->saludable_picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->asintomatico_picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->policia_picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ambulancia_picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ladron_picture))->BeginInit();
			this->SuspendLayout();
			// 
			// Alexander_picture
			// 
			this->Alexander_picture->Image = gcnew Bitmap("jugador.png");
			this->Alexander_picture->BackColor = System::Drawing::Color::White;
			this->Alexander_picture->Location = System::Drawing::Point(28, 139);
			this->Alexander_picture->Name = L"Alexander_picture";
			this->Alexander_picture->Size = System::Drawing::Size(80, 80);
			this->Alexander_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Alexander_picture->TabIndex = 0;
			this->Alexander_picture->TabStop = false;
			this->Alexander_picture->Click += gcnew System::EventHandler(this, &MyForm_Instrucciones1::pictureBox1_Click);
			// 
			// saludable_picture
			//
			this->saludable_picture->Image = gcnew Bitmap("infectado_sano.png");
			this->saludable_picture->Location = System::Drawing::Point(28, 287);
			this->saludable_picture->Name = L"saludable_picture";
			this->saludable_picture->Size = System::Drawing::Size(80, 80);
			this->saludable_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->saludable_picture->TabIndex = 1;
			this->saludable_picture->TabStop = false;
			// 
			// asintomatico_picture
			// 
			this->asintomatico_picture->Image = gcnew Bitmap("infectado_asintomatico.png");
			this->asintomatico_picture->Location = System::Drawing::Point(663, 287);
			this->asintomatico_picture->Name = L"asintomatico_picture";
			this->asintomatico_picture->Size = System::Drawing::Size(80, 80);
			this->asintomatico_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->asintomatico_picture->TabIndex = 2;
			this->asintomatico_picture->TabStop = false;
			this->asintomatico_picture->Click += gcnew System::EventHandler(this, &MyForm_Instrucciones1::pictureBox3_Click);
			// 
			// policia_picture
			// 
			this->policia_picture->Image = gcnew Bitmap("policia.png");
			this->policia_picture->Location = System::Drawing::Point(663, 139);
			this->policia_picture->Name = L"policia_picture";
			this->policia_picture->Size = System::Drawing::Size(80, 80);
			this->policia_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->policia_picture->TabIndex = 3;
			this->policia_picture->TabStop = false;
			this->policia_picture->Click += gcnew System::EventHandler(this, &MyForm_Instrucciones1::pictureBox4_Click);
			// 
			// ambulancia_picture
			// 
			this->ambulancia_picture->Image = gcnew Bitmap("ambulancia_img.png");
			this->ambulancia_picture->Location = System::Drawing::Point(28, 430);
			this->ambulancia_picture->Name = L"ambulancia_picture";
			this->ambulancia_picture->Size = System::Drawing::Size(80, 80);
			this->ambulancia_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ambulancia_picture->TabIndex = 4;
			this->ambulancia_picture->TabStop = false;
			// 
			// ladron_picture
			// 
			this->ladron_picture->Image = gcnew Bitmap("ladron.png");
			this->ladron_picture->Location = System::Drawing::Point(663, 430);
			this->ladron_picture->Name = L"ladron_picture";
			this->ladron_picture->Size = System::Drawing::Size(80, 80);
			this->ladron_picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ladron_picture->TabIndex = 5;
			this->ladron_picture->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(93, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(114, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(206, 39);
			this->label2->TabIndex = 7;
			this->label2->Text = L"ALEXANDER:\r\n- Se mueve con las teclas direccionales.\r\n- Lanza mensajes con la let"
				L"ra \"ESPACIO\".";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(447, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(210, 65);
			this->label3->TabIndex = 8;
			this->label3->Text = L"POLICIA\r\n- Aparece en un tiempo aleatorio.\r\n- Se mueve automáticamente. \r\n- Captu"
				L"ra uno por uno a los adversarios de \r\ncolor verde.";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm_Instrucciones1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(143, 259);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(435, 287);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(222, 65);
			this->label5->TabIndex = 10;
			this->label5->Text = L"ADVERSARIO ASINTOMATICO \r\n- Se desplaza libremente por el mundo.\r\n- Si colisiona "
				L"con un mensaje cambia de color\r\na rojo.\r\n- En nivel avanzado, lanza objetos.\r\n";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label6->Location = System::Drawing::Point(114, 430);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 65);
			this->label6->TabIndex = 11;
			this->label6->Text = L"AMBULANCIA\r\n- Aparece en un tiempo aleatorio.\r\n- Se mueve automáticamente. \r\n- Ca"
				L"ptura uno por uno a los adversarios de \r\ncolor rojo";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label7->Location = System::Drawing::Point(436, 430);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(221, 52);
			this->label7->TabIndex = 12;
			this->label7->Text = L"LADRON\r\n- Aparece cuando los adversarios han sido \r\ncapturados.\r\n- Debes de ayuda"
				L"r al policia a que lo capture.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label8->Location = System::Drawing::Point(114, 287);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(222, 65);
			this->label8->TabIndex = 13;
			this->label8->Text = L"ADVERSARIO SALUDABLE \r\n- Se desplaza en una sola zona del mundo.\r\n- Si colisiona "
				L"con un mensaje cambia de color\r\na verde.\r\n- En nivel avanzado, lanza objetos.";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::ForestGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(287, 536);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(296, 48);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Regresar al menu principal";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm_Instrucciones1::button1_Click);
			// 
			// MyForm_Instrucciones1
			// 
			this->BackgroundImage = gcnew Bitmap("portada_instrucciones_img.jpg");
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 596);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ladron_picture);
			this->Controls->Add(this->ambulancia_picture);
			this->Controls->Add(this->policia_picture);
			this->Controls->Add(this->asintomatico_picture);
			this->Controls->Add(this->saludable_picture);
			this->Controls->Add(this->Alexander_picture);
			this->Name = L"MyForm_Instrucciones1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm_Instrucciones1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Alexander_picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->saludable_picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->asintomatico_picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->policia_picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ambulancia_picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ladron_picture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Close();
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
