#include <iostream>
#include "QX_Circulo.h"
using namespace std;

int main(){
    
    Ponto point;
    Ponto point01;

    point.x = 5.3;
    point.y = 5.4;

    Circulo c1(2.0,point);
    
    cout << "Pontos (x:y) -> ";
    c1.getCentro();

    cout << "Raio: " << c1.getRaio() << "\n";
    cout << "Area: " << c1.area() << "\n";
    

    c1.setRaio(3.0);
    cout << "Raio: " << c1.getRaio() << "\n";
    cout << "Area: " << c1.area() << "\n";
    
    point01.x = 3.2;
    point01.y = 3.7;

    cout << "Pontos (x:y) -> ";
    c1.getCentro();
    
    std::cout << "O ponto (" << point01.x << ":" << point01.y << ") pertence ao circulo ? ";
    cout << c1.interior(point01) << "\n";    
    
    c1.setX(3.5);
    c1.setY(4.2);

    cout << "Pontos (x:y) -> ";
    c1.getCentro();



    return 0;
}