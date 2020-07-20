#include <iostream>
using namespace std;

void criaVetor(int* vec, int n){
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
}


void printaVetor(int* vec, int n){
     for(int i = 0; i < n; i++){
        if(i == n-1){
            cout << vec[n-1];
        }else{
            cout << vec[i] << ", ";
        }
        
    }cout << "\n";
}


int main(){

    int n = 0;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    int* V = new (nothrow) int[n];

    criaVetor(V, n);
    printaVetor(V, n);

    delete [] V;
    return 0;
}