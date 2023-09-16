#include <stdio.h>


int DP_count = 1;
int RE_count = 1;
int fib(int n);


int fibonacci(int n, int* a);

int main() {
	int input = 0;
	int array[41] = {0}; // 40과 초기화 안해서 틀렸었다.
	
	scanf_s("%d", &input);


	fibonacci(input, array);
	fib(input);
	printf("%d %d", RE_count, DP_count);
}

int fib(int n) {
	
	if (n == 1 or n == 2) {
		return 1;
	}
	else {
		RE_count++;
		return (fib(n - 1) + fib(n - 2));
	}
}

int fibonacci(int n, int* a) {
	if (n < 2) {
		
		return a[n] = n;
	}
	if (a[n] > 0) {
		DP_count++;
		return a[n];
	}

	a[n] = fibonacci(n-1,a) + fibonacci(n-2,a);
	
	return a[n];
}
