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

	bool terminada = (accion != 9 && accion != 16 && fila == 0);

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

		if ((accion != 24 && accion != 26)) { //Agachado no debe reiniciar animacion			

			imagenActual++;

			if (imagenActual >= spriteFinal) {

				if ((accion == 9) || (accion == 16) || (fila != 0)) { //Termina animacion no parable
					pos_y = 300;
					terminada = true;
				}

				imagenActual = accion;
			}
		}
	}

	uvRect.width = 49;
	uvRect.height = 90;
	cout << accion << endl;
	switch (fila) {
	case 0: //Primera fila
		switch (accion) {
			case 9: //Salto
				uvRect.width = 49;
				uvRect.height = 100;
				uvRect.left = imagenActual * uvRect.width + 1;
				uvRect.top = fila * uvRect.height + 5;
				break;
			case 16: //Salto hacia delante
				cout << imagenActual << endl;
				if (imagenActual == 18) {
					uvRect.width = 98;
					uvRect.height = 90;
					uvRect.left = imagenActual * 49 + 1;
					uvRect.top = fila * uvRect.height + 15;
				} else if (imagenActual == 20) {
					uvRect.width = 98;
					uvRect.height = 90;
					uvRect.left = imagenActual * 49 + 43 + 1;
					uvRect.top = fila * uvRect.height + 15;
				} else {
					uvRect.width = 49;
					uvRect.height = 100;
					uvRect.top = fila * uvRect.height + 5;
					if (imagenActual < 18) {
						uvRect.left = imagenActual * uvRect.width + 1;
					} else if (imagenActual == 19) {
						uvRect.left = imagenActual * uvRect.width + 43 + 1;
					} else {
						uvRect.left = imagenActual * 49 + 86 + 1;
					}
				}
				break;
		case 24: //Agacharse
			uvRect.left = imagenActual * uvRect.width + 86 + 1;
			uvRect.top = fila * uvRect.height + 15;
			break;
		case 26: //Bloquear agachado
			uvRect.left = imagenActual * uvRect.width + 86 + 1;
			uvRect.top = fila * uvRect.height + 15;
			break;
		default:
			uvRect.left = imagenActual * uvRect.width + 1;
			uvRect.top = fila * uvRect.height + 15;
			break;
		}
		break;

	case 1: //Segunda fila
		switch (accion) {
		case 8: //Puñetazo arriba
			uvRect.left = imagenActual * uvRect.width + 19;
			uvRect.top = fila * uvRect.height + 41;
			break;
		case 3: //Puñetazo largo
			uvRect.left = imagenActual * uvRect.width + 21; 
			uvRect.top = fila * uvRect.height + 41;
			break;
		default: //Puñetazo corto
			uvRect.left = imagenActual * uvRect.width - 2;
			uvRect.top = fila * uvRect.height + 41;
			break;
		}
		break;
	}
	return terminada;

}

#endif
