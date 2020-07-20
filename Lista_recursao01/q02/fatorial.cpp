#include <iostream>
using namespace std;

int fat(int n){
    if (n == 0) return 1;
    else return n * fat(n-1);
}

int main(){
    int n = 0;
    cout << "Fatorial: ";
    cin >> n;
    
    cout << fat(n) << "\n";

    return 0;
}