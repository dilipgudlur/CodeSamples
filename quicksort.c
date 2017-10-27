#include<stdio.h>

void quicksort(int *arr, int size) {
    if(!arr || size < 0)
        return;

    
}

int main() {

   int arr[] = {3,8,1,6,7};
   int size = sizeof(arr)/sizeof(int);
   int i = 0;
   quicksort(arr,size);
   printf("Sorted array is\n");
   for(i = 0;i < size;i++) {
       printf("%d\t",arr[i]);
   }
   return 0;
}
