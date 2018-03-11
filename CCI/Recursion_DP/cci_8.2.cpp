/*8.2 Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns. 
The robot can only move in two directions, right and down, but certain cells are "off limits" such that the 
robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.*/

//Approach: at every cell, either move a row down and stay in same column or move a column right and stay in same row. From destination if we are able to reach origin (0,0)
//then its a valid path else, add it to failedPoint so it can be used to quickly return false;

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//standard recursion uses O(2^r+c). Adding memoization to recursion, it becomes O(rc). Below solution uses recursion with memoization
bool roboRideSol1(int r, int c,vector<vector<int>>& path) {
 
    if(r < 0 || c < 0)
        return false;
        
    if(r == 0 && c == 0) {
        path.add(r,c);
        return true;
    }
    
    if(failedPoint.contains(r,c)) //use the cached result to speedup
        return false;
    
    if(roboRideSol1(r,c-1,path) || roboRideSol1(r-1,c,path)) {
        path.add(r,c);
        return true;
   }
   
   failedPoint.add(r,c); //cache the result
   return false;
        
}

int main()
{
    int rows = 3;
    int cols = 4;
    vector<vector<int>> path;
    if(roboRideSol1(rows,cols,path)) {
        cout << "Path exists" << endl;
        for(int i = 0;i < path.size();i++)
            cout << path[i][0] << "," << path[i][1] << endl;
    }
    else
        cout << "Path doesnt exist" << endl;
}

