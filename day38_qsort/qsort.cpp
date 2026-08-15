#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[],int low,int high) {
int pivot = arr[high];
int j = low;
for (int i = low;i < high;i++) {
if (arr[i] < pivot) {
swap(arr[i],arr[j]);
j++;
}
}
swap(arr[j],arr[high]);
return j;
}

void qsort(int arr[],int low,int high) {
if (low < high) {
int pi = partition(arr,low,high);
qsort(arr,low,pi - 1);
qsort(arr,pi + 1,high);
}
}

int main() {
int arr[] = {10,5,7,3,8,9,1,2,4,6};
qsort(arr,0,9);
for (int i = 0;i < 10;i++) cout << arr[i] << " ";
cout << endl;
return 0;
}
