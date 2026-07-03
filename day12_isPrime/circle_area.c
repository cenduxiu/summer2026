#include <stdio.h>
double circleArea(double radius) {
return 3.14159 * (radius * radius);
}
int main() {
double radius;
printf("请输入圆的半径: ");
scanf("%lf", &radius);
double S = circleArea(radius);
printf("半径为%.2lf的圆,面积为%.2lf\n",radius,S);
return 0;
}
