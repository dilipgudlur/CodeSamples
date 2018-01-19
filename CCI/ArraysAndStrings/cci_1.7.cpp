#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place? 
*/

void rotate(vector<vector<int>>& matrix) {
    size_t n = matrix.size(); //n is both rowsize and colsize, since its nxn
    
    if(!n || n == 1 || n != matrix[0].size())
        return;
    
    for(int layer = 0;layer < n/2;layer++) {
        int start = layer;
        int end = n - 1 - layer;
        for(int i = start;i < end;i++) {
            int offset = i - start;            
            int top = matrix[start][i]; //save the top item
            matrix[start][i] = matrix[end-offset][start]; //move left item to top
            matrix[end-offset][start] = matrix[end][end-offset]; //move bottom item to left
            matrix[end][end-offset] = matrix[i][end]; //move right item to bottom
            matrix[i][end] = top; //move top item to right
        }
    }  
}

int main()
{
    vector<vector<int> > vec {{1,2,3},{4,5,6},{7,8,9}}; //2D vector, 3x3
    rotate(vec);
    cout << "2D Matrix rotated by 90 deg is " << endl;
    for(int i = 0;i < vec.size();i++) {
        for(int j = 0;j < vec[i].size();j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}

