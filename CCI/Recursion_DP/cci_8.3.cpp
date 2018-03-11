/*8.3 Magic Index: A magic index in an array A[ 1 ... n-1] is defined to be an index such that A[ i] i. 
Given a sorted array of distinct integers, write a method to find a magic index, 
if one exists, in array A. FOLLOW UP What if the values are not distinct?*/

//Approach: Brute force approach - O(n), find if arr[i] = i, then return i
//O(lgn) wiht binary search - If no duplicates then if arr[mid] = mid, return mid. If arr[mid] > mid, means moving right will cause arr[mid] to be always > mid so have to move left
//if(arr[mid] < mid, then move right to have possibility of finding magic index

//its tricky if there are duplicates in the array, that will cause you to search both sides of the array. - O(n)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//O(lgn) solution
int magicIndexDistinct(vector<int>& arr, int low,int high) {
    if(low > high)
        return -1;
    
    int mid = (low+high)/2;
    if(arr[mid] == mid)
        return mid;
    else if(arr[mid] > mid)
        return magicIndexDistinct(arr,low,mid-1);
    else
        return magicIndexDistinct(arr,mid+1,high);
}

//arr with duplicates, search both left and right
int magicIndexDuplicates(vector<int>& arr, int low,int high) {
    if(low > high)
        return -1;
    
    int mid = (low+high)/2;
    if(arr[mid] == mid)
        return mid;
        
    //search left, search from low till min of arr[mid],mid-1. We already know that till index arr[mid], mid is > arr[mid] so no point searching between arr[mid] and mid-1
    int leftIndex = min(arr[mid],mid-1);
    int left = magicIndexDistinct(arr,low,leftIndex);
    if(left > -1)
        return left;
    
    //search right, irrespective of what arr[mid], mid are, take the maximum of mid+1 and arr[mid] till high to do the searching, because lets say at mid  = 4, arr[mid] is 6, then 
    //arr[mid] == mid cannot happen between indexes 4 and 6, if there is a match then it will be after index 6, because at index 4,5 we already know its less than arr[mid], 
    int rightIndex = max(arr[mid],mid+1);
    int right = magicIndexDistinct(arr,rightIndex,high);
    if(right > -1)
        return right;
}

int main()
{
    vector<int> arrDistinct = {-40,-20,-1,1,2,3,5,7,9,12,13};
    vector<int> arrDuplicates = {-10,-5,2,2,2,3,4,7,9,12,13};
    cout << "Magic Index exists at " << magicIndexDistinct(arrDistinct, 0, arrDistinct.size()-1) << endl;
    cout << "Magic Index exists at " << magicIndexDuplicates(arrDuplicates, 0, arrDuplicates.size()-1) << endl;
}

