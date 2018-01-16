// Example program
#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. 
A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.
The palindrome does not need to be limited to just dictionary words. 
EXAMPLE Input: Tact Coa 
Output: True (permutations: "taco cat'; "atco eta·; etc.) 
*/

/*Trick: Not more than 1 charin the string can have odd number of char occurences
In a palindrome, atmost 1 char has odd number of char count occurence*/

/*Solution1 - use a 128 count long array to count occurrences,
if more than 1 char occurs odd number of times, then its not a Palindrome*/

bool palindromePerm(string s) {
    
    size_t n = s.size();
    int charCount[128] = {0};
    int result = 0;
    for(int i = 0;i < n;i++) {
        charCount[s[i]]++;
    }
    
    for(int i = 0;i < 128;i++) {
        if(charCount[i] && (charCount[i]%2) != 0) {
            cout << charCount[i] << endl;
            result++;
            if(result > 1)
                return false;
        }
    }
    return true;
}


/*Solution2 - use an integer (32 bits to represent 26 chars of alphabet
As the chars occur in the string, toggle the bits of the integer. Using the above trick,
at the end of the string, atmost 1 bit should be set in the integer*/

void toggleBits(int& bitVector, int index) {
    int mask = 1 << index;
    bitVector ^= mask;
}

bool palindromePermBitVector(string s) {
    
    size_t n = s.size();
    int bitVector = 0;
    int index = 0;
    
    for(int i = 0;i < n;i++) {
        index = s[i] - 'a';
        toggleBits(bitVector,index);
    }
    
    if(!bitVector) //no bits set
        return true;
    if((bitVector & (bitVector-1)) == 0) //check if 1 bit is set eg: 01000 & 00111 is 0
        return true;
    
    return false;
}

int main()
{
    string s = "abcdedcba";
    
    if(palindromePerm(s))
        cout << "Palindrome permutation" <<endl;
    else
        cout << "Not a Palindrome permutation" <<endl;
        
    return 0;
}
