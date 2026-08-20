#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void bubble(int arr[],int n) {
for (int i = 0;i < n - 1;i++) {
int swapped = 0;
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j] > arr[j + 1])
swap(arr[j],arr[j + 1]);
swapped = 1;
}
if (!swapped) return;
}
}

void choose(int arr[],int n) {
for (int i = 0;i < n - 1;i++) {
int min = i;
for (int j = i;j < n;j++) {
if (arr[j] < arr[min]) min = j;
}
if (min != i) swap(arr[min],arr[i]);
}
}

void insertion(int arr[],int n) {
for (int i = 1;i < n;i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0&&arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
}
}

int partition(int arr[],int low,int high) {
int pivot = arr[high];
int i = low;
for (int j = low;j < high;j++) {
if (arr[j] < pivot) {
swap(arr[i],arr[j]);
i++;
}
}
swap(arr[i],arr[high]);
return i;
}

void quicksort(int arr[],int low,int high) {
if (low < high) {
int pi = partition(arr,low,high);
quicksort(arr,low,pi - 1);
quicksort(arr,pi + 1,high);
}
}

void merge(int arr[],int left,int mid,int right) {
int n = right - left + 1;
int *temp = (int *)malloc(n * sizeof(int));
int i = left;
int j = mid + 1;
int k = 0;
while (i <= mid&&j <= right) {
if (arr[i] < arr[j]) temp[k++] = arr[i++];
else temp[k++] = arr[j++];
}
while (i <= mid) temp[k++] = arr[i++];
while (j <= right) temp[k++] = arr[j++];
for (int p = 0;p < n;p++) {
arr[left + p] = temp[p];
}
free(temp);
temp = NULL;
}

void mergesort(int arr[],int left,int right) {
if (left < right) {
int mid = left + (right - left) / 2;
mergesort(arr,left,mid);
mergesort(arr,mid + 1,right);
merge(arr,left,mid,right);
}
}

void print(int arr[],int n) {
for (int i = 0;i < n;i++) 
cout << arr[i] << " ";
cout << endl;
}

int main() {
int arr[] = {5,2,3,2,4,8,6};
int n = sizeof(arr) / sizeof(int);
bubble(arr,n);
print(arr,n);

choose(arr,n);
print(arr,n);

insertion(arr,n);
print(arr,n);

quicksort(arr,0,n - 1);
print(arr,n);

mergesort(arr,0,n - 1);
print(arr,n);

return 0;
}
