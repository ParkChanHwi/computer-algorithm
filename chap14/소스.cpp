#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG Fibonacci(int n) {
	int i;
	ULONG Result;
	ULONG* FibonacciTable;

	if (n == 0 || n == 1)
		return n;

	FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (n + 1));

	FibonacciTable[0] = 0;
	FibonacciTable[1] = 1;

	for (i = 2; i <= n; i++) {

		FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
	}

	Result = FibonacciTable[n];

	free(FibonacciTable);

	return Result;

}

int main(void) {
	int n = 46;
	ULONG Result = Fibonacci(n);

	printf("Fibonacci(%d) = %lu \n", n, Result);

}