#pragma once
#include "Personaje.h"
class Adversario :	public Personaje{
private:
	int tipo;
protected:
	Adversario();
	~Adversario();

	void cambiar_color();
};

