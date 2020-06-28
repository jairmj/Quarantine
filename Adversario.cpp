#include "pch.h"
#include "Adversario.h"


Adversario::Adversario(){}
Adversario::Adversario(int pini_f, int pfin_f, int pini_c, int pfin_c):Personaje(pini_f, pfin_f, pini_c, pfin_c) {
	pos_x = 10; pos_y = 400;
	dx = 5; dy = 0;
	posicion = "A";
	posicion_destino = "B";
	animacion = 0;
	animacion_direcciones_apoyo = true;
	color = 1;
}
Adversario::~Adversario(){}

void Adversario::cambiar_color() { color = 2; }

void Adversario::establecer_tipo(int nuevo) { tipo = nuevo; }
int Adversario::conseguir_tipo() { return tipo; }

void Adversario::establecer_posicion(std::string nuevo) { posicion = nuevo; }
void Adversario::establecer_posicion_destino(std::string nuevo) { posicion_destino = nuevo; }

void Adversario::mover(Graphics^ g, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado, int contador_timer) {

	w = img_adversario_tipo1->Width / 4;
	h = img_adversario_tipo1->Height / 4;

	pos_x += w; pos_y += h;
	
	caminar_desde_hasta(posicion, posicion_destino, g, img_adversario_tipo1, img_adversario_tipo1_marcado, contador_timer);
}


void Adversario::caminar_desde_hasta(std::string pos_inicial, std::string pos_final,
									Graphics^ g, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado, int contador_timer)
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
	//Listo
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
					else if (tipo == 2) {
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
			dibujar(g, img_adversario_tipo1);
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
					else if (tipo == 2) {
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

			dibujar(g, img_adversario_tipo1);
		}
		else {//Llegó a arriba, caminar hacia la derecha
			if (pos_x < 576) {
				sf = 1; pos_x += 3;

				pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
				dibujar(g, img_adversario_tipo1);
			}
			else {//Llegó a la derecha, caminar hacia arriba hasta el destino
				if (pos_y > 300) {
					sf = 3; pos_y -= 3;

					pos_x -= w; pos_y -= h;	sc++; if (sc == 4)sc = 0;
					dibujar(g, img_adversario_tipo1);

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
					dibujar(g, img_adversario_tipo1);


					if (animacion == 4) {
						pos_x = 576 - w; pos_y = 300 - h;	//Establezco la posición exacta.
						animacion = 0; posicion = "B";

						if (tipo == 1) posicion_destino = "A"; //Si es tipo 1 que vuelva a A
						else if (tipo == 2) {
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
	//Listo
	else if (posicion == "B" && posicion_destino == "A" && tipo == 2) {//Camino 1
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

	if (color == 1)dibujar(g, img_adversario_tipo1);
	if (color == 2)dibujar(g, img_adversario_tipo1_marcado);
}

/*
0 = arriba
1 = abajo
2 = izquierda
3 = derecha
4 = neutro
*/