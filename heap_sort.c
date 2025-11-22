#include <stdio.h>
#include <stdlib.h>

long long *global_comparacoes_h;
long long *global_movimentacoes_h;

void swap_h(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n) {
        (*global_comparacoes_h)++;
        if (arr[left] > arr[largest])
            largest = left;
    }
    
    if (right < n) {
        (*global_comparacoes_h)++;
        if (arr[right] > arr[largest])
            largest = right;
    }
    
    if (largest != i) {
        swap_h(&arr[i], &arr[largest]);
        (*global_movimentacoes_h) += 3;
        heapify(arr, n, largest);
    }
}

void heapSortInternal(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap_h(&arr[0], &arr[i]);
        (*global_movimentacoes_h) += 3;
        heapify(arr, i, 0);
    }
}

void heap_sort(int arr[], int n, long long *comparacoes, long long *movimentacoes) {
    global_comparacoes_h = comparacoes;
    global_movimentacoes_h = movimentacoes;
    heapSortInternal(arr, n);
}


