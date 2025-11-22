#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble_sort.c"
#include "insertion_sort.c"
#include "merge_sort.c"
#include "quick_sort.c"
#include "heap_sort.c"
#include "selection_sort.c"
#include "timsort.c"

typedef struct {
    double tempo;
    long long qtd_comparacoes;
    long long qtd_movimentacoes;
} Resultado;

typedef void (*AlgoritmoOrdenacao)(int*, int, long long*, long long*);

Resultado experimento(AlgoritmoOrdenacao algoritmo, int tamanho_do_array, int cenario){
    Resultado res;
    int *array = (int*)malloc(tamanho_do_array * sizeof(int));
    
    // Inicializar array conforme o cenário
    if (cenario == 1) {
        // Array já ordenado
        for (int i = 0; i < tamanho_do_array; i++) {
            array[i] = i;
        }
    } else if (cenario == 2) {
        // Array ordenado ao contrário
        for (int i = 0; i < tamanho_do_array; i++) {
            array[i] = tamanho_do_array - i;
        }
    } else {
        // Array com valores aleatórios
        srand(time(NULL));
        for (int i = 0; i < tamanho_do_array; i++) {
            array[i] = rand() % 10000;
        }
    }
    
    res.qtd_comparacoes = 0;
    res.qtd_movimentacoes = 0;
    
    // Medir tempo de execução
    clock_t inicio = clock();
    algoritmo(array, tamanho_do_array, &res.qtd_comparacoes, &res.qtd_movimentacoes);
    clock_t fim = clock();
    
    res.tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    free(array);
    return res;
}

int main(){
    // Definir algoritmos
    AlgoritmoOrdenacao algoritmos[] = {
        bubble_sort,
        insertion_sort,
        selection_sort,
        merge_sort,
        quick_sort,
        heap_sort,
        timsort
    };
    
    const char* nomes_algoritmos[] = {
        "Bubble Sort",
        "Insertion Sort",
        "Selection Sort",
        "Merge Sort",
        "Quick Sort",
        "Heap Sort",
        "TimSort"
    };
    
    int num_algoritmos = 7;
    
    // Definir tamanhos
    int tamanhos[] = {1000, 5000, 10000};
    int num_tamanhos = 3;
    
    // Definir cenários
    const char* cenarios[] = {
        "Array já ordenado",
        "Array ordenado ao contrário",
        "Array com valores aleatórios"
    };
    int num_cenarios = 3;
    
    // Abrir arquivo para escrita
    FILE *arquivo = fopen("resultados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de resultados!\n");
        return 1;
    }
    
    printf("=== EXPERIMENTO DE ALGORITMOS DE ORDENAÇÃO ===\n\n");
    fprintf(arquivo, "=== EXPERIMENTO DE ALGORITMOS DE ORDENAÇÃO ===\n\n");
    
    // Executar experimentos para cada combinação
    for (int alg = 0; alg < num_algoritmos; alg++) {
        printf("\n========== %s ==========\n", nomes_algoritmos[alg]);
        fprintf(arquivo, "\n========== %s ==========\n", nomes_algoritmos[alg]);
        
        for (int tam = 0; tam < num_tamanhos; tam++) {
            printf("\n--- Tamanho do array: %d elementos ---\n", tamanhos[tam]);
            fprintf(arquivo, "\n--- Tamanho do array: %d elementos ---\n", tamanhos[tam]);
            
            for (int cen = 1; cen <= num_cenarios; cen++) {
                printf("\nCenário: %s\n", cenarios[cen - 1]);
                fprintf(arquivo, "\nCenário: %s\n", cenarios[cen - 1]);
                
                Resultado r = experimento(algoritmos[alg], tamanhos[tam], cen);
                
                printf("  Tempo: %.6f s\n", r.tempo);
                printf("  Comparações: %lld\n", r.qtd_comparacoes);
                printf("  Movimentações: %lld\n", r.qtd_movimentacoes);
                
                fprintf(arquivo, "  Tempo: %.6f s\n", r.tempo);
                fprintf(arquivo, "  Comparações: %lld\n", r.qtd_comparacoes);
                fprintf(arquivo, "  Movimentações: %lld\n", r.qtd_movimentacoes);
            }
        }
        printf("\n");
        fprintf(arquivo, "\n");
    }
    
    printf("\n=== EXPERIMENTO CONCLUÍDO ===\n");
    fprintf(arquivo, "\n=== EXPERIMENTO CONCLUÍDO ===\n");
    
    fclose(arquivo);
    printf("\nResultados salvos em 'resultados.txt'\n");
    
    return 0;
}