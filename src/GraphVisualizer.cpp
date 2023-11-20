#include "interfaces.h"

GraphVisualizer::GraphVisualizer(){};

GraphVisualizer::GraphVisualizer(Graph g){
    this->g = g;
};

GraphVisualizer::~GraphVisualizer(){};

void GraphVisualizer::showGraph(){

    //creating window
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Graph");
    //variable for handling events
    sf::Event event;

    //creating objects to display
    //vertices -> circles
    int nOfVertices = g.getNoVertices();
    sf::CircleShape** vertices = (sf::CircleShape**)calloc(nOfVertices, sizeof(sf::CircleShape*));
    for(int i=0;i<nOfVertices;i++){
        vertices[i] = new sf::CircleShape(20.0f, 100);
        vertices[i]->setFillColor(sf::Color::Black);
        vertices[i]->setPosition(100, 100);
    }

    //main loop
    while(window.isOpen()){
        //background color
        window.clear(sf::Color::White);

        //display vertices
        for(int i=0;i<nOfVertices;i++){
            window.draw(*vertices[i]);
        }

        //display window
        window.display();

        //event handling
        while (window.pollEvent(event)) {
            //closing window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

};