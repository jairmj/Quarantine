#include "pch.h"
#include "Personaje.h"

Personaje::Personaje() {}
Personaje::~Personaje(){}

void Personaje::set_pos_x(int nuevo) { pos_x = nuevo; }
void Personaje::set_pos_y(int nuevo) { pos_y = nuevo; }
void Personaje::set_dx(int nuevo) { dx = nuevo; }
void Personaje::set_dy(int nuevo) { dy = nuevo; }
void Personaje::set_vida(int nuevo) { vida = nuevo; }

int Personaje::return_pos_x() { return pos_x; }
int Personaje::return_pos_y() { return pos_y; }
int Personaje::return_dx() { return dx; }
int Personaje::return_dy() { return dy; }
int Personaje::return_vida() { return vida; }

void Personaje::caminar() {

}
void Personaje::correr(){

}
void Personaje::disparar(){

}