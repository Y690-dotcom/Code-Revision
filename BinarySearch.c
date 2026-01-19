#include<stdio.h>

int bsearch(int arr[],int start,int end,int element){
  if(start > end)
      return -1;
    
    int mid = start+(end-start)/2;  // no loop it is recursive
    if(arr[mid] == element)
       return mid;
    else if(arr[mid] > element)
      return bsearch(arr,start,mid-1,element);
    
    else return bsearch(arr,mid+1,end,element);  
     
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
int element;
printf("\nEnter the element you want to search");
scanf("%d",&element);

int start = 0,end = n-1;
int ans = bsearch(arr,start,end,element);

if(ans != -1)
   printf("Element found at %d index",ans);
else printf("Element was not found");   
}