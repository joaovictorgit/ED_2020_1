#include <iostream>
#include <fstream>
#include <chrono>
#include "ordenacaoVetor.h"
using namespace std;

/*Dupla:
João Victor de Almeida Félix - 0476849
Rayrisson Vinicius Alves de Lima - 0472050
*/

/*
No arquivo "main.cpp" será implementado métodos auxiliares que irão imprimir os resultados do tempo médio de executação 
dos algoritmos de ordenação que irão utilizar os valores do array(vetor) que irá pegar cada valor e gerar 5 sementes com 
números aleatório com o tamanho proporcional ao valor na posição do array(vetor). Os dados serão gravados em arquivos ".dat" 
que serão lidos e nesse momento que usaremos as funções iterativas e recursiva dos algoritmos propostos no pdf para que possamos 
mostrar o desempenho desses algoritmos e mostrar qual é melhor. Na main teremos apenas o array(vetor), seu tamanho e a chamada das 
funções que serão responsável pelas operações de gerar, ler os dados, ordenar o valores e mostrar o tempo médio ao qual o array 
foi ordenado.
*/
int main(){
    
    int tam = 0;
    //
    const int vetor[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,
	    10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
    // Atributo que guarda o tamanho do vetor
    tam = sizeof(vetor)/sizeof(vetor[0]);
    
    // Irá gerar números aleatórios
    // Cada posição do vetor será um novo vetor de tamanho vetor[i] que irá gerar números randonicos
    gera_dados(tam, vetor);
    // Mostra o tempo médio do InsertionSort iterativo
    gera_insertion_iterative(vetor, tam);
    // Mostra o tempo médio do InsertionSort recursivo
    gera_insertion_recursive(vetor, tam);
    // Mostra o tempo médio do SelectionSort iterativo
    gera_selection_iterative(vetor,tam);
    // Mostra o tempo médio do SelectionSort recursivo
    gera_selection_recursive(vetor,tam);
    // Mostra o tempo médio do MergeSort iterativo
    gera_merge_iterative(vetor,tam);
    // Mostra o tempo médio do MergeSort recursivo
    gera_merge_recursive(vetor,tam);
    // Mostra o tempo médio do QuickSort iterativo
    gera_quick_iterative(vetor,tam);
    // Mostra o tempo médio do QuickSort recursivo
    gera_quick_recursive(vetor,tam);
    return 0;
}