#ifndef QX_CIRCULO_H
#define QX_CIRCULO_H
// Struct Ponto;
struct Ponto{
    int x;
    int y;
};

class Circulo{
    public:
        //  cria um cíırculo cujo centro é um atributo do tipo Ponto e raio é um float;
        Circulo(float raio, Ponto centro);
        // destrutor
        ~Circulo();
    private:
        
        float raio;
        Ponto _p = {0,0};
    public: 
        
        //  atribui novo valor ao raio do c´ırculo;
        void setRaio(float r);
        // obtém o raio
        float getRaio();
        // obtém o centro
        Ponto getCentro();
        // calcula a área do círculo
        float area();
        // verifica se o Ponto p está dentro do círculo.
        bool interior(Ponto p);
};


#endif