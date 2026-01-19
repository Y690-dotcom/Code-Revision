#include<stdio.h>
int main(){
int arr[] = {0,2,1,4,5};
int n = 5;                              // Selection Sort
for(int i =0 ;i<n-1 ;i++){
  int min_ind = i;
  for(int j=i+1 ; j<n ; j++){
    if(arr[j] < arr[min_ind]){
        int min_ind = j;
    }
    int temp = arr[min_ind];
    arr[min_ind] = arr[i];
    arr[i] = temp;
  }
}

printf("Sorted Array is : ");
for(int i=0 ; i<n ;i++){
  printf("%d",arr[i]);
  printf(" ");
}

  return 0;

}