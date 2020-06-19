#include "pch.h"
#include "Vehiculo.h"

Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}

void Vehiculo::set_pos_x(int nuevo) { pos_x = nuevo; }
void Vehiculo::set_pos_y(int nuevo) { pos_y = nuevo; }
void Vehiculo::set_dx(int nuevo) { dx = nuevo; }
void Vehiculo::set_dy(int nuevo) { dy = nuevo; }
void Vehiculo::set_velocidad(int nuevo) { velocidad = nuevo; }

int Vehiculo::return_pos_x() { return pos_x; }
int Vehiculo::return_pos_y() { return pos_y; }
int Vehiculo::return_dx() { return dx; }
int Vehiculo::return_dy() { return dy; }
int Vehiculo::return_velocidad() { return velocidad; }

void Vehiculo::mover() {

}

void Vehiculo::capturar() {

}