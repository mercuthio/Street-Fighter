#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "Animacion.h"

using namespace sf;
using namespace std;

class Personaje {
public:

	Personaje(Texture*, float, float, int[15][15]);
	~Personaje() = default;

	float pos_x;

	void actualizar(float);
	void dibujar(RenderWindow&);

private:

	int vida;
	int fila;
	int sprite;
	int numSprites[15][15];

	RectangleShape cuerpo;
	Animacion animacion;

};

Personaje::Personaje(Texture* textura, float pos_x_, float tiempoCambio_, int numSprites_[15][15]) : animacion(tiempoCambio_){

	vida = 200;	
	fila = 0;
	sprite = 0;
	pos_x = pos_x_;

	for (int i = 0; i < 15 && numSprites[i][0] != '\0'; i++) {
		for (int j = 0; j < 15 && numSprites_[i][j] != '\0'; j++){
			numSprites[i][j] = numSprites_[i][j];
		}
	}

	cuerpo.setSize(Vector2f(100.0f, 150.0f));
	cuerpo.setPosition(pos_x, 300);
	cuerpo.setTexture(textura);

}

void Personaje::actualizar(float tiempo) {

	if (Keyboard::isKeyPressed(Keyboard::A) && (pos_x - 750 * tiempo) > 0) {

		pos_x -= 750 * tiempo;
		fila = 0;
		sprite = 1;

	} else if (Keyboard::isKeyPressed(Keyboard::D) && (pos_x + 750 * tiempo) < 825){

		pos_x += 750 * tiempo;
		fila = 0;
		sprite = 1;

	} else {

		fila = 0;
		sprite = 0;
	}
	
	if (pos_x == 0.0f) {

		fila = 0;
		sprite = 0;

	}

	animacion.actualizar(fila,numSprites[fila][sprite-1],numSprites[fila][sprite], tiempo);
	cuerpo.setTextureRect(animacion.uvRect);
	cuerpo.setPosition(pos_x, 300);
	cuerpo.setScale(1.75, 1.75);
}

void Personaje::dibujar(RenderWindow& window) {

	window.draw(cuerpo);

}

#endif