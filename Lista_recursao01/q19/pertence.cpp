#include <iostream>
using namespace std;

int pertence(int v[], int n, int x){
    if(n == 0){
        if(v[0] == x){
            return 1;
        }
    }else{
        if(v[n-1] == x) return 1;
        else return pertence(v, n-1, x);
    }

    return 0;
}

int main(){
    int n = 0;
    cin >> n;

    int vet[n];
    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    int x = 0;
    cin >> x;

    cout << pertence(vet,n, x) << endl;

    return 0;
}