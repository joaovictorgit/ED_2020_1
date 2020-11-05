#ifndef ORDENACAO_VETOR_H
#define ORDENACAO_VETOR_H
    // Métodos de ordenação
    void insertionSort(int array[], int n);
    void insertionSort_recursive(int array[], int n);
    void mergeSort(int array[], int p, int r);
    void mergeSort_interative(int array[], int r);
    void selectionSort(int array[], int n);
    void selectionSortRecursive(int array[], int n, int i);
    void quickSortIterativo(int array[], int p, int r);
    void quickSortRecursive(int array[], int p, int r);
    // Métodos auxiliares
    void intercala(int array[], int p, int q, int r);
    int min(int array[], int i, int n, int minimun);
    int separa(int array[], int p, int r);
    // Métodos de gerar e ler dados
    void gera_dados(int num_iteracoes, const int vetor_tam[]);
    void ler_dados(int n, int A[], const char *nomeArquivo);
    // Métodos do tempo médio dos algoritmos de ordenação
    void gera_insertion_iterative(const int vetor[], int tam);
    void gera_insertion_recursive( const int vetor[],int tam);
    void gera_merge_iterative(const int vetor[], int tam);
    void gera_merge_recursive(const int vetor[], int tam);
    void gera_selection_iterative(const int vetor[], int tam);
    void gera_selection_recursive(const int vetor[], int tam);
    void gera_quick_iterative(const int vetor[], int tam);
    void gera_quick_recursive(const int vetor[], int tam);

#endif