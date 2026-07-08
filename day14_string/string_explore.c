
#include <stdio.h>
int main() {
char str[] = "Hello";

printf("字符串: %s\n", str);
printf("逐个字符遍历: \n");

for (int i = 0;str[i] != '\0';i++) {
printf("str[%d] = '%c' ASCII码 = %d\n",i,str[i],str[i]);
}
//验证\0的存在
printf("\n\\0的ASCII码 = %d\n",str[5]);
return 0;
}
