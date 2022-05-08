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

void countingSort(int* a, int* b, int pos, int n){
    int* c = new int[10]; // 0-9 for all the numbers
    for(int i = 0; i < 10; i++){
        c[i] = 0;
    }
    for(int i = 0; i < n; i++){
        c[(a[i]/pos)%10]++;
    }
    for(int i = 1; i < 10; i++){
        c[i] = c[i] + c[i-1];
    }
    for(int i = n-1; i >= 0; i--){
        b[--c[(a[i]/pos)%10]] = a[i];
    }
}

void radixSort(int* a, int *b, int n){
    int maximum = max(a, n);
    for(int pos = 1; maximum/pos > 0; pos*=10){
        countingSort(a, b, pos, n);
    }
}

int main() {
    std::cout<<"Radix Sort : ";
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
    radixSort(arr,b,n);
    std::cout<<"\nAfter Sorting : ";
    for(int i = 0; i < n; i++){
        std::cout<<b[i]<<"\t";
    }
}