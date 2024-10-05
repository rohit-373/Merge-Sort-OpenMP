#include <stdio.h>
#include <omp.h>

#define MAX_SIZE 250000

void merge(int arr[], int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortSequential(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortSequential(arr, l, m);
        mergeSortSequential(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int i, size, arr[MAX_SIZE];

    FILE *file = fopen("numbers.txt", "r");

    fscanf(file, "%d", &size);
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    double start = omp_get_wtime();
    mergeSortSequential(arr, 0, size - 1);
    double end = omp_get_wtime();

    printf("Time in sequential mode: %f seconds\n", (end - start));
    return 0;
}