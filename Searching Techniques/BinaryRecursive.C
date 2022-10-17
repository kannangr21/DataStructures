#include <stdio.h>
int recursiveBinarySearch(int array[], int low, int high, int
element)
{
if (high >= low){
int middle = low + (high - low )/2;
if (array[middle] == element)
return middle;
else if (array[middle] > element)
return recursiveBinarySearch(array,low, middle-1,
element);
else
return recursiveBinarySearch(array, middle+1, high,
element);
}
return -1;
}
void main()
{
int num, i, key;
int low, high;
printf("Enter the total number of elements :");
scanf("%d", &num);
int array[num];
printf("Enter %d elements of the list :",num);

for (i = 0; i < num; i++)
scanf("%d", &array[i]);
printf("Enter element to be searched : ");
scanf("%d", &key);
int pos = recursiveBinarySearch(array, 0, num-1, key);
if(pos == -1 )
{
printf("Element not found in the array ");
}
else {
printf("Element found at location : %d",pos+1);
}
}