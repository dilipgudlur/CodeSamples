#include<stdio.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int partition(int *arr, int start, int end) {

    if(!arr)
        return -1;

    if(start >= end)
        return -1;

    int pivot = arr[end];

    int pIndex = start;

    int i = 0;

    for(i = start; i < end; i++) {
        if(arr[i] <= pivot) {
            if(i != pIndex)
                swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    if(pIndex != end)
        swap(&arr[pIndex], &arr[end]);
    printf("Pindex is %d\n", pIndex);
    for(i = start; i <= end; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return pIndex;
}

void quicksort(int *arr, int start, int end) {
    if(!arr)
        return;

    if(start >= end)
       return;

    int pIndex = partition(arr, start, end);

    if(pIndex < 0)
        return;

    quicksort(arr, start, pIndex - 1);
    quicksort(arr, pIndex + 1, end);
}

int main() {

   int arr[] = {3,0,4,5,8,1,6,8,2,4,7,9};
   int size = sizeof(arr)/sizeof(int);
   int i = 0;
   int start = 0;
   int end = size - 1;
   quicksort(arr, start, end);
   printf("Sorted array is\n");
   for(i = 0;i < size;i++) {
       printf("%d\t",arr[i]);
   }
   printf("\n");
   return 0;
}
