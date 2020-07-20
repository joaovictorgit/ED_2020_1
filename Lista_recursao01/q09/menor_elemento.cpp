#include <iostream>
using namespace std;

int menor_elemento(int v[], int n){
    int menor = 0;

    if(n == 1){
        return v[0];
    }
    else{
        menor = menor_elemento(v,n-1);
        if(menor > v[n-1]){
            return v[n-1];
        }else{
            return menor;
        }
    }
}

int main(){
    
    int n = 0;
    cout << "N: ";
    cin >> n;

    int vet[n];
    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    cout << menor_elemento(vet,n) << "\n";
    cout << vet[n-1];
    return 0;
}