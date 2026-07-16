#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
if (argc != 3) {
printf("用法: %s <整数1> <整数2>\n",argv[0]);
return 1;
}
int a = atoi(argv[1]);
int b = atoi(argv[2]);
printf("%d + %d = %d\n",a,b,a + b);
return 0;
}


