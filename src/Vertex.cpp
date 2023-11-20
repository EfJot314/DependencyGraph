#include "interfaces.h"

Vertex::Vertex(){};

Vertex::Vertex(int id){
    this->id = id;
    this->x = 0;
    this->y = 0;
    r = 30.0f;
    circle = new sf::CircleShape(r, 100);
    circle->setFillColor(sf::Color::Black);
    circle->setPosition(x-r, y-r);
}

Vertex::Vertex(int x, int y, int id){
    this->id = id;
    this->x = x;
    this->y = y;
    r = 30.0f;
    circle = new sf::CircleShape(r, 100);
    circle->setFillColor(sf::Color::Black);
    circle->setPosition(x-r, y-r);
}

Vertex::~Vertex(){};

void Vertex::addToWindow(sf::RenderWindow* window){
    window->draw(*circle);
};