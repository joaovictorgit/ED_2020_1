#include <iostream>
using namespace std;

struct Music{
        string nome;
        string autor;
        float preco;
        int ano;
};

//função

Music* criaMusica(){
        Music* M = new Music;
        cout << "\nNome: ";
        cin >> M->nome;
        cout << "Autor: ";
        cin >> M->autor;
        cout << "Preco: ";
        cin >> M->preco;
        // cout << "Ano: ";
        // cin >> M->ano;

        return M;
}

void printMusica(Music* m){
        cout << "\nNome: " << m->nome <<"\n";
        cout << "Autor: " << m->autor <<"\n";
        cout << "Preço: " << m->preco <<"\n";
        cout << "Ano: " << m->ano <<"\n";
        cout << "===========\n";
}

void printMusics(Music** m, int n){
        for(int i = 0; i < n; i++){
                printMusica(m[i]);
        }       
}

int Lexico(string a, string b){ // 1 a > b; -1 a< b ; 0 a == b
        for(int i=0; a[i] || b[i]; i++){
                if(a[i] > b[i]) return 1;
                else if(a[i] < b[i]) return -1;
        }return 0;
}

void sortName(Music** m, int n){
        for(int j=0; j< n; j++){
                for(int i=0;i < n-1;i++){
                        if(Lexico(m[i]->nome, m[i+1]->nome) == 1){
                                swap(m[i]->nome, m[i+1]->nome);
                                
                         }
                }
        }
}

void searchMusic(Music** m, int n, string musicName, string setAutor){
        for(int i = 0; i < n; i++){
                if(m[i]->nome == musicName){
                        m[i]->autor = setAutor;
                }
        }
}


int main(){
        int n;
        cout << "N: ";
        cin >> n;
        cout << "Musicas:\n";
         

        Music ** m = new Music*[n];
        
        for(int i = 0; i< n; i ++){
               m[i] = criaMusica();     
        }

        cout << "----------------------\n";
         printMusics(m, n);
        // cout << "musica buscada: ";
        // string nome, novoAutor;
        // cin>>nome;
        // cout<<"autor que quer alterar: ";
        // cin >> novoAutor;

        // searchMusic(m,n,nome, novoAutor);
        sortName(m,n);
         printMusics(m, n);


        
        
        
       
         



        return 0;
}