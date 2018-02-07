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

int nextLargerArithmetic(int n) {
    //step1 is common - calculate the 0's and 1's using the above approach
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
    
    //step2 - flip the 0 at bit x to 1 and all bits on right to 0
    //add (2^zerosToRight-1) to set the bits that were zeros: (1 << zerosToRight) - 1
    
    n += (1 << zerosToRight) - 1;
    
    //add 1 to the above number to flip the zero at bit x: (1 << zerosToRight) - 1 + 1 = (1 << zerosToRight)
    n += 1;
    
    //step3 - set the number of ones back: (2^(onesToRight-1)-1), one 1 has allready been added
    n += (1 << (onesToRight-1)) - 1;
    return n; //can also be written as [return n + (1 << zerosToRight) + (1 << (onesToRight-1)) - 1]
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
    n &= mask; //cleared out the bits incuding the bit x and all bits to its right
    
    //Step3 - set (onesToRight+1) bits starting from immediately right of bitsToRight (bit x) position (0-Indexed)
    mask = 1 << (onesToRight+1);
    mask -= 1;
    mask <<= (zerosToRight-1); //mask is now like this 000011100000 such that only onesToRight bits can be set, ref to 5.1.cpp, two more techniques are mentioned there
    n |= mask; 
    
    //instead of clearing out all bits including bitx, you could also have cleared only bits to the right and then subtracted 1,
    //that would have cleared the bit at bitx and set all the bits on the right to 1. Then its just a matter of clearing the (zerosToRight-1) bits from lsb
    
    return n;
}

int previousSmallerArithmetic(int n) {
    if(!n)
        return -1;
        
    int tmp = n;
    int onesToRight = 0;
    int zerosToRight = 0;
    //Approach: calculate the number of 1's and 0's to the right of the non-trailing 1
    //Flip this 1, clear all bits to the right of this. Set (onesToRight+1) 1's starting immediately right to the non-trailing 1
    
    //step1 is common- find the non-trailing 1
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
    
    //step2 - flip the 1 to 0 at bitx, clear all bits to right
    n -= (1 << onesToRight) - 1;
    
    //subtract another 1 to clear the bit x and set all bits on the right
    n -= 1;
    
    //now clear the (zerosToRight-1) bits starting from lsb
    n -= (1 << (zerosToRight-1)) - 1; //you could also write this as [return n - (1 << onesToRight) - (1 << (zerosToRight)) + 1]
    
    return n;
}

int main() {
    
    int a =  13948; //in binary - 11011001111100
    int b = 10115;
    cout << "Next larger number than " << a << " with same number of 1's set is " << nextLarger(a) << endl;
    cout << "Next larger number than " << a << " with same number of 1's set is " << nextLargerArithmetic(a) << endl;
    cout << "Previous smaller number than " << b << " with same number of 1's set is " << previousSmaller(b) << endl;
    cout << "Previous smaller number than " << b << " with same number of 1's set is " << previousSmallerArithmetic(b) << endl;
    return 0;   
}
