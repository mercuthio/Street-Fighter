#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Escenario {
public:
	Escenario(String, int, Sprite, map<String, int>);
	~Escenario() = default;
	void modVida(int);
	bool estaVivo();
	void mover(int);
private:
	int vida;
	int x;
	Sprite sprite;
	String nombre;
	map <String, int> numSprites;
};

Escenario::Escenario(String nombre_, int x_, Sprite sprite_, map<String, int> numSprites_) {
	vida = 200;
	nombre = nombre_;
	x = x_;
	sprite = sprite_;
	numSprites = numSprites_;
}

#endif