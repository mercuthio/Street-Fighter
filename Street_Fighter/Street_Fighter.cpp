#include "SFML/Graphics.hpp"
#include <iostream>
#include "Personaje.h"
#include "Escenario.h"
#include "Animacion.h"

using namespace sf;
using namespace std;

int ANCHO_PANTALLA = 1000;
int ALTO_PANTALLA = 600;

int spritesRyu[8][15] = { {4,9,16,24,26,27},{3,8,11,18,23} };

int main()
{
    RenderWindow window(VideoMode(ANCHO_PANTALLA, ALTO_PANTALLA), "Street Fighter");

    Texture texturaRyu;
    texturaRyu.loadFromFile("Sprites/Personajes/Ryu.png");
    Personaje personaje(&texturaRyu,20,300,0.035f,spritesRyu);

    Texture texturaEsc1;
    texturaEsc1.loadFromFile("Sprites/Escenarios/Sagat.png");
    Escenario escenario(&texturaEsc1);

    Clock reloj;
    Event event;

    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();
        
        }

        personaje.actualizar(0.005f);

        window.clear();
        //escenario.dibujar(window);
        personaje.dibujar(window);
        window.display();
    }

    return 0;
}