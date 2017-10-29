#include<stdio.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void merge(int *arr, int *left, int numL, int *right, int numR) {

    if(!arr)
        return;

    int l = 0;
    int r = 0;

    for(;l < numL && r < numR;) {
        if(left[l] < right[r]
    }
}

void mergesort(int *arr, int start, int end) {
    if(!arr)
        return;

    if(start >= end)
       return;

    int mid = (start + end)/2;

    int numL = mid-start+1;
    int numR = end-mid+1;
    int *left = (int*)malloc(numL*sizeof(int));
    int *right = (int*)malloc(numR*sizeof(int));

    left = &arr[start];
    right = &arr[mid+1];

    mergesort(left, start, mid);
    mergesort(right, mid + 1, end);
    merge(arr, left, numL, right, numR);
}

int main() {

   int arr[] = {3,0,4,5,8,1,6,8,2,4,7,9};
   int size = sizeof(arr)/sizeof(int);
   int i = 0;
   int start = 0;
   int end = size - 1;
   mergesort(arr, start, end);
   printf("Sorted array is\n");
   for(i = 0;i < size;i++) {
       printf("%d\t",arr[i]);
   }
   printf("\n");
   return 0;
}
