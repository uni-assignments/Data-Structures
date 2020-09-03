
class CelulaFila{
    public:
        CelulaFila(){};

    private:
        Nave nave;
        CelulaFila *prox;
    
    friend class FilaEncadeada;        
};
