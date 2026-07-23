#include <stdio.h>
int main() {
int arr[5] = {1,2,3,4,5};
for (int i = 0;i < 5;i++) {
printf("arr[%d] = %d,地址 = %p\n",i,arr[i],&arr[i]);
}
return 0;
}
