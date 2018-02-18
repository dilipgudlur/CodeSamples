#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

/*Mergesort - Avg case runtime is O(nlogn). In mergesort, every step splits the problem in half so runtime is O(nlgn). Space complexit is O(n) since at each step we use n extra space

 Complexity analysis:
a. Best case/Avg Case [O(nlgn)] - At each step, problem of n elements is split into two equal halves on n/2:
At step1, Tn = 2T(n/2) + n*c where c is the time taken in partition function and the function operates on the whole range of n elements so n*c.
At step2, Tn = 2[2T(n/4) + (n/2)*c] + nc = 4T(n/4) + 2nc
At step3, Tn = 4[2T(n/8) + (n/4)*c] + 2nc = 8T(n/8) + 3nc
At step k, Tn = 2^k * T(n/2^k) + k*n*c
We know T(1) is constant operation of c1, so after how many steps k, will n become 1 which means n/2^k = 1, so after k = lgn steps n becomes 1
Replacing, 2^k with 1 and k with lgn (lg n means logn with base 2)
Tn = n*c1 + lgn * n * c = O(nlgn)
*/

void merge(vector<int>& a,vector<int> left,vector<int> right) {
    
    int i = 0;
    int j = 0;
    int k = 0;
    int l = left.size();
    int r = right.size();
    while(i < l && j < r) {
        if(left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    
    while(i < l) {
        a[k++] = left[i++];
    }
    
    while(j < r) {
        a[k++] = right[j++];
    }
}

void populate(vector<int>& arr,vector<int> a, int low, int high) {
    for(int i = low;i <= high;i++)
        arr.push_back(a[i]);
}

void mergesort(vector<int>& a,int low, int high) {
    if(low >= high) //most important part - terminating condition, single element is always sorted
        return;
    
    int mid  = (low + high)/2;
    vector<int> left;
    vector<int> right;
    populate(left,a,low,mid); //populate left
    populate(right,a,mid+1,high); //populate right
    mergesort(left,0,left.size()-1); //split the left into two halves, important: since this is a fresh array, start with 0 as low
    mergesort(right,0,right.size()-1); //split right into two halves, important: since this is a fresh array, start with 0 as low
    merge(a,left,right);
}

int main()
{
  vector<int> a = {10,17,19,9,7, 1, 0, 4, 8, 7}; // {5,3,1,2,3}
  int low = 0;
  int high = a.size()-1;
  mergesort(a,low,high);
  cout << "Sorted array is " << endl;
  for(int i = 0;i < a.size();i++)
      cout << a[i] << ", ";
  cout <<endl;
}
