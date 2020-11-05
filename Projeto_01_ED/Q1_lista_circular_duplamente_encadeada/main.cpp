#include <iostream>
#include "List.h"
using namespace std;

/* Questão 1
Aluno: João Victor de Almeida Félix
Matrícula: 476849
*/

/*
No aquivo main.cpp será implementada todas as funções que estão na List.h. A estrutara da main foi feita
para que o usuário digite quantas lista se deseja criar, os valores a serem inseridos ou removidos entre
as outras funções existentes. Utilizando alguns atributos para serem utilizados na funções que estão devida-
mente explicados na List.cpp, além de um laço while junto com switch que será utilizado para escolher
a opc desejada para realizar a função pedida. Todas as funções pedidas no PDF foram usadas. Em cada case que for
escolhido haverá a utilização dos atributos que foram sitados anteriormente e a chamada das funções. Haverá con-
dições parao caso as listas digitadas pelo usuário existam ou não. No final haverá um default que dirá uma mensa-
gem de erro caso a opção escolhida pelo usuário não exista e um caso que irá destruir as listas, que será o
"case 20" e o caso que irá encerrar o sistema, neste caso a opção será o "case 21".
OBS: Iremos tratar de selecionar as litas por número, exemplo, escolher a primeira lista, basta 
digitar o valor 1.
No caso 1 onde iremos criar as lista, o usário deve criar uma quantidade de listas que satisfazem as funções.
*/ 
int main(){

   
    // Tamanho da quantidade de listas do programa
    int size = -1;
    // Valores a serem inseirdos
    int valores = 0;
    // Vetor do tipo List que será alocado no case 1
    List* vec;
    // Atributo n (auxiliar) para se referir a uma lista
    int n = 0;
    // Atributo n2 (auxiliar) para se referir a uma segunda lista quando pedida em uma função como concat()
    int n2 = 0;
    //  Atributo que serve para dizer a quantidade de elementos que serão adicionados na lista
    int qtd_elementos;
    // Atributo que serve para para ser usaso na função search e retorna o nó caso ele exista
    int no_valor = 0;
    // Atributo chave que recebera um elemento para ser utilizado em funções como remove, removeAll etc
    int chave = 0;
    // Atributo pos que será utilizado em funções como insertAfter ou removeNodeAt
    int pos = 0;
    // Atributo boolean que recebe true e faz com que o loop continue até o cont ser false
    bool cont = true;
    // Atributo opc que será usado no switch para entrar em algum dos casos
    int opc = 0;
    // Atributo line que irá imprimir as opções dentro do while
    string line = "";
    line+= "/-------------Menu--------------/\n";
    line+=  "(1) Criar n Listas\n";
    line+=  "(2) push back\n";
    line+=  "(3) print\n";
    line+=  "(4) empty\n";
    line+=  "(5) size\n";
    line+=  "(6) printReverse\n";
    line+=  "(7) clear\n";  
    line+=  "(8) pop back\n"; 
    line+=  "(9) removeNode\n";  
    line+=  "(10) insertAfter\n";  
    line+=  "(11) remove\n";  
    line+=  "(12) removeAll\n" ;  
    line+=  "(13) removeNodeAt\n"; 
    line+=  "(14) concat\n";
    line+=  "(15) copy\n";
    line+=  "(16) copyArray\n";
    line+=  "(17) equal\n";  
    line+=  "(18) separate\n";
    line+=  "(19) merge_lists\n" ;  
    line+=  "(20) Destruir Listas()\n"; 
    line+=  "(21) Sair do programa\n";
    line+= "/-------------------------------/\n";
    while(cont){
        cout << line;
        cout << "Escolha uma opcao: ";
        cin >> opc;
        system("clear");
        switch(opc){
            // Irá cria um vetor de List que será alocado dinamicamente com o tamanho (size)
            // size é o atributo que guardará o tamanho do vetor "vec"
            case 1:
                cout << "Diga quantas listas se deseja criar para realizar as funcoes: \n";
                cin >> size;
                vec = new List[size];
            break;
            // Irá adicionar os valores na lista desejada
            case 2:
                cout << "Qual lista deseja adicionar elementos: ";
                cin >> n;
                if(n-1 <= size){
                    cout << "Quantidade de elementos a inserir: ";
                    // Atributo que irá guarda a quantidad de elementos que será adiconado no vetor 
                    cin >> qtd_elementos;
                    // Vetor que irá receber a quantidade de elementos                               
                    int vetor[qtd_elementos];
                    cout << "Adicione os elementos na Lista " << n << ": ";
                    // Utilizando o for para adicionar os elementos no vetor
                    // Ainda dentro do for chama a função push_back para adicionar os elementos do vetor 1 a 1
                    for(int i = 0; i < qtd_elementos; i++){
                        cin >> vetor[i];
                        vec[n-1].push_back(vetor[i]);
                        
                    }
                }
                else{
                    cout << "Lista nao existe\n";
                }

            break;
            // Irá imprimir os valores das listas usando a função print
            case 3:
                // Por meio do for imprime os valores da lista na posicao i
                for(int i = 0; i < size; i++){
                    cout << "Lista " << i+1 << " -> ";
                    vec[i].print();
                }
            break;
            // Verifica se a lista está vazia
            case 4:
                if(size > -1){
                    // Por meio do for verifica se a lista na posicao i está vazia
                    for(int i = 0; i < size; i++){
                        if(vec[i].isEmpty()){
                            cout << "Lista " << i+1 << " esta vazia\n"; 
                        }
                        else{cout << "Lista " << i+1 << " nao esta vazia\n";}
                    }
                }
                
            break;
            // Mostra o tamanho de cada
            case 5:
                // Utilizando o for irá inicialmente verificar se a lista está vazia
                // Se sim, então imprime 0, caso contrário, utiliza a função size e retorna o tamanho da lista
                for(int  i = 0; i < size; i++){
                    if(vec[i].isEmpty()){
                        cout << "Lista " << i+1 << " tem tamanho 0\n";
                    }else{
                        cout << "Lista " << i+1 << " tem tamanho " << vec[i].size() << endl;
                    }
                }
            break;
            // Imprime os valores invertidos
            case 6:
                // Por meio do for, usa a função printReverse e mostra os valores da lista invertida na posição i
                for(int i = 0; i < size; i++){
                    cout << "Lista " << i+1 << " -> ";
                    vec[i].printReverse();
                }
            break;
            // Limpa a lista caso não esteja vazia
            case 7:
                cout << "Lista que vc deseja limpar: ";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista então limpa a lista
                if(n-1 <= size){
                    // Verifca se a lista na posição n-1 não esteja vazia
                    // Se não estiver vazia, então usa a função clear e limpa a lista
                    if(!vec[n-1].isEmpty()){
                        vec[n-1].clear();
                        cout << "Lista " << n << " limpa\n";
                    }
                    else{
                        cout << "Lista ja esta vazia\n";
                    }
                }else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Remove o último valor da lista
            case 8:
                cout << "Qual lista deseja remover o ultimo elemento ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista, então usa a função pop_back
                if(n-1 <= size){
                    cout << "Elemento " << vec[n-1].pop_back() << " da lista " << n << " removido\n";
                }
                else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Remove o nó da lista
            case 9:
                cout << "Qual lista deseja remover o no ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista, então usa a função search e retorna o nó
                if(n-1 <= size){                    
                    cout << "Digite o valor do no que deseja excluir: ";
                    cin >> no_valor;
                    Node* p = vec[n-1].search(no_valor);
                    // Caso o nó existe, então remove o nó da lista usando a função removeNode
                    vec[n-1].removeNode(p);
                }
                else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Inseri um novo valor na após a posição indicada
            case 10:
                cout << "Qual lista deseja adicionar o novo elemento ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista
                if(n-1 <= size){
                    cout << "Qual posicao se deseja inserir o valor ?\n";
                    cin >> pos;
                    cout << "Digite o elemento: ";
                    cin >> chave;
                    // Usa a função insertAfter para adcionar o valor na posição pos+1
                    vec[n-1].insertAfter(chave,pos);
                }
                else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Remove o valor da lista na posição digitada pelo usuário
            case 11:
                cout << "Qual lista deseja remover o elemento ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista
                if(n-1 <= size){
                    cout << "Digite o elemento que deseja remover: ";
                    cin >> chave;
                    // Remove o valor da lista
                    vec[n-1].remove(chave);
                }
                else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Remove todos os valores repetidos da lista
            case 12:
                cout << "Qual lista deseja remover os elementos ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista
                if(n-1 <= size){
                    cout << "Digite o elemento a ser removido: ";
                    cin >> chave;
                    // Usando o removeAll, remove todos os valores "chave" que estão na lista
                    vec[n-1].removeAll(chave);
                }
                else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Remove o valor da lista pela posição
            case 13:
                cout << "Qual lista deseja remover o elemento ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista
                if(n-1 <= size){
                    cout << "Qual posicao da lista " << n << " se deseja excluir o elemento: ";
                    cin >> pos;
                    // Usando a função removeNodeAt remove a posição digitada pelo usuário
                    vec[n-1].removeNodeAt(pos);
                }
                else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Concatena duas lista
            case 14:
                cout << "Qual lista deseja que seja concatenada ?\n";
                cin >> n;
                cout << "Qual lista deseja que concatene com a lista " << n << "?\n";
                cin >> n2;
                // Se as listas que o usário digitou forem menores ou iguais ao tamanho da lista
                if(n-1 <= size && n2-1 <= size){
                    // Usando a função "concat" e concatena os elementos da segunda lista com a primeira
                    vec[n-1].concat(&vec[n2-1]);
                }
                else{
                    cout << "Algumas das lista n foi criada\n";
                }
            break;
            // Copia os elementos de uma lista para outra
            case 15:
                cout << "Qual lista deseja que seja copiada ?\n";
                cin >> n;
                cout << "Qual lista deseja receber a copia " << n << "?\n";
                cin >> n2;
                // Se as listas que o usário digitou forem menores ou iguais ao tamanho da lista
                if(n-1 <= size && n2-1 <= size){
                    // Usando a função "copy", copia a lista n para outra lista n2
                    vec[n2-1] = *vec[n-1].copy();
                }
                else{
                    cout << "Alguma das lista nao foi criada\n";
                }
            break;
            // Adiciona um vetor de tamanho x em uma lista
            case 16:
                cout << "Qual lista deseja-se adicionar os valor do vetor ?\n";
                cin >> n;
                // Se a lista que o usário digitou for menores ou iguais ao tamanho da lista
                if(n-1 <= size){
                    cout << "Digite o tamanho do vetor para adicionar os elementos: " ;
                    cin >> qtd_elementos;
                    // Cria um vetor "array" com qtd_elementos digitados pelo usuário
                    int array[qtd_elementos];
                    cout << "Insira os elementos no vetor: ";
                    // Inseri os elementos no vetor "array"
                    for(int i = 0; i < qtd_elementos; i++){
                        cin >> array[i];
                    }
                    // Usando a função copyArray, adicona os elementos do vetor na lista que o usário escolheu
                    vec[n-1].copyArray(qtd_elementos,array);
                }else{
                    cout << "Lista nao foi criada\n";
                }
            break;
            // Compara duas lista (caso seja 1, então verdadeido, caso seja 0, então falso)
            case 17:
                cout << "Quais listas deseja comparar ?\n";
                cin >> n;
                cin>> n2;
                // Se as listas que o usário digitou forem menores ou iguais ao tamanho da lista
                if(n-1 <= size && n2-1 <= size){
                    // Usando a função equals para saber se a lista n é igual a lista n2
                    cout << "Lista eh igual ? " << vec[n-1].equal(&vec[n2-1]) << endl;
                }
                else{
                    cout << "Alguma das listas nao foi criada\n";
                }
            break;
            // Separa uma lista em duas
            case 18:
                cout << "Qual lista deseja ser separada ? \n";
                cin >> n;
                cout << "Qual lista deseja que receba a outra parte dos elementos da lista " << n << " ?\n";
                cin >> n2;
                // Se as listas que o usário digitou forem menores ou iguais ao tamanho da lista
                if(n-1 <= size && n2-1 <= size){
                    cout << "Digite a quantidade de elementos que deseja separar da lista " << n << ": ";
                    cin >> pos;
                    // Usando a função separete, a lista n será separada até a posição "pos"
                    // A lista n2 receberá os valores da lista n após a posição "pos" que o usuário digitou
                    vec[n2-1] = *vec[n-1].separate(pos);
                }
            break;
            // Intercala duas listas
            case 19:
                cout << "Qual lista vai ficar intercalada ? \n";
                cin >> n;
                cout << "Qual lista ira intercalar os elementos com a lista " << n << " ?\n";
                cin >> n2;
                // Se as listas que o usário digitou forem menores ou iguais ao tamanho da lista
                if(n-1 <= size && n2-1 <= size){
                    // Usando a função merge_lists, intercala a lista n com a lista n2
                    vec[n-1].merge_lists(&vec[n2-1]);
                }
                else{
                    cout << "Alguma das lista nao foi criada\n";
                }
            break;
            // Destroi todas as lista do vetor "vec"
            case 20:
                // Se a lista que o usário digitou for menor ou igual ao tamanho da lista, caso não seja não faz nada
                if(size != -1){
                    // Deleta o vetor "vec"
                    // Nesse caso a função do destrutor ~List() irá ser executada
                    delete[] vec;
                    // Tamanho da lista volta a ser -1
                    size = -1;
                }
            break;
            // O atributo cont do tipo boolean recebe falso, que faz com que o laço pare o programa se encerre
            case 21:
                if(size > -1){
                    cout << "fail: destrua as listas antes de sair do programa!\n";
                }
                else{
                    cont = false;
                    cout << "Programa encerrado!\n";
                }
            break;
            // Caso nenhum dos case seja selecionado então o usuário digitou uma opção inválida
            default:
                cout << "fail: comando invalido\n";
            break;
        }

    }
        
    return 0;
}