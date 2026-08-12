#include <stdio.h>
#include <math.h>

int main() {
long ns[] = {10,100,1000,10000};
int sizes = sizeof(ns) / sizeof(ns[0]);

printf("n\tO(1)\tO(log n)\tO(n)\tO(n log n)\tO(n2)\n");
for (int i = 0;i < sizes;i++) {
long n = ns[i];
printf("%ld\t1\t%ld\t\t%ld\t%ld\t\t%ld\n",n,(long)(log2(n)),n,(long)(n * log2(n)),n * n);
}
return 0;
}
