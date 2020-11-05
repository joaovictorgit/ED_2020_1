#ifndef CONJUNTOS_H
#define CONJUNTOS_H

struct Node;

class Conjunto{
    private:
        Node* head;
        int _size;
    public:
        Conjunto();
        ~Conjunto();
        bool isEmpty();
        void print(Conjunto* A);
        void clear();
        int size();
        bool search(int value);
        Conjunto* uniao(Conjunto* A, Conjunto* B, Conjunto* C);
        Conjunto* intersec(Conjunto* A, Conjunto* B, Conjunto* C);
        Conjunto* diferenca(Conjunto* A,Conjunto* B,Conjunto* C);
        Conjunto* diferenca_simetrica(Conjunto* A,Conjunto* B,Conjunto* C);
        int membro(int value,Conjunto* A);
        void criaConjVazio();
        Conjunto* insere(int y,Conjunto* A);
        Conjunto* remove(int value, Conjunto* A);
        Conjunto* copia(Conjunto* A, Conjunto* B);
        int min(Conjunto* A);
        int max(Conjunto* A);
        bool igual(Conjunto* A, Conjunto* B);        
};
#endif