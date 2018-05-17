#include "DNI_t.hpp"
#include "ABB_t.cpp"

void mostrarstats(std::vector<double> v){
    
    double max= *max_element(v.begin(), v.end());
    double min= *min_element(v.begin(), v.end());
    float  avg= accumulate(v.begin(), v.end(), 0.0)/v.size(); 
    
    
    std::cout << "Media: "  << avg << std::endl;
    
    std::cout << "Mínimo: " << min << std::endl;
    
    std::cout << "Máximo: " << max << std::endl;
    
    std::cout << "______________________" << std::endl;
    
}

void demostracion(void){
    
    ABB_t<int> arbold;
    
    std::cout << "Ha inicializado en modo Demostración." << std::endl;
    std::cout << "A contiunacion, procederemos a crear un arbol de BBS de N nodos." << std::endl;
    
    bool ciclo= true;
    while(ciclo== true){
        std::cout << std::endl;
        std::cout << " Por favor, indique como desea proceder:" << std::endl;
        std::cout << " > [i]nsertar clave." << std::endl;
        std::cout << " > [e]liminar Clave" << std::endl;
        std::cout << " > [x] Salir del programa." << std::endl << std::endl;
        std::cout << " [Selección] >> ";
    
        char pgm;
        int val;
        std::cin >> pgm;
        std::cout << std::endl << std::endl;
    
    
        switch(pgm){
        
            case('i'):
                std::cout << " [Inserte valor] >> ";
                std::cin >> val;
                std::cout << std::endl;
            
                arbold.insertar(val);
                arbold.verArbol();
            break;
            
            case('e'):
                std::cout << " [Inserte valor] >> ";
                std::cin >> val;
                std::cout << std::endl;
            
                arbold.borrar(val);
                arbold.verArbol();
            break;
            
            case('x'):
                ciclo= false;
            break;
            
            default:
                std::cout << " Opción inválida. " << std::endl;
            break;
            
        }
    }       
}


void estadistica(void){
    
    ABB_t<AyEDA::DNI_t> arbole;
    
    std::cout << "Ha inicializado en modo Demostración." << std::endl;
    std::cout << "A contiunacion, procederemos a crear un arbol de BBS de N nodos." << std::endl;
    std::cout << " [Inserte N] >> ";
    
    int N;
    std::cin >> N;
    std::cout << std::endl << std::endl;
    
    std::cout << " [Inserte nPruebas] >> ";
    
    int nPruebas;
    std::cin >> nPruebas;
    std::cout << std::endl << std::endl;
    
    std::vector<AyEDA::DNI_t> v;
    for(int i= 0; i< N*2; i++){
		v.push_back(AyEDA::DNI_t());
	}
    
    for(int i= 0; i< N; i++){
        arbole.insertar(v[i]);
    }
    
    std::cout << "Comparaciones en búsqueda:" << std::endl;
    std::vector<double> vbusqueda;
    for(int i= 0; i< nPruebas; i++){
        int r= std::rand()% N;
        arbole.buscar(v[r]);
        
        vbusqueda.push_back(arbole.get_test());
        arbole.get_test()= 0;
    }
    mostrarstats(vbusqueda);
    
    std::cout << "Comparaciones en inserción:" << std::endl;
    std::vector<double> vinsert;
    for(int i= 0; i< nPruebas; i++){
        
        int r= N + ( std::rand() % ( N*2 - N + 1 ) );
        arbole.insertar(v[r]);
        
        vinsert.push_back(arbole.get_test());
        arbole.get_test()= 0;
    }
    mostrarstats(vinsert);
    
}





int main(){
    
    srand(52601583);
    
    std::cout << std::endl;
    std::cout << " [Práctica 5 AYEDDA] " << std::endl;
    
    bool ciclo= true;
    
    while(ciclo== true){
    
        std::cout << std::endl;
        std::cout << " Por favor, indique como desea inicializar:" << std::endl;
        std::cout << " > Programa modo [d]emostración." << std::endl;
        std::cout << " > Programa modo [e]stadística." << std::endl;
        std::cout << " > [x] Salir del programa." << std::endl << std::endl;
        std::cout << " [Selección] >> ";

        char pgm;
        std::cin >> pgm;
        std::cout << std::endl << std::endl;
    
        switch(pgm){
        
            case('d'):
            //demostrar= true;
            demostracion();
            break;
                
            case('e'):
            estadistica();
            break;
        
            case('x'):
            ciclo= false;
            break;
        
            default:
            std::cout << " Opción inválida, por favor, seleccione [e]stadística, [d]emostración o [x]Salir. " << std::endl;
            break;
            
        }
    
    }
    
}