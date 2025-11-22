# Experimento de Algoritmos de Ordenação

Implementação e análise comparativa de 7 algoritmos de ordenação clássicos em C, medindo desempenho em diferentes cenários e tamanhos de entrada.

## 🎯 Algoritmos Implementados

- **Bubble Sort** - Algoritmo simples de comparação adjacente
- **Insertion Sort** - Ordenação por inserção
- **Selection Sort** - Ordenação por seleção
- **Merge Sort** - Divisão e conquista (O(n log n))
- **Quick Sort** - Particionamento recursivo
- **Heap Sort** - Baseado em heap binário
- **TimSort** - Híbrido (Merge + Insertion), usado no Python/Java

## 📊 Métricas Coletadas

Para cada algoritmo, o experimento mede:
- ⏱️ **Tempo de execução** (em segundos)
- 🔍 **Número de comparações** entre elementos
- 🔄 **Número de movimentações** de dados

## 🧪 Cenários de Teste

Os algoritmos são testados em 3 cenários diferentes:
1. **Array já ordenado** - Melhor caso para alguns algoritmos
2. **Array ordenado ao contrário** - Pior caso para vários algoritmos
3. **Array com valores aleatórios** - Caso médio realista

## 📏 Tamanhos de Entrada

- 1.000 elementos
- 5.000 elementos
- 10.000 elementos

## 🚀 Como Executar

```bash
# Compilar
gcc -o experimento main.c -lm

# Executar
./experimento

# Resultados salvos em resultados.txt
