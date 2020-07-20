#include <iostream>
using namespace std;

int* copy(int* v, int n){
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        A[i] = v[i];
    }
    return A;
    delete A;
}

void printa(int *V, int n){
    for(int i = 0; i < n; i++){
        cout << V[i] << " ";
    }cout << "\n";
}

int main(){
    int n = 0;
    cin >> n;
    
    int V[n];
    for(int i = 0; i < n; i++){
        cin >> V[i];
    }
    int* copia = copy(V,n);
    printa(copia,n);
    
    


    return 0;
}