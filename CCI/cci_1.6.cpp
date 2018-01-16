#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.6 String Compression: Implement a method to perform basic string compression using the counts of repeated characters. 
For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the 
original string, your method should return the original string. You can assume the string has only uppercase and lowercase 
letters (a -z).
*/

/*Note: avoid the + operator for concatenating, it creates a new instance by first copying the original string
and then concatenating the new ones. Instead use either the += OR append function */

string compress(string s) {
    string result = "";
    size_t n = s.size();
    if(!n)
        return result;
    if(n == 1) {
        //Note: AVOID USING + operator to concatenate, instead use +=
        result += s;
        result += "1";
        return result.size() < n ? result : s;
    }
        
    int i = 0;
    int j = 1;
    
    while(j < (int)n) {
        
        if(s[i] == s[j]) {
            j++;
        }
        else {
            //Note: AVOID USING + operator to concatenate, instead use +=
            result += s[i];
            result += to_string(j-i);
            i = j;
            j++;
        }
    }
    //Note: AVOID USING + operator to concatenate, instead use +=
    result += s[i];
    result += to_string(n-i);
    
    return result.size() < n ? result : s;
}

int main()
{
    //string s = "aaaadbbbcccccaaa";
    string s = "a";
    clock_t t;
    t = clock();
    string out = compress(s);
    cout << "time consumed is " << clock()-t <<endl;
    cout << "Compressed string is " << out <<endl;
   
    return 0;
}
