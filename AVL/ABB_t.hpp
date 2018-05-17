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
    
    void insertar(Base_t data);
    nodoBB_t<Base_t>* recursiveAdd(Base_t data, nodoBB_t<Base_t>* current_search);
    
    void borrar(const Base_t data);
    nodoBB_t<Base_t>* recursiveRemove(Base_t data, nodoBB_t<Base_t>* current_search);
    nodoBB_t<Base_t>* IOP(nodoBB_t<Base_t>* current, nodoBB_t<Base_t>* node_to_remove);
    
    
    
    bool buscar(const Base_t data);
    bool vacio(nodoBB_t<Base_t> *r) {return r==NULL;}
    bool esHoja(nodoBB_t<Base_t> *r) {return !r->get_der() && !r->get_izq();}
    
    void podar(nodoBB_t<Base_t>* nodo);
    
    void verArbol();
    
    double& get_test(){return test_;}
    
    //Mierda de AVL
    
    int height(nodoBB_t<Base_t>* node_query);
	void fixHeight(nodoBB_t<Base_t>* parent);
	int heightDiff(nodoBB_t<Base_t>* parent);
	nodoBB_t<Base_t>* balance(nodoBB_t<Base_t>* parent);
	nodoBB_t<Base_t>* rotateRight(nodoBB_t<Base_t>* pivot);
	nodoBB_t<Base_t>* rotateLeft(nodoBB_t<Base_t>* pivot2);
	nodoBB_t<Base_t>* getMin(nodoBB_t<Base_t>* parent);
    nodoBB_t<Base_t>* removeMin(nodoBB_t<Base_t>* parent);
    
    
    
};