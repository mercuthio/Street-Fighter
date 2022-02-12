#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Animacion {
public:

	Animacion(float);
	~Animacion() = default;
	bool actualizar(int, int, int, float, float&, float&);

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

}

bool Animacion::actualizar(int fila_, int accion_, int spriteFinal, float tiempo, float &pos_y, float& pos_x) {

	bool enSuelo = (accion != 9) && (accion != 16);

	tiempoTotal += tiempo;

	if ((fila != fila_) || (accion != accion_)) {
		cout << "Nueva entrada: " << accion_ << endl;
		fila = fila_;
		accion = accion_;
		imagenActual = accion;
	}

	if ((accion == 9) && (imagenActual < ((spriteFinal - accion_) / 2) + accion_)) { //Esta subiendo (salto simple)
		if (pos_y - (spriteFinal - accion_) > 0)
			pos_y -= (spriteFinal - accion_);
	}
	else if ((accion == 9) && (imagenActual > ((spriteFinal - accion_) / 2) + accion_)) { //Esta cayendo
		if (pos_y + (spriteFinal - accion_) < 300)
			pos_y += (spriteFinal - accion_);
	}

	if ((accion == 16) && (imagenActual <= ((spriteFinal - accion_) / 2) + accion_)) { //Esta subiendo (salto hacia delante)
		if (pos_y - (spriteFinal - accion_) > 0) {
			pos_y -= (spriteFinal - accion_);
		}
		if (pos_x + (spriteFinal - accion_) < 825)
			pos_x += (spriteFinal - accion_);
	}
	else if ((accion == 16) && (imagenActual > ((spriteFinal - accion_) / 2) + accion_)) { //Esta cayendo
		if (pos_y + (spriteFinal - accion_) < 300)
			pos_y += (spriteFinal - accion_);
		if (pos_x + (spriteFinal - accion_) < 825)
			pos_x += (spriteFinal - accion_);
	}

	if (tiempoTotal >= tiempoCambio) {
		tiempoTotal -= tiempoCambio;

		if ((accion != 23 && accion != 25)) { //Agachado no debe reiniciar animacion			

			imagenActual++;

			if (imagenActual >= spriteFinal) {

				if ((accion == 9) || (accion == 16)) { //Termina animacion de salto
					pos_y = 300;
					enSuelo = true;
				}

				imagenActual = accion;
			}
		}
	}
	
	switch (accion) {
	/*case 9: //Salto

		break;
	case 16: //Salto hacia delante

		break;*/
	case 23: //Agacharse
		uvRect.left = imagenActual * uvRect.width+30;
		uvRect.top = fila * uvRect.height + 15;
		break;
	case 25: //Bloquear agachado
		uvRect.left = imagenActual * uvRect.width+32;
		uvRect.top = fila * uvRect.height + 15;
		break;
	default:
		uvRect.width = 49;
		uvRect.height = 90;
		uvRect.left = imagenActual * uvRect.width + 1;
		uvRect.top = fila * uvRect.height + 15;
		break;
	}

	return enSuelo;

}

#endif
