#include<stdio.h>

void counting_sort(int arr[], int size){

    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    int output[size];

    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(int i = 0; i < size; i++)
        count[arr[i]]++;

    for(int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < size; i++)
        arr[i] = output[i];
}

int main(){
    int arr[5] = {2, 3, 4, 1, 5};
    int size = 5;

    printf("Elements in the array : ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    counting_sort(arr, size);

    printf("\nSorted array : ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
