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

    //loading font
    sf::Font font;
    font.loadFromFile("SFML/myFont.ttf");

    //creating objects to display
    //vertices
    int nOfVertices = g.getNoVertices();
    Vertex** vertices = (Vertex**)calloc(nOfVertices, sizeof(Vertex*));
    for(int i=0;i<nOfVertices;i++){
        vertices[i] = new Vertex(100, 100, i+1);
    }
    //edges
    int nOfEdges = g.getNoEdges();
    Edge** edges = (Edge**)calloc(nOfEdges, sizeof(Edge*));
    int counter = 0;
    for(int i=0;i<nOfVertices;i++){
        for(int j=i;j<nOfVertices;j++){
            if(g.edgeExist(i, j)){
                edges[counter] = new Edge(vertices[i], vertices[j]);
                counter++;
            }
        }
    }


    //creating variable which is storing id of vertex to move
    int movingVertex = -1;

    //mouse position
    int mouseX = sf::Mouse::getPosition(*window).x;
    int mouseY = sf::Mouse::getPosition(*window).y;
    
    //main loop
    while(window->isOpen()){
        //get mouse position
        mouseX = sf::Mouse::getPosition(*window).x;
        mouseY = sf::Mouse::getPosition(*window).y;

        //background color
        window->clear(sf::Color::White);

        //update and display edges
        for(int i=0;i<nOfEdges;i++){
            edges[i]->updatePosition();
            edges[i]->addToWindow(window);
        }

        //display vertices
        for(int i=0;i<nOfVertices;i++){
            vertices[i]->addToWindow(window);
        }

        

        //display window
        window->display();
        

        //event handling
        while(window->pollEvent(event)) {
            //closing window
            if(event.type == sf::Event::Closed) {
                window->close();
            }
            //mouse pressed
            else if(event.type == sf::Event::MouseButtonPressed){
                //left button
                if(event.mouseButton.button == sf::Mouse::Left){
                    //get first vertex which is under mouse
                    for(int i=nOfVertices-1;i>=0;i--){
                        if(vertices[i]->isOverVertex(mouseX, mouseY)){
                            movingVertex = i;
                            break;
                        }
                    }
                }
            }
            //mouse released
            else if(event.type == sf::Event::MouseButtonReleased){
                //stop moving vertex
                movingVertex = -1;
            }
        }

        //if mouse left button in pressed
        if(movingVertex >= 0){
            vertices[movingVertex]->setPosition(mouseX, mouseY);
        }
    }

};