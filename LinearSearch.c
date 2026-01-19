#include<stdio.h>

int lsearch(int arr[],int index,int size,int element){
      if(index == size)
         return -1;

      if(arr[index] == element)
         return index;
      else return lsearch(arr,index+1,size,element);

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
int ans = lsearch(arr,0,n,element);

if(ans != -1)
   printf("\nElement found at index %d",ans);
else printf("\nElement was not found");   
}