#include <stdio.h>
int isPrime(int num) {
if (num <= 1) {
return 0;
}
for (int i = 2;i * i < num;i++) {
if (num % i == 0) {
return 0;
}
}
return 1;
}
int main() {
int num;
for (int num = 1;num < 101;num++) {
if (isPrime(num)) {
printf("%d\t",num);
}
}
return 0;
}
