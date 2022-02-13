#ifndef INICIO_H
#define INICIO_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Inicio {

public:
	Inicio(Texture*, Font, float);
	~Inicio() = default;

	void draw(RenderWindow& window);
	void Actualizar(float);

private:

	float tiempoTotal;
	float tiempoCambio;

	Font font;
	Text text;
	RectangleShape fondo;

};

Inicio::Inicio(Texture* textura, Font font_, float tiempo) {

	font = font_;
	tiempoTotal = 0;
	tiempoCambio = tiempo;

	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setString("Presiona cualquier boton para continuar");
	text.setCharacterSize(20);

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Inicio::Actualizar(float tiempo) {

	tiempoTotal += tiempo;
	if (tiempoTotal >= tiempoCambio) {
		
		tiempoTotal -= tiempoCambio;
		
		if (text.getFillColor() == Color::Red) {
			text.setFillColor(Color::Black);
		}
		else {
			text.setFillColor(Color::Red);
		}

	}

}

void Inicio::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(fondo);
	
	text.setPosition(Vector2f(window.getSize().x / 8, (window.getSize().y/2) + window.getSize().y / 4));
	window.draw(text);

}


#endif