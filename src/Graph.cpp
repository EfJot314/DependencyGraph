#include "interfaces.h"

Graph::Graph(){};

Graph::Graph(int nOfVertices){
    this->nOfVertices = nOfVertices;

    matrix = (int**)calloc(nOfVertices, sizeof(int*));
    for(int i=0;i<nOfVertices;i++){
        matrix[i] = (int*)calloc(nOfVertices, sizeof(int));
    }
};

Graph::~Graph(){};

int Graph::getNoVertices(){
    return nOfVertices;
};

void Graph::addEdge(int v1, int v2){
    //validation
    if(v1 < 0 || v2 < 0 || v1 >= nOfVertices || v2 >= nOfVertices){
        return;
    }

    //adding edge
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
};

void Graph::removeEdge(int v1, int v2){
    //validation
    if(v1 < 0 || v2 < 0 || v1 >= nOfVertices || v2 >= nOfVertices){
        return;
    }

    //removing edge
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
};

bool Graph::edgeExist(int v1, int v2){
    //validation - when sth is wrong, then false
    if(v1 < 0 || v2 < 0 || v1 >= nOfVertices || v2 >= nOfVertices){
        return false;
    }

    //returnig result
    return matrix[v1][v2] == 1;
};



