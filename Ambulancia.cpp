#include "pch.h"
#include "Ambulancia.h"
#include <iostream>
Ambulancia::Ambulancia() {}
Ambulancia::Ambulancia(int pini_f, int pfin_f, int pini_c, int pfin_c): Personaje(pini_f, pfin_f, pini_c, pfin_c) {
	dx = 5; dy = 0;
	pos_x = 0;pos_y = 700;
	aparicion_aleatoria = rand()%100; activado = false;
}
Ambulancia::~Ambulancia(){}

void Ambulancia::mover(Graphics^ g, Bitmap^ img_ambulancia){
	if (!activado) aparicion_aleatoria++;

	if (aparicion_aleatoria == 100 || activado) {
		w = img_ambulancia->Width / 2;
		h = img_ambulancia->Height / 2;
		if (pos_x + dx < g->VisibleClipBounds.Left) dx *= -1;
		if (pos_x + dx + w > g->VisibleClipBounds.Right) dx *= -1;

		pos_x += dx;
		dibujar(g, img_ambulancia);
		activado = true;
	}


	//if (pos_y - 5 > g->VisibleClipBounds.Top)
	//	dy = -velocidad; dx = 0;
	//if (pos_y + 5 + h < g->VisibleClipBounds.Bottom) dy = velocidad; dx = 0;
}