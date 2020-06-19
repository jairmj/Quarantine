#include "pch.h"
#include "Jugador.h"

Jugador::Jugador() {}

Jugador::Jugador(int pini_f, int pfin_f, int pini_c, int pfin_c): Personaje(pini_f, pfin_f, pini_c, pfin_c) {
	pos_x = 100;
	pos_y = 100;
	direccion = 0;
}
Jugador::~Jugador(){}

void Jugador::caminar(Graphics^ g, Bitmap^ img) {
	switch (direccion) {
	case 0: {dy = -5; dx = 0; break; }
	case 1: {dy = 5; dx = 0; break; }
	case 2: {dy = 0; dx = -5; break; }
	case 3: {dy = 0; dx = 5; break; }
	case 4: {dy = 0; dx = 0; break; }
	default: break;
	}
	pos_x += dx;
	pos_y += dy;

	w = img->Width / 4;
	h = img->Height / 4;
	dibujar(g, img);
	sc++;
	if (sc == 5) sc = 0;
	direccion = 4;
}