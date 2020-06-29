#pragma once
#include "Personaje.h"
#include "Proyectil.h"
#include "Jugador.h"
#include <iostream>
class Adversario :	public Personaje{
private:
	int tipo;//Tipo 1 Saludable, Tipo 2 Asintomático, tipo 3 Ladrón
	int color; //Color 1 normal, color 2 perseguido por policia/ambulancia
	int animacion, timer_direcciones;
	bool animacion_direcciones_apoyo, marcado;
	std::string posicion;
	std::string posicion_destino;
public:
	Proyectil** arreglo_proyectiles;
	bool vivo, ladron;
	Adversario();
	Adversario(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Adversario();

	void mover(Graphics^ g, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado, Bitmap^ img_adversario_tipo2, Bitmap^ img_adversario_tipo2_marcado,
		Bitmap^ img_ladron, Bitmap^ img_proyectiles, Jugador user, int contador_timer, int dificultad);
	void cambiar_color();
	int retornar_color();

	void establecer_tipo(int nuevo);
	int conseguir_tipo();

	void establecer_posicion(std::string nuevo);
	void establecer_posicion_destino(std::string nuevo);

	void caminar_desde_hasta(std::string pos_inicial, std::string pos_final,
		Graphics^ g, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,
		Bitmap^ img_adversario_tipo2, Bitmap^ img_adversario_tipo2_marcado, Bitmap^ img_ladron,
		int contador_timer);
	void mover_proyectiles(Graphics^ g, Bitmap^ img_bala);
	void disparar(Jugador user);

	
};

