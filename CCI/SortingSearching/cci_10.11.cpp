#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

/*10.11 Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to the
adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers. 
For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. 
Given an array of integers, sort the array into an alternating sequence of peaks and valleys. 
EXAMPLE Input: {5, 3, 1, 2, 3} 
Output: {5, 1, 3, 2, 3} */

/*Approach1 - Sort the array in nlogn, starting from index 1 swap with adjacent array element at index 2. Skip an index and move to index 3 and do the same thing
Approach2 - Without sorting (better than nlogn), starting at index 1, if the element at index 1 is not the highest among the two adjacent elements, swap it with the
highest element. Skip an index and do the same at index 3.
*/

//Approach1 - relies on sorting to find the higher of the adjacent elements - O(nlogn)
/*void peaksAndValley(vector<int>& a) {
    sort(a.begin(),a.end());
    for(int i = 1;i < a.size();i+=2) {
        swap(a[i-1],a[i]); //swap with the bigger element on the right, such that now peak is in the center
    }
}*/

int getHighest(vector<int> a, int lower, int middle, int higher) {
    size_t n = a.size();
    int lowerVal = lower >= 0 && lower < n ? a[lower] : INT_MIN; 
    int middleVal = middle >= 0 && middle < n ? a[middle] : INT_MIN;
    int higherVal = higher >= 0 && higher < n ? a[higher] : INT_MIN;
    
    int maxVal = max(middleVal,max(lowerVal,higherVal));
    
    if(maxVal == lowerVal)
        return lower;
    else if(maxVal == middleVal)
        return middle;
    else
        return higher;
}

//Approach2 - doesn't rely on sorting, instead simply swaps the middle element with higher of the adjacent elements - O(n)
void peaksAndValley(vector<int>& a) {
    for(int i = 1;i < a.size();i+=2) {
        //find the highest element from i-1,i, i+1 indexes
        int index = getHighest(a,i-1,i,i+1);
        if(i != index)
            swap(a[i],a[index]); //swap current element with the bigger element, such that now peak is in the center
    }
}


int main()
{
  vector<int> a = {9, 1, 0, 4, 8, 7 }; // {5,3,1,2,3}
  peaksAndValley(a);
  cout << "Rearranged elements in peaks and valley format is " << endl;
  for(int i = 0;i < a.size();i++)
      cout << a[i] << ", ";
  cout <<endl;
}

