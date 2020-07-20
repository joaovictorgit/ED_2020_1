#include <iostream>
using namespace std;
#define MAX 7


void binario(int n){
    int vet[MAX];
    int i = 0;
    
    if(n > 0){
        vet[i] = n % 2;
        i++;
        binario(n/2);
    }

    for(int j = i-1; j >= 0; j--){
        cout << vet[j] << " ";
    }
}

int main(){

    int n = 0;
    cout << "N: ";
    cin >> n;

    binario(n);

    


    return 0;
}