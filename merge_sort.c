#include <stdio.h>
#include <stdlib.h>

long long *global_comparacoes;
long long *global_movimentacoes;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        (*global_comparacoes)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*global_movimentacoes)++;
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        (*global_movimentacoes)++;
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        (*global_movimentacoes)++;
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSortRec(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSortRec(arr, l, m);
        mergeSortRec(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

void merge_sort(int arr[], int n, long long *comparacoes, long long *movimentacoes) {
    global_comparacoes = comparacoes;
    global_movimentacoes = movimentacoes;
    mergeSortRec(arr, 0, n - 1);
}


