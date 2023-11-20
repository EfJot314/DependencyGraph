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

    //getting word
    string word;
    getline(file, word);

    //getting actions
    InputParser ip;
    string line;
    while (getline(file, line)) {
        ip.parse(line);
    }


    //create solver
    Solver s(ip, word);


    //show D
    Relations* D = s.createDependencies();
    cout << "D = {";
    for(int i=0;i<D->length;i++){
        cout << "{" << D->tab[i].e1 << ", " << D->tab[i].e2 << "}";
        if(i < D->length-1)
            cout << ", ";
    }
    cout << "}" << endl;

    //show I
    Relations* I = s.createIndependecies();
    cout << "I = {";
    for(int i=0;i<I->length;i++){
        cout << "{" << I->tab[i].e1 << ", " << I->tab[i].e2 << "}";
        if(i < I->length-1)
            cout << ", ";
    }
    cout << "}" << endl;


    //create graph
    // Graph* g = s.createGraph();

    
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
