#include <stdio.h>
#include <stdlib.h>
void printArray(int A[], int size);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main() {
    int arr[] = {1, 4, 2, 5, 6, 3};
    int size = 6;

    printf("Given array: \n");
    printArray(arr, 6);

    mergeSort(arr, 0, 5);

    printf("Sorted array: \n");
    printArray(arr, 6);
    return 0;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        printArray(arr, 6);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge temp arrays back into final array
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Add all elements of L & R arrays back
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d \t", A[i]);
    }
    printf("\n");
}
