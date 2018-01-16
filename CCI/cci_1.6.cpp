#include <iostream>
#include <string>
#include <algorithm>    // std::sort

using namespace std;

/*1.6 String Compression: Implement a method to perform basic string compression using the counts of repeated characters. 
For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the 
original string, your method should return the original string. You can assume the string has only uppercase and lowercase 
letters (a -z).
*/

string compress(string s) {
    string result = "";
    size_t n = s.size();
    if(!n)
        return result;
    if(n == 1) {
        result += s + "1";
        return result.size() < n ? result : s;
    }
        
    int i = 0;
    int j = 1;
    
    while(j < (int)n) {
        
        if(s[i] == s[j]) {
            j++;
        }
        else {
            result += s[i] + to_string(j-i);
            i = j;
            j++;
        }
    }
    
    result += s[i] + to_string(n-i); //completes the remaining string
    
    return result.size() < n ? result : s;
}

int main()
{
    //string s = "aaaadbbbcccccaaa";
    string s = "a";
    
    string out = compress(s);
    cout << "Compressed string is " << out <<endl;
   
    return 0;
}
