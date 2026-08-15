#include <iostream>
using namespace std;

void bubble(int arr[],int n) {
for (int i = 0;i < n - 1;i++) {
int swap = 0;
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j] > arr[j + 1]) {
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swap = 1;
}
}
if (!swap) return;
}
}

void choose(int arr[],int n) {
for (int i = 0;i < n - 1;i++) {
int min = i;
for (int j = i + 1;j < n;j++) {
if (arr[min] > arr[j]) min = j;
}
if (min != i) {
int temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
}
}
}


void add_sort(int arr[],int n) {
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

void cout_sort(int arr[],int n) {
for (int i = 0;i < n;i++) cout << arr[i] << " ";
cout << endl;
}
 
int main() {
int data[] = {5,3,1,2,8};
int n = sizeof(data) / sizeof(int);

bubble(data,n);
cout_sort(data,n);

choose(data,n);
cout_sort(data,n);

add_sort(data,n);
cout_sort(data,n);

return 0;
}

