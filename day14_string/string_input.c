#include <stdio.h>
int main() {
char line[20];
printf("请输入一行文字: ");
fgets(line,sizeof(line),stdin);
printf("用%%s打印: %s\n",line);
printf("逐个字符打印: ");
for (int i = 0;line[i] != '\0';i++) {
if  (line[i] =='\n') {
printf("'\\n'");
} else {
printf("'%c'",line[i]);
}
}
printf("\n");
return 0;
}
