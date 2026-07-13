#include <stdio.h>
#include <stdlib.h>
int main() {
int n;
printf("请输入数组大小: ");
scanf("%d",&n);
if (n <= 0) {
printf("大小必须为正数! \n");
return 1;
}
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("内存申请失败! \n");
return 1;
}
int sum = 0;
for (int i = 0;i < n;i++) {
printf("请输入第%d个数: ",i + 1);
scanf("%d",&arr[i]);
sum += arr[i];
}
printf("总和 = %d\n",sum);
free(arr);
arr = NULL;
return 0;
}

