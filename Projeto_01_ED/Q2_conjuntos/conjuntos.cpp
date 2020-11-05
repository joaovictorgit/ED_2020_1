#include <iostream>
#include <climits>
#include "conjuntos.h"

struct Node{
    int value;      // Atributo que irá guardar o valor do Node
    Node* next;     // Ponteiro next que aponta para o próximo Node
    Node* back;     // Ponteiro back que aponta para o Node anterior
};

// Construtor
Conjunto::Conjunto(){
    // Chama o método criarConjVazio para criar Conjuntos
    criaConjVazio();
}
// Cria um Conjunto Vazio e retorna o Conjunto
void Conjunto::criaConjVazio(){
    
    head = new (std::nothrow) Node; // cria um novo Node

    // Verificamos se o novo Node for igual a nullptr
    if(head == nullptr){
        std::cout << "fail\n";
        exit(1);
    }

    /* Faz com os ponteiros next e back apontem para head 
    inicialmente caracterizando a lista circular duplamente encadeada*/
    head->next = head;
    head->back = head;
    // Incializamos o Conjunto com tamanho 0
    _size = 0;
    std::cout << "Conjunto criado!\n";

    
}

// Destrutor
Conjunto::~Conjunto(){
    // Limpamos a lista caso não esteja vaiza
    if(!isEmpty()){
        clear();        // limpa o Conjunto(lista) deixando apenas o head
    }
    delete head;    // libera a memória que havia sido alocada para head
    std::cout << "Conjunto destruido!\n";
}

// Método clear que apaga todos os Node exceto o head;
void Conjunto::clear(){
    // Verifica se o Conjunto está vazio
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }
    else{
        // Criamos um Node aux que aponta para o último elemento do Conjunto
        Node* aux = head->back;
        // Criamos um Node ant que aponta para o aux
        Node* ant = aux;
        // Enquanto o aux não aponta para head
        while(aux != head){
            aux = aux->back;    // Faz aux apontar para seu antecessor
            delete ant;         // Deleto o Node ant
            ant = aux;          // Faz o ant apontar para o aux
        }
        // No final sempre fazemos head->next e head->back apontar para o próprio head
        head->next = head;
        head->back = head;
       
    }
}

// Método que verifica se a lista está vazia
bool Conjunto::isEmpty(){
    // Verifica se o ponteiro next da cabeça aponta para ele mesma
    // Caso seja verddadeiro quer dizer que a lista está vazia
    return (head->next == head ? true : false);
}

int Conjunto::size(){
    // Ponteiro do tipo Node que aponta para o próximo nó após a cabeça
    Node* aux = head->next;
    // Atributo soma que guardará o tamanho da lista
    int soma = 0;
    // Enquanto o Node aux não apontar para a cabeça do Conjunto
    while(aux != head){
        soma++;             // Incrementa em 1 no atributo soma
        aux = aux->next;    // Faz o aux apontar para o próximo nó
    }
    // Atributo da classe Conjunto recebe o atributo soma
    _size = soma;
    // Retorno o tamanho do Conjunto
    return _size;
}

/* Método que retorna true caso o Node exista no conjunto. 
Retorna false caso key não esteja no Conjunto.
*/
bool Conjunto::search(int key){
    // Node aux que recebe head->next
    Node* aux = head->next;

    // Caso o ponteiro next de head aponte para a head então retorna falso
    if(head->next == head){
        return false;
    }else{
        // Enquanto aux não apontar para a cabeça do Conjunto
        while(aux != head){
            // Se o valor do Node aux for igual á key retorna true e para o while
            if(aux->value == key){
                return true;
                break;
            }
            // Caso contário, faz o aux apontar para o próximo até encontrar o key
            aux = aux->next ;
        }
    }
    // Se não encontrou o key no Conjunto, então retorna falso
    return false ;
}

// Insere um inteiro key ao final da lista
Conjunto* Conjunto::insere(int key, Conjunto* A){
    Node* novo = new Node;  // cria um novo Node
    novo->value = key;      
    // Criamos o Node aux que ponta para o último elemento da lista
    Node* aux = A->head->back;
    // Verificamos por meio da função search2 se o valor não está na lista, caso esteja ele não adiciona o valor
    if(!A->search(novo->value)){
        // A partir daqui verificamos dois casos
        // Caso esteja vazia adicionamos o primeiro elemento da lista
        if(A->isEmpty()){
            // Fazemos que head->next aponte para o novo Node
            // Depois fazemos com que o novo Node aponte para o head
            A->head->next = novo;
            novo->back = A->head;
            std::cout << "Add " << novo->value << std::endl;
        }
        else{
            // Fazemos o aux->next apontar para o novo Node
            // Depois fazemos o novo->back apontar para o aux 
            aux->next = novo;
            novo->back = aux;
            std::cout << "Add " << novo->value << std::endl;
            
        }
        
        /*No final todas vez que adicionamos uma nova key na lista sempre realizamos a operação
        do novo->next apontar para o head e o head->back apontar para o novo para a lista 
        continuar com sua estrutura circular  
        */ 
        novo->next = A->head;
        A->head->back = novo;
    }

    return A;
    // Informação de que o elemento foi adicionado no final da lista

}

// Imprimi os elementos da lista
void Conjunto::print(Conjunto* A){
    // Cria um ponteiro auxiliar que aponta para head->next (proximo Node da lista)
    Node* aux = A->head->next;
    
    // Verifica se a lista está vazia. Caso esteja, imprime uma mensagem
    if(isEmpty()){
        std::cout << "fail: conjunto vazia\n";
    }else{
        // Por meio do while fazemos percorrer a lista enquanto o aux não aponta para o head
        
        while(aux != A->head){
            // Imprimimos o value do Node
            std::cout << aux->value << " "; 
            // Em seguida fazemos com que aux aponte para o próximo Node
            aux = aux->next;
            
        }
        std::cout << std::endl;
    }
    
}

// Recebe os conjuntos A e B como parˆametro e retorna o conjunto C = A ∪ B.
Conjunto* Conjunto::uniao(Conjunto* A, Conjunto* B, Conjunto* C){
    // Node aux_A que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux_A = A->head->next;
    // Node aux_B que aponta para o Node após ao Node da cabeça do Conjunto B
    Node* aux_B = B->head->next;
    // Atributo tam_a do tipo interio que irá receber o tamanho do Conjunto A
    int tam_a = A->size();
    // Atributo tam_b do tipo interio que irá receber o tamanho do Conjunto B
    int tam_b = B->size();
    if(A->isEmpty() || B->isEmpty()){
        std::cout << "Conjunto vazia\n";
    }
    else{
        // Enquanto que axu_A ou aux_B não apontam para nulo realiza as seguintes operações
        while(aux_A != A->head || aux_B != B->head){
            // Se o tamanho do Conjunto A for maior que 0, então realiza as seguintes operações
            if(tam_a > 0)
                C->insere(aux_A->value, C);       // Adiciona o valo do Node aux_A usando o método insere no Conjunto C
                aux_A = aux_A->next;              // Faz o aux_A apontar para o próximo Node
            // Se o tamanho do Conjunto A for maior que 0, então realiza as seguintes operações
            if(tam_b > 0)
                C->insere(aux_B->value, C);       // Adiciona o valo do Node aux_B usando o método insere no Conjunto C
                aux_B = aux_B->next;              // Faz o aux_B apontar para o próximo Node
            tam_a--;                              // Decrementa 1
            tam_b--;                              // Decrementa 1
        }
    }
    
    // Retorno o Conjunto C
    return C;
}
// Recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A ∩ B.
Conjunto* Conjunto::intersec(Conjunto* A, Conjunto* B, Conjunto* C){

    // Node aux_A que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux_A = A->head->next;
    
    // Enquanto o Node aux_A não aponta para a cabeça do conjunto A
    while(aux_A != A->head){
        // Verifica se o valor do Conjunto A não escontra-se no Conjunto B
        // Faz com que o aux_A aponte para o próximo
        if(!B->search(aux_A->value)){
            aux_A = aux_A->next;
        }
        C->insere(aux_A->value, C);     // Usando o método insere para adicionar o elemento no Conjunto C
        aux_A = aux_A->next;            // Faz com que o aux_A aponte para o próximo
    }
    // Retorno o Conjunto C
    return C;
}

// recebe os conjuntos A e B como parâmetro e retorna o conjunto C = A - B.
Conjunto* Conjunto::diferenca(Conjunto* A, Conjunto* B, Conjunto* C){

    // Node aux que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux = A->head->next;
    // Enquanto aux não aponta para nulo
    while(aux != A->head){
        /* Usando o método search caso o valor de Node aux não esteja no Conjunto B, usa o método add 
        e adiciona o valor do Node aux  e faz o aux_a apontar para o próximo*/
        if(B->search(aux->value) == false){
            C->insere(aux->value, C);
            aux = aux->next;
        }
        // Caso não entre na condição, faz o Node aux apontar para o próximo
        aux = aux->next;
    }
    // Retorno o Conjunto C
    return C;
}
// Recebe os conjuntos A e B como parˆametro e retorna o conjunto C = A - B.
Conjunto* Conjunto::diferenca_simetrica(Conjunto* A, Conjunto* B, Conjunto* C){
    // Node aux_A que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux_A = A->head->next;
    // Node aux_A que aponta para o Node após ao Node da cabeça do Conjunto B
    Node* aux_B = B->head->next;
    // Enquanto aux_A não apontam para para a cabeça do Conjunto A
    while(aux_A != A->head){
        // Verifica se o valor do aux_A não se encontra no Conjunto B.
        // Caso não se encontre, adiciona o valor no Conjunto C
        if(!B->search(aux_A->value)){
            C->insere(aux_A->value, C);     // Adiciona no valor no Conjunto C
            aux_A = aux_A->next;            // Faz o aux_A apontar para o próximo
        }
        // Caso não entre na condição
        // Faz o aux_A apontar para o próximo
        aux_A = aux_A->next;
    }
    // Enquanto aux_B não apontam para para a cabeça do Conjunto B
    while(aux_B != B->head){
        // Verifica se o valor do aux_B não se encontra no Conjunto A.
        // Caso não se encontre, adiciona o valor no Conjunto C
        if(!A->search(aux_B->value)){
            C->insere(aux_B->value, C);     // Adiciona no valor no Conjunto C
            aux_B = aux_B->next;            // Faz o aux_A apontar para o próximo
        }
        // Caso não entre na condição
        // Faz o aux_A apontar para o próximo
        aux_B = aux_B->next;
    }
    // Retono o conjunto C
    return C;
}

// Recebe o conjunto A e um elemento y e retorna um 1 se y ∈ A e 0 caso contrário.
int Conjunto::membro(int value, Conjunto* A){
    // Verifica se o conjunto está vazio
    if(A->isEmpty()){
        std::cout << "Conjunto vazio!\n";
        return 0;
    }
    else{
        // Verifica se o valor não esteja no Conjunto
        // Caso seja falso, retorna 0
        if(!A->search(value)){
            return 0;
        }
    }
    // Caso não entre em nenhuma das condições anteriores, então retorna 1
    return 1;
}

Conjunto* Conjunto::remove(int y, Conjunto* A){
    // Verifica se a lista está fazia. 
    if(A->isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
         // Cria um Node aux que aponta para o próximo da cabeça(head->next)
        Node* aux = A->head->next;
        // Cria um Node ant que aponta para head
        Node* ant = A->head;
        while(aux != A->head){
            if(aux->value == y){
                ant->next = aux->next;      // Faz com que o ponteiro next aponte para o próximo aux
                aux->next->back = ant;      // Faz com que o ponteiro back do próximo aux aponte para ant
                
            }
            ant = aux;                      // Faz o ant apontar para o aux
            aux = aux->next;                // Faz o aux apontar para o próximo
        }
    }
    return A;
}

// Faz uma cópia do conjunto A em B
Conjunto* Conjunto::copia(Conjunto* A, Conjunto* B){
    // Node aux que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux = A->head->next;
    // Verifca se o Conjunto A está vazio
    if(A->isEmpty()){
        std::cout << "lista vazia\n";
        return nullptr;
    }else{
        // Enquanto o aux não aponta para a cabeça do Conjunto A
        while(aux != A->head){
            // Usando o método insere, adiciono o valor do Node aux no Conjunto B
            B->insere(aux->value, B);
            // Faz o oaux apontar para o próximo Node
            aux = aux->next;
        }
        
    }
    // Retorno o Conjunto B
    return B;
}

// Método que retorna o valor m´ınimo do conjunto A.
int Conjunto::min(Conjunto* A){
    // Atributo minimo que irá guardar o valor da maior elemento do Conjunto A
    // Inicialmente ele com o valor do primeiro Node após a cabeça
    int minimo = A->head->next->value;
    // Node aux que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux = A->head->next;
    // Enquanto aux não aponta para nulo
    while(aux != A->head){
        // Se o valor do Node aux for menor ao minimo, o atributo minimo recebe o valor do Node aux
        if(aux->value < minimo){
            minimo = aux->value;
        }
        // Caso não entre nessa condição, faz o aux apontar para o próximo Node
        aux = aux->next;
    }
    // Retorno o minimo
    return minimo;
}

// Método que retorna o valor máximo do conjunto A.
int Conjunto::max(Conjunto* A){
    // Atributo maximo que irá guardar o valor da maior elemento do Conjunto A
    // Inicialmente ele com o valor do primeiro Node após a cabeça
    int maximo = A->head->next->value;
    // Node aux que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux = A->head->next;
    // Enquanto aux não aponta para nulo
    while(aux != A->head){
        // Se o valor do Node aux for maior ou igual ao maximo, o atributo maximo recebe o valor do Node aux
        if(aux->value >= maximo){
            maximo = aux->value;
        }
        // Caso não entre nessa condição, faz o aux apontar para o próximo Node
        aux = aux->next;
    }
    // Retorno o maximo
    return maximo;
}

// Retorna true se os conjuntos A e B são iguais e false caso contrário.
bool Conjunto::igual(Conjunto* A, Conjunto* B){
    // Stributo tam_A que guarda o tamanho do Conjunto A
    int tam_A = A->size();
    // Stributo tam_B que guarda o tamanho do Conjunto B
    int tam_B = B->size();
    // Node aux_A que aponta para o Node após ao Node da cabeça do Conjunto A
    Node* aux_A = A->head->next;
    // Node aux_B que aponta para o Node após ao Node da cabeça do Conjunto B
    Node* aux_B = B->head->next;

    // Se alguns dos Conjuntos, A e B, esteja vazio, retorna nulo
    if(A->isEmpty() || B->isEmpty()){
        std::cout<< "lista vazia\n";
        return false;
    }
    // Se o tamanho dos Conjuntos A e B forem diferentes retorna falso
    else if(tam_A != tam_B){ return false;}
    else{
        while(aux_A != A->head){
            if(!B->search(aux_A->value))
                return false;
            aux_A = aux_A->next;
        }
    }
    // Caso não entre em nenhuma das condições retorna true
    return true;
    
}