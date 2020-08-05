#include <iostream>
#include "QX_Circulo.h"



//  cria um cíırculo cujo centro é um atributo do tipo Ponto e raio é um float;
Circulo::Circulo(float raio, Ponto centro){
    setRaio(raio);
    _p.x = centro.x;
    _p.y = centro.y;
}
// destrutor
Circulo::~Circulo(){
    std::cout << "Circulo destruido";
}


//  atribui novo valor ao raio do c´ırculo;
void Circulo::setRaio(float r){
    raio = r;
}
// obtém o raio
float Circulo::getRaio(){
    return raio;
}
// obtém o centro
Ponto Circulo::getCentro(){
    return _p;
}
// calcula a área do círculo
float Circulo::area(){
    float aux_area;
    aux_area = 3.14 * (getRaio() * getRaio());
    return aux_area;
}
// verifica se o Ponto p está dentro do círculo.
bool Circulo::interior(Ponto p){
    if(p.x <= _p.x && p.y <= _p.y){
        return true;
    }
    else{
        return false;
    }
}