#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0
*/

    int ROWS;
    int COLS;
    
    void make_row_zero(vector<vector<int>>& matrix, int row) {
        for(int i = 0; i < COLS;i++) {
            matrix[row][i] = 0;
        }
    }
    
    void make_col_zero(vector<vector<int>>& matrix, int col) {
        for(int i = 0; i < ROWS;i++) {
            matrix[i][col] = 0;
        }
    }

    //solution1 - order of m+n space complexity = O(rows+cols)
    /*void setZeroes(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        
        bool rowZero[ROWS] = {false};
        bool colZero[COLS] = {false};
        
        for(int i = 0;i < ROWS;i++) {
            for(int j = 0;j < COLS;j++) {
                // NOTE: !(rowZero[i] == true && colZero[j] == true) is same as (rowZero[i] == false || colZero[j] == false)
                if(matrix[i][j] == 0 && !(rowZero[i] == true && colZero[j] == true)) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        
        for(int i = 0;i < ROWS;i++) {
            if(rowZero[i])
                make_row_zero(matrix,i);
        }
        
        for(int i = 0;i < COLS;i++) {
            if(colZero[i])
                make_col_zero(matrix,i);
    }*/
        
    //solution2 - O(1) space complexity: reuse the first row and column to store whether row or column has 0
    void setZeroes(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        for(int i = 0;i < ROWS;i++) { //check if first col has a zero
            if(matrix[i][0] == 0)
                firstColZero = true;
        }
        
        for(int i = 0;i < COLS;i++) { ////check if first row has a zero
            if(matrix[0][i] == 0)
                firstRowZero = true;
        }
        
        //reuses the first row and col to set 0's for remaining matrix
        for(int i = 1;i < ROWS;i++) {
            for(int j = 1;j < COLS;j++) {
                // NOTE: !(rowZero[i] == true && colZero[j] == true) is same as (rowZero[i] == false || colZero[j] == false)
                if(matrix[i][j] == 0 && !(matrix[i][0] == 0 && matrix[0][j] == 0)) {
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1;i < ROWS;i++) {
            if(matrix[i][0] == 0)
                make_row_zero(matrix,i);
        }
        
        for(int i = 1;i < COLS;i++) {
            if(matrix[0][i] == 0)
                make_col_zero(matrix,i);
        }
        
        if(firstRowZero)
            make_row_zero(matrix,0);
        
        if(firstColZero)
            make_col_zero(matrix,0);
        
    }
    
int main()
{
    vector<vector<int> > vec {{1,2,3},{0,5,6},{7,0,9}}; //2D vector, 3x3
    setZeroes(vec);
    cout << "Zeroed out matrix is " << endl;
    for(int i = 0;i < vec.size();i++) {
        for(int j = 0;j < vec[i].size();j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}

