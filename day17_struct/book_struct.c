#include <stdio.h>
#include <string.h>
struct Book {
char title[100];
char author[50];
float price;
};
int main() {
struct Book book1;
strcpy(book1.title,"C Primer Plus");
strcpy(book1.author,"Stephen Prata");
book1.price = 79.0;
printf("书名: %s\n",book1.title);
printf("作者: %s\n",book1.author);
printf("价格: %.2f\n",book1.price);
return 0;
}
