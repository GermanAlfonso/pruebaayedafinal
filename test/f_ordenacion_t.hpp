#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>


bool demostrar= false;
double cambios= 0;

namespace AyEDA{
    
    typedef unsigned int f_ordenacion_inx_t;
    template<class Base_t>
    class f_ordenacion_t{
        
        protected:
    
            std::vector<Base_t> vector_;
            f_ordenacion_inx_t size_;
        
        public:
            
            //CONSTRUCTOR / DESTRUCTOR
            f_ordenacion_t(std::vector<Base_t> vector, f_ordenacion_inx_t size):
            vector_(vector),
            size_(size)
            {}
            
            ~f_ordenacion_t(){};
            
            //UTILIDAD
            void heapify(int n, int i);
            
            //ORDENACIÓN
            void execute_insercion();
            void execute_bubblesort();
            void execute_heapsort();
            void execute_quicksort(int left, int right);
            void execute_shellsort();
        
    };
    
    template<class Base_t> 
    void f_ordenacion_t<Base_t>::execute_insercion(void){
       
       int i, j;
       Base_t actual;
       
       for (i = 1; i < size_; i++) {
        actual = vector_[i];
        for (j = i; j > 0 && vector_[j - 1] > actual; j--) {
            vector_[j] = vector_[j - 1];
            cambios++;
        }
        vector_[j] = actual;
        cambios++;
        
        //Mostrar por pantalla el vector
        if(demostrar==true){
        for (int i= 0; i<size_; i++){            //std::cout << *i << ' ';
            std::cout << vector_[i] << "   ";
        }
        std::cout << std::endl;}
        
       }
    }
    
    template<class Base_t> 
    void f_ordenacion_t<Base_t>::execute_bubblesort(void){
        
        int i, j;
        for (i = 0; i < size_-1; i++)      
            for (j = 0; j < size_-i-1; j++){
                if (vector_[j] > vector_[j+1]){
                    Base_t temp= vector_[j];
                    vector_[j]= vector_[j+1];
                    vector_[j+1]= temp;
                    cambios++;

                    if(demostrar){
                    for (int i= 0; i<size_; i++){
                        std::cout << vector_[i] << "   ";
                    }
                    std::cout << std::endl;}
                }
            }
    }    
    
    template<class Base_t> 
    void f_ordenacion_t<Base_t>::execute_heapsort(void){
        
        // Build heap (rearrange array)
        for (int i = size_ / 2 - 1; i >= 0; i--)
            heapify(size_, i);
 
        // One by one extract an element from heap
        for (int i=size_-1; i>=0; i--){
            //swap(vector_[0], vector_[i]);
            
            Base_t temp= vector_[0];
            vector_[0]= vector_[i];
            vector_[i]= temp;
            cambios++;
            
            if(demostrar){
            for (int xxx= 0; xxx<size_; xxx++){
                std::cout << vector_[xxx] << "   ";
            }
            std::cout << std::endl;}  
            
            
            
            // call max heapify on the reduced heap
            heapify(i, 0);
        }





    }
    
    template<class Base_t> 
    void f_ordenacion_t<Base_t>::execute_quicksort(int left, int right){
        
        int min = (left+right)/2;
        
        int i = left;
        int j = right;
        Base_t pivot = vector_[min];

        while(left<j || i<right)
        {
            while(vector_[i]<pivot)
            i++;
            while(vector_[j]>pivot)
            j--;
    
            if(i<=j){
                
                int temp = vector_[i];
                vector_[i] = vector_[j];
                vector_[j] = temp;
                cambios++;
                
                if(demostrar){
                for (int xxx= 0; xxx<size_; xxx++){
                    std::cout << vector_[xxx] << "   ";
                }
                std::cout << std::endl;}  
                
                i++;
                j--;
            }
            else{
                if(left<j)
                    this->execute_quicksort(left, j);
                if(i<right)
                    this->execute_quicksort(i,right);
                return;
            }
        }
        
        
        
        
    }
    
    template<class Base_t> 
    void f_ordenacion_t<Base_t>::execute_shellsort(void){
        
    	int i, j, k;
    	
	    // Gap 'i' between index of the element to be compared, initially n/2.
	    for(i = size_/2; i > 0; i = i/2){
		    for(j = i; j < size_; j++){
		    	for(k = j-i; k >= 0; k = k-i){
		    		// If value at higher index is greater, then break the loop.
		    		if(vector_[k+i] >= vector_[k])
		    		break;
		    		// Switch the values otherwise.
		    		else
		    		{
		    			Base_t temp = vector_[k];
		    			vector_[k] = vector_[k+i];
		    			vector_[k+i] = temp;
		    			cambios++;
		    			
		    			if(demostrar){
		    			for (int xxx= 0; xxx<size_; xxx++){
                            std::cout << vector_[xxx] << "   ";
                        }
                        std::cout << std::endl;}  
		    			
		    		}
		    	}
		    }
	    }
        
    }
    
    template<class Base_t> 
    void f_ordenacion_t<Base_t>::heapify(int n, int i){
        
        int largest = i;  // Initialize largest as root
        int l = 2*i + 1;  // left = 2*i + 1
        int r = 2*i + 2;  // right = 2*i + 2
     
        // If left child is larger than root
        if (l < n && vector_[l] > vector_[largest])
            largest = l;
     
        // If right child is larger than largest so far
        if (r < n && vector_[r] > vector_[largest])
            largest = r;
     
        // If largest is not root
        if (largest != i)
        {
            //swap(vector_[i], vector_[largest]);
     
            Base_t temp= vector_[i];
            vector_[i]= vector_[largest];
            vector_[largest]= temp;
            cambios++;
            
            if(demostrar){
            for (int xxx= 0; xxx<size_; xxx++){
                std::cout << vector_[xxx] << "   ";
            }
            std::cout << std::endl;}  
     
            // Recursively heapify the affected sub-tree
            heapify(n, largest);
        }
        
        
        
    }
    
}