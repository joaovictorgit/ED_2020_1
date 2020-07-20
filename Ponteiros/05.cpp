#include <iostream>
using namespace std;

int* intercal(int* v, int n, int* w, int m){
        int* inter = new int[n+m];
        int N = n+m;
        int x=0, y=0;
        for(int i =0; i< N;i++){
                if(i%2 == 0){
                        //elemento do 1
                        inter[i] = v[x];
                        x++;
                }else{ 
                        //elemento 2
                         inter[i] = w[y];
                        y++;
                }
        }

        return inter;
}


void printVet(int* v, int n){
        for(int i =0; i<n; i++){
                cout << v[i] << " ";
        }cout << "\n";
}

int main(){
        int n;
        cout << "N: ";
        cin >> n;
        int v[n];
        cout << "V:\n";
        for(int i =0; i<n; i++){
                cin >>v[i];
        }
        cout << "---------------\n";
        int m;
        cout <<"M: ";
        cin >> m;
        int w[m];
        cout << "W:\n";
         for(int i =0; i<m; i++){
                 cin>>w[i];
         }
        cout << "---------------\n";

        int *z = intercal(v,n,w,m);

        printVet(z,n+m);

        delete z;
        return 0;
}