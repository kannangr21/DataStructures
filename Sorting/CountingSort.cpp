#include<iostream>
#include<stdlib.h>

using namespace std;

int max(int* arr, int n){
    int maximum = arr[1];
    for(int i = 0; i < n+1; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }
    return maximum;
}

void countingSort(int* array, int*b, int max,int size){
    int* count = new int[max];
    for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    b[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
}

int main() {
    std::cout<<"Counting Sort : ";
    std::cout<<"\nEnter the number of elements : ";
    int n;
    std::cin>>n;
    int* arr = new int[n];
    int* b = new int[n];
    std::cout<<"Enter the elements : ";
    for(int i = 0; i < n; i++){
        std::cin>>arr[i];
    }
    std::cout<<"\nBefore Sorting : ";
    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<"\t";
    }
    countingSort(arr,b,max(arr,n),n);
    std::cout<<"\nAfter Sorting : ";
    for(int i = 0; i < n; i++){
        std::cout<<b[i]<<"\t";
    }
}