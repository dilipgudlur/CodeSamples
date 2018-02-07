#include <iostream>

using namespace std;

/*5.6 Conversion: Write a function to determine the number of bits you would need to flip to convert integer A to integer B. 
EXAMPLE Input: 29 (or: 11101), 15 (or: 01111) 
Output: 2
*/
//Approach: Use XOR to find the bits that are different, only opposite bits will give a 1 in the final XOR. Once XOR is done, use KR bit counting technique

int bitFlipAB(int a, int b) {
    
    int c = a ^ b;
    int count = 0;
    while(c) {
        c = c & (c-1); //this is kernighan and richie technique to do bit counting
        count++;
    }
    return count;
}

int main() {
    
    int a = 29; 
    int b = 15;
    cout << "Number of bits flips needed to convert " << a << " into " << b <<  " is " << bitFlipAB(a,b) << endl;
    return 0;   
}
