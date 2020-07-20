#include <iostream>
using namespace std;

int ordem(int n){
    if(n >= 1){ 
        cout << n << " ";
        return ordem(n-1);
    }
    else return 0;
}


int main(){
    int n = 0;
    cout << "Imprimar os primeiros n elementos: ";
    cin >> n;

    cout << ordem(n) << " ";
}