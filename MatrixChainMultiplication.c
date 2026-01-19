#include<stdio.h>
#include<limits.h>

int matrix_multiplication(int arr[],int i,int j){
  if(i==j)
   return 0;

  int min = 1000000;
  int count,k;
  for(k=i;k<j;k++){
    count = matrix_multiplication(arr,i,k)+matrix_multiplication(arr,k+1,j)+
            arr[i-1] * arr[k] * arr[j];
     if(count < min)
        min = count;       
  } 
  return min;   // answer is 38
}
int main(){
  int arr[] = {1,2,3,4,5};
  int size = sizeof(arr)/sizeof(arr[0]);

  int ans = matrix_multiplication(arr,1,size-1);
  printf("Minimum number of multiplication is %d",ans);
}