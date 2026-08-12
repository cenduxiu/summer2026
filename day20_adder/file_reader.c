#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc,char *argv[]) {
if (argc < 2) {
printf("用法: %s [-n] [-c] <文件名>\n",argv[0]);
printf("-n 显示行号\n");
printf("-c 显示每行字符数\n");
return 1;
}
int show_line_num = 0;
int show_char_count = 0;
char *filename = NULL;

for (int i = 1;i < argc;i++) {
if (strcmp(argv[i],"-n") == 0) {
show_line_num = 1;
} else if (strcmp(argv[i],"-c") == 0) {
show_char_count = 1;
} else {
filename = argv[i];
}
}
if (filename == NULL) {
printf("错误:未指定文件名\n");
return 1;
}
FILE *fp = fopen(filename,"r");
if (fp == NULL) {
printf("错误:无法打开文件%s\n",filename);
return 1;
}
char line[MAX_LINE];
int line_num = 0;
while (fgets(line,sizeof(line),fp) != NULL) {
line_num++;
if (show_line_num && show_char_count) {
printf("%4d [%3lu] %s",line_num,strlen(line),line);
} else if (show_line_num) {
printf("%4d %s",line_num,line);
} else if (show_char_count) {
printf("[%lu] %s",strlen(line),line);
} else {
printf("%s",line);
}
}
fclose(fp);
return 0;
}
