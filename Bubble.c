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

// Bubble Sort
for(int i=n-1;i>=0;i++){
  for(int j=1;j<n-1;j++){
    if(arr[j] < arr[j-1]){
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
    }
  }
}
printf("\nSorted Array : ");
for(int i=0;i<n;i++){
  printf("%d ",arr[i]);
}
}