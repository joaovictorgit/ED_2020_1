#include <iostream>
#include "QX_Circulo.h"



//  cria um cíırculo cujo centro é um atributo do tipo Ponto e raio é um float;
Circulo::Circulo(float raio, Ponto centro){
    setRaio(raio);    
    _p = new Ponto;
    if(_p != nullptr){
        setX(centro.x);
        setY(centro.y);
    }
    
    
}
// destrutor
Circulo::~Circulo(){
    if(_p != nullptr){
        std::cout << "Circulo destruido";
        delete _p;
    }
}


//  atribui novo valor ao raio do c´ırculo;
void Circulo::setRaio(float r){
    raio = r;
}
// atribui novo valor à coordenada x
void Circulo::setX(float v){
    _p->x = v;
    std::cout << "x -> " << _p->x << "\n";
    
}
// atribui novo valor à coordenada y
void Circulo::setY(float v){
    _p->y = v;
    std::cout << "y -> " << _p->y << "\n";
    
} 

// obtém o raio
float Circulo::getRaio(){
    return raio;
}
// obtém o centro
Ponto* Circulo::getCentro(){
    
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
    if(p.x <= _p->x && p.y <= _p->y){
        return true;
    }
    else{
        return false;
    }
}