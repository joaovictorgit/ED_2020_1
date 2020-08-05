#include <iostream>
#include "QX_Circulo.h"
using namespace std;

int main(){
    
    Ponto point;
    point.x = 5;
    point.y = 5;
    Circulo c1(2.0,point);
    cout << "Area: " << c1.area() << "\n";
    c1.setRaio(3.0);
    cout << "Area: " << c1.area() << "\n";
    Ponto point01;
    point01.x = 3;
    point01.y = 3;
    cout << c1.interior(point01) << "\n";    


    return 0;
}