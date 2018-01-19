#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.9 String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. 
Given two strings, S1 and S2, write code to check if S2 is a rotation of S1 using only one call to isSubstring 
(e.g., "waterbottle" is a rotation of"erbottlewat"). 
*/

/*Trick: if s2 is a rotation of s1, then s1s1 defintily contains s2 as a substring 
lets say s1 is made of 2 parts - x(wat) + y(erbottle)
and s2 is made of y(erbottle) + x(wat)
Then xyxy definitely contains yx as a substring. Use isSubstring method to check if yx(s2) is contained in xyxy(s1s1)
*/

bool isRotation(string s1, string s2) {
    size_t l1 = s1.size();
    size_t l2 = s2.size();
    
    if(!l1 || !l2)
        return false;
    if(l1 != l2)
        return false;
    
    string s1s1 = s1;
    s1s1 += s1; //concatenate another s1 to s1s1
    
    return isSubstring(s1s1,s2) ? true : false;
}

int main()
{
    string s1 = "waterbottle"
    string s2 = "erbottlewat"
    if(isRotation(s1,s2));
        cout << "S2 is a rotation of S1" << endl;
    else
        cout << "S2 is not a rotation of S1" << endl;
   
    return 0;
}

