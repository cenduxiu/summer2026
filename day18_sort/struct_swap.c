#include <stdio.h>
typedef struct{
int x;
int y;
}Point;
int main() {
Point p1 = {3,5};
Point p2 = {7,2};
printf("交换前: p1=(%d,%d) p2=(%d,%d)\n",p1.x,p1.y,p2.x,p2.y);
Point temp = p1;
p1 = p2;
p2 = temp;
printf("交换后: p1=(%d,%d) p2=(%d,%d)\n",p1.x,p1.y,p2.x,p2.y);
return 0;
}
