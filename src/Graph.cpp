#include "interfaces.h"

Graph::Graph(){};

Graph::Graph(int nOfVertices){
    this->nOfVertices = nOfVertices;
    this->nOfEdges = 0;

    matrix = (int**)calloc(nOfVertices, sizeof(int*));
    names = (std::string*)calloc(nOfVertices, sizeof(std::string));
    for(int i=0;i<nOfVertices;i++){
        matrix[i] = (int*)calloc(nOfVertices, sizeof(int));
    }

};

Graph::~Graph(){};

int Graph::getNoVertices(){
    return nOfVertices;
};

int Graph::getNoEdges(){
    return nOfEdges;
};

void Graph::addEdge(int v1, int v2){
    //validation
    if(v1 < 0 || v2 < 0 || v1 >= nOfVertices || v2 >= nOfVertices){
        return;
    }

    //adding edge
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
    nOfEdges++;
};

void Graph::removeEdge(int v1, int v2){
    //validation
    if(v1 < 0 || v2 < 0 || v1 >= nOfVertices || v2 >= nOfVertices){
        return;
    }

    //removing edge
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
    nOfEdges--;
};

bool Graph::edgeExist(int v1, int v2){
    //validation - when sth is wrong, then false
    if(v1 < 0 || v2 < 0 || v1 >= nOfVertices || v2 >= nOfVertices){
        return false;
    }
    //returnig result
    return matrix[v1][v2] == 1;
};

void Graph::setVertexName(int id, std::string name){
    //validation
    if(id < 0 || id >= nOfVertices)
        return;
    //if everything is ok, then set name
    names[id] = name;
}

std::string Graph::getName(int id){
    if(id < 0 || id >= nOfVertices || names[id].empty())
        return std::to_string(id+1);
    //returning result
    return names[id];
}



