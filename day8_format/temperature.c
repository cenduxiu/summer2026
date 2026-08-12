#include <stdio.h>

int main() {
	float fahrenheit, celsius;
	printf("qingshuruhuashiwendu: ");
	scanf("%f",&fahrenheit);
	celsius = (fahrenheit - 32) * 5.0 / 9.0;
	printf("%.1fhuashidu = %.1f sheshidu\n",fahrenheit, celsius);

	return 0;
}
