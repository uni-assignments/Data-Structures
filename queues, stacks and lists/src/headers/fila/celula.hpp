
class CelulaFila{
    public:
        CelulaFila(){
            nave.set_identificador(-1);
            prox = NULL;
        };

    private:
        Nave nave;
        CelulaFila *prox;
    
    friend class FilaEncadeada;        
};
