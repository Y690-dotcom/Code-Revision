#include<stdio.h>
void merge(int arr[],int left,int mid,int right){
    int i=left,j= mid+1,k=0;
    int temp[50];

    while(i <= mid && j <= right){
      if(arr[i] <= arr[j])
        temp[k++] = arr[i++];
      else temp[k++] = arr[j++] ; 
    }
    while(i<=mid){
      temp[k++] = arr[i++];
    }
    while(j<=right){
      temp[k++] = arr[j++];
    }

    for(i = left,k=0;i<=right;i++,k++){
      arr[i] = temp[k];
    }

  }

void mergesort(int arr[],int left,int right){
  if(left < right){
    int mid = (left+right)/2;

    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);

  }
}

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
mergesort(arr,0,n-1);  // left right pass 
printf("\nSorted Array : ");
for(int i=0;i<n;i++){
  printf("%d ",arr[i]);
}  
}