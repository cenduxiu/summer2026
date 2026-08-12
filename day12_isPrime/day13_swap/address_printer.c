#include <stdio.h>
int main() {
int a = 10;
double b = 3.14;
char c = 'X';
int *pa = &a;
double *pb = &b;
char *pc = &c;
printf("a的值: %d,a的地址: %p\n",a,&a);
printf("b的值: %lf,b的地址: %p\n",b,&b);
printf("c的值: %c,c的地址: %p\n",c,&c);
printf("pa的值: %p,pa指向的值: %d,pa自身的地址: %p\n",pa,*pa,&pa);
printf("pb的值: %p,pb指向的值: %lf,pb自身的地址: %p\n",pb,*pb,&pb);
printf("pc的值: %p,pc指向的值: %c,pc自身的地址: %p\n",pc,*pc,&pc);
return 0;
}

