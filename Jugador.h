#pragma once
#include "Personaje.h"


using namespace std;
class Jugador :	public Personaje
{
private:
public:
	int direccion;
	Jugador();
	Jugador(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Jugador();

	void caminar(Graphics^ g, Bitmap^ img);
};

