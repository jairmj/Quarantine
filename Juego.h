#pragma once
#include "Jugador.h"
#include "Adversario.h"
#include "Ambulancia.h"
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Juego
{
private:
	int segundos, minutos, contador_timer;
	int pantalla_inicio, mapa_principal;
	int puntos;
	int cantidad_adversarios, cantidad_maxima_adversarios, cantidad_adv_tipo1, cantidad_adv_tipo2;
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
	void dinamica_juego(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles,
		Bitmap^ img_ambulancia, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,String^ segundero, String^ minutero);
	void Init();
	Adversario* crear_enemigo(int tipo);
	void cambiar_direccion(int direccion);
	void disparar();
	void mostrar_tiempo(Graphics^ g, String^ segundero, String^ minutero);
	void colisiones();
	bool ayudaColisionEnemigo_proyectil(Adversario* e1, Proyectil* e2);
};

