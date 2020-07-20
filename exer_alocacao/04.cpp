#include <iostream>
using namespace std;

void printaVetor(int* vec, int n){
     for(int i = 0; i < n; i++){
        if(vec[i] > 2){
            if(i == n-1){
                cout << vec[n-1];
            }else{
                cout << vec[i] << ", ";
            }
        }
    }cout << "\n";
}

int main(){

    int n = 0;
    

    for(;;){
        cout << "Digite valor de n: ";
        cin >> n;
        if(n < 0){
            cout << "Digite um valor positivo!\n";
        }
        else{
            int* V = new (nothrow) int[n];
            for(int i = 0; i < n; i++){
                cin >> V[i];
                if(V[i] < 2){
                    cout << "Digite um valor acima de 2\n";
                }
            }
            printaVetor(V, n);
            delete [] V;
            break;
        }
    }
    


    return 0;
}