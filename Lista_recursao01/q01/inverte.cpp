#include <iostream>
using namespace std;

void trocar(int* v, int i, int n){
    int aux = 0; 
    aux = v[i];
    v[i] = v[n];
    v[n] = aux;
    
}

void inverte(int* v,int i, int n){ 
   
   
   if(i < n){
        trocar(v,i,n);
        inverte(v,i+1,n-1);
    }
}

int main(){
    int n = 0;
    cin >> n;
    int vet[n];

    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    
    
    inverte(vet,0 ,n-1); 
    
    for(int i = 0; i < n; i++){
        cout << vet[i] << " ";
    }cout << "\n";
}