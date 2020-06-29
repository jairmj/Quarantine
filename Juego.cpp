#include "pch.h"
#include "Juego.h"
#include <iostream>
#include <conio.h>
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

Adversario* Juego::crear_enemigo(int tipo, bool ladron) {

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
	else if(tipo == 2 || tipo == 3) {//Enemigo de tipo 2 y ladr�n
		if (tipo == 2) {
			eleccion = rand() % 3;//asintom�tico solo sale en B, C o D
			nuevo_adversario->establecer_tipo(2);
		}
		if (tipo == 3) {
			eleccion = rand() % 4;//Ladr�n sale en cualquier lado
			nuevo_adversario->establecer_tipo(3);
		}
		switch (eleccion)
		{
		case 0: {
			nuevo_adversario->set_pos_x(576 - 61);
			nuevo_adversario->set_pos_y(300 - 80);
			nuevo_adversario->establecer_posicion("B");
			switch (rand()%3)//Como aparece en B tiene que ir a otro destino
			{
			case 0: nuevo_adversario->establecer_posicion_destino("A"); break;
			case 1: nuevo_adversario->establecer_posicion_destino("C"); break;
			case 2: nuevo_adversario->establecer_posicion_destino("D"); break;
			default:break;
			}
			break;
		}
		case 1: {
			nuevo_adversario->set_pos_x(896 - 61);
			nuevo_adversario->set_pos_y(555 - 80);
			nuevo_adversario->establecer_posicion("C");
			break;
		}
		case 2: {
			nuevo_adversario->set_pos_x(281 - 61);
			nuevo_adversario->set_pos_y(675 - 80);
			nuevo_adversario->establecer_posicion("D");
			break;
		}
		case 3: {
			nuevo_adversario->set_pos_x(91 - 61);
			nuevo_adversario->set_pos_y(110 - 80);
			nuevo_adversario->establecer_posicion("A");
			break;
		}
		default:
			break;
		}

	}
	if (ladron) nuevo_adversario->ladron = true;
	else nuevo_adversario->ladron = false;
	arreglo_adversarios[cantidad_adversarios] = nuevo_adversario;
	cantidad_adversarios++;

	return nuevo_adversario;
}

void Juego::Init() {

	cantidad_adv_tipo1 = cantidad_adv_tipo2 = 0;
	cantidad_maxima_adversarios = rand() % 6 + 5;
	arreglo_adversarios = new Adversario * [cantidad_maxima_adversarios + 1];
	cantidad_adversarios = 0;
	
	jugador_user = new Jugador(0, 0, 0, 0);
	jugador_user->cambiar_sf(0);
	jugador_user->cambiar_sc(0);


	ambulancia = new Ambulancia(0, 4, 0, 4);
	ambulancia->cambiar_sc(0);
	ambulancia->cambiar_sf(0);

	policia = new Policia(0, 4, 0, 4);
	policia->cambiar_sc(0);
	policia->cambiar_sf(0);

	contador_timer = segundos = minutos = cantidad_adverasrios_eliminados = mapa_principal = 0;
	fase_inicial = true;
	final_v1 = final_v2 = game_over = pantalla_game_over = pantalla_you_win = inmunidad = apoyo_inmunidad = false;
	game_over_v2 = false;
	timer_inmunidad = -1;
}
void Juego::mostrar_inicio(){}

void Juego::dinamica_juego(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles, Bitmap^ img_pociones, Bitmap^ mapa_sjl, Bitmap^ mapa_brena,
							Bitmap^ img_ambulancia, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,
							Bitmap^ img_adversario_tipo2, Bitmap^ img_adversario_tipo2_marcado, Bitmap^ img_policia,
							Bitmap^ img_ladron, Bitmap^ img_exclamacion, Bitmap^ img_game_over, Bitmap^ img_you_win, String^ segundero, String^ minutero, String^ puntos_string)
{
		if (!pantalla_game_over && !pantalla_you_win) {//Si ni el game over ni el you win se han activado
			if (mapa_principal == 0) dibujar_mapa(g, mapa_brena);
			else if (mapa_principal == 1) dibujar_mapa(g, mapa_sjl);


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
								crear_enemigo(1, false);
								cantidad_adv_tipo1++;// es 3
							}
							else {
								crear_enemigo(2, false);
								cantidad_adv_tipo2++;// es 1
							}
						}
						break;
					}
					case 2: {
						if (cantidad_adv_tipo1 + cantidad_adv_tipo2 < cantidad_maxima_adversarios) {
							if (cantidad_adv_tipo2 <= cantidad_maxima_adversarios / 2) {
								crear_enemigo(2, false);
								cantidad_adv_tipo2++;
							}
							else {
								crear_enemigo(1, false);
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


			if (inmunidad && apoyo_inmunidad) {//La inmunidad se activ�, en 3 segundos se ir�
				timer_inmunidad = segundos + 3;
				apoyo_inmunidad = false;
			}

			if (timer_inmunidad == segundos) {
				inmunidad = false; //Pasaron 3 segundos, desactivo inmunidad
				timer_inmunidad = -1;
			}
	
			mostrar_vidas(g, vidas, puntos_string);
			mostrar_tiempo(g, segundero, minutero);
			mostrar_puntos(g, puntos_string);
			jugador_user->caminar(g, img, img_proyectiles, mapa_principal);
			ambulancia->mover(g, img_ambulancia, img_exclamacion,arreglo_adversarios, cantidad_adversarios);
			policia->mover(g, img_policia, img_exclamacion ,arreglo_adversarios, cantidad_adversarios);
			for (int i = 0; i < cantidad_adversarios; i++) {
				arreglo_adversarios[i]->mover(g,img_adversario_tipo1, img_adversario_tipo1_marcado,
												img_adversario_tipo2, img_adversario_tipo2_marcado,img_ladron, img_pociones,
												*jugador_user, contador_timer, dificultad);
			}

			//Funcionalidad adicional

			if (cantidad_adverasrios_eliminados == cantidad_maxima_adversarios && fase_inicial) {//Si ha matado a todos
				fase_inicial = false;
				MessageBox::Show("Ha aparecido un ladr�n en el distrito!\n�ayuda al policia a capturarlo yendo a por �l!", "�CUIDADO!",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				crear_enemigo(1, true);//Creo al ladr�n
				cantidad_maxima_adversarios++;//Se a�ade el nuevo adversario
				cantidad_adv_tipo1++;
			}

			//Final del juego
			if (final_v2) {
				reset();
			}
		

			if (minutos == tiempo || vidas == 0) {
				game_over_v2 = true;
			}
		}
		else if(pantalla_game_over){//Se activ� game over
			dibujar_mapa(g, img_game_over);
		}
		else if (pantalla_you_win) {//El jugador ha ganado
			dibujar_mapa(g, img_you_win);
		}

		if (game_over_v2) {
			game_over_v2 = false;
			pantalla_game_over = true;
			if(minutos == tiempo) MessageBox::Show("�Te has quedado sin tiempo!\n pulse r para reiniciar", "GAME OVER",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			if(vidas == 0)MessageBox::Show("�Te has quedado sin vidas!\n pulse r para reiniciar", "GAME OVER",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}

}

void Juego::cambiar_direccion(int direccion) {
	jugador_user->direccion = direccion;
}

void Juego::disparar() {
	jugador_user->disparar();
}

void Juego::mostrar_tiempo(Graphics^ g, String^ segundero, String^ minutero) {




	System::Drawing::Font^ myfont = gcnew System::Drawing::Font("Consolas", 20);
	System::Drawing::SolidBrush^ mybrush = gcnew System::Drawing::SolidBrush(Color::Black);

	if (segundos > 9) {
		segundero = segundos.ToString();
		minutero = minutos.ToString() + ":" + segundero;
	}
	else if (segundos < 10) {
		segundero = "0" + segundos.ToString();
		minutero = minutos.ToString() + ":" + segundero;
	}
	g->DrawString(minutero, myfont, mybrush, 10, 10);
	
}

void Juego::mostrar_puntos(Graphics^ g, String^ puntos_string) {

	puntos_string = "Puntos: " + jugador_user->retornar_puntos().ToString();
	System::Drawing::Font^ myfont = gcnew System::Drawing::Font("Consolas", 20);
	System::Drawing::SolidBrush^ mybrush = gcnew System::Drawing::SolidBrush(Color::Black);
	g->DrawString(puntos_string, myfont, mybrush, 900, 10);
	
}

void Juego::mostrar_vidas(Graphics^ g, int vidas, String^ puntos_string) {

	puntos_string = "Vidas: " + vidas.ToString();
	System::Drawing::Font^ myfont = gcnew System::Drawing::Font("Consolas", 20);
	System::Drawing::SolidBrush^ mybrush = gcnew System::Drawing::SolidBrush(Color::Black);
	g->DrawString(puntos_string, myfont, mybrush, 900, 40);
	
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

bool Juego::ayudaColision_ambulancia_enemigo(Adversario* e1, Ambulancia* e2) {
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

bool Juego::ayudaColision_policia_enemigo(Adversario* e1, Policia* e2) {
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
bool Juego::ayudaColision_jugador_enemigo(Jugador* e1, Adversario* e2) {
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

bool Juego::ayudaColision_jugador_proyectil(Jugador* e1, Proyectil* e2) {
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
				if (ayudaColisionEnemigo_proyectil(arreglo_adversarios[adv], jugador_user->arreglo_proyectiles[bala]) && arreglo_adversarios[adv]->vivo) {//Si una bala choca con un enemigo
					jugador_user->arreglo_proyectiles[bala]->cambiar_eliminar(true);
					if (arreglo_adversarios[adv]->retornar_color() == 1) {
						jugador_user->a�adir_10puntos();
						arreglo_adversarios[adv]->cambiar_color();
					}
				}
			}
		}
	}

	//Ambulancia y policia con los marcados
	for (int adv = 0; adv < cantidad_adversarios; adv++) {
		if (ayudaColision_ambulancia_enemigo(arreglo_adversarios[adv], ambulancia)) {
			if (arreglo_adversarios[adv]->conseguir_tipo() == 2 && arreglo_adversarios[adv]->retornar_color() == 2
				&& arreglo_adversarios[adv]->vivo) {
				arreglo_adversarios[adv]->vivo = false;
				ambulancia->numero_objetivo = 100;
				cantidad_adverasrios_eliminados++;
			}

		}
		if (ayudaColision_policia_enemigo(arreglo_adversarios[adv], policia)) {
			if (arreglo_adversarios[adv]->conseguir_tipo() == 1  && arreglo_adversarios[adv]->retornar_color() == 2
				&& arreglo_adversarios[adv]->vivo)
			{
				arreglo_adversarios[adv]->vivo = false;
				policia->numero_objetivo = 100;
				cantidad_adverasrios_eliminados++;
				if (final_v1) {
					final_v2 = true;//Final de la partida
				}
			}
		}
	}

	//Jugador y ladr�n
	for (int adv = 0; adv < cantidad_adversarios; adv++) {
		if (ayudaColision_jugador_enemigo(jugador_user, arreglo_adversarios[adv])) {
			if (arreglo_adversarios[adv]->ladron && arreglo_adversarios[adv]->retornar_color() == 1) {
				jugador_user->a�adir_10puntos();
				arreglo_adversarios[adv]->cambiar_color();
				final_v1 = true;
			}
		}
	}

	//Proyectiles y jugador
	for (int adv = 0; adv < cantidad_adversarios; adv++) {
		for (int bala = 0; bala < arreglo_adversarios[adv]->retornar_cantidad_proyectiles(); bala++) {
			if (ayudaColision_jugador_proyectil(jugador_user, arreglo_adversarios[adv]->arreglo_proyectiles[bala])) {
				vidas--;
				arreglo_adversarios[adv]->arreglo_proyectiles[bala]->cambiar_eliminar(true);
			}
		}
	}

	//Enemigos y jugador
	for (int adv = 0; adv < cantidad_adversarios; adv++) {
		if (!(arreglo_adversarios[adv]->ladron) && !inmunidad) {//Si no es el ladron y no est� activa la inmunidad
			if (ayudaColision_jugador_enemigo(jugador_user, arreglo_adversarios[adv])) {
				vidas--;
				inmunidad = true;
				apoyo_inmunidad = true;
			}
		}
	}

}

void Juego::dibujar_mapa(Graphics^ g, Bitmap^ img_mapa) {
	Rectangle porcion_dibujo = Rectangle(0, 0, img_mapa->Width, img_mapa->Height);
	g->DrawImage(img_mapa, 0, 0, porcion_dibujo, GraphicsUnit::Pixel);
}



void Juego::reset() {
	if (mapa_principal == 0) {
	Init();
	mapa_principal = 1;
	}
	else {//El jugador gan�
		pantalla_you_win = true;
	}
}