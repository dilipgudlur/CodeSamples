#include<stdio.h>

void swap(char *p1, char *p2) {

    *p1 = *p1 ^ *p2;
    *p2 = *p1 ^ *p2;
    *p1 = *p1 ^ *p2;
}

void permuteString(char *arr, int k, int n) {
   if(k == n) {
      int i;
      for(i = 0;i < n; i++)
         printf("%c",arr[i]);
      printf("\n");
      return;
   }
   int i;
   for(i = k; i < n; i++) {
      swap(&arr[k],&arr[i]);
      permuteString(arr,k+1,n);
      swap(&arr[k],&arr[i]);
   }
}

int main() {
   char arr[3] = "hel";
   int n = 3;
   int k = 0;
   permuteString(arr,k,n);
   return 0;
}
