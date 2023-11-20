#include "interfaces.h"


int main()
{
    //for random numbers
    srand((unsigned) time(NULL));

    //create example graph
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    //graph visualization
    GraphVisualizer gv(g);
    gv.showGraph();

    return 0;
}
