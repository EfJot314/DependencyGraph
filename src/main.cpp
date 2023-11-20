#include "interfaces.h"


int main()
{
    //for random numbers
    srand((unsigned) time(NULL));

    //create example graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);


    //graph visualization
    GraphVisualizer gv(g);
    gv.showGraph();

    return 0;
}
