#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int arr[],int left,int mid,int right) {
int n = right - left + 1;
int *temp = (int *)malloc(n * sizeof(int));
if (!temp) {
cout << "内存分配失败" << endl;
return;
}
int i = left;
int j = mid + 1;
int k = 0;
while (i <= mid&&j <= right) {
if (arr[i] < arr[j])
temp[k++] = arr[i++];
else temp[k++] = arr[j++];
}
while (i <= mid) temp[k++] = arr[i++];
while (j <= right) temp[k++] = arr[j++];
for (int p = 0;p < n;p++) arr[left + p] = temp[p];
free(temp);
}

void mergesort(int arr[],int left,int right) {
if(left >= right) return;
int mid = left + (right - left) / 2;
mergesort(arr,left,mid);
mergesort(arr,mid + 1,right);
merge(arr,left,mid,right);
}

int main() {
int data[] = {2,3,5,7,33,86,24,64,7,34,66,23};
int n = sizeof(data) / sizeof(int);
mergesort(data,0,n - 1);
for (int i = 0;i < n;i++) cout << data[i] << " ";
cout << endl;
return 0;
}
