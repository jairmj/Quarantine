#pragma once
class Vehiculo
{
private:
	int pos_x, pos_y, dx, dy, velocidad;
protected:
	Vehiculo();
	~Vehiculo();

	void set_pos_x(int nuevo);
	void set_pos_y(int nuevo);
	void set_dx(int nuevo);
	void set_dy(int nuevo);
	void set_velocidad(int nuevo);

	int return_pos_x();
	int return_pos_y();
	int return_dx();
	int return_dy();
	int return_velocidad();

	void mover();
	void capturar();

};

