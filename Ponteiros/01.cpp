#include <iostream>
using namespace std;

struct Aluno{
    string nome;
    int idade;
    float media;
};

Aluno* criaAluno(Aluno* a){
    cout << "Nome: ";
    cin >> a->nome;
    cout << "Idade: ";
    cin >> a->idade;
    cout << "Media: ";
    cin >> a->media;

    return a;
}

void swapName(Aluno* a1, Aluno* a2){
    string nome = a2->nome;
    a2->nome = a1->nome;
    a1->nome = nome;
}

void printa(Aluno* a){
    cout << "Nome: " << a->nome << "\n";
    cout << "Idade: " << a->idade << "\n";
    cout << "Media: " << a->media << "\n\n";
}

int main(){
    Aluno* a1 = new Aluno;
    Aluno* a2 = new Aluno;

    criaAluno(a1);
    criaAluno(a2);

    printa(a1);
    printa(a2);

    swapName(a1,a2);
    
    printa(a1);
    printa(a2);
    
    return 0;
}