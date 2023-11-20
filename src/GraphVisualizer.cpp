#include "interfaces.h"

GraphVisualizer::GraphVisualizer(){};

GraphVisualizer::GraphVisualizer(Graph g){
    this->g = g;
};

GraphVisualizer::~GraphVisualizer(){};

void GraphVisualizer::showGraph(){

    //creating window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Graph");
    //variable for handling events
    sf::Event event;

    //creating objects to display
    //vertices -> circles
    int nOfVertices = g.getNoVertices();
    Vertex** vertices = (Vertex**)calloc(nOfVertices, sizeof(Vertex*));
    for(int i=0;i<nOfVertices;i++){
        vertices[i] = new Vertex(100, 100, i+1);
    }

    //main loop
    while(window->isOpen()){
        //background color
        window->clear(sf::Color::White);

        //display vertices
        for(int i=0;i<nOfVertices;i++){
            vertices[i]->addToWindow(window);
        }

        //display window
        window->display();

        //event handling
        while (window->pollEvent(event)) {
            //closing window
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }
    }

};