#include <iostream>
using namespace std;

int soma_vet(int vet[], int n){
    
    if(n == 0){
       return 0;
    }else{
        return vet[n-1] + soma_vet(vet, n-1);
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

    cout << soma_vet(vet, n) << "\n";

    return 0;
}
