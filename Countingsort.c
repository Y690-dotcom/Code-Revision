#include<stdio.h>

void counting_sort(int arr[],int size){
  int max = arr[0];
  for(int i=1;i<size;i++){
    if(arr[i] > max)  
    max = arr[i]; 
  }
  int count[max+1];
  int output[size];

  for(int i=0;i<=max;i++)
     count[i] = 0;

for(int j=0;j<size;j++){
   count[arr[j]] ++;
}
for(int i=1;i<=max;i++){
  count[i] += count[i-1];
}
for(int j=size-1;j>=0;j--){
  output[count[arr[j]] -1] = arr[j];
  count[arr[j]] --;
}
 // copying output to the original array
 for(int i=0 ; i<size;i++){
  arr[i] = output[i];
 }
}

int main(){
int arr[5] = {2,3,4,1,5} , size = 5;
printf("\nElements in the array : ");
for(int i=0;i<5;i++){
  printf("%d " ,arr[i]);
}

counting_sort(arr,size);
printf("\nSorted array : ");
for(int i=0;i<5;i++){
  printf("%d ",arr[i]);
}
return 0;
}


