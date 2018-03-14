/*8.10 Paint Fill: Implement the"paint fill"function that one might see on many image editing programs. 
That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, 
fill in the surrounding area until the color changes from the original color. 
*/

/*Approach: this uses the dfs mechanism to fill all the grid with a different color. Can use BFS too
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack> 

using namespace std;

//fill the whole grid with the new color
void paintFill(vector<vector<int>>& grid, int row, int col, int ncolor) {
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        return;
    
    if(grid[row][col] == ncolor) //already has new color, so dont fill this
        return;
    else {
        grid[row][col] = ncolor;
        paintFill(grid,row+1,col,ncolor);
        paintFill(grid,row-1,col,ncolor);
        paintFill(grid,row,col+1,ncolor);
        paintFill(grid,row,col-1,ncolor);
        //return;
    }
}

int main()
{
    int ROWS = 4;
    int COLS = 5;
    vector<vector<int>> grid(ROWS,vector<int>(COLS,7)); //initialize a 2d grid of color #7
    int row = 2;
    int col = 3;
    int ncolor = 8;
    paintFill(grid,row,col,ncolor);
    cout << "Color of grid is " << endl;;
    for(int i = 0;i < ROWS;i++) {
        for(int j = 0;j < COLS;j++) {
            cout << grid[i][j] << ",";
        }
        cout << endl;
    }
}

