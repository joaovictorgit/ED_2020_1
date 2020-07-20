#include <iostream>
using namespace std;

struct Cadastro{
    string nome;
    int idade;
    string endereco;
};

Cadastro* criarCad(Cadastro* cria_cadastro, int n){
    for(int i = 0; i < n; i++){
        cout << "Digite o nome: ";
        cin >> (cria_cadastro[i]).nome;
        cout << "Digite a idade: ";
        cin >> (cria_cadastro[i]).idade;
        cout << "Digite o endereco: ";
        cin >> (cria_cadastro[i]).endereco;
    }
    return cria_cadastro;
}

void printaCad(Cadastro* printa_cadastro, int n){
    cout << "\n";
    for(int i = 0; i < n; i++){
        cout << "Nomde: " << (printa_cadastro[i]).nome << "\n";
        cout << "Idade: " << (printa_cadastro[i]).idade << "\n";
        cout << "Endereco: " << (printa_cadastro[i]).endereco << "\n\n";
    }
   
}


int main(){
    int n = 0;
    cout << "Digite o valor de N: ";
    cin >> n;

    Cadastro* cad = new (nothrow) Cadastro[n];
    criarCad (cad, n);
    printaCad (cad, n);


    delete [] cad;
    return 0;
}