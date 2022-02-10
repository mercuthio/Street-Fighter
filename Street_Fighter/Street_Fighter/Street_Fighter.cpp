#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personaje.h"
#include "Animacion.h"

using namespace sf;
using namespace std;

int ANCHO_PANTALLA = 1000;
int ALTO_PANTALLA = 600;

int spritesRyu[8][15] = { {4,9,16,23,25,27},{3,8,11,18,23} };

int main()
{
    RenderWindow window(VideoMode(ANCHO_PANTALLA, ALTO_PANTALLA), "Street Fighter");

    Image imagen;
    imagen.loadFromFile("Sprites/Personajes/Ryu.png");
    imagen.createMaskFromColor(Color::Cyan);
    Texture textura;
    textura.loadFromImage(imagen);
    Personaje personaje(&textura,20,0.05f,spritesRyu);

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
        personaje.dibujar(window);
        window.display();
    }

    return 0;
}