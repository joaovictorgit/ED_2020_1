#include <iostream>
using namespace std;

void soma(int vet[], int tam){
    if(tam == 0)
        return ;
    
    int v_aux[tam - 1];
    for(int i = 0; i < (tam - 1); i++)
        v_aux[i] = vet[i] + vet[i + 1]; 
    soma(v_aux, tam - 1);
    
    
    cout << "[";
    for(int i = 0; i < tam; i++)
        
        if(i == tam - 1)
            cout << vet[tam - 1];
        else
            cout << vet[i] << ", ";   
    cout << "]" << endl;
}


int main(){
    int n = 0;
    cin >> n;
    int vet[n];

    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    soma(vet, n);
    
    
    
}