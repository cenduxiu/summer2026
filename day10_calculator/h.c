#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;

    printf("请输入第一个数字：");
    scanf("%lf", &num1);

    printf("请输入运算符（+ - * /）：");
    scanf(" %c", &op);

    printf("请输入第二个数字：");
    scanf("%lf", &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            
        case '/':
            if (num2 == 0) {
                printf("错误：除数不能为0！\n");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            
        default:
            printf("错误：无效的运算符！\n");
    }

    return 0;
}
