#pragma once
class Personaje
{
private:
	int vida, pos_x, pos_y, dx, dy, arma, velocidad;
protected:
	Personaje();
	~Personaje();

	void set_pos_x(int nuevo);
	void set_pos_y(int nuevo);
	void set_dx(int nuevo);
	void set_dy(int nuevo);
	void set_vida(int nuevo);

	int return_pos_x();
	int return_pos_y();
	int return_dx();
	int return_dy();
	int return_vida();

	void caminar();
	void correr();
	void disparar();
};

