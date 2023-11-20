#include "interfaces.h"


Solver::Solver(){};

Solver::Solver(InputParser ip, std::string word){
    this->ip = ip;
    this->word = word;
};

Solver::~Solver(){};

Relations* Solver::createDependencies(){
    int n = ip.getNoActions();
    Relations* D = new Relations;
    D->tab = (Pair*)calloc(n*n, sizeof(Pair));
    D->length = 0;
    //for every action...
    for(int i=0;i<n;i++){
        Action a = ip.getAction(i);
        //...search for another action...
        for(int j=0;j<n;j++){
            bool flag = false;
            Action b = ip.getAction(j);
            //...which has my variable in dependencies...
            for(int z=0;z<b.nOfDependencies;z++){
                if(b.dependencies[z] == a.variable){
                    flag = true;
                    D->tab[D->length] = Pair{a.id, b.id};
                    D->length++;
                    break;
                }
            }
            if(!flag){
                //...or I have its variable in dependencies...
                for(int z=0;z<a.nOfDependencies;z++){
                    if(a.dependencies[z] == b.variable){
                        D->tab[D->length] = Pair{a.id, b.id};
                        D->length++;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    //...or if both has the same variable...
                    if(a.variable == b.variable){
                        D->tab[D->length] = Pair{a.id, b.id};
                        D->length++;
                        flag = true;
                    }
                }
            }
        }
    }
    return D;
};

Relations* Solver::createIndependecies(){
    int n = ip.getNoActions();
    Relations* I = new Relations;
    I->tab = (Pair*)calloc(n*n, sizeof(Pair));
    I->length = 0;
    //for every action...
    for(int i=0;i<n;i++){
        Action a = ip.getAction(i);
        //...search for another action...
        for(int j=0;j<n;j++){
            bool flag = false;
            Action b = ip.getAction(j);
            //...which has my variable in dependencies...
            for(int z=0;z<b.nOfDependencies;z++){
                if(b.dependencies[z] == a.variable){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                //...or I have its variable in dependencies...
                for(int z=0;z<a.nOfDependencies;z++){
                    if(a.dependencies[z] == b.variable){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    //...or if both has the same variable...
                    if(a.variable == b.variable){
                        flag = true;
                    }
                    //if there is no relation between a and b, then add to I
                    if(!flag){
                        I->tab[I->length] = Pair{a.id, b.id};
                        I->length++;
                    }
                }
            }
        }
    }
    return I;
};


Graph* Solver::createGraph(Relations* D){
    Graph* g = new Graph(word.length());
    //for every letter in word...
    int counter = 0;
    for(int i=0;i<word.length();i++){
        char c = word[i];
        //...search for action which has id equal to c
        for(int j=0;j<ip.getNoActions();j++){
            if(ip.getAction(j).id == c){
                g->setVertexName(i, c);
                counter++;
                //search for edges
                for(int z=0;z<i;z++){
                    //add edge only then, when it is in dependency array
                    for(int x=0;x<D->length;x++){
                        if(D->tab[x].e1 == c && D->tab[x].e2 == word[z]){
                            g->addEdge(z, i);
                            break;
                        }
                    }
                }
            }
        }
    }
    return g;
};
