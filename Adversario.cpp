#include "pch.h"
#include "Adversario.h"
#include <iostream>
#include <stdlib.h>

Adversario::Adversario(){}
Adversario::Adversario(int pini_f, int pfin_f, int pini_c, int pfin_c):Personaje(pini_f, pfin_f, pini_c, pfin_c) {
	pos_x = 10; pos_y = 400;
	dx = 5; dy = 0;
	posicion = "A";
	posicion_destino = "B";
	animacion = 0;
	animacion_direcciones_apoyo = vivo = true;
	color = 1;
}
Adversario::~Adversario(){}

void Adversario::cambiar_color() { color = 2; }
int Adversario::retornar_color() { return color;}

void Adversario::establecer_tipo(int nuevo) { tipo = nuevo; }
int Adversario::conseguir_tipo() { return tipo; }

void Adversario::establecer_posicion(std::string nuevo) { posicion = nuevo; }
void Adversario::establecer_posicion_destino(std::string nuevo) { posicion_destino = nuevo; }

void Adversario::mover(Graphics^ g, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,
	Bitmap^ img_adversario_tipo2, Bitmap^ img_adversario_tipo2_marcado, Bitmap^ img_ladron, Bitmap^ img_proyectiles, Jugador user, int contador_timer, int dificultad) {

	w = img_adversario_tipo1->Width / 4;
	h = img_adversario_tipo1->Height / 4;

	pos_x += w; pos_y += h;
	
	if (vivo && rand() % 40 == 6 && dificultad == 1) {//Aleatoriamente, solo crea balas en el nivel avanzado
		disparar(user);
	}



	mover_proyectiles(g, img_proyectiles);
	caminar_desde_hasta(posicion, posicion_destino, g, img_adversario_tipo1, img_adversario_tipo1_marcado, img_adversario_tipo2, img_adversario_tipo2_marcado, img_ladron, contador_timer);
}


void Adversario::caminar_desde_hasta(std::string pos_inicial, std::string pos_final,
									Graphics^ g, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,
									Bitmap^ img_adversario_tipo2, Bitmap^ img_adversario_tipo2_marcado,
									Bitmap^ img_ladron, int contador_timer)
{


	/*
	 A: [91, 110]
	 B: [576, 300]
	 C: [896, 555]
	 D: [281, 675]

	 sf:

	 0: abajo
	 1: derecha
	 2: izquierda
	 3: arriba
	*/

	// Hacia B
	if(pos_inicial == "A" && pos_final == "B") {
		if (pos_x < 576) {// Caminar hacia la derecha
			sf = 1; pos_x += 3;

			pos_x -= w; pos_y -= h; sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a la derecha, caminar hacia abajo hastga llegar al destino
			if (pos_y < 300) {
				sf = 0; pos_y += 3;

				pos_x -= w; pos_y -= h;

				sc++; if (sc == 4)sc = 0;
			}
			else {//LLegó al destino, cambio la posición inicial y la de destino
				sf = animacion;



				if (animacion_direcciones_apoyo) {
					timer_direcciones = contador_timer + 10;
					animacion_direcciones_apoyo = false;
				}

				if (contador_timer == timer_direcciones) {
					sc = 0;
					if (sf = 2) sc = 0;
					animacion++;
					animacion_direcciones_apoyo = true;
				}


				pos_x -= w; pos_y -= h;


				if (animacion == 4) {
					pos_x = 576 - w; pos_y = 300 - h;	//Establezco la posición exacta.
					animacion = 0; posicion = "B";		
					
					if (tipo == 1) posicion_destino = "A"; //Si es tipo 1 que vuelva a A
					else if (tipo == 2 || tipo == 3) {
						switch (rand()%3)//Es tipo 2, posición destino aleatoria en todo el mapa
						{
							case 0: { posicion_destino = "A"; break; }
							case 1: { posicion_destino = "C"; break; }
							case 2: { posicion_destino = "D"; break; }
							default: break;
						}
						
					}
				}
			}
		}
	}// Listo   //Listo

	else if (posicion == "C" && posicion_destino == "B") {//Camino 1
		if (pos_x > 576) {// Caminar hacia la izquierda
			sf = 2; pos_x -= 3;

			pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a la izquierda, caminar hacia arriba hasta llegar al destino
			if (pos_y > 300) {
				sf = 3; pos_y -= 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
			}
			else {//LLegó al destino, animación y cambio la posición inicial y la de destino

				sf = animacion;


				if (animacion_direcciones_apoyo) {
					timer_direcciones = contador_timer + 10;
					animacion_direcciones_apoyo = false;
				}

				if (contador_timer == timer_direcciones) {
					sc = 0;
					if (sf = 2) sc = 0;
					animacion++;

					animacion_direcciones_apoyo = true;
				}
				pos_x -= w; pos_y -= h;

				if (animacion == 4) {
					pos_x = 576 - w; pos_y = 300 - h;	//Establezco la posición exacta.
					animacion = 0; posicion = "B";

					if (tipo == 1) posicion_destino = "A"; //Si es tipo 1 que vuelva a A
					else if (tipo == 2 || tipo == 3) {
						switch (rand() % 3)//Es tipo 2, posición destino aleatoria en todo el mapa
						{
						case 0: { posicion_destino = "A"; break; }
						case 1: { posicion_destino = "C"; break; }
						case 2: { posicion_destino = "D"; break; }
						default: break;
						}

					}
				}

			}
		}
	}

	else if (posicion == "D" && posicion_destino == "B") {//Camino 1
		if (pos_y > 527) {// Caminar hacia la arriba
			sf = 3; pos_y -= 3;

			pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a arriba, caminar hacia la derecha
			if (pos_x < 576) {
				sf = 1; pos_x += 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
			}
			else {//Llegó a la derecha, caminar hacia arriba hasta el destino
				if (pos_y > 300) {
					sf = 3; pos_y -= 3;

					pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
				}
				else {//LLegó al destino, animación y cambio la posición inicial y la de destino

					sf = animacion;


					if (animacion_direcciones_apoyo) {
						timer_direcciones = contador_timer + 10;
						animacion_direcciones_apoyo = false;
					}

					if (contador_timer == timer_direcciones) {
						sc = 0;
						if (sf = 2) sc = 0;
						animacion++;

						animacion_direcciones_apoyo = true;
					}
					pos_x -= w; pos_y -= h;

					if (animacion == 4) {
						pos_x = 576 - w; pos_y = 300 - h;	//Establezco la posición exacta.
						animacion = 0; posicion = "B";

						if (tipo == 1) posicion_destino = "A"; //Si es tipo 1 que vuelva a A
						else if (tipo == 2 || tipo == 3) {
							switch (rand() % 3)//Es tipo 2, posición destino aleatoria en todo el mapa
							{
							case 0: { posicion_destino = "A"; break; }
							case 1: { posicion_destino = "C"; break; }
							case 2: { posicion_destino = "D"; break; }
							default: break;
							}

						}
					}

			}
			}
		}
	}

	// Desde B hacia el resto
	else if (posicion == "B" && posicion_destino == "A" && tipo == 2 || tipo == 3) {//Camino 1
		if (pos_y > 110) {// Caminar hacia la arriba
			sf = 3; pos_y -= 3;

			pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a arriba, caminar hacia la izquierda hasta llegar al destino
			if (pos_x > 91) {
				sf = 2; pos_x -= 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
			}
			else {//LLegó al destino, animación y cambio la posición inicial y la de destino

				sf = animacion;


				if (animacion_direcciones_apoyo) {
					timer_direcciones = contador_timer + 10;
					animacion_direcciones_apoyo = false;
				}

				if (contador_timer == timer_direcciones) {
					sc = 0;
					if (sf = 2) sc = 0;
					animacion++;

					animacion_direcciones_apoyo = true;
				}
				pos_x -= w; pos_y -= h;
				if (animacion == 4) {
					pos_x = 91 - w; pos_y = 110 - h; animacion = 0;

					posicion = "A"; posicion_destino = "B";
				}

				if (animacion == 4) {
					pos_x = 576 - w; pos_y = 300 - h;	//Establezco la posición exacta.
					animacion = 0; posicion = "B";

					
				}

			}
		}
	}

	else if (posicion == "B" && posicion_destino == "A" && tipo == 1) {//Camino 1
		if (pos_x > 91) {
			sf = 2; pos_x -= 3;
			pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a arriba, caminar hacia la izquierda hasta llegar al destino
			if (pos_y > 110) {// Caminar hacia la derecha
				sf = 3; pos_y -= 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
			}
			else {//LLegó al destino, animación y cambio la posición inicial y la de destino
				sf = animacion;

				if (animacion_direcciones_apoyo) {
					timer_direcciones = contador_timer + 10;
					animacion_direcciones_apoyo = false;
				}

				if (contador_timer == timer_direcciones) {
					sc = 0;
					if (sf = 2) sc = 0;
					animacion++;

					animacion_direcciones_apoyo = true;
				}
				pos_x -= w; pos_y -= h;
				if (animacion == 4) {
					pos_x = 91 - w; pos_y = 110 - h; animacion = 0;

					posicion = "A"; posicion_destino = "B";
				}

				if (animacion == 4) {
					pos_x = 576 - w; pos_y = 300 - h;	//Establezco la posición exacta.
					animacion = 0; posicion = "B";
				}
		}
	}
	}

	else if (posicion == "B" && posicion_destino == "C") {//Camino 1
		if (pos_y < 555) {// Caminar hacia abajo
			sf = 0; pos_y += 3;

			pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a abajo, caminar hacia la derecha hasta llegar al destino
			if (pos_x < 896) {
				sf = 1; pos_x += 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
			}
			else {//LLegó al destino, animación y cambio la posición inicial y la de destino

				sf = animacion;


				if (animacion_direcciones_apoyo) {
					timer_direcciones = contador_timer + 10;
					animacion_direcciones_apoyo = false;
				}

				if (contador_timer == timer_direcciones) {
					sc = 0;
					if (sf = 2) sc = 0;
					animacion++;
					animacion_direcciones_apoyo = true;
				}
				pos_x -= w; pos_y -= h;
				if (animacion == 4) {
					pos_x = 896 - w; pos_y = 555 - h; animacion = 0;
					posicion = "C"; posicion_destino = "B";
				}
			}
		}
	}

	else if (posicion == "B" && posicion_destino == "D") {//Camino 1
		if (pos_y < 527) {// Caminar hacia abajo
			sf = 0; pos_y += 3;

			pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
		}
		else {//Llegó a abajo, caminar hacia la izquierda
			if (pos_x > 281) {
				sf = 2; pos_x -= 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
			}
			else {//Llegó a la izquierda, caminar hacia abajo hasta el destino
				if (pos_y < 675) {
					sf = 0; pos_y += 3;

					pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
				}
				else {//LLegó al destino D, animación y cambio la posición inicial y la de destino

					sf = animacion;


					if (animacion_direcciones_apoyo) {
						timer_direcciones = contador_timer + 10;
						animacion_direcciones_apoyo = false;
					}

					if (contador_timer == timer_direcciones) {
						sc = 0;
						if (sf = 2) sc = 0;
						animacion++;

						animacion_direcciones_apoyo = true;
					}
					pos_x -= w; pos_y -= h;

					if (animacion == 4) {
						pos_x = 281 - w; pos_y = 675 - h;	//Establezco la posición exacta.
						animacion = 0; 
					
						posicion = "D"; posicion_destino = "B";

					}
				}
			}
		}
	}


	if (tipo == 1 && vivo && !ladron) {
		if (color == 1)dibujar(g, img_adversario_tipo1);
		if (color == 2)dibujar(g, img_adversario_tipo1_marcado);

	}
	else if (tipo == 2 && vivo && !ladron) {
		if (color == 1)dibujar(g, img_adversario_tipo2);
		if (color == 2)dibujar(g, img_adversario_tipo2_marcado);
	}
	else if (ladron && vivo) {
		dibujar(g,img_ladron);
	}

}

/*
0 = arriba
1 = abajo
2 = izquierda
3 = derecha
4 = neutro
*/

void Adversario::disparar(Jugador user) {
	Proyectil** copia = new Proyectil * [cantidad_proyectiles + 1];
	//Proyectil proyectil_nuevo = Proyectil(0, 0, 0, 8);
	for (int j = 0; j < cantidad_proyectiles; j++) copia[j] = arreglo_proyectiles[j];

	copia[cantidad_proyectiles] = new Proyectil(0, 0, 0, 0);//Establecer parámetros.
	copia[cantidad_proyectiles]->cambiar_sf(0);
	copia[cantidad_proyectiles]->cambiar_sc(0);
	copia[cantidad_proyectiles]->set_dy(0);
	copia[cantidad_proyectiles]->set_dx(0);

	if ((pos_x < user.return_pos_x()) && (pos_y < user.return_pos_y())) {//jugador a la derecha y abajo{
		if (abs(pos_x - user.return_pos_x()) > abs(pos_y - user.return_pos_y())) {//Hay mas distancia hacia la derecha, dispara hacia ahí
			sf = 1;
			copia[cantidad_proyectiles]->set_dx(8);
			copia[cantidad_proyectiles]->set_dy(0);
		}
		else {//Hay más distanci hacia abajo
			sf = 0;
			copia[cantidad_proyectiles]->set_dx(0);
			copia[cantidad_proyectiles]->set_dy(8);
		}
	}
	else if ((pos_x < user.return_pos_x()) && (pos_y > user.return_pos_y())) {//Derecha y arriba
		if (abs(pos_x - user.return_pos_x()) > abs(pos_y - user.return_pos_y())) {//Hay mas distancia hacia la derecha, dispara hacia ahí
			copia[cantidad_proyectiles]->set_dx(8);
			copia[cantidad_proyectiles]->set_dy(0);
		}
		else {//Hay más distanci hacia arriba
			copia[cantidad_proyectiles]->set_dx(0);
			copia[cantidad_proyectiles]->set_dy(-8);
		}
	}
	else if ((pos_x > user.return_pos_x()) && (pos_y > user.return_pos_y())) {//izquierda y arriba
		if (abs(pos_x - user.return_pos_x()) > abs(pos_y - user.return_pos_y())) {//Hay mas distancia hacia la derecha, dispara hacia ahí
			copia[cantidad_proyectiles]->set_dx(-8);
			copia[cantidad_proyectiles]->set_dy(0);
		}
		else {//Hay más distanci hacia arriba
			copia[cantidad_proyectiles]->set_dx(0);
			copia[cantidad_proyectiles]->set_dy(-8);
		}
	}
	else if ((pos_x > user.return_pos_x()) && (pos_y < user.return_pos_y())) {//izquierda y abajo
		if (abs(pos_x - user.return_pos_x()) > abs(pos_y - user.return_pos_y())) {//Hay mas distancia hacia la derecha, dispara hacia ahí
			sf = 2;
			copia[cantidad_proyectiles]->set_dx(-8);
			copia[cantidad_proyectiles]->set_dy(0);
		}
		else {//Hay más distanci hacia abajo
			sf = 0;
			copia[cantidad_proyectiles]->set_dx(0);
			copia[cantidad_proyectiles]->set_dy(8);
		}
	}

	if (sf == 3) {// arriba
		copia[cantidad_proyectiles]->set_pos_y(pos_y - 80);
		copia[cantidad_proyectiles]->set_pos_x(pos_x - w / 2);
	}
	if (sf == 0) {//Abajo

		copia[cantidad_proyectiles]->set_pos_y(pos_y);
		copia[cantidad_proyectiles]->set_pos_x(pos_x - w/2);
	}
	if (sf == 1) {// derecha
		copia[cantidad_proyectiles]->set_pos_y(pos_y - h / 2);
		copia[cantidad_proyectiles]->set_pos_x(pos_x);
	}
	if (sf == 2) {// izquierda
		copia[cantidad_proyectiles]->set_pos_y(pos_y + h/2);
		copia[cantidad_proyectiles]->set_pos_x(pos_x);
	}




	(cantidad_proyectiles)++;
	arreglo_proyectiles = copia;

}

void Adversario::mover_proyectiles(Graphics^ g, Bitmap^ img_bala) {
	//Borrar las balas que han sido marcadas como eliminadas:

	//Cuento cuántas hay
	int cantidad_balas_a_eliminar = 0;
	for (int j = 0; j < cantidad_proyectiles; j++) {
		cantidad_balas_a_eliminar += arreglo_proyectiles[j]->retonar_eliminar() ? 1 : 0;
	}

	//Creo arreglo con la cantidad de balas que quedan
	Proyectil** copia = new Proyectil * [cantidad_proyectiles - cantidad_balas_a_eliminar];
	//Las paso al arreglo
	int ind = 0;
	for (int j = 0; j < cantidad_proyectiles; j++) {
		if (!arreglo_proyectiles[j]->retonar_eliminar()) {
			copia[ind] = arreglo_proyectiles[j];
			ind++;
		}
	}
	//Actualizo variables
	cantidad_proyectiles -= cantidad_balas_a_eliminar;
	arreglo_proyectiles = copia;

	//Muevo todas las balas que quedaron
	for (int j = 0; j < cantidad_proyectiles; j++) {

		arreglo_proyectiles[j]->Mover(g, img_bala, 2);
	}
}