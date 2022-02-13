#include "SFML/Graphics.hpp"
#include <iostream>
#include "Personaje.h"
#include "Escenario.h"
#include "Animacion.h"
#include "Inicio.h"
#include "Menu.h"

using namespace sf;
using namespace std;

int ANCHO_PANTALLA = 800;
int ALTO_PANTALLA = 600;

int RATIO_ANCHO = 4;
int RATIO_ALTO = 3;

int spritesRyu[8][15] = { {4,9,16,24,26,27},{3,8,11,18,23},{3,8,11,16,21},{3,7,12,15,18,23}, {3,5,8,10,13,20,22,26,29}, {5,11,16,23}, {4,8,9,17,20,25}, {3,7,8} };

int main()
{
    RenderWindow window(VideoMode(ANCHO_PANTALLA, ALTO_PANTALLA), "Street Fighter");

    Font letra;
    letra.loadFromFile("Sprites/Letra/Fuente.ttf");
    Texture textura;

    textura.loadFromFile("Sprites/Menus/inicio.png");
    Inicio inicio(&textura, letra, 0.1f);

    textura.loadFromFile("Sprites/Menus/Menu.png");
    Texture t_cursor;
    t_cursor.loadFromFile("Sprites/Menus/Cursor.png");
    Menu menu(&textura,&t_cursor, letra, 0.1f);

    Texture texturaRyu;
    texturaRyu.loadFromFile("Sprites/Personajes/Ryu.png");
    Personaje personaje(&texturaRyu, 20, 300, 0.035f, spritesRyu);

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

        //personaje.actualizar(0.005f);
        //inicio.Actualizar(0.005f);
        menu.Actualizar(0.005f);

        window.clear();
        //personaje.dibujar(window);
        //inicio.draw(window);
        menu.draw(window);
        window.display();
    }

    return 0;
}