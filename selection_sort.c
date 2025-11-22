#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n, long long *comparacoes, long long *movimentacoes) {
    int i, j, min_idx;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*movimentacoes) += 3;
        }
    }
}


