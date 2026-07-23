#include <stdio.h>
int main() {
int num;
printf("请输入一个整数: ");
scanf("%d", &num);
if (num % 2 == 0) {
printf("%d是偶数\n", num);
} else {
printf("%d是奇数\n", num);
}

int year;
printf("请输入年份: ");
scanf("%d", &year);
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
printf("%d是闰年\n", year);
} else {
printf("%d不是闰年\n", year);
}

int a, b, c, max;
printf("请输入3个整数（用空格隔开）：");
scanf("%d %d %d", &a, &b, &c);
max = a;
if (b > max) max = b;
if (c > max) max = c;
printf("最大值是: %d\n", max);

int x, y;
printf("请输入x: ");
scanf("%d", &x);
if (x < 0) {
y = -x;
} else if (x < 10) {
y = x * x;
} else {
y = 2 * x + 1;
}
printf("y = %d\n", y);

return 0;
}
