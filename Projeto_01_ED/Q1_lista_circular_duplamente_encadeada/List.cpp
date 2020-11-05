#include <iostream>
#include <climits>
#include "List.h"

struct Node{
    int value;      // Atributo que irá guardar o valor do Node
    Node* next;     // Ponteiro next que aponta para o próximo Node
    Node* back;     // Ponteiro back que aponta para o Node anterior
};


// Construtor
List::List(){
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
    // Incializamos a lista com tamanho 0
    _size_list = 0;
    std::cout << "Lista criada\n";
}

// Destrutor
List::~List(){
    // Limpamos a lista caso não esteja vaiza
    if(!isEmpty()){
        clear();        // limpa a lista deixando apenas o head
    }
    delete head;    // libera a memória que havia sido alocada para head
    std::cout << "Lista destruida\n";
}

// Método clear que apaga todos os Node exceto o head;
void List::clear(){
    // Verifica se a lista está vazia
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }
    else{
        // Criamos um Node aux que aponta para o último elemento da lista
        Node* aux = head->back;
        // Criamos um Node ant que aponta para o aux
        Node* ant = aux;
        // Enquanto o aux não aponta para head
        while(aux != head){
            aux = aux->back;
            delete ant;
            ant = aux;
        }
        // No final sempre fazemos head->next e head->back apontar para o próprio head
        head->next = head;
        head->back = head;
       
    }
}

// Método que verifica se a lista está vazia
bool List::isEmpty(){
    // Verifica se o ponteiro next da cabeça aponta para ele mesma
    // Caso seja verddadeiro quer dizer que a lista está vazia
    return (head->next == head ? true : false);
}

// Insere um inteiro key ao final da lista
void List::push_back(int key){
    Node* novo = new Node; // cria um novo Node
    novo->value = key;

    // A partir daqui verificamos dois casos
    // Caso esteja vazia adicionamos o primeiro elemento da lista
    if(isEmpty()){
        // Fazemos que head->next aponte para o novo Node
        // Depois fazemos com que o novo Node aponte para o head
        head->next = novo;
        novo->back = head;
    }
    // Caso já exista um Node na lista 
    else{
        // Criamos o Node aux que ponta para o último elemento da lista
        Node* aux = head->back;
        // Fazemos o aux->next apontar para o novo Node
        // Depois fazemos o novo->back apontar para o aux 
        aux->next = novo;
        novo->back = aux;
        
    }
    /*No final todas vez que adicionamos uma nova key na lista sempre realizamos a operação
      do novo->next apontar para o head e o head->back apontar para o novo para a lista 
      continuar com sua estrutura circular  
    */ 
    novo->next = head;
    head->back = novo;
    // Informação de que o elemento foi adicionado no final da lista
    std::cout << "Add " << novo->value << std::endl;

}


// Imprimi os elementos da lista
void List::print(){
    // Cria um ponteiro auxiliar que aponta para head->next (proximo Node da lista)
    Node* aux = head->next;
    
    // Verifica se a lista está vazia. Caso esteja, imprime uma mensagem
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        // Por meio do while fazemos percorrer a lista enquanto o aux não aponta para o head
        
        while(aux != head){
            // Imprimimos o value do Node
            std::cout << aux->value << " "; 
            // Em seguida fazemos com que aux aponte para o próximo Node
            aux = aux->next;
            
        }
        std::cout << std::endl;
    }
    
}

// Método que retorna o tamanho da lista
int List::size(){
    // Node aux que aponta para o próximo Node da cabeça
    Node* aux = head->next;
    // Cria um atributo soma para guardar a quantidade de Node da lista
    int soma = 0;

    // Enquanto o aux não aponta para a cabeça ele faz as seguintes operações dentro do while
    while(aux != head){
        soma++;             // Aumenta o tamanho de _size_list +1 enquanto aux for diferente de head
        aux = aux->next;    // Faz o aux apontar para o próximo Node
    }
    _size_list = soma;      // Faço _size_list receber soma
    return _size_list;      // Retorno _size_list(tamanho da lista)
}

// Imprime os elementos da lista em ordem reversa
void List::printReverse(){
    // Cria um ponteiro auxiliar que aponta para head->back (último Node da lista)
    Node* aux = head->back;

    // Verifica se a lista está vazia. Caso esteja, imprime uma mensagem
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        
        // Por meio do while fazemos percorrer a lista enquanto o aux não aponta para o head
        while(aux != head){
            // Imprimimos o value do Node
            std::cout << aux->value << " "; 
            // Em seguida fazemos com que aux aponte para o Node anterior, pois estamos começando do final da lista
            aux = aux->back;
        }
        std::cout << std::endl;
    }
}

// Remove elemento do final da lista e retorna seu valor
int List::pop_back(){
    // Cria um Node aux que aponta para o último elemento
    Node* aux = head->back;
    // Crio um Node ant que aponta para o aux
    Node* ant = aux;
    // Atributo que reberá o elemento a ser removido
    int value_remove;
    // Verifica se a lista está vazia. Caso esteja, imprime uma mensagem
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
        return INT_MIN; // retornar o valor do menor inteiro possível
    }else{
        aux = aux->back;            // aux aponta para seu antecessor
        value_remove = ant->value;  // o atributo value_remove recebe o valor de ant
        delete ant;                 // deleto o ant
        aux->next = head;           // faço o aux->next(Node atual que é o último da lista agora) apontar para o head
        head->back = aux;           // faço o head->back apontar para o Node aux(último Node agora)
        _size_list--;               // Diminui o tamanho da lista 1 unidade
    }
    return value_remove;            // retorno o valor que foi removido
}

/* Método que retorna o Node anterior. 
Retorna nullptr caso key não esteja na lista, caso contrário retorna o Node*/
Node* List::search(int key){
    // Node aux que recebe head->next
    Node* aux = head->next;

    // Caso o ponteiro next de head aponte para a head então retorna nullptr
    if(head->next == head){
        return nullptr;
    }else{
        
        while(aux != head && aux->value != key){
            aux = aux->next ;
        }
    }
    return aux ;
}

// Remove da lista o nó apontado pelo ponteiro p
void List::removeNode(Node *p){
    // Node aux que aponta para o próximo Node da cabeça
    // Node* aux = head->next;
    // Verifica se a lista está vazia. Caso esteja, imprime uma mensagem
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        // Utilizando a função remove() ,  remove o Node da lista
        remove(p->value);
        std::cout << "Node removido\n";
    }


}


// Insere um novo nó com valor key após o k-ésimo nó da lista.
void List::insertAfter(int key, int k){
    // atributo indice que será utilizado para percorren a lista
    int indice = 0;

    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        // Cria um Node aux que aponta para o próximo da cabeça(head->next)
        Node* aux = head->next;
        // Cria um Node prox que aponta para aux
        Node* prox = aux;
        // Cria um Node novo
        Node* novo = new Node;
        novo->value = key;

        if(k >= 0 && k < _size_list){
            while(indice !=  k){
                indice++;           // Faz o indice percorrer até o k
                aux = aux->next;    // Faz o aux ir para o próximo
                prox = aux;         // Faz o prox apontar para o aux
                
            }
            prox = aux->next;       // Faz o prox ir pro aux->next, ou seja, 1 posição a mais do aux
            novo->back = aux;       // Faz o novo->back apontar para o aux
            aux->next = novo;       // Faz o aux->next apontar para o novo
            novo->next = prox;      // Faz o novo->next apontar para o prox
            prox->back = novo;      // Faz o prox->back apontar para o novo
            /*
            Ao fazermos as operações com o prox é para apontarmos para o próximo de aux
            como se o prox estivesse na posição 1 e apontar para a posição 3, enquanto que a
            posição 2 seria Node novo. Todos esses passos são feitos após o while
            */
           
        }
        // Caso o k seja igual que o tamanho da lista, inseri no final
        else if(k == _size_list){
            push_back(key);
        }
        // Caso o k seja maior que o tamanho da lista, o k é inválido
        else{
            std::cout << "fail: indice invalido\n";
        }
    }
    // Imprime a informação de que foi adicionado o elemtento após o k-ésimo elemento
    std::cout << "Add " << key << " na posicao " << k+1 << std::endl;
}

// Remove da lista a primeira ocorréncia do inteiro key
void List::remove(int key){
    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
         // Cria um Node aux que aponta para o próximo da cabeça(head->next)
        Node* aux = head->next;
        // Cria um Node ant que aponta para head
        Node* ant = head;
        while(aux != head){
            if(aux->value == key){
                ant->next = aux->next;      // Faz com que o ponteiro next aponte para o próximo aux
                aux->next->back = ant;      // Faz com que o ponteiro back do próximo aux aponte para ant
                
            }
            ant = aux;                      // Faz o ant apontar para o aux
            aux = aux->next;                // Faz o aux apontar para o próximo
        }
    }
}



// Remove da lista todas as ocorréncias do inteiro key
void List::removeAll(int key){
    

    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    
    }
    else{
        // Node aux que recebe head->next
        Node* aux = head->next;
        // Faço um verificação
        // Enquanto o aux não aponta para o head e enquanto existir um Node com key
        while(aux != head && search(key)){
            // Remove a key 
            remove(key);
            // aux aponta para o próximo
            aux = aux->next;
            
        }
        
    }
}

/*
Remove o k-ésimo nó da lista encadeada e retorna
o seu valor. Caso o k-ésimo nó não exista, o programa retorna o valor especial
INT MIN definido no cabe¸calho climits.
*/ 
int List::removeNodeAt(int k){

    // Atributo que retorna o valor do Node que será removido
    int value;

    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        // Caso o k seja maior que o tamanho da lista, retorna o valor mínimo de um inteiro
        if(k > _size_list){
            return INT_MIN;
        }else{
            // Node aux que aponta para o próximo da cabeça (head->next)
            Node* aux = head->next;
            // Node ant que aponta para o anterior de aux (head)
            Node* ant = head;

            // Atributo indice que irá percorrer a lista
            int indice = 0;

            while(aux != head){
                // Caso o indice seja igual ao k apaga o Node
                if(k == indice && k < _size_list){
                    aux = aux->next;            // Faz o aux apontar para o próximo Node
                    value =  aux->back->value;  // Faz o value receber o valor do Node anterior de aux
                    delete aux->back;           // Deleto o aux anterior
                    aux->back = ant;            // Faz o ponteiro aux->back apontar para o ant
                    ant->next = aux;            // Faz o ant apontar para o aux (Node atual)
                }
                // Caso o k seja igual ao tamnho da lista
                else if(k == indice && k == _size_list){
                    delete aux;                 // delete aux
                    ant->next = head;           // Faz o ant apontar para a cabeça(head)
                }
                // Caso contrário
                ant = aux;          // Faz o ant apontar para o aux
                aux = aux->next;    // aux aponta para o próximo
                indice++;           // indice aumenta o tamanho mais 1

            }

        }
    }
    return value;
} 


/*
Concatena a lista atual com a lista lst passada por
parâmetro. Após essa operação ser executada, lst será uma lista vazia, ou seja, o
único nó de lst será o nó cabeça. 
*/

void List::concat(List *lst){
    
    // Node aux que aponta para o ultimo Node da lista
    Node* aux = head->back;
    
    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        
        aux->next = lst->head->next;        // Faz o ponteiro next de aux apontar para o primeiro Node da Lista lst diferente de head(lst->head->next)
        lst->head->next->back = aux;        // Faz o ponteiro back do Node após a cabeça da lista apontar para o aux
        lst->head->back->next = head;       // Faz o ponterio next do último Node de lst apontar para o head da primeira lista
        head->back = lst->head->back;       // Faz o ponteiro back da lista 1 apontar para o último Node da lista lst
        lst->head->next = lst->head;        // Faz o ponteiro next da cabeça da lista lst apontar para ele mesma
        lst->head->back = lst->head;        // Faz o ponteiro back da cabeça da lista lst apontar para ele mesma
    }
}

// Retorna um ponteiro para uma cópia desta lista.
List* List::copy(){
    // Node aux que aponta para o próximo Node da cabeça
    Node* aux = head->next;
    // Cria uma nova List
    List* lst = new List;

    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
    }else{
        
        while(aux != head){
            lst->push_back(aux->value);     // Adiciono o valor de aux na lista usando a função push_back
            aux = aux->next;                // Faz o aux apontar para o próximo
        }

    }
    return lst;                             // Retorno a lista
}

/* Copia os elementos do array arr para a
lista. O array arr tem n elementos. Todos os elementos anteriores da lista são
mantidos e os elementos do array arr devem ser adicionados ap´os os elementos
originais.*/
void List::copyArray(int n, int arr[]){

    // Adiciono os elementos no final da lista
    for(int i = 0; i < n; i++){
        push_back(arr[i]);
    }

}

/* Determina se a lista passada por parâmetro é igual à
lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho e o valor
do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista.*/
bool List::equal(List *lst){
    // Atributo size_list que guarda o tamnaho da lista 1
    int size_list = size();
    // Atributo size_lst que guarda o tamanho da lista lst
    int size_lst = lst->size();

    // Node aux que aponta para o último elemento da lista 1
    Node* aux = head->back;
    // Node aux_lst que aponta para o último elemento da lista lst
    Node* aux_lst = lst->head->back;
    // Atributo number_aux que recebe o valor do Node aux
    int number_aux = aux->value;
    // Atributo number_lst que recebe o valor do Node aux_lst
    int number_lst = aux_lst->value;

    // Verifica se a lista 1 está vazia ou se a lista lst está vazia. Caso alguma esteja retorna falso e imprime uma mensagem de lista vazia
    if(isEmpty() || lst->isEmpty()){
        std::cout << "fail: lista vazia\n";
        return false;
    }

    // Compara se o último Node da lista 1 e lista lst são iguais, assim como seu tamanho. 
    // Caso sejam iguais retorna true, caso contrário falso
    return (number_lst == number_aux && size_list == size_lst) ? true : false;

}

/* Recebe como parâmetro um valor inteiro n e divide a
lista em duas, de forma à segunda lista começar no primeiro nó logo após a primeira
ocorrência de n na lista original. A função deve retornar um ponteiro para a segunda
subdivisão da lista original, enquanto a cabeça da lista original deve continuar
apontando para o primeiro elemento da primeira lista, caso ele n˜ao tenha sido o
primeiro a ter valor n.*/
List* List::separate(int n){
    // Crio um nova lista lst
    List* lst = new List;
    // Crio um Node aux que aponta para head
    Node* aux = head->next;
        

    // Verifica se a lista está fazia. 
    if(isEmpty()){
        std::cout << "fail: lista vazia\n";
        return nullptr;
    }
    else{
        // Caso n seja 1 
        if(n == 1){
            lst->head->next = aux;  // Faz o ponteiro next da cabeça da lista lst apontar para o aux
            aux->next = lst->head;  // Faz o próximo Node de aux apontar para a cabeça da lista lst
            lst->head->back = aux;  // Faz o ponteiro back da cebeça da lista lst apontar para auz;

        }
        // Caso a lista seja maior que 2 e menor que o tamanho
        else if(n >= 2 && n < size()){
            // Crio um atributo indice para percorrer a lista
            int indice = 0;
            // Enquanto o indice for menor que n faz a seguinte operações
            while(indice < n){
                indice++;                   // Faz o indice aumentar mais 1 enquanto é menor que n
                aux = aux->next;            // Faz o aux apontar para o próximo
            }

            Node* prox = aux->next;         // Node prox que apontar para o próximo Node de aux
            prox->back = head->back;        // Faz o ponteiro back de prox apontar para o últimi Node da lista 1
            head->back->next = prox;        // Faz o ponteiro next do último Node da lista 1 apontar para o prox
            aux->next = head;               // Faz o ponteiro next de aux apontar para a head
            head->back = aux;               // Faz o ponteiro back de aux apontar para a head
            prox->back->next = lst->head;   // Faz o ponteiro next do último Node de prox apontar para a cabeça da lista lst (lst->head)
            lst->head->back = prox->back;   // Faz o ponteiro back da cabeça da lista lst apontar para o último Node de prox (prox->back)
            lst->head->next = prox;         // Faz o ponteiro next da cabeça da lista lst apontar para o prox
            prox->back = lst->head;         // Faz o ponteiro back de prox apontar para a cabeça da lista lst(lst->head)
        }
        
    }
    return lst;                             // Retorno a lista lst
}


/*Recebe uma List como parâmetro e constrói
uma nova lista com a intercalação dos nós da lista original com os nós da lista
passada por parâmetro. Ao final desta operação, list2 deve ficar vazia.*/

void List::merge_lists(List *list2){
    // Crio um nova lista
    List* lista = new List;

    // Node aux que recebe o próximo Node da cabeça da lista 1
    Node* aux = head->next;
    // Node aux_lst que recebe o próximo Node da cabeça da lista list2
    Node* aux_list2 = list2->head->next;
    // Atributo size_aux que recebe o tamanho da lista 1
    int size_aux = size();
    // Atributo size_list2 que recebe o tamanho da list2
    int size_list2 = list2->size();
 
    
    // Verifca se alguma das listas está vazia
    if(isEmpty() || list2->isEmpty()){
        std::cout << "fail: lista vazia\n";
    }
    else{
        // Enquanto a aux da lista 1 não aponta para o head ou o aux_list2 não aponta para a list2_head
        while(aux != head || aux_list2 != list2->head){
            // Se o tamanho da lista 1 for maior que 0 ele realiza as seguintes operações
            if(size_aux > 0)
                lista->push_back(aux->value);       // Adiciona o aux->value usando a funçao push_back
                aux = aux->next;                    // Faz o aux apontar para o próximo Node
            // Se o tamanho da list2 for maior que 0 ele realiza as seguintes operações
            if(size_list2 > 0)
                lista->push_back(aux_list2->value); // Adiciona o aux_list2->value usando a funçao push_back
                aux_list2 = aux_list2->next;        // Faz o aux_list2 apontar para o próximo Node
            
            size_aux--;                             // Diminui 1 unidade o tamanho da lista 1
            size_list2--;                           // Diminui 1 unidade o tamanho da list2
        }

        /* As operações realizadas nas 2 linhas a seguir fazem com que 
        a lista 1 seja nula, ou seja os ponteiros next e back de head apontam para ela mesma*/
        aux->next = head;                           // Faz o ponteiro next de aux apontar para a cabeça da lista 1
        aux->back = head;                           // Faz o ponteiro back de aux apontar para a cabeça da lista 1
        
        /* As operações realizadas nas linhas 567 e 568 fazem com que 
        a list2 seja nula, ou seja os ponteiros next e back de list2->head apontam para ela mesma*/
        list2->head->next = list2->head;            // Faz o ponteiro next de list2->head apontar para a cabeça da list2
        list2->head->back = list2->head;            // Faz o ponteiro back de list2->head apontar para a cabeça da list2

        /*As operações da realizadas nas 4 linhas a seguir fazem com que
        os ponteiros next e back de aux apontem para a lista "lista"*/
        aux->next = lista->head->next;              // Faz o ponteiro next de aux apontar para o próximo Node da cabeça da lista "lista"
        aux->back = lista->head->back;              // Faz o ponterio back de aux apontar para o último Node da lista "lista"
        lista->head->back->next = aux;              // Faz o ponteiro next do último Node da lista "lista" aponte para auz
        lista->head->next->back = aux;              // Faz o ponteiro back do Node após a cabeça da lista "lista" apontar para o aux
    }
        

}