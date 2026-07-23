#include <stdio.h>
int my_strlen(char str[]) {
int count = 0;
while (str[count] != '\0') {
count++;
}
return count;
}
void my_strcpy(char dest[],char src[]) {
int i = 0;
while (src[i] != '\0') {
dest[i] = src[i];
i++;
}
dest[i] = '\0';
}
int main() {
char test[] = "Hello,World!";
char buffer[50];
int len1 = my_strlen(test);
printf("字符串： \"%s\"\n",test);
printf("my_strlen长度: %d\n",len1);
my_strcpy(buffer,test);
printf("\n复制后的字符串: \"%s\"\n",buffer);
char empty[] = "";
printf("\n空字符串长度: %d\n",my_strlen(empty));
return 0;
}
