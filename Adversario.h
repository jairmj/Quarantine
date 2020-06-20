#pragma once
#include "Personaje.h"
class Adversario :	public Personaje{
private:
	int tipo;
public:
	Adversario();
	Adversario(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Adversario();

	void mover(Graphics^ g, Bitmap^ img_ambulancia);
	void cambiar_color();
};

