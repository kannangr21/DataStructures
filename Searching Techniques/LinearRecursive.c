#include <stdio.h>
int linearRec(int arr[], int value, int index, int n)
{
int pos = 0;
if(index >= n)
{
return 0;
}
else if (arr[index] == value)
{
pos = index + 1;
return pos;
}
else
{
return linearRec(arr, value, index+1, n);
}
return pos;
}
void main()
{
int n, value, pos;
printf("Enter the total elements in the array :");
scanf("%d", &n);

int arr[n];
printf("Enter the array elements :");
for (int i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Enter the element to search :");
scanf("%d", &value);
pos = linearRec(arr, value, 0, n);
if (pos != 0)
{
printf("Element found at position :%d ", pos);
}
else
{
printf("Element not found");
}
}