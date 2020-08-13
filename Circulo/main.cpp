#include <iostream>
#include "QX_Circulo.h"
using namespace std;

// g++ main.cpp QX_Circulo.cpp -o exe && ./exe

int main(){
    
    Ponto point = {0,0};
    Ponto point01;

    point.x = 5.3;
    point.y = 5.4;

    Circulo c1(2.0,point);
    
    Ponto* centro01 = c1.getCentro();
    cout << "Pontos (x:y) -> " << "(" << centro01->x << ":" << centro01->y << ")\n";
    

    cout << "Raio: " << c1.getRaio() << "\n";
    cout << "Area: " << c1.area() << "\n";
    

    c1.setRaio(3.0);
    cout << "Raio: " << c1.getRaio() << "\n";
    cout << "Area: " << c1.area() << "\n";
    
    point01.x = 3.6;
    point01.y = 3.7;


    cout << "O ponto (" << point01.x << ":" << point01.y << ") pertence ao circulo ? ";
    cout << c1.interior(point01) << "\n";    
    
    c1.setX(3.5);
    c1.setY(4.2);
    
    Ponto* centro02 = c1.getCentro();
    cout << "Pontos (x:y) -> " << "(" << centro02->x << ":" << centro02->y << ")\n";


    cout << "O ponto (" << point01.x << ":" << point01.y << ") pertence ao circulo ? ";
    cout << c1.interior(point01) << "\n";

    



    return 0;
}