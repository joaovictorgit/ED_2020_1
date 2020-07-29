#include <iostream>
using namespace std;

int mdc(int x, int y){
    if(y == 0){
        return x;
    }else{
        return mdc(y, x%y);
    }
}

int main(){
    int x = 0;
    int y = 0;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

    cout << mdc(x,y) << "\n";
    return 0;
}