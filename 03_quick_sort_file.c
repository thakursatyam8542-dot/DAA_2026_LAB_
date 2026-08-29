#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    int a[n];

    FILE *fp = fopen("numbers.txt", "w");

    if (fp == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    printf("Random elements:\n");

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        fprintf(fp, "%d ", a[i]);
        printf("%d ", a[i]);
    }

    fclose(fp);

    fp = fopen("numbers.txt", "r");

    if (fp == NULL) {
        printf("\nUnable to open file for reading.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    quickSort(a, 0, n - 1);

    printf("\nSorted elements:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
