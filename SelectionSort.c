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

  // Selection Sort
  for(int i=0;i<n-1;i++){
    int min_ind = i;
    for(int j=i+1;j<n;j++){
      if(arr[min_ind] > arr[j]){
        int temp = arr[min_ind];
        arr[min_ind] = arr[j];
        arr[j] = temp;
      }
    }
  }

printf("\nSorted Array : ");
for(int i=0;i<n;i++){
  printf("%d ",arr[i]);
}  
}
