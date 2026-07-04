#include <stdio.h>
void badSwap(int a,int b) {
int temp = a;
a = b;
b = temp;
printf("badSwap内部: a = %d,b = %d\n",a,b);
}
int main() {
int x = 10;
int y = 20;
printf("调用前: x = %d,y = %d\n",x,y);
badSwap(x,y);
printf("调用后: x = %d,y = %d\n",x,y);
return 0;
}
