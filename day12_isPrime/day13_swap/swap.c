#include <stdio.h>
void swap(int *a,int *b) {
int c = *a;
*a = *b;
*b = c;
}
int main() {
int x = 10;
int y = 20;
printf("原本x = %d,y = %d\n",x,y);
swap(&x,&y);
printf("现在x = %d,y = %d\n",x,y);
return 0;
}
