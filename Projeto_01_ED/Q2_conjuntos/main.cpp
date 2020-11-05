#include <iostream>
#include "conjuntos.h"
using namespace std;

/*
No aquivo main.cpp será implementada todas as funções que estão na conjunto.h. A estrutara da main foi feita
para que o usuário digite quantos conjuntos se deseja criar, os valores a serem inseridos ou removidos entre
as outras funções existentes. Utilizando alguns atributos para serem utilizados na funções que estão devida-
mente explicadas no conjunto.cpp, além de um laço while junto com switch que será utilizado para escolher
a opção desejada para realizar a função pedida. Todas as funções pedidas no PDF foram usadas. Em cada case que for
escolhido haverá a utilização dos atributos que foram sitados anteriormente e a chamada das funções. Haverá con-
dições parao caso as listas digitadas pelo usuário existam ou não. No final haverá um default que dirá uma mensa-
gem de erro caso a opção escolhida pelo usuário não exista e um caso que irá destruir os conjuntos, que será o
"case 14" que também será o caso que irá encerrar o sistema.
OBS: Utilizamos números para nos referirmos aos Conjuntos, exemplo, Conjunto 1 , Conjunto 2, etc.
No caso 1 onde iremos criar os Conjuntos, o usário deve criar uma quantidade de Conjuntos que satisfazem
as funções.
*/
int main(){
    // Atributo do tipo Conjunto
    Conjunto* vec;
    // Atributo que guardará o tamnho do conjunto
    int size_conju = -1;
    // Atributo que será utilizado nos métodos
    int key = 0;
    // Atributo que fará com que o while funcione, enquanto for true
    // Atributos n , n2 e n3 do tipo inteiros que serão usados para se referir-se aos conjuntos
    int n = -1;
    int n2 = -1;
    int n3 = -1;
    // Vetor que guarda caracteris
    char letras[10] = {'A','B', 'C','D','E','F','G','H','I','J'};
    bool cont = true;
    // Atributo que irá ser utilizado no switch
    int opc = 0;
    // String que terá o menu de opções
    string line = "\n/------------Menu-------------/\n";
    line += "(1) Criar n Conjuntos Vazios\n";
    line += "(2) insere(y,A)\n";
    line += "(3) uniao(A,B,C)\n";
    line += "(4) interseccao(A,B,C)\n";
    line += "(5) diferenca(A,B,C):\n";
    line += "(6) diferenca simetrica(A,B,C):\n";
    line += "(7) membro(y,A)\n";
    line += "(8) remove(y,A)\n";
    line += "(9) copia(A,B)\n";
    line += "(10) min(A)\n";
    line += "(11) max(A)\n";
    line += "(12) igual(A,B)\n";
    line += "(13) printConju\n";
    line += "(14) Sair do programa\n";
    line += "/-----------------------------------/\n";
    while(cont){
        cout << line;
        cout << "Escolha uma opcao: ";
        cin >> opc;
        system("clear");

        switch (opc){
        // Criando uma quantidade de Conjuntos que satisfazem todos os métodos a serem implementados
        case 1:
            if(size_conju == -1){
                cout << "Digite a qtd de Conjuntos que serao criados para se trabalhar: ";
                cin >> size_conju;
                vec = new Conjunto[size_conju]; // Aloca uma n quatidade de Conjuntos
            }
        break;
        // Adicionar o elemento no conjunto escolhido pelo usuário
        case 2:
            cout << "Digite o valor a ser inserido: ";
            cin >> key;
            cout << "Qual Conjunto deseja inserir o novo valor ? ";
            cin >> n;
            if(n-1 <= size_conju){
                // Chama o método insere no Conjunto escolhido pelo usuário
                vec[n-1] = *vec[n-1].insere(key, &vec[n-1]);
            }
            else{
                cout << "fail: Conjunto nao existe!\n";
            }
        break;
        // Um conjunto n recebe a união de dois conjuntos escolhidos pelo usuário
        case 3:
            cout << "Digite os Conjuntos que irao ser unidos: ";
            cin >> n;
            cin >> n2;
            if(n-1 <= size_conju && n2-1 <= size_conju){
                cout << "Digite qual conjunto ira receber a uniao dos Conjuntos " << letras[n-1] << " e " << letras[n2-1] << " :";
                cin >> n3;
                vec[n3-1] = *vec[n3-1].uniao(&vec[n-1], &vec[n2-1], &vec[n3-1]);
            }
            else{
                cout <<"fail: Algum dos conjuntos nao foi criado!\n";
            }
        break;
        // Um conjunto n recebe a intersecção de dois conjuntos escolhidos pelo usário
        case 4:
            cout << "Digite os Conjuntos que irao fazer a interseccao: ";
            cin >> n;
            cin >> n2;
            if(n-1 <= size_conju && n2-1 <= size_conju){
                cout << "Digite qual conjunto ira receber a interseccao dos Conjuntos " << letras[n-1] << " e " << letras[n2-1] << " :";
                cin >> n3;
                vec[n3-1] = *vec[n3-1].intersec(&vec[n-1], &vec[n2-1], &vec[n3-1]);
            }
            else{
                cout <<"fail: Algum dos conjuntos nao foi criado!\n";
            }
        break;
        // Um Coonjunto irá receber a diferença entre dois conjuntos
        case 5:
            cout << "Digite os Conjuntos escolhido: ";
            cin >> n;
            cin >> n2;
            if(n-1 <= size_conju && n2-1 <= size_conju){
                cout << "Digite qual conjunto ira receber a difernca dos Conjuntos " << letras[n-1] << " e " << letras[n2-1] << " :";
                cin >> n3;
                vec[n3-1] = *vec[n3-1].diferenca(&vec[n-1],&vec[n2-1],&vec[n3-1]);
            }
            else{
                cout <<"fail: Algum dos conjuntos nao foi criado!\n";
            }
        break;
        // Reliza a diferença simétrica de dois Conjuntos
        case 6:
            cout << "Digite os Conjuntos escolhido: ";
            cin >> n;
            cin >> n2;
            if(n-1 <= size_conju && n2-1 <= size_conju){
                cout << "Digite qual conjunto ira receber a difernca dos Conjuntos " << letras[n-1] << " e " << letras[n2-1] << " :";
                cin >> n3;
                vec[n3-1] = *vec[n3-1].diferenca_simetrica(&vec[n-1],&vec[n2-1],&vec[n3-1]);
            }
            else{
                cout <<"fail: Algum dos conjuntos nao foi criado!\n";
            }
        break;
        // Verificar se o valor digitado pertence ao conjunto
        case 7:
            cout << "Escolha o conjunto:";
            cin >> n;
            if(n-1 <= size_conju){
                cout << "Digite o valor que deseja verificar: ";
                cin >> key;
                cout << key  << " pertence ao Conjunto " << letras[n-1] << " ? " << vec[n-1].membro(key, &vec[n-1]) << endl;
            }
            else{
                cout << "fail: Conjunto nao foi criado!\n";
            }
        break;
        case 8:
            cout << "Escolhe o Conjunto que se deseja remove o valor: ";
            cin >> n;
            if(n-1 <= size_conju){
                cout << "Digite o valor a ser removido: ";
                cin >> key;
                vec[n-1] = *vec[n-1].remove(key, &vec[n-1]);
            }
            else{
                cout << "fail: Conjunto nao foi criado!\n";
            }
        break;
        // Irá fazer um cópia de um conjunto para outro
        case 9:
            cout << "Digite o Conjunto que sera copiado: ";
            cin >> n;
            if(n-1 <= size_conju){
                cout << "Escolha o Conjunto que recebera a copia: ";
                cin >> n2;
                vec[n2-1] = *vec[n2-1].copia(&vec[n-1],&vec[n2-1]);
            }
            else{
                cout << "fail: Conjunto nao foi criado!\n";
            }
        break;
        // Retorna o mínimo do Conjunto escolhido
        case 10:
            cout << "Escolha o Conjunto: ";
            cin >> n;
            if(n-1 <= size_conju){
                cout << "O minimo do Conjunto " << letras[n-1] << " eh " << vec[n-1].min(&vec[n-1]) << endl;
            }
            else{
                cout << "fail: Conjunto nao foi criado!\n";
            }

        break;
        // Retorno o máximo do Conjunto escolhido
        case 11:
            cout << "Escolhe o Conjunto: ";
            cin >> n;
            if(n-1 <= size_conju){
                cout << "O maximo do Conjunto " << letras[n-1] << " eh " << vec[n-1].max(&vec[n-1]) << endl;
            }
            else{
                cout << "fail: Conjunto nao foi criado!\n";
            }
        break;
        // Verifica se dois Conjuntos são iguais
        case 12:
            cout << "Escolha os Conjuntos que serao comparados: ";
            cin >> n; 
            cin >> n2;
            if(n-1 <= size_conju && n2-1 <= size_conju){
                cout << "Conjuntos " << letras[n-1] << " e " << letras[n2-1] << " sao iguais ? " << vec[n-1].igual(&vec[n-1], &vec[n2-1]) << endl;
            }
            else{
                cout << "fail: Conjunto nao foi criado!\n";
            }
        break;
        case 13:
            for(int i = 0; i < size_conju; i++){
                cout << "Conjunto " << letras[i] << " => ";
                vec[i].print(&vec[i]);
            }
        break;
        case 14:
            cont = false;
            if(size_conju == -1){}
            else{
                delete[] vec;
            }
        break;
        default:
            cout << "Fail: comando invalido!\n";
            break;
        }


    }

    return 0;
}
    