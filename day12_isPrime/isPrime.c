#include <stdio.h>
int isPrime(int num) {
if (num <= 1) {
return 0;
}
for (int i = 2;i < num;i++) {
if (num % i == 0) {
return 0;
}
}
return 1;
}
 
int main() {
int num;
printf("请输入一个正整数: ");
scanf("%d", &num);
int a = isPrime(num);
if (a == 1) {
printf("%d是素数\n",num);
} else {
printf("%d不是素数\n",num);
}
return 0;
}
