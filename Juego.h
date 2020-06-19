#pragma once
class Juego
{
private:
	int pantalla_inicio, mapa_principal;
	int puntos;
protected:
	Juego();
	~Juego();
	void mostrar_inicio();
	void mostrar_mapa_principal();
	void mostrar_mapa_secundario();
	void dinamica_juego();
};

