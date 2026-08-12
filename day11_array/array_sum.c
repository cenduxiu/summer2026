#include <stdio.h>
int main() {
int arr[5],sum = 0;
double average;
printf("请输入5个整数: \n");
for (int i = 0;i < 5;i++) {
printf("第%d个整数: ",i + 1);
scanf("%d",&arr[i]);
}
for (int i = 0;i < 5;i++) {
sum += arr[i];
}
average = (double)sum / 5;
printf("总和= %d\n平均值= %.2lf\n",sum,average);
return 0;
}
