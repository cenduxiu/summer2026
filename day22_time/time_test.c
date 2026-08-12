#include <stdio.h>
#include <time.h>

long sum_o1(long n) {
return n * (n + 1) / 2;
}

long sum_on(long n) {
long sum = 0;
for (long i = 1;i <= n;i++) {
sum += i;
}
return sum;
}

long sum_on2(long n) {
long sum = 0;
for (long i = 1;i <= n;i++) {
for (long j = 1;j <= i;j++) {
sum += 1;
}
}
return sum;
}

int main() {
long n = 500000;
clock_t start,end;
double cpu_time;

start = clock();
long r1 = sum_o1(n);
end = clock();
cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("O(1) 结果=%ld 耗时=%lf秒\n",r1,cpu_time);

start = clock();
long r2 = sum_on(n);
end = clock();
cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("O(n) 结果=%ld 耗时=%lf秒\n",r2,cpu_time);

start = clock();
long r3 = sum_on2(n);
end = clock();
cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("O(n2) 结果=%ld 耗时=%lf秒\n",r3,cpu_time);

return 0;
}
