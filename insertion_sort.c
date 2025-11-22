#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n, long long *comparacoes, long long *movimentacoes) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        (*movimentacoes)++;
        
        while (j >= 0 && arr[j] > key) {
            (*comparacoes)++;
            arr[j + 1] = arr[j];
            (*movimentacoes)++;
            j = j - 1;
        }
        if (j >= 0) (*comparacoes)++;
        arr[j + 1] = key;
        (*movimentacoes)++;
    }
}


