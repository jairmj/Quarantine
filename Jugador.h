#pragma once
#include "Personaje.h"
#include <iostream>
#include <string>
using namespace std;
class Jugador :	public Personaje
{
private:
	string* arreglo_mensaje = new string[10];
protected:
	Jugador();
	~Jugador();
};

