#include <stdio.h>
void reverse_array(int *arr,int len) {
int *left = arr;
int *right = arr + len - 1;
while (left < right) {
int temp = *left;
*left = *right;
*right = temp;
left++;
right--;
}
}
int main() {
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int len = sizeof(arr) / sizeof(arr[0]);
printf("反转前: ");
for (int i = 0;i < len;i++) {
printf("%d",*(arr + i));
}
printf("\n");
reverse_array(arr,len);
printf("反转后: ");
for (int i = 0;i < len;i++) {
printf("%d",*(arr + i));
}
printf("\n");
return 0;
}










