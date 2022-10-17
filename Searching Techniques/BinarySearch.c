#include<stdio.h>
int binsearch(int[], int, int, int);
void main() {
int num, i, key, position;
int low, high;
printf("Enter the total number of elements :");
scanf("%d", &num);
int arr[num];
printf("Enter %d elements of the list :",num);
for (i = 0; i < num; i++) {
scanf("%d", &arr[i]);
}
low = 0;
high = num - 1;
printf("Enter element to be searched : ");
scanf("%d", &key);
position = binsearch(arr, key, low, high);
if (position != -1) {
printf("the Number %d is present at %d", key,(position + 1));
}
else
printf("The number %d is not present in the list",key);
}
int binsearch(int a[], int x, int low, int high) {

int mid;
if (low > high)
return -1;
mid = (low + high) / 2;
if (x == a[mid]) {
return (mid);
}
else if (x < a[mid]) {
binsearch(a, x, low, mid - 1);
}
else {
binsearch(a, x, mid + 1, high);
}
}