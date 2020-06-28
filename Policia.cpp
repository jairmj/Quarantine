#include "pch.h"
#include "Policia.h"

Policia::Policia() {};
Policia::Policia(int pini_f, int pfin_f, int pini_c, int pfin_c) : Personaje(pini_f, pfin_f, pini_c, pfin_c) {
	dx = 8; dy = 8;
	pos_x = 0; pos_y = 555;
	numero_objetivo = 100;
}


void Policia::mover(Graphics^ g, Bitmap^ img_policia, Adversario** arreglo_adversarios, int cantidad_adversarios) {

		for (int adv = 0; adv < cantidad_adversarios; adv++) {
			if (arreglo_adversarios[adv]->retornar_color() == 2 &&
				(arreglo_adversarios[adv]->conseguir_tipo() == 1 || arreglo_adversarios[adv]->conseguir_tipo() == 3) &&
				arreglo_adversarios[adv]->vivo) {
				numero_objetivo = adv;//Encuentra un infectado marcado de tipo 2 vivo, lo marca para ir a por él
				break;//Ha encontrado al primero, por lo que tiene que ir a buscarle y no hay necesidad de buscar más
			}
		}

		w = img_policia->Width / 4;
		h = img_policia->Height / 4;
		if (numero_objetivo != 100) {//Ha encontado un objetivo a por el cual ir
			if (arreglo_adversarios[numero_objetivo]->return_pos_x() > pos_x&& arreglo_adversarios[numero_objetivo]->return_pos_x() > pos_x + 10) {//Está a la derecha
				sf = 1;
				if (dx < 0) dx *= -1;
				pos_x += dx;
			}
			else if (arreglo_adversarios[numero_objetivo]->return_pos_x() < pos_x && arreglo_adversarios[numero_objetivo]->return_pos_x() < pos_x - 10) {//Está a la izquierda
				sf = 2;

				if (dx < 0) dx *= -1;
				pos_x -= dx;
			}
			else if (arreglo_adversarios[numero_objetivo]->return_pos_y() > pos_y) {//Está a abajo
				sf = 0;
				pos_y += dy;
			}
			else if (arreglo_adversarios[numero_objetivo]->return_pos_y() < pos_y) {//Está arriba
				sf = 3;
				pos_y -= dy;
			}

		}
		else {//No hay objetivos, se mueve de izquierda a derecha
			if (pos_x + dx < g->VisibleClipBounds.Left) dx *= -1;
			if (pos_x + dx + w > g->VisibleClipBounds.Right) dx *= -1;

			pos_x += dx;
			if (dx > 0) {
				sf = 1;
			}
			else {
				sf = 2;
			}
		}



		sc++;
		if (sc == 4) sc = 0;
		dibujar(g, img_policia);
	
}