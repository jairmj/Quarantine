#pragma once
#include "Jugador.h"
#include "Adversario.h"
#include "Ambulancia.h"
#include "Policia.h"
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
	int segundos, minutos, contador_timer, eleccion;
	int pantalla_inicio, mapa_principal;
	int cantidad_adversarios, cantidad_maxima_adversarios, cantidad_adv_tipo1,
		cantidad_adv_tipo2, cantidad_adverasrios_eliminados;
	bool fase_inicial, final_v1, final_v2;
	Jugador* jugador_user;
	Adversario** arreglo_adversarios;
	Ambulancia* ambulancia;
	Policia* policia;
	Adversario* adversario_tipo1;
public:
	
	Juego();
	~Juego();
	void mostrar_inicio();
	void dibujar_mapa(Graphics^ g, Bitmap^ img_mapa);
	void dinamica_juego(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles, Bitmap^ mapa_sjl, Bitmap^ mapa_brena,
		Bitmap^ img_ambulancia, Bitmap^ img_adversario_tipo1, Bitmap^ img_adversario_tipo1_marcado,
		Bitmap^ img_adversario_tipo2, Bitmap^ img_adversario_tipo2_marcado, Bitmap^ img_policia,
		Bitmap^ img_ladron, String^ segundero, String^ minutero, String^ puntos_string);
	void Init();
	Adversario* crear_enemigo(int tipo, bool ladron);
	void cambiar_direccion(int direccion);
	void disparar();
	void mostrar_tiempo(Graphics^ g, String^ segundero, String^ minutero);
	void mostrar_puntos(Graphics^ g, String^ puntos_string);
	void colisiones();
	bool ayudaColisionEnemigo_proyectil(Adversario* e1, Proyectil* e2);
	bool ayudaColision_ambulancia_enemigo(Adversario* e1, Ambulancia* e2);
	bool ayudaColision_policia_enemigo(Adversario* e1, Policia* e2);
	bool ayudaColision_jugador_enemigo(Jugador* e1, Adversario* e2);
	void reset();
};

