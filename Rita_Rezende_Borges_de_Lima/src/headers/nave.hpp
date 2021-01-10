#ifndef NAVE_H
#define NAVE_H


#include <cstdio> // em C substituir por #include <stdio.h>

class Nave {
    
    public:
        Nave(){};
        Nave(int id){this->identificador = id;};
        
        void imprime(){printf("%d", this->identificador);};
        void set_identificador(int id){this->identificador = id;};
        int get_identificador(){return this->identificador;};
    
    private:
        int identificador;
};

#endif