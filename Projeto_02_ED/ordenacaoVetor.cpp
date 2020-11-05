#include <iostream>
#include <fstream>
#include <chrono>
#include <stack>
#include "ordenacaoVetor.h"



void ler_dados(int n, int A[], const char *nomeArquivo) 
{	
	std::ifstream fin(nomeArquivo, std::ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor
	}
	fin.close(); // fecha o arquivo de leitura
}

void gera_dados(int num_iteracoes, const int vetor_tam[]) 
{
	for(int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "date/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
			std::ofstream fout(nome_arquivo.c_str(), std::ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[iteracao];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

// InsertionSort interativo
void insertionSort(int array[], int n){
    int i, j, key;
    // Realiza a operação enquanto j for menor que o tamanho do array
    for(j = 1; j < n; j++){
        // Key recebe o valor na posição atual
        key = array[j];
        // i que recebe a posição anteiror de j
        i = j-1;
        // Realiza o loop enquanto i não for 0 e até o valor de key ser menor que a posição atual do array
        while(i >= 0 && array[i] > key){
            array[i+1] = array[i];
            i--;
        }
        // A key atual vai para primeira posição do array
        array[i+1] = key;
    }
    
}

// InsertionSort recursivo
void insertionSort_recursive(int array[], int n){
    int key, i, j;
    // Atributo j que recebe o tamanho do array
    j = n;
    // Caso base
    // Quando n for igual a 0 não irá retornar nada
    if(n == 0){
        return;
    }
    // Chama a função
    // Impilha os dados
    insertionSort_recursive(array,n-1);
        
    // key recebe a posição anterior de j no array
    key = array[j-1];
    // Atributo i que inicialmente começa duas posições anteriores de j
    i = j-2;
    // Realiza o loop enquanto i não for 0 e até o valor de key ser menor que a posição atual do array
    while(i >= 0 && array[i] > key){
        // Desloco para a direita os elementos do array
        // Decrementa o i
        array[i+1] = array[i];
        i--;
    }
    // A key atual vai para primeira posição do array
    array[i+1] = key;
    
}

void intercala (int A[] , int p , int q , int r) {  
    int i = p;
    int j = q+1;
    int k  = 0;;  
    int *W = new(std::nothrow) int[r-p+1]; // Vetor auxilia
    if(W == nullptr){
        exit(1);
    }
    else{
        
        // Intercala A[p..q] e A[q +1.. r]
        // Caso o laço pare e ainda exista valores a serem ordenados
        // Utilizamos um mais 2 laços caso sobre valores da primeira ou da segunda parte do vetor
        // Assim o restante será ordenado
        while (i <= q && j <= r) {
            if (A[i] <= A[j]){
                W[k++] = A[i++];
            }
            else{
                W[k++] = A[j++];
            }
        }
        while (i <= q) {
            W[k++] = A[i++];
            
        }
        while (j <= r){
            W[k++] = A[j++];
        } 
        // Copia vetor ordenado W para o vetor A
        // Deleta o vetor W
        for (i = p; i <= r; i++){
            A[i] = W[i-p];
        }
        delete[] W;

    }
}

void mergeSort(int A[] , int p , int r) {
    if(p < r) {
        int q = (p + r) / 2; // Dividir
        // Conquistar
        mergeSort (A , p , q );
        mergeSort (A , q+1, r);
        // Combinar
        
        intercala (A, p, q, r);
        
    }

}
// MergeSort iterativo
// OBS: Aqui temos outro algoritmo merge que está comentado e que apresenta um pior desempenho
void mergeSort_interative(int array[], int r){  
    /*int q = (p+r) / 2;
    int i = 0;
    int v1 = 0;
    int v2 = 0;
    while(i < q){
        for(int j = 0; j <= q;j++){
            if(array[j] > array[j+1]){
                //std::swap(array[j],array[j+1]);
                v1 = array[j];
                array[j] = array[j+1];
                array[j+1] = v1;
            }
        }
        i++;
    }
    
    int t = q+1;
    int a = 0;
    while(a < t){
        for(int b = q+1; b < r;b++){
            if(array[b] > array[b+1]){
                //std::swap(array[b],array[b+1]);
                v2 = array[b];
                array[b] = array[b+1];
                array[b+1] = v2;
            }
        }
        a++;
    }
    
    intercala(array,p,q,r);*/
    int inicio, meio, fim;
    int novo_meio;
    
    // Enquanto meio for menor que o tamanho do vetor
    for(meio = 1; meio < r; meio *= 2){
        inicio = 0;
        // Enquanto a soma entre inicio e meio for menor que o tamanho do vetor
        // Atributo fim recebe o inicio + o dobro do meio meno 1
        // Caso esse valor execeda o tamanho do vetor, fim recebe n (tamanho)
        // Chama a função intercala para os valores A[inicio..fim]
        // Onde quebramos o vetor inicialmente em um vetor de n = 2 e usamos o intercala
        // Em seguido após o fim do laço mais interno, o atributo inicio dobrado de valor
        for(inicio = 0; inicio+meio < r; inicio += 2*meio){
            fim = inicio + (2*meio) - 1;
            novo_meio = (fim+inicio) / 2;
            if(fim > r){
                fim = r;
            }
            intercala(array,inicio,novo_meio,fim);
        }
    }
}

int separa(int array[], int p, int r){
    int pivot = array[r];                   //Define o pivot como o ultimo elemento
    int j = p;                              //j recebe p
    for(int k = p; k < r; k++){             //Percorre da posição p ate o final
        if(array[k] <= pivot){              //Se o vetor na posição k for menor ou igual ao pivot
            std::swap(array[k], array[j]);  //Realiza a troca
            j++;                            //Incrementa j
        }
    } 
    array[r] = array[j];                    //Joga o elemento que está apos onde foi realizada a ultima troca para o final
    array[j] = pivot;                       //E joga o pivot para o posição do elemento que foi para o final(Fazendo um switch)
    return j;                               //retorna a posição do pivot
}

void quickSortRecursive(int array[], int p, int r){
    if(p < r){  //Enquanto a posição inicial for menor que a final
        int i = separa(array, p, r);            //i recebe o indice do pivot
        quickSortRecursive(array, p, i - 1);    //Faz a chamada recursiva do incio até o indice do pivot menos 1
        quickSortRecursive(array, i + 1, r);    //Faz a chamada recursiva do indice do pivot mais 1 até o final
    }
}

void quickSortIterativo(int array[], int p, int r){
    std::stack<int> pilha;              //Cria uma pilha
    pilha.push(p);                      //Adiciona p(Indice inicial) ao topo da pilha
    pilha.push(r);                      //Adicionar r(Indice final) ao topo da pilha
    while(!pilha.empty()){              //Enquanto a pilha não estiver vazia continua executando
        r = pilha.top();                //r recebe o topo da pila
        pilha.pop();                    //Desempilha 1 elemento
        p = pilha.top();                //p recebe o topo da pila
        pilha.pop();                    //Desempilha 1 elemento
        int indice = separa(array, p, r);//Chama a função separa e guarda o indice do pivot
        if(indice - 1 > p){             //Se o indice do pivot menos 1 for maior que p
            pilha.push(p);              //Empilha p
            pilha.push(indice - 1);     //Empilha o indice do pivot menos 1
        }
        if(indice + 1 < r){             //Se o indice do pivot mais 1 for menor que r
            pilha.push(indice + 1);     //Empilha indice do pivot mais 1
            pilha.push(r);              //Empilha r
        }
    }
}

int min(int array[], int i, int n, int minimun){
    if(i == n){         //Se o vetor chegar ao final
        return minimun; //Retorna minimun
    }else{
        if(array[minimun] < array[i]){      //Se o vetor na posição minimun for menor que o etor na posição i
            min(array, i + 1, n, minimun);  //Faz a chamada recursiva incrementando a posição inicial e mantem o minimun
        }else{                              //Caso contrario
            min(array, i + 1, n, i);        //Faz a chamada recursiva incrementando a posição inicial e substitui o minimun por i        
        }
    }
}

void selectionSortRecursive(int array[], int n, int i){
    if(i == n - 1){ //Checa se o vetor chegou ao final
        return;     //retorna vazio
    }else{
        std::swap(array[min(array, i + 1, n, i)], array[i]);    //Realiza a troca do array da posição i com a array a posição min(chama a função min)
        selectionSortRecursive(array, n, i + 1);        //Faz a chamada recursiva incrementando 1 a posiçãp inicial
    }
}

void selectionSort(int array[], int n){
    for(int i = 0; i < n - 1; i++){//Faz uma laço que começa em 0 e vai ate o final do vetor
        int min = i;                //Atribui o indice do primeiro elemento a min
        for(int j = i + 1; j < n; j++){//Faz uma laço que começa em i+1 e vai ate o final do vetor
            if(array[j] < array[min]){//Compara se o elemento daquela posição é menor
                min = j;    //Atribui o indice daquela posição a min
            }
        }
        std::swap(array[i], array[min]);//Realizar a troca com min
    }
}



// Os métodos a seguir serão utilizados para mostrar o tempo médio de execução de cada algoritmo de ordenação.
// Com eles serão gerados os arquivos com os dados
// É chamado o ofstream(fluxo) para geração do arquivo .txt
// Depois é usado um laço para percorrer por cada tamanho de vetor e outro laço mais interno assim chamando a função (ler_dados) para acessar os arquivos .dat com as informações randomicas
// Depois chamamos a função e lemos quando ela começou a ser executada e quando terminar, retornamos o tempo de execução


void gera_insertion_iterative(const int vetor[], int tam){
    // Irá guardar o tempo médio o insertionSort interativos
    std::ofstream insert_interative("duracao_media/insertionSort_iterative.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_insertion_i = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_i = std::chrono::high_resolution_clock::now();

            insertionSort(n_vec, size_vec);

            auto end_i = std::chrono::high_resolution_clock::now();

            auto duracao_insertion_i = std::chrono::duration_cast<std::chrono::microseconds>(end_i-begin_i).count();

            d_m_insertion_i += duracao_insertion_i;
        }
        d_m_insertion_i = d_m_insertion_i / 5.0;
        std::cout << "[Insertion iterative] N = " << size_vec << ", tempo media de exe -> " << d_m_insertion_i <<" microssegundos \n";
        insert_interative << size_vec << " " << d_m_insertion_i << "\n";
    }
    insert_interative.close();
    
}


void gera_insertion_recursive(const int vetor[],int tam){
    
    std::ofstream insert_recursive("duracao_media/insertionSort_recursive.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_insertion_r = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_r = std::chrono::high_resolution_clock::now();

            insertionSort_recursive(n_vec, size_vec);

            auto end_r = std::chrono::high_resolution_clock::now();

            auto duracao_insertion_r = std::chrono::duration_cast<std::chrono::microseconds>(end_r-begin_r).count();

            d_m_insertion_r += duracao_insertion_r;
        }
        d_m_insertion_r = d_m_insertion_r / 5.0;
        std::cout << "[Insertion recursive] N = " << size_vec << ", tempo media de exe -> " << d_m_insertion_r <<" microssegundos \n";
        insert_recursive << size_vec << " " << d_m_insertion_r << "\n";
    }
    insert_recursive.close();
    
        
}

void gera_merge_iterative(const int vetor[], int tam){
    std::ofstream merge_recursive("duracao_media/mergeSort_iterative.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_merge_r = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_r = std::chrono::high_resolution_clock::now();

            mergeSort_interative(n_vec,size_vec);

            auto end_r = std::chrono::high_resolution_clock::now();

            auto duracao_merge_r = std::chrono::duration_cast<std::chrono::microseconds>(end_r-begin_r).count();

            d_m_merge_r += duracao_merge_r;
        }
        d_m_merge_r = d_m_merge_r / 5.0;
        std::cout << "[Merge iterative] N = " << size_vec << ", tempo media de exe -> " << d_m_merge_r <<" microssegundos \n";
        merge_recursive << size_vec << " " << d_m_merge_r << "\n";
    }
    merge_recursive.close();
}

void gera_merge_recursive(const int vetor[], int tam){
    std::ofstream merge_interative("duracao_media/mergeSort_recursive.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_merge_i = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_i = std::chrono::high_resolution_clock::now();

            mergeSort(n_vec,0 ,size_vec-1);

            auto end_i = std::chrono::high_resolution_clock::now();

            auto duracao_merge_i = std::chrono::duration_cast<std::chrono::microseconds>(end_i-begin_i).count();

            d_m_merge_i += duracao_merge_i;
        }
        d_m_merge_i = d_m_merge_i / 5.0;
        std::cout << "[Merge recursive] N = " << size_vec << ", tempo media de exe -> " << d_m_merge_i <<" microssegundos \n";
        merge_interative << size_vec << " " << d_m_merge_i << "\n";
    }
    merge_interative.close();
}

void gera_selection_iterative(const int vetor[], int tam){
    std::ofstream selec_iter("duracao_media/selectionSort_iterative.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_selec_i = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_i = std::chrono::high_resolution_clock::now();

            selectionSort(n_vec,size_vec);

            auto end_i = std::chrono::high_resolution_clock::now();

            auto duracao_selec_i = std::chrono::duration_cast<std::chrono::microseconds>(end_i-begin_i).count();

            d_m_selec_i += duracao_selec_i;
        }
        d_m_selec_i = d_m_selec_i / 5.0;
        std::cout << "[Selection iterative] N = " << size_vec << ", tempo media de exe -> " << d_m_selec_i <<" microssegundos \n";
        selec_iter << size_vec << " " << d_m_selec_i << "\n";
    }
    selec_iter.close();
}

void gera_selection_recursive(const int vetor[], int tam){
    std::ofstream selec_rec("duracao_media/selectionSort_recursive.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_selec_r = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_r = std::chrono::high_resolution_clock::now();

            selectionSortRecursive(n_vec,size_vec,0);

            auto end_r = std::chrono::high_resolution_clock::now();

            auto duracao_selec_r = std::chrono::duration_cast<std::chrono::microseconds>(end_r-begin_r).count();

            d_m_selec_r += duracao_selec_r;
        }
        d_m_selec_r = d_m_selec_r / 5.0;
        std::cout << "[Selection recursive] N = " << size_vec << ", tempo media de exe -> " << d_m_selec_r <<" microssegundos \n";
        selec_rec << size_vec << " " << d_m_selec_r << "\n";
    }
    selec_rec.close();
}

void gera_quick_iterative(const int vetor[], int tam){
    std::ofstream quick_interative("duracao_media/quickSort_iterative.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_quick_i = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_i = std::chrono::high_resolution_clock::now();

            quickSortIterativo(n_vec,0,size_vec-1);

            auto end_i = std::chrono::high_resolution_clock::now();

            auto duracao_quick_i = std::chrono::duration_cast<std::chrono::microseconds>(end_i-begin_i).count();

            d_m_quick_i += duracao_quick_i;
        }
        d_m_quick_i = d_m_quick_i / 5.0;
        std::cout << "[Quick iterative] N = " << size_vec << ", tempo media de exe -> " << d_m_quick_i <<" microssegundos \n";
        quick_interative << size_vec << " " << d_m_quick_i << "\n";
    }
    quick_interative.close();
}

void gera_quick_recursive(const int vetor[], int tam){
    std::ofstream quick_rec ("duracao_media/quickSort_recursive.txt", std::ofstream::out);
    for(int interation = 0; interation < tam; interation++){
        
        long double d_m_quick_r = 0.0;
        int size_vec = vetor[interation];
        int n_vec[size_vec];

        for(int seed = 0; seed < 5; seed++){
            std::string name_archive = "date/random"+std::to_string(interation)+"_"+std::to_string(seed)+".dat";

            ler_dados(size_vec, n_vec, name_archive.c_str());
            auto begin_r = std::chrono::high_resolution_clock::now();

            quickSortRecursive(n_vec,0,size_vec-1);

            auto end_r = std::chrono::high_resolution_clock::now();

            auto duracao_quick_r = std::chrono::duration_cast<std::chrono::microseconds>(end_r-begin_r).count();

            d_m_quick_r += duracao_quick_r;
        }
        d_m_quick_r = d_m_quick_r / 5.0;
        std::cout << "[Quick recursive] N = " << size_vec << ", tempo media de exe -> " << d_m_quick_r <<" microssegundos \n";
        quick_rec << size_vec << " " << d_m_quick_r << "\n";
    }
    quick_rec.close();
}