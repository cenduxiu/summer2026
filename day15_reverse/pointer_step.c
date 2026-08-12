#include <stdio.h>
int main() {
int arr[3] = {1,2,3};
double darr[3] = {1.0,2.0,3.0};
char carr[3] = {'A','B','C'};
printf("int数组: \n");
printf("arr = %p\n",arr);
printf("arr + 1 = %p\n",arr + 1);
printf("步长 = %ld字节\n\n",((arr + 1) - arr)*sizeof(int));
printf("double数组: \n");
printf("darr = %p\n",darr);
printf("darr + 1 = %p\n",darr + 1);
printf("步长 = %ld字节\n\n",((darr + 1) - darr)*sizeof(double));
printf("char数组: \n");
printf("carr = %p\n",carr);
printf("carr + 1 = %p\n",carr + 1);
printf("步长 = %ld字节\n",((carr + 1) - carr))*sizeof(char);
return 0;
} 
