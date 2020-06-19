#pragma once
#include "Jugador.h"
#include "Adversario.h"
class Juego
{
private:
	int pantalla_inicio, mapa_principal;
	int puntos;
	Jugador* jugador_user;
	Adversario** arreglo_adversarios;

public:
	Juego();
	~Juego();
	void mostrar_inicio();
	void mostrar_mapa_principal();
	void mostrar_mapa_secundario();
	void dinamica_juego(Graphics^ g, Bitmap^ img);
	void Init();
	Adversario* crear_enemigo(int tipo);
	void mover_jugador(Graphics^ g, Bitmap^ img);
	void cambiar_direccion(int direccion);
};

