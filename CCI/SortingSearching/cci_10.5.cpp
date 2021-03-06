// Example program
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*10.5 Sparse Search: Given a sorted array of strings that is interspersed with empty strings, 
write a method to find the location of a given string. 
EXAMPLE Input: ball, {"at","","","", "ball","","", "car", "" , "" , "dad", "",""} 
Output: 4*/

//Approach: Use regular binary search, if you encounter a middle element which is an empty string,
//use the nearest non-empty string to continue the search. Start with sdjoining elements, if both are
//empty then start expanding towards their adjoining elements 

/*Note: The worst-case runtime for this algorithm is O ( n). In fact, it's impossible to have an 
algorithm for this problem that is better than O(n) in the worst case. After all, you could have 
an array of all empty strings except for one non-empty string. There is no "smart" way to find this 
non-empty string. In the worst case, you will need to look at every element in the array. 
Careful consideration should be given to the situation when someone searches fort he empty string. 
Should we find the location (which is an O( n) operation)? Or should we handle this as an error? 
*/

int sparseSearch(vector<string> a,string target) {
    
    if(!a.size() || !target.size())
        return -1; //invalid string
        
    int l = 0;
    int h = a.size()-1;
    
    while(l <= h) {
        int m = (l+h) >> 1;
        if(a[m] == "") {//empty string
            int left = m-1;
            int right = m+1;
            if(a[left] != "") {
                if(a[l] < target)
                    l = left+1;
                else if(a[l] > target)
                    h = left-1;
                else //equals target
                    return left;
            }
            else if(a[right] != "") {
                if(a[right] > target)
                    h = right-1;
                else if(a[right] < target)
                    l = right+1;
                else //target found
                    return right;
            }
            else if(a[left] == "" && a[right] == "") {
                if(left > l && right < h) {
                    left--;
                    right++;
                }
                else
                    return -1;
            }
            
        }
        else if(a[m] > target) {//search left
            h = m-1;
        }
        else if(a[m] < target) {//search right
            l = m+1;
        }
        else { //target found
            return m;
        }
    }
    return -1;
}

int main()
{
  vector<string> a = {"at","","","", "ball","","", "car", "" , "" , "dad", "",""};
  string target = "dad";
  cout << "String " << target << " occurs at index " << sparseSearch(a,target) << endl;  
}

