#include "pch.h"
#include "Juego.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Juego::Juego(){
	Init();
}
Juego::~Juego(){}

Adversario* Juego::crear_enemigo(int tipo) {

	Adversario* nuevo_adversario = new Adversario(0, 0, 0, 0);
	nuevo_adversario->set_vida(5);
	nuevo_adversario->establecer_posicion_destino("B");
	nuevo_adversario->cambiar_sf(0);
	nuevo_adversario->cambiar_sc(0);

	if (tipo == 1) {//Enemigo tipo 1, comienza en el punto A
		nuevo_adversario->set_pos_x(91 - 61);
		nuevo_adversario->set_pos_y(110 - 80);
		nuevo_adversario->establecer_posicion("A");
		nuevo_adversario->establecer_tipo(1);
	}
	else {//Enemigo de tipo 2
		nuevo_adversario->set_pos_x(896 - 61);
		nuevo_adversario->set_pos_y(555 - 80);
		nuevo_adversario->establecer_posicion("C");
		nuevo_adversario->establecer_tipo(2);
	}
	arreglo_adversarios[cantidad_adversarios] = nuevo_adversario;
	cantidad_adversarios++;

	return nuevo_adversario;
}

void Juego::Init() {
	cantidad_adv_tipo1 = cantidad_adv_tipo2 = 0;
	cantidad_maxima_adversarios = rand() % 6 + 5;
	arreglo_adversarios = new Adversario * [cantidad_maxima_adversarios];
	cantidad_adversarios = 0;
	
	jugador_user = new Jugador(0, 0, 0, 0);
	jugador_user->cambiar_sf(0);
	jugador_user->cambiar_sc(0);


	ambulancia = new Ambulancia(0, 1, 0, 1);
	ambulancia->cambiar_sc(0);
	ambulancia->cambiar_sf(0);





	
	contador_timer = segundos = minutos = 0;

	//int cantidad_enemigos = rand() % 6 + 5;
	//arreglo_adversarios = new Adversario * [cantidad_enemigos];
	//int intercalador = 1;
	//for (int i = 0; i < cantidad_enemigos; i++) {
	//	arreglo_adversarios[i] = crear_enemigo((i%2));
	//}
}
void Juego::mostrar_inicio(){}
void Juego::mostrar_mapa_principal(){}
void Juego::mostrar_mapa_secundario(){}
void Juego::dinamica_juego(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles,
							Bitmap^ img_ambulancia, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,
							String^ segundero, String^ minutero)
{

	colisiones();

	contador_timer++; //Aumenta 1 cada 100 ms, cada 10 es 1 segundo
	if (contador_timer % 10 == 0 && contador_timer != 0) {
		segundos++;
		if (segundos == 60) {
			minutos++;
			segundos = 0;
		}
	

		if (segundos % 10 == 0 && segundos != 0) {
			switch (rand() % 2 + 1)// 1 y 2
			{
			case 1: {
				if (cantidad_adv_tipo1 + cantidad_adv_tipo2 < cantidad_maxima_adversarios) {
					if (cantidad_adv_tipo1 <= cantidad_maxima_adversarios / 2) {
						crear_enemigo(1);
						cantidad_adv_tipo1++;// es 3
					}
					else {
						crear_enemigo(2);
						cantidad_adv_tipo2++;// es 1
					}
				}
				break;
			}
			case 2: {
				if (cantidad_adv_tipo1 + cantidad_adv_tipo2 < cantidad_maxima_adversarios) {
					if (cantidad_adv_tipo2 <= cantidad_maxima_adversarios / 2) {
						crear_enemigo(2);
						cantidad_adv_tipo2++;
					}
					else {
						crear_enemigo(1);
						cantidad_adv_tipo1++;
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}


	mostrar_tiempo(g, segundero, minutero);
	jugador_user->caminar(g, img, img_proyectiles);
	ambulancia->mover(g, img_ambulancia);
	for (int i = 0; i < cantidad_adversarios; i++) {
		arreglo_adversarios[i]->mover(g,img_adversario_tipo1, img_adversario_tipo1_marcado,contador_timer);
	}
	//adversario_tipo1->mover(g, img_adversario_tipo1, contador_timer);
}

void Juego::cambiar_direccion(int direccion) {
	jugador_user->direccion = direccion;
}

void Juego::disparar() {
	jugador_user->disparar();
}

void Juego::mostrar_tiempo(Graphics^ g, String^ segundero, String^ minutero) {


	segundero = segundos.ToString();
	minutero = minutos.ToString();

	System::Drawing::Font^ myfont = gcnew System::Drawing::Font("Arial", 10);
	System::Drawing::SolidBrush^ mybrush = gcnew System::Drawing::SolidBrush(Color::Black);
	g->DrawString(segundero, myfont, mybrush, 20, 10);
	g->DrawString(minutero, myfont, mybrush, 10, 10);
	
}

bool Juego::ayudaColisionEnemigo_proyectil(Adversario* e1, Proyectil* e2) {
	Rectangle r1, r2;

	r1.X = e1->return_pos_x();
	r1.Y = e1->return_pos_y();
	r1.Width = e1->retornar_w();
	r1.Height = e1->retornar_h();


	r2.X = e2->return_pos_x();
	r2.Y = e2->return_pos_y();
	r2.Width = e2->retornar_w();
	r2.Height = e2->retornar_h();

	return r1.IntersectsWith(r2);
}

void Juego::colisiones(){
	//Proyectiles con los enemigos
	if (jugador_user->retornar_cantidad_proyectiles() > 0 && cantidad_adversarios > 0) {//Si hay proyectiles y enemigos actualmente
		for (int adv = 0; adv < cantidad_adversarios; adv++) {
			for (int bala = 0; bala < jugador_user->retornar_cantidad_proyectiles(); bala++) {
				if (ayudaColisionEnemigo_proyectil(arreglo_adversarios[adv], jugador_user->arreglo_proyectiles[bala])) {//Si una bala choca con un enemigo
					jugador_user->arreglo_proyectiles[bala]->cambiar_eliminar(true);
					arreglo_adversarios[adv]->cambiar_color();
				}
			}
		}
	}

}