#include <iostream>
using namespace std;

int cont_char(char nome[], char c, int i = 0){
    
    
    if(nome[i] == '\0'){
        return 0;
    }
    return (c == nome[i]) + cont_char(nome, c, i+1);
}

int main(){
    int n = 0;
    cin >> n;
    
    char nome[n];
    char c;

    cout << "Digite o nome: \n";
    for(int i = 0; i < n ; i++){
        cin >> nome[i];
    }
    
    cout << "Char: ";
    cin >> c;

    cout << cont_char(nome, c, 0) << "\n"; 

    return 0;
}