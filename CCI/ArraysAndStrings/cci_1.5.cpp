#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.5 One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.
Given two strings, write a function to check if they are one edit (or zero edits) away. 
EXAMPLE pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false
*/

bool oneReplace(string s1,string s2) {
    size_t l1 = s1.size(); //both strings have same size
    int count = 0;
    for(int i = 0;i < l1;i++) {
        if(s1[i] != s2[i]) {
            if(++count > 1)
                return false;
        }
    }
    return true;
}

bool oneInsertRemove(string s1,string s2) { //s1 is the smaller string
    size_t l1 = s1.size();
    
    int count = 0;
    int i = 0;
    int j = 0;
    
    while(i < l1) {
        if(s1[i] != s2[j]) {
            j++;
            if(++count > 1)
                return false;
        }
        else {
            i++;
            j++;
        }
    }
    return true;
}

bool oneEditAway(string s1, string s2) {

    size_t l1 = s1.size();
    size_t l2 = s2.size();
    
    if(l1 == l2)
        return oneReplace(s1,s2);
    else if(l1 == l2+1)
        return oneInsertRemove(s2,s1);
    else if(l1+1 == l2)
        return oneInsertRemove(s1,s2);
    else
        return false;
}

int main()
{
    string s1 = "pales";
    string s2 = "bale";
    
    if(oneEditAway(s1,s2))
        cout << "One Edit Away" <<endl;
    else
        cout << "More than 1 edit away" <<endl;
        
    return 0;

}

