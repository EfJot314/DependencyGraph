#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <math.h>


class Graph{
    private:
        int** matrix;
        int nOfVertices;
    public:
        Graph();
        Graph(int nOfVertices);
        ~Graph();
        int getNoVertices();
        void addEdge(int v1, int v2);
        void removeEdge(int v1, int v2);
        bool edgeExist(int v1, int v2);
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

