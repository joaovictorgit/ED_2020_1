#include <iostream>
using namespace std;

int ordem_par(int n){
    if(n % 2 == 0){
        if(n >= 1){ 
            cout << n << " ";
            return ordem_par(n-2);
        }
        else return 0;
    }else{
        cout << "apenas numeros pares\n";
        return 0;
    }
    
}


int main(){
    int n = 0;
    cout << "Imprimar os primeiros n elementos: ";
    cin >> n;

    cout << ordem_par(n) << " ";
}