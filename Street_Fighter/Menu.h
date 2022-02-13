#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int NUMERO_OPCIONES = 3;

class Menu {

public:
	Menu(Texture*, Texture*, Font, float);
	~Menu() = default;

	void draw(RenderWindow& window);
	void Actualizar(float);
	int OpcionElegida();
	void moverCursor(bool);

private:

	float tiempoTotal;
	float tiempoCambio;
	int opcionElegida;

	Font font;
	Text text[NUMERO_OPCIONES + 1];
	RectangleShape fondo;
	RectangleShape cursor;

};

Menu::Menu(Texture* textura, Texture* cursor_, Font font_, float tiempo) {

	font = font_;
	tiempoTotal = 0;
	tiempoCambio = tiempo;
	opcionElegida = 0;

	text[0].setFont(font);
	text[0].setFillColor(Color::Red);
	text[0].setString("NUEVO DUELO");
	text[0].setCharacterSize(20);

	text[1].setFont(font);
	text[1].setFillColor(Color::Red);
	text[1].setString("OPCIONES");
	text[1].setCharacterSize(20);

	text[2].setFont(font);
	text[2].setFillColor(Color::Red);
	text[2].setString("SALIR");
	text[2].setCharacterSize(20);

	cursor.setTexture(cursor_);
	cursor.setSize(Vector2f(30.0f, 30.0f));

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Menu::Actualizar(float tiempo) {

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
		moverCursor(true);

	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
		moverCursor(false);

	}

	tiempoTotal += tiempo;
	if (tiempoTotal >= tiempoCambio) {

		tiempoTotal -= tiempoCambio;

		if (text[opcionElegida].getFillColor() == Color::Red) {
			text[opcionElegida].setFillColor(Color::Black);
		}
		else {
			text[opcionElegida].setFillColor(Color::Red);
		}

	}

}

int Menu::OpcionElegida() {

	return opcionElegida;

}

void Menu::draw(RenderWindow& window) {
	
	fondo.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(fondo);

	text[0].setPosition(Vector2f(window.getSize().x / 3, ((window.getSize().y / 2) + window.getSize().y / 4) + 25));
	window.draw(text[0]);

	text[1].setPosition(Vector2f(window.getSize().x / 3, ((window.getSize().y / 2) + window.getSize().y / 4) + 50));
	window.draw(text[1]);

	text[2].setPosition(Vector2f(window.getSize().x / 3, ((window.getSize().y / 2) + window.getSize().y / 4) + 75));
	window.draw(text[2]);
	
	switch (opcionElegida) {
	case 2: //Salir
		cursor.setPosition(Vector2f(window.getSize().x / 3 - 35, ((window.getSize().y / 2) + window.getSize().y / 4) + 75));
		break;
	case 1: //Opciones
		cursor.setPosition(Vector2f(window.getSize().x / 3 - 35, ((window.getSize().y / 2) + window.getSize().y / 4) + 50));
		break;
	default: //Iniciar duelo
		cursor.setPosition(Vector2f(window.getSize().x / 3 - 35, ((window.getSize().y / 2) + window.getSize().y / 4) + 25));
		break;
	}

	window.draw(cursor);

}

void Menu::moverCursor(bool arriba) {

	for (int i = 0; i < NUMERO_OPCIONES; i++) {
		text[i].setFillColor(Color::Red);
	}

	if (arriba) {
		opcionElegida--;
		if (opcionElegida < 0) {
			opcionElegida = NUMERO_OPCIONES;
		}
	}
	else if (!arriba) {
		opcionElegida++;
		if (opcionElegida > NUMERO_OPCIONES) {
			opcionElegida = 0;
		}
	}

}

#endif