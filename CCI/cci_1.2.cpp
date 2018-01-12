/* Check Permutation: Given two strings, write a method to decide if one is a permutation of the other. */

#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

bool isAnagram(string& s1,string& s2) {
 
    size_t n = s1.size();
    
    if(n != s2.size())
        return false;
    
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    
    for(int i = 0;i < (int)n;i++) {
        if(s1[i] != s2[i])
            return false;
    }
    
    return true;
}

int main()
{
    string s1 = "hello";
    string s2 = "olelz";
    
    if(isAnagram(s1,s2))
        cout << "strings are permutations" << endl;
    else
        cout << "strings are not permutations" << endl;
        
    return 0;

}
