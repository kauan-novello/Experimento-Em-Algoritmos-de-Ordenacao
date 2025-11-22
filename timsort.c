#include <stdio.h>
#include <stdlib.h>

#define RUN 32
#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long *global_comparacoes_t;
long long *global_movimentacoes_t;

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        (*global_movimentacoes_t)++;
        
        while (j >= left && arr[j] > key) {
            (*global_comparacoes_t)++;
            arr[j + 1] = arr[j];
            (*global_movimentacoes_t)++;
            j--;
        }
        if (j >= left) (*global_comparacoes_t)++;
        arr[j + 1] = key;
        (*global_movimentacoes_t)++;
    }
}

void merge_tim(int arr[], int l, int m, int r) {
    int len1 = m - l + 1;
    int len2 = r - m;
    
    int *left = (int*)malloc(len1 * sizeof(int));
    int *right = (int*)malloc(len2 * sizeof(int));
    
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    
    while (i < len1 && j < len2) {
        (*global_comparacoes_t)++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        (*global_movimentacoes_t)++;
        k++;
    }
    
    while (i < len1) {
        arr[k] = left[i];
        (*global_movimentacoes_t)++;
        i++;
        k++;
    }
    
    while (j < len2) {
        arr[k] = right[j];
        (*global_movimentacoes_t)++;
        j++;
        k++;
    }
    
    free(left);
    free(right);
}

void timSortInternal(int arr[], int n) {
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, MIN((i + RUN - 1), (n - 1)));
    
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = MIN((left + 2 * size - 1), (n - 1));
            
            if (mid < right)
                merge_tim(arr, left, mid, right);
        }
    }
}

void timsort(int arr[], int n, long long *comparacoes, long long *movimentacoes) {
    global_comparacoes_t = comparacoes;
    global_movimentacoes_t = movimentacoes;
    timSortInternal(arr, n);
}


