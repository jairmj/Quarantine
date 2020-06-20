#pragma once
#include "Personaje.h"
class Ambulancia :	public Personaje{
public:
	int aparicion_aleatoria;
	bool activado;
	Ambulancia();
	Ambulancia(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Ambulancia();

	void mover(Graphics^ g, Bitmap^ img_ambulancia);
};

