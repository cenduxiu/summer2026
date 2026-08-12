#include <stdio.h>
int main() {
int arr[3] = {10,20,30};
int *p = arr;
printf("下标法: \n");
for (int i = 0;i < 3;i++) {
printf("arr[%d] = %d\n",i,arr[i]);
}
printf("指针飘移法: \n");
for (int i = 0;i < 3;i++) {
printf("*(p + %d) = %d\n",i,*(p + i));
}
return 0;
}
