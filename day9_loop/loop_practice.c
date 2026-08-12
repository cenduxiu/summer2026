#include <stdio.h>
int main() {
printf("1到100: ");
for (int i = 1; i <= 100; i++) {
printf("%d",i);
}
printf("\n\n");

int sum = 0, j = 1;
while (j <= 100) {
sum += j;
j++;
}
printf("1到100的和: %d\n\n",sum);

printf("100以内的偶数: ");
for (int k = 1; k <= 100; k++) {
if (k % 2 == 0) {
printf("%d", k);
}
}
printf("\n\n");

int n, factorial = 1;
printf("请输入一个正整数n: ");
scanf("%d", &n);
for (int m = 1;m <= n; m++) {
factorial *= m;
}
printf("%d的阶乘 = %d\n", n, factorial);

return 0;
}
