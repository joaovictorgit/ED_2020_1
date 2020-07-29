#include <iostream>
using namespace std;


void vetPrint(int *v, int n){
    for(int i=0;i<n;i++) cout<<v[i]<<", ";

    cout <<"\n";
}


bool auxVerSum(int *v, int n, int pivo, int x){

    if(n==0){
        return false;
    }else if((v[n-1] + pivo) == x){
        return true;
    }
    
    else{
        return false || auxVerSum(v,n-1,pivo, x);
    }
}

bool sum2Vet(int *v,int n, int x, int pivo=0){ 
    
    if(n==pivo){ 
        return false;
    }
    
    else{
        
        
        if(pivo>0){ 
            int aux = v[0];
            v[0] = v[pivo];
            v[pivo] = aux;
        }
        
        
        if(auxVerSum(v+1, n-1, v[0], x)){
            return true;
        }else{ 
            return false || sum2Vet(v,n,x,pivo+1);
        }   
        
    }
}

int main(){

    int n;
    cout << "N: ";
    cin >> n;
    int v[n];
    cout << "Vetor:\n";
    for(int i =0 ; i< n; i++){
        cin >> v[i];
    }

    int x;
    cout << "X: ";
    cin >> x;

    cout << "Encontrei a soma? " << sum2Vet(v,n,x)<<"\n";
    vetPrint(v,n);
    return 0;
}