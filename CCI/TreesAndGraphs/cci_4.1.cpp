#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>    // std::find

using namespace std;

/*4.1 Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes. 
*/

//Two approaches to make a graph - array of vectors or vector of lists. This implements an array of vectors

void addEdge(vector<int> dg[],int u, int v) {
    dg[u].push_back(v); //this is a directed edge so there is no bidirectional linkage
}

bool hasEdge(vector<int> dg[],int u, int v) {
    if(find(dg[u].begin(),dg[u].end(),v) != dg[u].end()) //v has been found in the list corresponding to u
        return true;
    return false;
}

int main() {
    int V = 5;
    int u = 2,v = 4;
    vector<int> dg[V];
    addEdge(dg, 0, 1);
    addEdge(dg, 0, 4);
    addEdge(dg, 1, 2);
    addEdge(dg, 1, 3);
    addEdge(dg, 1, 4);
    addEdge(dg, 2, 3);
    addEdge(dg, 3, 4);
    if(hasEdge(dg,u,v))
        cout << "Node " << u << " and " << v << " has an edge" << endl;
    else
        cout << "Node " << u << " and " << v << " dont have an edge" << endl;
    return 0;   
}
