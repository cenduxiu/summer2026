#include <stdio.h>
void greet(char name[]) {
printf("你好， %s! \n",name);
}

int main() {
greet("独秀");
greet("张三");
greet("爱因斯坦");
return 0;
}
