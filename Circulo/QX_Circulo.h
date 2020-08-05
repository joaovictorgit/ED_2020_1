#ifndef QX_CIRCULO_H
#define QX_CIRCULO_H
// Struct Ponto;
struct Ponto{
    float x;
    float y;
};

class Circulo{
    public:
        //  cria um cíırculo cujo centro é um atributo do tipo Ponto e raio é um float;
        Circulo(float raio, Ponto centro);
        // destrutor
        ~Circulo();
    private:
        Ponto* _p = new Ponto;
        float raio;
        
    public: 
        
        //  atribui novo valor ao raio do círculo;
        void setRaio(float r);
        // atribui novo valor à coordenada x
        void setX(float v);
        // atribui novo valor à coordenada y
        void setY(float v); 
        // obtém o raio
        float getRaio();
        // obtém o centro
        Ponto* getCentro();
        // calcula a área do círculo
        float area();
        // verifica se o Ponto p está dentro do círculo.
        bool interior(Ponto p);
};


#endif