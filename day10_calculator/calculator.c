#include <stdio.h>
int main() {
double num1, num2, result;
char operator;
printf("请输入第一个数字: ");
scanf("%lf", &num1);
printf("请输入运算符(+, -, *, /) : ");
scanf(" %c", &operator);
printf("请输入第二个数字: ");
scanf("%lf", &num2);
if (operator == '+') {
result = num1 + num2;
} else if (operator == '-') {
result = num1 - num2;
} else if (operator == '*') { 
result = num1 * num2;
} else if (operator == '/') {
if (num2 == 0) {
printf("错误：除数不能为0! \n");
} else {
result = num1 / num2;
}
} else {
printf("错误：无效的运算符! \n");
}
printf("%lf %c %lf = %-2lf\n", num1, operator, num2, result);
return 0;
}
