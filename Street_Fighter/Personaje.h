#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "Animacion.h"

using namespace sf;
using namespace std;

class Personaje {
public:

	Personaje(Texture*, float, float, float, int[15][15]);
	~Personaje() = default;

	float pos_x;
	float pos_y;

	void actualizar(float);
	void dibujar(RenderWindow&);

private:

	bool terminada;
	int vida;
	int fila;
	int sprite;
	int numSprites[15][15];

	RectangleShape cuerpo;
	Animacion animacion;

};

Personaje::Personaje(Texture* textura, float pos_x_, float pos_y_, float tiempoCambio_, int numSprites_[15][15]) : animacion(tiempoCambio_) {

	vida = 200;
	fila = 0;
	sprite = 0;
	pos_x = pos_x_;
	pos_y = pos_y_;
	terminada = true;

	for (int i = 0; i < 15 && numSprites[i][0] != '\0'; i++) {
		for (int j = 0; j < 15 && numSprites_[i][j] != '\0'; j++) {
			numSprites[i][j] = numSprites_[i][j];
		}
	}

	cuerpo.setSize(Vector2f(100.0f, 150.0f));
	cuerpo.setPosition(pos_x, pos_y);
	cuerpo.setTexture(textura);

	//cuerpo.setFillColor(Color::Green); //Para ver hitboxes descomentar y comentar anterior

}

void Personaje::actualizar(float tiempo) {

	cuerpo.setSize(Vector2f(100.0f, 150.0f));

	if (terminada) {

		if (Keyboard::isKeyPressed(Keyboard::D) && (pos_x + 750 * tiempo) < 825) { //Mover derecha

			fila = 0;

			if (Keyboard::isKeyPressed(Keyboard::W)) { //Salto hacia delante
				pos_x += 750 * tiempo;
				sprite = 3;

			}else if (Keyboard::isKeyPressed(Keyboard::E)) {
				fila = 1;
				sprite = 1;

			}else {
				pos_x += 750 * tiempo;
				sprite = 1;

			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::W)) { //Salto
			
			fila = 0;
			sprite = 2;

			if (Keyboard::isKeyPressed(Keyboard::E)) { //Puñetazo hacia arriba
				fila = 1;
				sprite = 2;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) { //Agacharse

			fila = 0;

			if (Keyboard::isKeyPressed(Keyboard::A)) { //Bloquear agachado
				sprite = 5;

			}
			else {
				sprite = 4;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::A) && (pos_x - 750 * tiempo) > 0) { //Mover izquierda

			pos_x -= 750 * tiempo;
			fila = 0;
			sprite = 1;

		}else if (Keyboard::isKeyPressed(Keyboard::E)) { //Puñetazo corto

			fila = 1;
			sprite = 0;

		}
		else {

			fila = 0;
			sprite = 0;
		}

		if (pos_x == 0.0f) {

			fila = 0;
			sprite = 0;

		}
	}

	if (sprite > 0) {
		terminada = animacion.actualizar(fila, numSprites[fila][sprite - 1], numSprites[fila][sprite], tiempo, pos_y, pos_x);
	}else{
		terminada = animacion.actualizar(fila, 0, numSprites[fila][sprite], tiempo, pos_y, pos_x);
	}

	cuerpo.setTextureRect(animacion.uvRect);
	cuerpo.setPosition(pos_x, pos_y);
	cuerpo.setScale(1.75, 1.75);
}

void Personaje::dibujar(RenderWindow& window) {

	window.draw(cuerpo);

}

#endif