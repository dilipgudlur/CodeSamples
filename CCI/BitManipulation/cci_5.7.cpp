#include <iostream>

using namespace std;

/*5.7 Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as possible 
(e.g., bit O and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
*/

//Use unsigned int here, since >>> is not available for c++, so if you use >> on signed int, then if signed bit will have a 1 for a negative number
//that will cause the swapping logic to mess up at the sign bit
unsigned int pairwiseSwap(unsigned int n) {
   unsigned int moveRight = (n & 0xAAAAAAAA) >> 1; //captures left part of the pair and moves right, its logical shift so that sign bit is replaced with 0
   unsigned int moveLeft = (n & 0x55555555) << 1; //captures right part of the pair and moves left
   
   return (moveRight | moveLeft);
}

int main() {
    
    unsigned int a = 29; 
    cout << "After Pairwise Swap of a,"<< " result is "<< pairwiseSwap(a) << endl;
    return 0;   
}
