#include "interfaces.h"


int main()
{
    //for random numbers
    srand((unsigned) time(NULL));

    //get number of actions
    int numberOfActions;
    std::cout << "Enter a number of actions: ";
    std::cin >> numberOfActions;

    //input actions
    InputParser ip(numberOfActions);
    

    //create example graph
    Graph g(numberOfActions);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);


    //graph visualization
    GraphVisualizer gv(g);
    gv.showGraph();

    return 0;
}
