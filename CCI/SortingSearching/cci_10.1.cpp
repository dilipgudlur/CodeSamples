#include <iostream>
#include <vector>

using namespace std;

/*10.1 Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough 
buffer at the end to hold B. Write a method to merge B into A in sorted order.
*/

//Approach: since back of array a has extra space, starting from behind would avoid shifting
//the elements.

void merge(vector<int>& a, vector<int> b, int aIndex) {
    size_t l1 = a.size();
    size_t l2 = b.size();
    if(!l1 || !l2 || l1 < l2)
        return;
    
    int i = aIndex; //last element of a
    int j = l2-1; //last element of b
    int insertIndex = l1-1;
    
    
    while(j >= 0) { //no need to check for i since elements of a already there if b finishes first
        if(a[i] > b[j]) {
            a[insertIndex--] = a[i--];
        }
        else if(a[i] == b[j]) {
            a[insertIndex--] = a[i--];
            a[insertIndex--] = b[j--];
        }
        else{
            a[insertIndex--] = b[j--];
        } 
    }
}

int main() {
    
    vector<int> a = {1,5,7,8,0,0,0,0,0}; 
    vector<int> b = {2,4,5,6,9};
    int index = 3; //last element of a
    merge(a,b,index);
    cout << "Merged array a is "<< endl;
    for(int i = 0;i < a.size();i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;   
}
