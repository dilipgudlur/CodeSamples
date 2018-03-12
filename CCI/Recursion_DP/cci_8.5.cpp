/*8.5 Recursive Multiply: Write a recursive function to multiply two positive integers without using the * operator (or / operator).
You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations. */

/*Approach: At the base case, a product of number with 1 is a number itself. Number by multiplied by 2 is a number + number.This is O(lgn) where n is the smaller number
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int recMultiply(int smaller, int bigger) { //note that numbers are positive
    if(smaller == 0)
        return 0; //number mulitplied by 0, is 0
    
    if(smaller == 1)
        return bigger; //number multiplied by 1, is number itself
        
    int s = smaller >> 1; //divide by 2, dont change smaller, use a tmp
    
    int product = recMultiply(s,bigger);
    
    if(smaller % 2 == 0)
        return product + product;
    else
        return product + product + bigger;
}

int multiply(int a, int b) {
    
    int smaller = a < b ? a : b;
    int bigger = a > b ? a : b;
    return recMultiply(smaller,bigger);
}

int main()
{
    int a = 13;
    int b = 9;
    
    cout << "Product is " << multiply(a,b) << endl;        
}

