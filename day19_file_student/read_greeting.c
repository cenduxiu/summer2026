#include <stdio.h>
int main() {
FILE *fp = fopen("greeting.txt","r");
if (fp == NULL) {
printf("文件打开失败! \n");
return 1;
}
char line[100];
while (fgets(line,sizeof(line),fp) != NULL) {
printf("读到: %s",line);
}
fclose(fp);
return 0;
}
