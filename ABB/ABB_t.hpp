#include "nodoBB_t.hpp"


template<class Base_t>
class ABB_t{

    private: 
    
    nodoBB_t<Base_t>* raiz_;
    nodoBB_t<Base_t>* actual_;
    
    int contador;
    int altura;
    
    double test_;

    public:
    
    ABB_t(): raiz_(NULL), actual_(NULL) {}
    ~ABB_t(){podar(raiz_);}
    
    void insertar(const Base_t data);
    void borrar(const Base_t data);
    
    bool buscar(const Base_t data);
    bool vacio(nodoBB_t<Base_t> *r) {return r==NULL;}
    bool esHoja(nodoBB_t<Base_t> *r) {return !r->get_der() && !r->get_izq();}
    
    void podar(nodoBB_t<Base_t>* nodo);
    
    void verArbol();
    
    double& get_test(){return test_;}
    
};