#include "ABB_t.hpp"

//double test= 0;

template<class Base_t>
void ABB_t<Base_t>::podar(nodoBB_t<Base_t>* nodo){
   // Algoritmo recursivo, recorrido en postorden
   
   test_++;
   if(nodo) {
      podar(nodo->get_izq());   // Podar izquierdo
      podar(nodo->get_der());   // Podar derecho
      delete nodo;              // Eliminar nodo
      nodo = NULL;
   }
}

template<class Base_t>
void ABB_t<Base_t>::insertar(const Base_t data){
    
   nodoBB_t<Base_t>* padre = NULL;

   actual_ = raiz_;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   test_++; test_++;
   while(!vacio(actual_) /*&& data != actual_->get_data()*/) {
      padre = actual_;
      test_++;
      if(data > actual_->get_data()) {actual_ = actual_->get_der(); test_++;}
      else if(data <= actual_->get_data()){ actual_ = actual_->get_izq(); test_++;}
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   //test_++;
   //if(!vacio(actual_)) {return; }
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   test_++;
   if(vacio(padre)) raiz_ = new nodoBB_t<Base_t>(data);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(data <= padre->get_data()){ padre->get_izq() = new nodoBB_t<Base_t>(data); test_++;}
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(data > padre->get_data()){ padre->get_der() = new nodoBB_t<Base_t>(data); test_++;}

}

template<class Base_t>
void ABB_t<Base_t>::borrar(const Base_t data){
    
   nodoBB_t<Base_t> *padre = NULL;
   nodoBB_t<Base_t> *nodo;
   int aux;

   actual_ = raiz_;
   // Mientras sea posible que el valor esté en el árbol
   test_++;
   while(!vacio(actual_)) {
      test_++;
      if(data == actual_->get_data()) {                                          // Si el valor está en el nodo actual
         test_++;
         if(esHoja(actual_)) {                                                   // Y si además es un nodo hoja: lo borramos
            test_++;
            if(padre)                                                            // Si tiene padre (no es el nodo raiz)
               if(padre->get_der() == actual_) padre->get_der() = NULL;          // Anulamos el puntero que le hace referencia
               else if(padre->get_izq() == actual_) padre->get_izq() = NULL;
            delete actual_; // Borrar el nodo
            actual_ = NULL;
            return;
         }
         else {                                                                 // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual_;
            // Buscar nodo más izquierdo de rama derecha
            test_++;
            if(actual_->get_der()) {
               nodo = actual_->get_der();
               while(nodo->get_izq()) {
                  padre = nodo;
                  nodo = nodo->get_izq();
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual_->get_izq();
               while(nodo->get_der()) {
                  padre = nodo;
                  nodo = nodo->get_der();
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual_->get_data();
            actual_->get_data() = nodo->get_data();
            nodo->get_data() = aux;
            actual_ = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual_;
         test_++;
         if(data > actual_->get_data()) actual_ = actual_->get_der();
         else if(data < actual_->get_data()){ actual_ = actual_->get_izq(); test_++;}
      }
   }
}

template<class Base_t>
bool ABB_t<Base_t>::buscar(const Base_t data){
    
    actual_ = raiz_;
    
    // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!vacio(actual_)) {
      test_++;
      if(data == actual_->get_data()) return true;                                     // int encontrado
      else if(data > actual_->get_data()){ actual_ = actual_->get_der(); test_++;}     // Seguir
      else if(data < actual_->get_data()){ actual_ = actual_->get_izq(); test_++;}
   }
   return false; // No está en árbol
    
}

template<class Base_t>
void ABB_t<Base_t>::verArbol(){
   
   //bloque <nodo(nodoBB_t<Base_t>), nivel(int)>
   std::cout << "Nivel 0: ";
   
   std::queue <std::pair <nodoBB_t<Base_t>*, int> > Q;
   nodoBB_t<Base_t>* nodo;
   
   int nivel, nivel_actual= 0;
   
   std::pair <nodoBB_t<Base_t>*, int > test (raiz_,0); 
   Q.push(test);
   
   //std::cout << ' ' << myqueue.front();
   //myqueue.pop();
   
   while (!Q.empty()){
      
      nodo= Q.front().first;
      nivel= Q.front().second;
      Q.pop();
      
      if(nivel > nivel_actual){
         nivel_actual = nivel;
         std::cout << std::endl;
         std::cout << "Nivel " << nivel_actual << ": ";
      }
      
      if(nodo != NULL){
       
         std::cout << "[" << nodo->get_data() << "] ";
         
         std::pair <nodoBB_t<Base_t>*, int > aux (nodo->get_izq(), nivel+1);
         Q.push(aux);
         std::pair <nodoBB_t<Base_t>*, int > aux2 (nodo->get_der(), nivel+1);
         Q.push(aux2);
         
      }else{
         std::cout << "[.]";
      }
      
      
   }
   
   
}