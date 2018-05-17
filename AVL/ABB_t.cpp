#include "ABB_t.hpp"

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

//Insertar

template<class Base_t>
void ABB_t<Base_t>::insertar(Base_t data){
   
   //if(vacio(raiz_)) raiz_ = new nodoBB_t<Base_t>(data);
   
   bool was_added = false;
   //nodoBB_t<Base_t>* aux = NULL;
	
	if (raiz_ == NULL){
		raiz_ = new nodoBB_t<Base_t>(data);
		raiz_->get_data() = data;
		was_added = true;
	} else {
		if (buscar(data)==false){
			raiz_ = recursiveAdd(data, raiz_);
			was_added = true;
		} else {
			was_added = false;
		}
	}
	
   return;
   
}

template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::recursiveAdd(Base_t data, nodoBB_t<Base_t>* current_search){
	if (current_search == NULL){
	   std::cout<< "mplp" << std::endl;
		nodoBB_t<Base_t>* location_added = new nodoBB_t<Base_t>(data);
		//location_added->get_data() = data;
		return balance(location_added);
	}
	
	if (data > current_search->get_data()){
		current_search->get_der() = recursiveAdd(data, current_search->get_der());
	} else {
		current_search->get_izq() = recursiveAdd(data, current_search->get_izq());
	}
	
	return balance(current_search);
}


template<class Base_t>
void ABB_t<Base_t>::borrar(const Base_t data){
   
   bool was_removed = false;
	if (raiz_ == NULL){
		// DO NOTHING
	} else {	
		nodoBB_t<Base_t>* checker = new nodoBB_t<Base_t>(data);
		if (buscar(checker->get_data()) != false /*&& (checker->get_data() == data)*/){
		   std::cout<< "mplp" << std::endl;
			raiz_ = recursiveRemove(data, raiz_);
			was_removed = true;
		} else {
			// DO NOTHING
		}
	}
	
   return;
   
}


template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::recursiveRemove(Base_t data, nodoBB_t<Base_t>* current_search){
	if (current_search == NULL){
	   std::cout<< "mplp duh1" << std::endl;
		return NULL;
	} else if (current_search->get_data() < data){
	   std::cout<< "mplp duh<" << std::endl;
		current_search->get_der() = recursiveRemove(data, current_search->get_der());
	} else if (current_search->get_data() > data){
	   std::cout<< "mplp duh>" << std::endl;
		current_search->get_izq() = recursiveRemove(data, current_search->get_izq());
	} else {
		if (current_search->get_izq() == NULL){
			nodoBB_t<Base_t>* temp = current_search->get_der();
			delete current_search;
			return temp;
		} else {
		   std::cout<< "mplp test" << std::endl;
			current_search->get_izq() = IOP(current_search->get_izq(), current_search);
			return balance(current_search);
		}
	}
   
	return balance(current_search);
}


template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::IOP(nodoBB_t<Base_t>* current, nodoBB_t<Base_t>* node_to_remove){
	if (current->get_der() == NULL){}
	if (current->get_der() != NULL){
		current->get_der() = IOP(current->get_der(), node_to_remove);
		return balance(current);
	} else {
		node_to_remove->get_data() = current->get_data();
		nodoBB_t<Base_t>* temp = current->get_izq();
		delete current;
		return temp;
	}	
}




///
///AVL
///

template<class Base_t>
int ABB_t<Base_t>::height(nodoBB_t<Base_t>* node_query){
	return node_query ? node_query->get_depht() : 0;
}

template<class Base_t>
void ABB_t<Base_t>::fixHeight(nodoBB_t<Base_t>* parent){
	int hl = height(parent->get_izq());
	int hr = height(parent->get_der());
	parent->get_depht() = (hl>hr ? hl : hr) + 1;
}

template<class Base_t>
int ABB_t<Base_t>::heightDiff(nodoBB_t<Base_t>* parent){
	//cout << parent->data << " | " << parent->height << " = parent height | height right = " << height(parent->get_der()) << " | height left = " << height(parent->get_izq()) << endl;
	return height(parent->get_der()) - height(parent->get_izq());
}

template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::balance(nodoBB_t<Base_t>* parent){
	fixHeight(parent);
	int heightDifference = heightDiff(parent);
	if (heightDifference == 2){
		//cout << "heightDiff == 2" << endl;
		if (heightDiff(parent->get_der()) < 0)
			parent->get_der() = rotateRight(parent->get_der());
		return rotateLeft(parent);
	} else if (heightDifference == -2){
		//cout << "heightDiff == -2" << endl;
		if (heightDiff(parent->get_izq()) > 0)
			parent->get_izq() = rotateLeft(parent->get_izq());
		return rotateRight(parent);
	} else {
		//cout << "heightDifference = " << heightDifference << " thus no balance needed" << endl;
		return parent; // no balance needed
	}
}

template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::rotateRight(nodoBB_t<Base_t>* pivot){
	nodoBB_t<Base_t>* pivot2 = pivot->get_izq();
	pivot->get_izq() = pivot2->get_der();
	pivot2->get_der() = pivot;
	fixHeight(pivot);
	fixHeight(pivot2);
	return pivot2;
}

template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::rotateLeft(nodoBB_t<Base_t>* pivot2){
	nodoBB_t<Base_t>* pivot = pivot2->get_der();
	pivot2->get_der() = pivot->get_izq();
	pivot->get_izq() = pivot2;
	fixHeight(pivot2);
	fixHeight(pivot);
	return pivot;
}

template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::getMin (nodoBB_t<Base_t>* parent){
    return parent->get_izq()?getMin(parent->get_izq()):parent;
}

template<class Base_t>
nodoBB_t<Base_t>* ABB_t<Base_t>::removeMin (nodoBB_t<Base_t>* parent){
    if (parent->get_izq() == 0){
        return parent->get_der();
	}
    parent->get_izq() = removeMin(parent->get_izq());
    return balance(parent);
}




/////////////////LEGADO////////////////////


/*template<class Base_t>
void ABB_t<Base_t>::insertar(const Base_t data){
    
   nodoBB_t<Base_t>* padre = NULL;

   actual_ = raiz_;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   test_++; test_++;
   while(!vacio(actual_) && data != actual_->get_data()) {
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

}*/

/*template<class Base_t>
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
}*/
