#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[],int n) {
for (int i = 0;i < n - 1;i++) {
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j] > arr[j + 1]) {
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}

void bubble_sort_optimized(int arr[],int n) {
for (int i = 0;i < n - 1;i++) {
int swapped = 0;
for (int j = 0;j < n - 1 - i;j++) {
if (arr[j] > arr[j + 1]) {
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
swapped = 1;
}
}
if (!swapped) break;
}
}

void fill_random(int arr[],int n) {
for (int i = 0;i < n;i++) {
arr[i] = rand() % 10000;
}
}

void fill_sorted(int arr[],int n) {
for (int i = 0;i < n;i++) {
arr[i] = i;
}
}

void fill_reversed(int arr[],int n) {
for (int i = 0;i < n;i++) {
arr[i] = n - i;
}
}

int cmp(const void *a,const void *b) {
return (*(int *)a - *(int *)b);
}

int main() {
srand(time(NULL));
int sizes[] = {1000,5000,10000,20000};
int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
printf("===冒泡排序时间复杂度实测===\n\n");
for (int s = 0;s < num_sizes;s++) {
int n = sizes[s];
int *arr = (int *)malloc(n * sizeof(int));
int *arr_copy = (int *)malloc(n * sizeof(int));
if(arr == NULL || arr_copy == NULL) {
printf("内存分配失败!\n");
return 1;
}

clock_t start,end;
double cpu_time;

fill_random(arr,n);
memcpy(arr_copy,arr,n * sizeof(int));
start = clock();
bubble_sort(arr_copy,n);
end = clock();
cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("n=%d 随机数据(平均情况): %f秒\n",n,cpu_time);
fill_sorted(arr,n);
memcpy(arr_copy,arr,n * sizeof(int));
start = clock();
bubble_sort(arr_copy,n);
end = clock();
cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("n=%d 逆序(最坏情况): %f秒\n",n,cpu_time);
fill_random(arr,n);
memcpy(arr_copy,arr,n * sizeof(int));
start = clock();
qsort(arr_copy,n,sizeof(int),cmp);
end = clock();
cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("n=%d qsort(O(n log n)): %f秒\n\n",n,cpu_time);
free(arr);
free(arr_copy);
}

return 0;
}

