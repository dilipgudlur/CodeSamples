// Example program
#include <iostream>
#include <string>

/*10.4 Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size method. 
It does, however, have an elementAt ( i) method that returns the element at index i in 0( 1) time. If i is 
beyond the bounds of the data structure, it returns -1. (For this reason, the data structure only supports 
positive integers.) Given a Listy which contains sorted, positive integers, find the index at which an element 
x occurs. If x occurs multiple times, you may return any index*/

//Approach: assume size of input array is not given, without using size, find the index of target element, if not found, return -1.
//Start with 1 element, keep doubling the size (logn), if elementAt(i) returns -1, that means we are out of bounds.
//If elementAt(i) returns greater than target, then make the last size as low and current size as high and search between
//if elementAt(i) returns lesser than target, double the size
//if elementAt(i) returns equal to target, return i

int binarySearch(Listy a,int l, int h, int target) {
    int m = 0;
    
    while(l <= h) {
        m = (l+h) >>1;
        int mid = a.elementAt(m);
        if(mid == target)
            return m;
        else if(mid > target || mid == -1) {
            h = m-1;
        }
        else if(mid < target) {
            l = m+1;
        }
    }
    return -1;
}

int searchNoSize(Listy a,int target) {
    
    int index = 1;
    while(a.elementAt(index) < target && a.elementAt(index) != -1) {
        index *= 2;
    }
    
    return binarySearch(a,index/2,index,target);
}

int main()
{
  Listy a = {1,3,5,7,8,9}
  int target = 7;
  cout << "Element " << target << " occurs at index " << searchNoSize(a,target) << endl;  
}

