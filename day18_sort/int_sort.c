#include <stdio.h>
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
int main() {
int nums[] = {5,3,8,1,9,2};
int n = sizeof(nums) / sizeof(nums[0]);
printf("排序前: ");
for (int i = 0;i < n;i++) {
printf("%d ",nums[i]);
}
printf("\n");
bubble_sort(nums,n);
printf("排序后: ");
for (int i = 0;i < n;i++) {
printf("%d ",nums[i]);
}
printf("\n");
return 0;
}
