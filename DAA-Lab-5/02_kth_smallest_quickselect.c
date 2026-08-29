#include <stdio.h>

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

int quickSelect(int a[], int low, int high, int k) {
    if (low <= high) {
        int p = partition(a, low, high);

        if (p == k)
            return a[p];

        if (k < p)
            return quickSelect(a, low, p - 1, k);

        return quickSelect(a, p + 1, high, k);
    }

    return -1;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 0;
    }

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid K. K must be between 1 and N.\n");
        return 0;
    }

    int answer = quickSelect(a, 0, n - 1, k - 1);

    printf("%dth smallest element = %d\n", k, answer);

    return 0;
}
