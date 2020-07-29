#include <iostream>
using namespace std;

int mult_rus(int a, int b){
    if(a == 1 ){
        return b;
    }

    else{
        if(a%2!=0){
            return b + mult_rus( a/2, b*2);
        }   
        return mult_rus( a/2, b*2);
    }
    
}

int main(){
    int a = 0;
    int b = 0;

    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    cout << mult_rus(a,b) << "\n";

    return 0;
}