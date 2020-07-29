#include <iostream>
using namespace std;

int sdig(int n){
    if(n == 0){
        return 0;
    }else{
        return (n%10) + sdig(n/10);
    }
}


int main(){
    
    int n = 0;
    cout << "N: ";
    cin >> n;

    cout << sdig(n) << "\n";

    return 0;
}