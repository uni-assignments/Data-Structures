class CelulaPilha {

    private:
        CelulaPilha *prox;
        Nave nave;
        friend class PilhaEncadeada;

    public:    
        CelulaPilha(){
            this->nave.set_identificador(-1);
            prox = NULL;
        };
};

