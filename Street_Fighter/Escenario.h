#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Escenario {
public:

	Escenario(Texture*);
	~Escenario() = default;

	void actualizar(float);
	void dibujar(RenderWindow&);

private:

	IntRect uvRect;
	RectangleShape cuerpo;

};

Escenario::Escenario(Texture* textura){

	uvRect.width = 464;
	uvRect.height = 200;
	cuerpo.setSize(Vector2f(464, 300));
	cuerpo.setPosition(0, 0);
	cuerpo.setTexture(textura);

}

void Escenario::actualizar(float tiempo) {
	cuerpo.setPosition(0, 0);
	cuerpo.setScale(1, 1);
}

void Escenario::dibujar(RenderWindow& window) {

	window.draw(cuerpo);

}

#endif