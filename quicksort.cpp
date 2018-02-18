#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

/*Quicksort - Avg case runtime is O(nlogn), worstcase runtime is O(n^2). Using randomized key, worst case can also be brought down to O(nlgn) */
/* Complexity analysis
a. Best case [O(nlgn)] - At each step, problem of n elements is split into two equal halves on n/2:
At step1, Tn = 2T(n/2) + n*c where c is the time taken in partition function and the function operates on the whole range of n elements so n*c.
At step2, Tn = 2[2T(n/4) + (n/2)*c] + nc = 4T(n/4) + 2nc
At step3, Tn = 4[2T(n/8) + (n/4)*c] + 2nc = 8T(n/8) + 3nc
At step k, Tn = 2^k * T(n/2^k) + k*n*c
We know T(1) is constant operation of c1, so after how many steps k, will n become 1 which means n/2^k = 1, so after k = lgn steps n becomes 1
Replacing, 2^k with 1 and k with lgn (lg n means logn with base 2)
Tn = n*c1 + lgn * n * c = O(nlgn)
b. Worst Case [O(n&2)] but with randomized sort gets reduced to O(nlgn) - at each step, problem is reduced by only 1. This happens in an already sorted array
Example - 1 2 3 4 5 6, here if last element is chosen as key, partition function would return the pivot index as the last element. SO for next step, sub array will include uptill 5, then 4 then 3.
Tn = T(n-1) + n*c at 1st step
Tn = (T(n-2) + n*c) + n*c = T(n-2) + 2*n*c, at 2nd step
Tn = T(n-k) + k*n*c, at kth step
when k = n-1, Tn = T(1) + (n-1)*n*c = c1 + Ccn^2 - n) = O(n^2)
*/

void randomize(vector<int>& a, int low, int high) {
    int range = high-low+1;
    int randomIndex = low + (rand() % range); //have to seed srand otherwise gives same result
    swap(a[randomIndex],a[high]); //instead of choosing a random index and making it pivot, swap it with the last element so rest of algo remains same
}
int partition(vector<int>& a,int low,int high) {
    int pivot = low;
    randomize(a,low,high); //randomized quicksort
    int key = high; //elements are compared against key which is highest index element, in worst case scenario, this will be O(n^2) complexity
    
    for(int i = low;i < high;i++) {
        if(a[i] <= a[key]) { //if element is smaller
            swap(a[pivot],a[i]);
            pivot++;
        }
    }
    swap(a[pivot],a[key]);
    return pivot;
}

void quicksort(vector<int>& a, int low, int high ) {
    if(low >= high) //most important part - terminating condition
        return;
    int mid = partition(a,low,high); //rearranges array such that left of mid are all smaller and right of mid are larger
    quicksort(a,low,mid-1); //again sort the left half
    quicksort(a,mid+1,high); //sort the right half
}

int main()
{
  vector<int> a = {10,17,19,9, 1, 0, 4, 8, 7 }; // {5,3,1,2,3}
  int low = 0;
  int high = a.size()-1;
  quicksort(a,low,high);
  cout << "Sorted array is " << endl;
  for(int i = 0;i < a.size();i++)
      cout << a[i] << ", ";
  cout <<endl;
}

