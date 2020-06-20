#include "pch.h"
#include "Juego.h"
#include <iostream>

Juego::Juego(){
	Init();
}
Juego::~Juego(){}

Adversario* Juego::crear_enemigo(int tipo) {

	Adversario* nuevo_adversario = new Adversario(0, 0, 0, 0);
	if (tipo == 0) {//Enemigo de tipo 1, x entre 0 y 450, y entre 0 y 400 
		nuevo_adversario->set_pos_x(rand() % 451);
		nuevo_adversario->set_pos_y(rand() % 401);
		nuevo_adversario->set_vida(5);
		nuevo_adversario->set_dx(0);
		nuevo_adversario->set_dy(0);
		switch (rand() % 4) //Movimiento aleatorio
		{
		case 0: {nuevo_adversario->set_dx(1);break;}
		case 1: {nuevo_adversario->set_dx(-1);break;}
		case 2: {nuevo_adversario->set_dy(1);break;}
		case 3: {nuevo_adversario->set_dy(-1);break;}
		default: break;}
	}
	else {//Enemigo de tipo 2
		nuevo_adversario->set_pos_x(rand() % 451);
		nuevo_adversario->set_pos_y(rand() % 401);
		nuevo_adversario->set_vida(5);
		nuevo_adversario->set_dx(0);
		nuevo_adversario->set_dy(0);
		switch (rand() % 4) //Movimiento aleatorio
		{
		case 0: {nuevo_adversario->set_dx(1); break; }
		case 1: {nuevo_adversario->set_dx(-1); break; }
		case 2: {nuevo_adversario->set_dy(1); break; }
		case 3: {nuevo_adversario->set_dy(-1); break; }
		default: break;
		}
	}


	return nuevo_adversario;
}

void Juego::Init() {
	jugador_user = new Jugador(0, 0, 0, 0);
	jugador_user->cambiar_sf(0);
	jugador_user->cambiar_sc(0);
	ambulancia = new Ambulancia(0, 1, 0, 1);
	ambulancia->cambiar_sc(0);
	ambulancia->cambiar_sf(0);
	adversario_tipo1 = new Adversario(0, 0, 0, 0);
	adversario_tipo1->cambiar_sc(0);
	adversario_tipo1->cambiar_sf(1);



	//int cantidad_enemigos = rand() % 6 + 5;
	//arreglo_adversarios = new Adversario * [cantidad_enemigos];
	//int intercalador = 1;
	//for (int i = 0; i < cantidad_enemigos; i++) {
	//	arreglo_adversarios[i] = crear_enemigo((i%2));
	//}
}
void Juego::mostrar_inicio(){}
void Juego::mostrar_mapa_principal(){}
void Juego::mostrar_mapa_secundario(){}
void Juego::dinamica_juego(Graphics^ g, Bitmap^ img, Bitmap^ img_proyectiles, Bitmap^ img_ambulancia, Bitmap^ img_adversario_tipo1){
	jugador_user->caminar(g, img, img_proyectiles);
	ambulancia->mover(g, img_ambulancia);
	adversario_tipo1->mover(g, img_adversario_tipo1);
}

void Juego::cambiar_direccion(int direccion) {
	jugador_user->direccion = direccion;
}

void Juego::disparar() {
	jugador_user->disparar();
}