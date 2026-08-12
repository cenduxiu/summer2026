#include <stdio.h>
int main() {
int arr[10];
printf("请输入10个整数: \n");
for (int i = 0;i < 10;i++) {
printf("第%d个整数: ",i + 1);
scanf("%d",&arr[i]);
}
int max = arr[0];
int min = arr[0];
for (int i = 0;i < 10;i++) {
if (arr[i] > max) {
max = arr[i];
}
if (arr[i] < min) {
min = arr[i];
}
}
printf("最大值: %d\n最小值: %d\n",max,min);
return 0;
}
