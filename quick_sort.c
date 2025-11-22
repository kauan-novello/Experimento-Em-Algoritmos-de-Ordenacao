#include <stdio.h>
#include <stdlib.h>

long long *global_comparacoes_q;
long long *global_movimentacoes_q;

void swap_q(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        (*global_comparacoes_q)++;
        if (arr[j] < pivot) {
            i++;
            swap_q(&arr[i], &arr[j]);
            (*global_movimentacoes_q) += 3;
        }
    }
    swap_q(&arr[i + 1], &arr[high]);
    (*global_movimentacoes_q) += 3;
    return (i + 1);
}

void quickSortRec(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSortRec(arr, low, pi - 1);
        quickSortRec(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int n, long long *comparacoes, long long *movimentacoes) {
    global_comparacoes_q = comparacoes;
    global_movimentacoes_q = movimentacoes;
    quickSortRec(arr, 0, n - 1);
}


