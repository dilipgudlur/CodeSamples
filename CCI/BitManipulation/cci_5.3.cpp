#include <iostream>

using namespace std;

/*5.3 Flip Bit to Win: You have an integer and you can flip exactly one bit from a O to a 1. 
Write code to find the length of the longest sequence of 1 s you could create. 
EXAMPLE Input: 1775  ((or: 11011101111)
Output: 8
*/

int flipBit(int a) {
    /* If all ls, this is already the longest sequence. */
    if (~a == 0) 
        return sizeof(int) * 8;
        
    int currentlength = 0; 
    int previouslength = 0;
    int maxlength = 1; //We can always have a sequence of at least one 1 
    while (a!= 0) { 
        if ((a & 1) == 1) //Current bit is a 1 
            currentlength++;
        else if((a & 1) == 0) { //Current bit is a 0 
            /* Update to 0 (if next bit is 0) or currentlength (if next bit is 1). */
            previouslength = (a & 2) == 0? 0 : currentlength; 
            currentlength = 0; 
        }
        maxlength = max(previouslength + currentlength + 1, maxlength); 
        a = a >> 1; //this should actually be a logical shift >>>, but that gives an error, for unsigned int, >> is same as >>>
        cout << "Maxlength is " << maxlength << endl;
    }
    return maxlength; 
}

int main() {
    
    int a = 1775;
    cout << "Number of ones in " << a << " are " << flipBit(a) << endl;
    return 0;   
}
