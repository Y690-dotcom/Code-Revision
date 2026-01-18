#include<stdio.h>
int main(){
  
  int n;
  printf("Enter the number of elements you wnat in the array ");
  scanf("%d",&n);
  int arr[n];
  printf("\nEnter the elements in the array\n ");
  for(int i=0;i<n;i++){
    printf("Enter the %i index element ",i);
    scanf("%d" ,&arr[i]);
  }
  printf("\nElements of the array : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }

  // Insertion Sort
  
  for(int i=1;i<n;i++){
    int key = arr[i];
     int j = i-1;
     while(j>=0 && arr[j] > key){
      arr[j+1] = arr[j];  // shift
      j--;
     }
     arr[j+1] = key;  // insert
  }
  

  printf("\nSorted Array : ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}