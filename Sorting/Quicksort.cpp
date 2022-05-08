#include <iostream>
#include <stdlib.h>
void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int* arr, int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(arr[j] <= x){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr, i+1, r);
    return i+1;
}

void quickSort(int* arr, int p, int r){
    if(p < r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main() {
    std::cout<<"QuickSort : ";
    std::cout<<"\nEnter the number of elements : ";
    int n;
    std::cin>>n;
    int* arr = new int[n+1];
    std::cout<<"Enter the elements : ";
    for(int i = 1; i < n+1; i++){
        std::cin>>arr[i];
    }
    std::cout<<"\nBefore Sorting : ";
    for(int i = 1; i < n+1; i++){
        std::cout<<arr[i]<<"\t";
    }
    quickSort(arr,1,n);
    std::cout<<"\nAfter Sorting : ";
    for(int i = 1; i < n+1; i++){
        std::cout<<arr[i]<<"\t";
    }
}