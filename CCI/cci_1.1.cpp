// For string search problems, trick is to use a bool/int array to keep track of chars that have already occurred. This brings insertiong/search complexity to O(1)
#include <iostream>
#include <string>

using namespace std;

bool stringUniq(string s) {
    char isPresent[256];
  
    //initialize bool array
    for(int i = 0;i < 256;i++) {
      isPresent[i] = false;
    }
    
    for(int i = 0;i < s.size();i++) {
        int index = s[i];
        if(isPresent[index])
            return false;
        else {
            isPresent[index] = true;
        }
    }
    return true;
}

int main()
{
    string s = "helo";  
    if(stringUniq(s))
        cout << "string has all uniq chars" << endl;
    else
        cout << "string has repetitions" << endl;
        
    return 0;
}

