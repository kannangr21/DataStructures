#include<iostream>
#include<stdlib.h>
#include "DataStructure.h"

using namespace std;

void bucketSort(double* arr, int n){
    SList<double> *buckets;
    buckets = new SList<double>[n];
    int bucketNum;
    for(int i = 0; i < n; i++){
		bucketNum = arr[i]*n;
		buckets[bucketNum].insertFront(arr[i]);
	}
    for(int i=0;i<n;i++){
		buckets[i].sort();
	}
    double t;
    for(int i = 0, j = 0; i < n; i++){
		for(int p = 1; p <= buckets[i].getSize();p++){
			if(buckets[i].elementAt(p,t)){
				arr[j++] = t;
			}
		}
	}
}

int main() {
    std::cout<<"Bucket Sort : ";
    std::cout<<"\nEnter the number of elements : ";
    int n;
    std::cin>>n;
    double* arr = new double[n];
    std::cout<<"Enter the elements : ";
    for(int i = 0; i < n; i++){
        std::cin>>arr[i];
    }
    std::cout<<"\nBefore Sorting : ";
    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<"\t";
    }
    bucketSort(arr,n);
    std::cout<<"\nAfter Sorting : ";
    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<"\t";
    }
}