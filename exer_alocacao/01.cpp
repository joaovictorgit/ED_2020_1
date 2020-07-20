#include <iostream>
using namespace std;



void printaVetor(int* vec, int n){
    for(int i = 0; i < n; i++){
        cout << vec[i] << ", ";
    }cout << "\n";
}

int main(){

    int n = 0;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    
    int* vec = new int[n];
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    } 
    printaVetor(vec, n);

    delete [] vec;
    return 0;
}