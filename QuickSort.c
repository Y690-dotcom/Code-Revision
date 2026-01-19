#include<stdio.h>

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int arr[],int left,int right){
  int pivot = arr[right];
  int i = left-1;

  for(int j=left;j<right;j++){
    if(arr[j] < pivot){
      i ++;
      swap(&arr[i],&arr[j]);      
    }
  }
  swap(&arr[i+1],&arr[right]);
  return i+1;
}
void quicksort(int arr[],int left,int right){
  if(left<right){
    int pi = partition(arr,left,right);
    quicksort(arr,left,pi-1);
    quicksort(arr,pi+1,right);

  }
}

int main(){
  
  int n;
  printf("Enter the number of elements you want in the array ");
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
quicksort(arr,0,n-1);  // left right pass 
printf("\nSorted Array : ");
for(int i=0;i<n;i++){
  printf("%d ",arr[i]);
}  
}