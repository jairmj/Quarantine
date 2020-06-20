#include "pch.h"
#include "Proyectil.h"

Proyectil::Proyectil() {}
Proyectil::Proyectil(int pini_f, int pfin_f, int pini_c, int pfin_c) :
	Personaje(pini_f, pfin_f, pini_c, pfin_c) {//Se invoca al constructor con parámetros de la clase personaje
	eliminar = false;
}

Proyectil::~Proyectil() {}


void Proyectil::Mover(Graphics^ g, Bitmap^ img_Proyectil) {
	//Para dejar la variable que posteriormente las elminará si es que salen de los bordes
	if (pos_x + dx < g->VisibleClipBounds.Left || pos_x + dx + w > g->VisibleClipBounds.Right) {
		eliminar = true;
	}
	if (pos_y + dy < g->VisibleClipBounds.Top || pos_y + dy + h > g->VisibleClipBounds.Bottom) {
		eliminar = true;
	}
	pos_x += dx;
	pos_y += dy;
	//Variables para el sprite
	w = img_Proyectil->Width ;
	h = img_Proyectil->Height / 8;
	dibujar(g, img_Proyectil);
}
void Proyectil::cambiar_eliminar(bool nuevo) {
	eliminar = nuevo;
}
bool Proyectil::retonar_eliminar() { return eliminar; }