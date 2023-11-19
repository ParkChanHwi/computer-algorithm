#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int m, int middle, int n) {
    int* sorted = (int*)malloc((n - m + 1) * sizeof(int));
    if (sorted == NULL) {
        // Handle memory allocation failure
        exit(1);
    }

    int i = m;
    int j = middle + 1;
    int k = 0;

    // 작은 순서대로 배열에 삽입
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        }
        else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }

    // 남은 데이터
    while (i <= middle) {
        sorted[k] = a[i];
        i++;
        k++;
    }

    while (j <= n) {
        sorted[k] = a[j];
        j++;
        k++;
    }

    // 정렬된 배열을 삽입
    for (int t = 0; t < k; t++) {
        a[m + t] = sorted[t];
    }

    free(sorted); // Release the dynamically allocated memory
}

void mergesort(int a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergesort(a, m, middle);
        mergesort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}

int main(void) {
    int N;
    scanf("%d", &N);  // Read the number of elements

    int* Arr = (int*)malloc(N * sizeof(int));
    if (Arr == NULL) {
        // Handle memory allocation failure
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);  // Read each element
    }

    mergesort(Arr, 0, N - 1);

    // Print the sorted array
    for (int i = 0; i < N; i++) {
        printf("%d ", Arr[i]);
    }

    free(Arr); // Release the dynamically allocated memory

    return 0;
}
