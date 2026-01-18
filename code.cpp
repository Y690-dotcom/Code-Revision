#include<iostream>
using namespace std;

int binary_search(int arr[1000],int key,int n){

  int start = 0;
  int end = n-1;
  while(start <= end){
    int mid = start + (end-start)/2;
    if(arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
    {
      end = mid-1;
    }
    else 
       start = mid + 1;       
  }
return -1;

}


int main(){
int arr[1000],key,n;
cout << "Enter the size of array : " ;
cin >> n;
cout << "\nEnter the elements in the array in sorted order : " ;
for(int i=0 ; i<n ; i++){
  cin >> arr[i];
}

cout << "\nEnter the element you want to find : ";
cin >> key;
int ans = binary_search(arr,key,n);
if(ans != -1)
    cout << "Value found at index " << ans << endl;
else
    cout << "Value not present and index position is " << ans << endl;
  return 0;

}