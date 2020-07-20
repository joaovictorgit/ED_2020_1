#include <iostream>
using namespace std;

struct Music{
        string nome;
        string autor;
        float preco;
        int ano;
};
struct Album{
        Music** musics; // vetor
        int n;
        float preco = 0;
};
//função
void updatePrice(Album* a, int x){
        float sum = 0;
        for(int i = 0 ; i< a->n; i ++ ){
                Music* m = a->musics[i]; 
                sum += m->preco;
        }
        a->preco = sum+sum*x/100;
}

Music* criaMusica(){
        Music* M = new Music;
        cout << "\n\nNome: ";
        cin >> M->nome;
        cout << "Autor: ";
        cin >> M->autor;
        cout << "Preco: ";
        cin >> M->preco;
        cout << "Ano: ";
        cin >> M->ano;

        return M;
}

void printMusica(Music* m){
        cout << "\n\nNome: " << m->nome <<"\n";
        //cout << "Autor: " << m->autor <<"\n";
        cout << "Preço: " << m->preco <<"\n";
        //cout << "Ano: " << m->ano <<"\n";
        cout << "===========\n";
}

int main(){
        int n;
        cout << "N: ";
        cin >> n;
        cout << "Musicas:\n";
         Album a;

        a.musics = new Music*[n];
        a.n = n;
        for(int i = 0; i< n; i ++){
                a.musics[i] = criaMusica();     
        }

        cout << "----------------------\n";
         updatePrice(&a, 5);

        ///////////////
        cout << "preço do album: " << a.preco << "\n";
        
        
        
       
         



        return 0;
}