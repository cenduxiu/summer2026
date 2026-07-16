#include <stdio.h>
int main() {
FILE *fp = fopen("greeting.txt","w");
if (fp == NULL) {
printf("文件打开失败! \n");
return 1;
}
fprintf(fp,"Hello,独秀! \n");
fprintf(fp,"这是第19天的练习。\n");
fprintf(fp,"文件操作其实没有那么难。\n");
fclose(fp);
printf("写入完成! \n");
return 0;
}
