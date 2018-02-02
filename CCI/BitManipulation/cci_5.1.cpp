#include <iostream>

using namespace std;

/*5.1 Insertion: You are given two 32-bit numbers, N and M , and two bit positions, i and j. 
Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume 
that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume 
that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, 
because M could not fully fit between bit 3 and bit 2. EXAMPLE Input: N = 10000000000, M = 10011, i = 2, j = 6
Output N = 10000100110
*/

void bitMerge(int& n, int m, int i, int j) {
    //1.clear out the bits from i to j in n: two approaches to clear bitsfrom i to j
    
    //a.either generate a mask by mobing 1 iteratively from i to j in a loop such that only bits from i to j are 1's, now flip this mask to reverse 1's to 0's 
    int mask = 0;
    for(int x = i;x <= j;x++) {
        mask |= 1 << x;
    }
    mask = ~mask;
    
    //b.start with an all 1's mask, shift this mask left and right to clear out bits from i to j.
    int mask = ~0; //all 1's mask
    int leftOnes = mask << (j+1);
    int rightOnes = (1 << i) - 1; //this is a useful trick, subtracting 1 from 1000 gives, 0111
    mask = leftOnes | rightOnes; //final mask with bits i to j cleared
    
    n &= mask; //clears the bits of n
    
    //2.shift m to align such that last bit of m is at position i
    m  <<= (i-1); //shift m by i-1, since ith position has to align with lsb of m
    
    //3.merge n and m
    n |= m;
}

int main() {
    
    int n = 1024;//binary is 10000000000
    int m = 19;//binary is 10011
    int i = 2;
    int j = 6;
    bitMerge(n,m,i,j);
    cout << "Bit Merged n is " << n <<endl;
    return 0;   
}
