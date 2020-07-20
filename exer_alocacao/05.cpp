#include <iostream>
using namespace std;



void buscaMat(int** mat, int valor, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == valor){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
            
        }
    }
}


void deleteMat(int** mat, int n){
    for(int i = 0; i < n; i++){
        delete [] mat[i];
        for(int j = 0; j < n; j++){
            delete [] mat[j];
        }
    }
}

int main(){

    int n = 0;
    int num = 0;

    cout << "Digite o tamanho da matriz: ";
    cin >> n;

    int** mat = new int*[n];
    for(int i = 0; i < n; i++){
        mat[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    
    cout << "Digite o numero: ";
    cin >> num;

    buscaMat(mat, num, n);
    deleteMat(mat, n);
    
    return 0;
}