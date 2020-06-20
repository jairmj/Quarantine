#pragma once
#include "Personaje.h"
class Proyectil: public Personaje
{
private:
	bool eliminar;
public:
	Proyectil();
	Proyectil(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Proyectil();
	void Mover(Graphics^ g, Bitmap^ img);
	void cambiar_eliminar(bool nuevo);
	bool retonar_eliminar();
};

