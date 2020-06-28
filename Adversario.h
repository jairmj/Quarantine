#pragma once
#include "Personaje.h"
#include <iostream>
class Adversario :	public Personaje{
private:
	int tipo;//Tipo 1 Saludable, Tipo 2 Asintomático
	int animacion, timer_direcciones;
	bool animacion_direcciones_apoyo;
	std::string posicion;
	std::string posicion_destino;
public:
	Adversario();
	Adversario(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Adversario();

	void mover(Graphics^ g, Bitmap^ img_adversario_tipo1, int contador_timer);
	void cambiar_color();

	void establecer_tipo(int nuevo);
	int conseguir_tipo();
	void caminar_desde_hasta(std::string pos_inicial, std::string pos_final,
		Graphics^ g, Bitmap^ img_adversario_tipo1, int contador_timer);
};

