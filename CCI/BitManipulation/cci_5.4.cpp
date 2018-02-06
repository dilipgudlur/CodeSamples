#include <iostream>

using namespace std;

/*5.4 Next Number: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation
*/

int nextLarger(int n) {
    //Approach: Lets say that the leftmost 0 after a set of 1's happens at bit x (from right). Starting from right, clear out all bits till position x-1,
    //lets say there were (y) 1's that got cleared out in this process. Convert the 0 at bit position x to 1. So now we have to add back (y-1) 1's. Starting from
    //right, flip the 0's to set the next (y-1) bits to 1.
    
    //step1 - find leftmost 0 - occurs at bit 7 (ref to incoming number 13948 in binary)
    int tmp = n;
    int onesToRight = 0;
    int zerosToRight = 0;
    //good technique - count 0's first and then 1's. that way if no 0's are present, you directly jump to counting 1's
    
    while((tmp & 1) == 0 && tmp != 0) {
        zerosToRight++;
        tmp >>= 1;
    }
    
    while((tmp & 1) == 1) {
        onesToRight++;
        tmp >>= 1;
    }
    //handle corner case - either number is 0 or number has no larger counterpart with same number of 1's
    int bitsToRight = onesToRight+zerosToRight;
    if(bitsToRight == 31 || bitsToRight == 0)
        return -1;

    //step2 - set the current bit construct a mask
    int mask = 1 << bitsToRight; //000...1000000
    n |= mask; //sets that bit, if zeros is 2 and ones is 5, then set bit number 7
    
    //step3 - clear out all bits from 0 to 6 using mask (111..1000000)
    mask -= 1; //000..0111111: subtraction flips the first 6 bits and clears the 7th bit
    mask = ~mask; //111..1000000: flips all the bits
    n &= mask;
    
    //step4 - now set the number of (onesToRight -1) 1's starting from lsb,
    mask = 1 << (onesToRight-1); //move a 1 to (onesToRight-1) position since bit position counting is 0 indexed
    mask -= 1; //sets first (onesToRight-1) bits, rest all are 0's
    n |= mask;
    return n;
}

int previousSmaller(int n) {
    if(!n)
        return -1;
        
    int tmp = n;
    int onesToRight = 0;
    int zerosToRight = 0;
    //Approach: calculate the number of 1's and 0's to the right of the non-trailing 1
    //Flip this 1, clear all bits to the right of this. Set (onesToRight+1) 1's starting immediately right to the non-trailing 1
    
    //step1 - find the non-trailing 1
    while((tmp & 1) == 1) {
        onesToRight++;
        tmp >>= 1;
    }
    
    while((tmp & 1) == 0 && tmp != 0) {
        zerosToRight++;
        tmp >>= 1;
    }
    
    int bitsToRight = zerosToRight + onesToRight; //non-trailing 1 is at position bitsToRight (0-indexed)
    
    if(bitsToRight == 31 || bitsToRight == 0) //error handling
        return -1;
    
    //Step2 - clear all bits right and including bitsToRight position (0-indexed)
    int mask = 1 << (bitsToRight+1);
    mask -= 1; //0000..111
    mask = ~mask; //flip bits so the (bitsToRight+1) can be cleared out
    n &= mask; //cleared out the bits
    
    //Step3 - clear out the bits to the right including the current bit
    mask -= 1;
    mask = ~mask;
    n |= mask; //clear out the bits to right of non-trailing 1, bitsToRight number of bits cleared
    
    //Step4 - set (onesToRight+1) bits starting from immediately right of bitsToRight position (0-Indexed)
    mask = 1 << (onesToRight+1);
    mask -= 1;
    mask <<= (zerosToRight-1); //mask is now like this 000011100000 such that only onesToRight bits can be set, ref to 5.1.cpp, two more techniques are mentioned there
    n |= mask; 
    
    return n;
}

int main() {
    
    int a =  13948; //in binary - 11011001111100
    int b = 10115;
    cout << "Next larger number than " << a << " with same number of 1's set is " << nextLarger(a) << endl;
    cout << "Previous smaller number than " << b << " with same number of 1's set is " << previousSmaller(b) << endl;
    return 0;   
}
