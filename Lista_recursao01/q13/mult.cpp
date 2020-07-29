#include <iostream>
using namespace std;

int mult(int a, int b){
    if(b == 0){
        return 0;
    }else{
        return a + mult(a, b-1);
    }
}

int main(){
    int a = 0;
    int b = 0;

    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    cout << mult(a,b) << "\n";

    return 0;
}