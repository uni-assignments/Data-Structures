
class CelulaLista {
    public:
        CelulaLista(){
            nave.set_identificador(-1);
            prox = NULL;
        };
    private:
        Nave nave;
        CelulaLista *prox;
    friend class ListaEncadeada;    
};