#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>    // std::find
#include <queue>

using namespace std;

/*4.1 Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes. 
*/

//Two approaches to make a graph - array of vectors or vector of lists. This implements an array of vectors
//BFS or DFS would give the right solution

/*BFS search depends on making a queue, for shortest path use BFS since it searches neighbours first*/

/*DFS search depends on recursive search*/

void addEdge(vector<int> dg[],int u, int v) {
    dg[u].push_back(v); //this is a directed edge so there is no bidirectional linkage
}

bool bfsSearch(vector<int> dg[],int u, int v,vector<bool>& visited,vector<int>& path) {
    if(u < 0 || v < 0) //check for invalid start/end
        return false;
    
    queue<int> q;
    q.push(u);
    
    while(!q.empty()) {
        int node = q.front();
        path.push_back(node); //add to the path vector
        visited[node] = true; //make sure visited is marked
        q.pop(); //remove from queue
        if(u < 0) 
            continue;
        else {//only if valid node
            for(int i = 0;i < (int)dg[node].size();i++) {
                int tmp = dg[node][i];
                if(visited[tmp] == false) { //push into queue, only if it hasn't been visited
                    if(tmp == v) { //destination has been found
                        path.push_back(tmp);
                        return true;
                    }
                    else
                        q.push(tmp);
                }
            }
        }
    }
    
    return false;
}

bool dfsSearch(vector<int> dg[],int u, int v, vector<bool>& visited,vector<int>& path) {
    if(u < 0 || v < 0) //check for valid nodes
        return false;
        
    visited[u] = true;
    path.push_back(u);
    cout << "visited " << u << endl;
    for(int i = 0; i < (int)dg[u].size();i++) {
        int tmp = dg[u][i];
        //cout << tmp << endl;
        if(visited[tmp] == false) {
            if(tmp == v) {
                path.push_back(tmp);
                return true;
            }   
            else
                return dfsSearch(dg,tmp,v,visited,path);
        }
    }
}

int main() {
    int V = 5;
    int u = 0,v = 3;
    vector<int> dg[V];
    vector<bool> visited(V,false);
    vector<int> path;
    addEdge(dg, 0, 1);
    addEdge(dg, 0, 4);
    addEdge(dg, 1, 2);
    addEdge(dg, 1, 3);
    addEdge(dg, 1, 4);
    addEdge(dg, 2, 3);
    addEdge(dg, 3, 4);
    //if(bfsSearch(dg,u,v,visited,path)) {
    if(dfsSearch(dg,u,v,visited,path)) {
        cout << "Shortest path is " << endl;
        for(int i = 0;i < path.size();i++)
            cout << path[i] << ",";
        cout << endl;
    }
    else
        cout << "Node " << u << " and " << v << " dont have an edge" << endl;
    return 0;   
}
