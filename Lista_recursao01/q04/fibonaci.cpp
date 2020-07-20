#include <iostream>
using namespace std;

int fib(int n){
    if(n == 1 || n == 2){ 
        return 1;
    }else{
        return fib(n-1) + fib(n-2);
    }
    
}

int main(){
    
    int n = 0;
    cout << "n-esimo termo de N: ";
    cin >> n;
    
    cout << fib(n) << "\n";
    
    return 0;
}