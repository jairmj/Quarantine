#pragma once
using namespace System::Drawing;
class Personaje
{
protected:
	
	int vida, pos_x, pos_y, dx, dy, arma, velocidad;
	int sf, sc, w, h, ini_f, fin_f, inic_c, fin_c; //Fila y columna del personaje a mostrar

public:
	Personaje();
	Personaje(int pini_f, int pfin_f, int pini_c, int pfin_c);
	~Personaje();

	void set_pos_x(int nuevo);
	void set_pos_y(int nuevo);
	void set_dx(int nuevo);
	void set_dy(int nuevo);
	void cambiar_w(int nuevo);
	void cambiar_h(int nuevo);
	void cambiar_sf(int nuevo);
	void cambiar_sc(int nuevo);
	void set_vida(int nuevo);
	void set_direccion(int nuevo);


	int return_pos_x();
	int return_pos_y();
	int return_dx();
	int return_dy();
	int retornar_w();
	int retornar_h();
	int retornar_sf();
	int retornar_sc();
	int return_vida();
	int retornar_direccion();


	void caminar(Graphics^ g, Bitmap^ img);
	void correr();
	void disparar();
	void dibujar(Graphics^ g, Bitmap^ img);
};

