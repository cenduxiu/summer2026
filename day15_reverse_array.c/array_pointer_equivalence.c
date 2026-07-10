#include <stdio.h>
int main() {
int arr[5] = {10,20,30,40,50};
int *p = arr;
printf("===下标法===\n");
for (int i = 0;i < 5;i++) {
printf("arr[%d] = %d\n",i,arr[i]);
}
printf("\n===指针偏移法===\n");
for (int i = 0;i < 5;i++) {
printf("arr[%d] = %d\n",i,*(arr + i));
}
printf("\n===通过指针遍历===\n");
for (int i = 0;i < 5;i++) {
printf("*(p + %d) = %d\n",i,*(p + i));
}
printf("\n===sizeo对比===\n");
printf("sizeof(arr) = %lu\n",sizeof(arr));
printf("sizeof(p) = %lu\n",sizeof(p));
return 0;
}
