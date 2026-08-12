#include <stdio.h>
#include <stdlib.h>
int *create_array(int n) {
if (n <= 0) return NULL;
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("内存申请失败! \n");
return NULL;
}
for (int i = 0;i < n;i++) {
printf("请输入第%d个数: ",i + 1);
scanf("%d",&arr[i]);
}
return arr;
}
void print_array(int *arr,int n) {
for (int i = 0;i < n;i++) {
printf("%d\n",arr[i]);
}
printf("\n");
}
void free_array(int **arr) {
if (*arr != NULL) {
free(*arr);
*arr = NULL;
}
}
int main() {
int n;
printf("请输入正整数: ");
scanf("%d",&n);
int *data = create_array(n);
if (data == NULL) {
return 1;
}
print_array(data,n);
free_array(&data);
if (data == NULL) {
printf("内存已释放，指针已置空\n");
}
return 0;
}
