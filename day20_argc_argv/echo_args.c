#include <stdio.h>
int main(int argc,char *argv[]) {
printf("总共收到%d个参数: \n",argc);
for (int i = 0;i < argc;i++) {
printf("argv[%d] = %s\n",i,argv[i]);
}
return 0;
}
