#include "interfaces.h"

using namespace std;

int main()
{
    //for random numbers
    srand((unsigned) time(NULL));


    //read data file
    ifstream file(dataFilePath);
    if (!file.is_open()) {
        cerr << "Cannot open file!" << endl;
        return 1;
    }

    //getting actions
    InputParser ip;
    string line;
    while (getline(file, line)) {
        ip.parse(line);
    }

    
    //create example graph
    Graph g(ip.getNoActions());
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);


    //graph visualization
    GraphVisualizer gv(g);
    gv.showGraph();

    return 0;
}
