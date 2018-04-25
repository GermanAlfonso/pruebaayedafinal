#include "DNI_t.hpp"
#include "f_ordenacion_t.hpp"

void mostrarstats(std::vector<double> v){
    
    //std::cout << "test: " << std::endl;
    
    double max= *max_element(v.begin(), v.end());
    double min= *min_element(v.begin(), v.end());
    float  avg= accumulate(v.begin(), v.end(), 0.0)/v.size(); 
    
    
    std::cout << "Media: "  << avg << std::endl;
    
    std::cout << "Mínimo: " << min << std::endl;
    
    std::cout << "Máximo: " << max << std::endl;
    
    std::cout << "______________________" << std::endl;
    
}



void demostracion(void){
    
    std::cout << "Ha inicializado en modo Demostración." << std::endl;
    std::cout << "A contiunacion, procederemos a ordenar un vector de tamaño N con el método de ordenación que desee." << std::endl;
    std::cout << "En primer lugar, seleecione el tamaño de la secuencia a ordenar >> ";
    
    int N;
    std::cin >> N;
    std::cout << std::endl;
    
    std::vector<AyEDA::DNI_t> v;
    for(int i= 0; i< N; i++){
		v.push_back(AyEDA::DNI_t());
	}
    
    std::cout << "Elija el método mediante el que desee ordenar: " << std::endl;
    std::cout << " [I]nserción. " << std::endl;
    std::cout << " Por intercambio, método de la [B]urbuja. " << std::endl;
    std::cout << " [H]eapSort. " << std::endl;
    std::cout << " [Q]uickSort. " << std::endl;
    std::cout << " [S]hellSort. " << std::endl;
    std::cout << " [Selección] >> ";
    
    char met;
    std::cin >> met;
    std::cout << std::endl;
    
     switch(met){
        
        case('I' | 'i'):{
        	AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_ins(v, N);
        	ord_ins.execute_insercion();
            break;
        }
        case('B' | 'b'):{
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_bub(v, N);
            ord_bub.execute_bubblesort();
            break;
        }
        //Función
        break;
        case('H' | 'h'):{
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_hea(v, N);
            ord_hea.execute_heapsort();
            break;
        }
        case('Q' | 'q'):{
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_qui(v, N);
            ord_qui.execute_quicksort(0, N-1);
            break;
        }
        
        case('S' | 's'):{
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_she(v, N);
            ord_she.execute_shellsort();
            break;
        }
        default:
        std::cout << " [ERROR]: NO EXSISTE LA FUNCIÓN DE ORDENACIÓN " << met << ". " << std::endl << std::endl;
     }
     
}


void estadistica(void){
    
    std::cout << "Ha inicializado en modo Estadística." << std::endl;
    std::cout << "A contiunacion, evaluaremos la eficiencia de los diferentes métodos de ordenación." << std::endl;
    std::cout << "En primer lugar, seleecione el tamaño de la secuencia a ordenar >> ";
    
    int N;
    std::cin >> N;
    std::cout << std::endl;
    
    std::cout << "En segundo lugar, seleecione el número de ordenaciones >> ";
    
    int P;
    std::cin >> P;
    std::cout << std::endl;
    
    std::cout << "______________________" << std::endl;
    
    std::cout << "[Inserción]" << std::endl;
    std::vector<double> vinsercion;
    for(int i= 0; i< P; i++){
            std::vector<AyEDA::DNI_t> v;
            for(int i= 0; i< P; i++){
		        v.push_back(AyEDA::DNI_t());
	        }
        
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_ins(v, N);
            ord_ins.execute_insercion();
            
            double aux = cambios;
            vinsercion.push_back(aux);
            cambios= 0;
            //std::cout << "test." << std::endl;
    }
    mostrarstats(vinsercion);
    
    std::cout << "[Bubblesort]" << std::endl;
    std::vector<double> vbs;
    for(int i= 0; i< P; i++){
            std::vector<AyEDA::DNI_t> v;
            for(int i= 0; i< P; i++){
		        v.push_back(AyEDA::DNI_t());
	        }
        
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_bub(v, N);
            ord_bub.execute_bubblesort();
            
            double aux = cambios;
            vbs.push_back(aux);
            cambios= 0;
    }
    mostrarstats(vbs);
    
    std::cout << "[Heapsort]" << std::endl;
    std::vector<double> vhs;
    for(int i= 0; i< P; i++){
            std::vector<AyEDA::DNI_t> v;
            for(int i= 0; i< P; i++){
		        v.push_back(AyEDA::DNI_t());
	        }
        
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_hea(v, N);
            ord_hea.execute_heapsort();
            
            double aux = cambios;
            vhs.push_back(aux);
            cambios= 0;
    }
    mostrarstats(vhs);
    
    std::cout << "[Quicksort]" << std::endl;
    std::vector<double> vqs;
    for(int i= 0; i< P; i++){
            std::vector<AyEDA::DNI_t> v;
            for(int i= 0; i< P; i++){
		        v.push_back(AyEDA::DNI_t());
	        }
        
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_qui(v, N);
            ord_qui.execute_quicksort(0, N-1);
            
            double aux = cambios;
            vqs.push_back(aux);
            cambios= 0;
    }
    mostrarstats(vqs);
    
    std::cout << "[Shellsort]" << std::endl;
    std::vector<double> vss;
    for(int i= 0; i< P; i++){
            std::vector<AyEDA::DNI_t> v;
            for(int i= 0; i< P; i++){
		        v.push_back(AyEDA::DNI_t());
	        }
        
            AyEDA::f_ordenacion_t<AyEDA::DNI_t> ord_she(v, N);
            ord_she.execute_shellsort();
            
            double aux = cambios;
            vss.push_back(aux);
            cambios= 0;
    }
    mostrarstats(vss);
    
}





int main(){
    
    srand(61792674);
    
    std::cout << std::endl;
    std::cout << " [Práctica 5 AYEDDA] " << std::endl;
    
    bool ciclo= true;
    
    while(ciclo== true){
    
    std::cout << std::endl;
    std::cout << " Por favor, indique como desea inicializar:" << std::endl;
    std::cout << " > Programa modo [D]emostración." << std::endl;
    std::cout << " > Programa modo [E]stadística." << std::endl;
    std::cout << " > [X] Salir del programa." << std::endl << std::endl;
    std::cout << " [Selección] >> ";

    char pgm;
    std::cin >> pgm;
    std::cout << std::endl << std::endl;
    
    switch(pgm){
        
        case('D' | 'd'):
        demostrar= true;
        demostracion();
        break;
        
        case('E' | 'e'):
        estadistica();
        break;
        
        case('X' | 'x'):
        ciclo= false;
        break;
        
        default:
        std::cout << " Opción inválida, por favor, seleccione [E]stadística, [D]emostración o [X]Salir. " << std::endl;
        break;
        
    }
    
    }
    
}