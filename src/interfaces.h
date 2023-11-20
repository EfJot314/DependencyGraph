#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <math.h>


class Graph{
    private:
        int** matrix;
        int nOfVertices;
        int nOfEdges;
    public:
        Graph();
        Graph(int nOfVertices);
        ~Graph();
        int getNoVertices();
        int getNoEdges();
        void addEdge(int v1, int v2);
        void removeEdge(int v1, int v2);
        bool edgeExist(int v1, int v2);
};

class Vertex{
    private:
        int x;
        int y;
        int id;
        float r;
        sf::CircleShape* circle;
        sf::Font font;
        sf::Text* text;
    public:
        Vertex();
        Vertex(int id);
        Vertex(int x, int y, int id);
        ~Vertex();
        void addToWindow(sf::RenderWindow* window);
        void setPosition(int x, int y);
        int getId();
        int getPositionX();
        int getPositionY();
        bool isOverVertex(int xi, int yi);
};

class Edge{
    private:
        Vertex* v1;
        Vertex* v2;
        sf::VertexArray* line;
    public:
        Edge();
        Edge(Vertex* v1, Vertex* v2);
        ~Edge();
        void addToWindow(sf::RenderWindow* window);
        void updatePosition();
};

class GraphVisualizer{
    private:
        Graph g;
    public:
        GraphVisualizer();
        GraphVisualizer(Graph g);
        ~GraphVisualizer();
        void showGraph();
};


class InputParser{
    private:
        int n;
    public:
        InputParser();
        InputParser(int n);
        ~InputParser();
        void parse(std::string line);

};



