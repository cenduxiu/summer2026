#include <stdio.h>

int partition(int arr[],int low,int high) {
int pivot = arr[high];
int j = low;
for (int i = low;i < high;i++) {
if (arr[i] < pivot) {
int temp = arr[j];
arr[j] = arr[i];
arr[i] = temp;
j++;
}
}
int temp1 = arr[high];
arr[high] = arr[j];
arr[j] = temp1;
return j;
}

void quicksort(int arr[],int low,int high) {
if (low < high) {
int pi = partition(arr,low,high);
quicksort(arr,low,pi - 1);
quicksort(arr,pi + 1,high);
}
}

int main() {
int data[] = {10,5,75,54,6,3,5,22,86,13};
int n = sizeof(data) / sizeof(int);
quicksort(data,0,n - 1);
for (int i = 0;i < n;i++) 
printf("%d ",data[i]);
printf("\n");
return 0;
}
