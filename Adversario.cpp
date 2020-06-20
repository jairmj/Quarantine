#include "pch.h"
#include "Adversario.h"


Adversario::Adversario(){}
Adversario::Adversario(int pini_f, int pfin_f, int pini_c, int pfin_c):Personaje(pini_f, pfin_f, pini_c, pfin_c) {
	pos_x = 10; pos_y = 400;
	dx = 5; dy = 0;
}
Adversario::~Adversario(){}

void Adversario::cambiar_color(){}


void Adversario::mover(Graphics^ g, Bitmap^ img_adversario_tipo1) {
	if (dx > 0) sf = 1;
	if (dx < 0) sf = 2;
	w = img_adversario_tipo1->Width / 4;
	h = img_adversario_tipo1->Height / 4;
	if (pos_x + dx < g->VisibleClipBounds.Left) dx *= -1;
	if (pos_x + dx + w > g->VisibleClipBounds.Right) dx *= -1;

	pos_x += dx;

	dibujar(g, img_adversario_tipo1);

	sc++;
	if (sc == 4)sc = 0;
}