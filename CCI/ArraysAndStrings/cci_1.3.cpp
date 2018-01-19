#include <iostream>
#include <string>

using namespace std;

/*1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient 
space at the end to hold the additional characters, and that you are given the "true" length of the string.
EXAMPLE Input: "Mr John Smith     ", 
        Output: "Mr%20John%20Smith" 
*/
void URLify(string& s, int len) {
    
    size_t n = s.size();
    int currentIndex = 0;
    
    //starting from the end move the chars back, find first non-space char
    for(int i = n-1;i >= 0;--i) {
        if(s[i] != ' ') {
            currentIndex = i;
            break;
        }
    }
    
    for(int i = n-1;i >= 0;) {
        if(s[currentIndex] != ' ') {
            s[i--] = s[currentIndex--];
        }
        else {//currentIndex is a space
            s[i--] = '0'; 
            s[i--] = '2';
            s[i--] = '%';
            currentIndex--;
        }
    }   
}

int main()
{
    string s = "Mr John Smith    ";
    
    URLify(s,13);
    
    cout << "URLified string is " << s << endl;
        
    return 0;
}

