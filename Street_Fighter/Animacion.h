#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Animacion {
public:

	Animacion(float);
	~Animacion() = default;
	void actualizar(int, int, int, float);
	
	IntRect uvRect;

private:

	int imagenActual;
	int fila;
	int accion;
	float tiempoTotal;
	float tiempoCambio;

};

Animacion::Animacion(float tiempoCambio_) {
	
	imagenActual = 0;
	fila = 0;
	accion = 0;
	tiempoCambio = tiempoCambio_;
	tiempoTotal = 0.0f;

	uvRect.width = 43;
	uvRect.height = 90;

}

void Animacion::actualizar(int fila_, int accion_, int spriteFinal, float tiempo) {

	tiempoTotal += tiempo;
	
	if ((fila != fila_) || (accion != accion_)) {
		cout << "Nueva entrada: " << accion_ << endl;
		fila = fila_;
		accion = accion_;
		imagenActual = accion;
	}

	if (tiempoTotal >= tiempoCambio){
		
		tiempoTotal -= tiempoCambio;
		imagenActual++;

		if (imagenActual >= spriteFinal) {
			imagenActual = accion;
		}

	}
	cout << imagenActual << endl;
	uvRect.left = imagenActual * uvRect.width;
	uvRect.top = fila * uvRect.height + 15;

}

#endif
