#include "pch.h"
#include "Personaje.h"

Personaje::Personaje() {}
Personaje::Personaje(int pini_f, int pfin_f, int pini_c, int pfin_c) {
	cantidad_proyectiles = 0;
}
Personaje::~Personaje(){}

void Personaje::set_pos_x(int nuevo) { pos_x = nuevo; }
void Personaje::set_pos_y(int nuevo) { pos_y = nuevo; }
void Personaje::set_dx(int nuevo) { dx = nuevo; }
void Personaje::set_dy(int nuevo) { dy = nuevo; }
void Personaje::cambiar_w(int nuevo) { w = nuevo; }
void Personaje::cambiar_h(int nuevo) { h = nuevo; }
void Personaje::cambiar_sf(int nuevo) { sf = nuevo; }
void Personaje::cambiar_sc(int nuevo) { sc = nuevo; }
void Personaje::Personaje::set_vida(int nuevo) { vida = nuevo; }
//void Personaje::set_direccion(int nuevo) { direccion = nuevo; }

int Personaje::return_pos_x() { return pos_x; }
int Personaje::return_pos_y() { return pos_y; }
int Personaje::return_dx() { return dx; }
int Personaje::return_dy() { return dy; }
int Personaje::retornar_w() { return w; }
int Personaje::retornar_h() { return h; }
int Personaje::retornar_sf() { return sf; }
int Personaje::retornar_sc() { return sc; }
int Personaje::retornar_cantidad_proyectiles() { return cantidad_proyectiles; }
int Personaje::Personaje::return_vida() { return vida; }
//int Personaje::retornar_direccion() { return direccion; }



void Personaje::correr(){

}

void Personaje::dibujar(Graphics^ g, Bitmap^ img) {

	Rectangle porcion_dibujo = Rectangle(w * sc, h * sf, w, h);
	g->DrawImage(img, pos_x, pos_y, porcion_dibujo, GraphicsUnit::Pixel);
}

