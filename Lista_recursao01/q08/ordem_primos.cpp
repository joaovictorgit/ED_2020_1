#include <iostream>
using namespace std;

bool primos(int n, int i = 2){
    if(i >= n){
        return true;
    }else{
        if(n % i == 0){
            return false;
        }else{
            return primos(n,i+1);
        }
    }
}


void ordem_primos(int n){
    if(n > 1){
        if(primos(n)){
            cout << n << " ";
        }
        ordem_primos(n-1);
    }
    
}


int main(){
    int n = 0;
    cin >> n;

    ordem_primos(n);
    return 0;
}