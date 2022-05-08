#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

void merge(int* arr, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];

    for (int i = 1; i <= n1; i++)
        L[i] = arr[p + i - 1];
    for (int j = 1; j <= n2; j++)
        R[j] = arr[q + j];

    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    int i, j;
    i = 1;
    j = 1;

    // ISSUES IN FOR LOOP
    // for(int k = p; k < r; k++){
    //     if(L[i] <= R[j]){
    //         arr[k] = L[i];
    //         i++;
    //     } else {
    //         arr[k] = R[j];
    //         j++;
    //     }
    // }

    int k = p;

    while (k < r){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1 + 1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2 + 1) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* a, int p, int r){
    if(p < r){
        int q = floor((p+r)/2);
       // cout<<"\nP:"<<p<<"\nQ:"<<q<<"\nR:"<<r<<endl;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}

int main() {
    std::cout<<"Merge Sort : ";
    std::cout<<"\nEnter the number of elements : ";
    int n;
    std::cin>>n;
    int* arr = new int[n + 1];
    std::cout<<"Enter the elements : ";
    for(int i = 1; i <= n; i++){
        std::cin>>arr[i];
    }
    std::cout<<"\nBefore Sorting : ";
    for(int i = 1; i <= n; i++){
        std::cout<<arr[i]<<"\t";
    }
    mergeSort(arr,1,n);
    std::cout<<"\nAfter Sorting : ";
    for(int i = 1; i <= n; i++){
        std::cout<<arr[i]<<"\t";
    }
}