#pragma once
#include "Jugador.h"
#include "Adversario.h"
#include "Ambulancia.h"
class Juego
{
private:
	int pantalla_inicio, mapa_principal;
	int puntos;
	Jugador* jugador_user;
	Adversario** arreglo_adversarios;
	Ambulancia* ambulancia;
	Adversario* adversario_tipo1;

public:
	Juego();
	~Juego();
	void mostrar_inicio();
	void mostrar_mapa_principal();
	void mostrar_mapa_secundario();
	void dinamica_juego(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles, Bitmap^ img_ambulancia, Bitmap^ img_adversario_tipo1);
	void Init();
	Adversario* crear_enemigo(int tipo);
	void cambiar_direccion(int direccion);
	void disparar();
};

