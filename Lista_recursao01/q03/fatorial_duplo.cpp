#include <iostream>
using namespace std;

int fat(int n){
    if(n % 2 == 1){
        if (n == 1) return 1;
        else return n * fat(n-2);
    }
    else{
        cout << "Apenas valor impar\n";
        return 0;
    }
}

int main(){
    int n = 0;
    cout << "Fatorial: ";
    cin >> n;
    
    cout << fat(n) << "\n";

    return 0;
}