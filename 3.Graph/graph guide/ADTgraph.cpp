//Using Dijkstra's Algorithm- edge-List method

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
private:
    int numVertices;

    //vector is used to create dynamic array to contain the lists
    vector<list<int>> adjLists; //pointer to an array containing adjacency lists
    bool isDirected;

public:
    Graph(int vertices,bool directed=false){
        numVertices = vertices;
        adjLists.resize(vertices); //creates a dynamic array of size vertices
        isDirected=directed;
    }

    //function in add edge to the graph
    void addEdge(int src,int dest){
        //Guard rail for out of bounds vertices
        if(src<0 || src >=numVertices||dest<0||dest>=numVertices){
            cout<<"Invalid vertex index.\n";
            return;
        }

        adjLists[src].push_back(dest);
        //If the graph is undirected, add the reverse edge as well.
        if(!isDirected){
            adjLists[dest].push_back(src); //reverse connection.
        }
    }
    //prints graph data
    void printGraph() const{
        for(int i=0;i<numVertices;++i){ //print vertices
            cout<<"Vertex "<<i<<":";
            for(int neighbor:adjLists[i]){ //prints data included in the vertice
                cout<<"->"<<neighbor;
            }
            cout<<"\n";
        }
    }
};

int main(void){
    //Create an undirected graph with 5 vertices(0-4)
    Graph g(5,false);

    //add edges
    g.addEdge(0,1);// vertice 0: ->1  and vertice 1: ->0
    g.addEdge(0,4);// vertice 0:->1->4 and vertice 4: ->0
    
    
    g.addEdge(1,2);//vertice 1: ->0->2 and vertice 2: ->1
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    cout<<"---Graph Adjacency List---\n";
    g.printGraph();
    return 0;
}

