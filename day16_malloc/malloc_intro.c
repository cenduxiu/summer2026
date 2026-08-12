#include <stdio.h>
#include <stdlib.h>
int main() {
int *arr;
int n = 5;
arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("内存申请失败! \n");
return 1;
}
for (int i = 0;i < n;i++) {
arr[i] = i + 1;
}
printf("动态数组: ");
for (int i = 0;i < n;i++) {
printf("%d",arr[i]);
}
printf("\n");
free(arr);
arr = NULL;
return 0;
}
