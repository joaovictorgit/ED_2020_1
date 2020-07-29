#include <iostream>
using namespace std;

int pontencia(int k, int n){
    if(n == 0){
        return 1;
    }else{
        return k * pontencia(k,n-1);
    }
}

int main(){
    int k = 0;
    int n = 0;
    cout << "K: ";
    cin >> k;

    cout << "N: ";
    cin >> n;

    cout << pontencia(k,n);
}