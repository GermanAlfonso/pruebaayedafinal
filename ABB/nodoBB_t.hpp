#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

template<class Base_t>
class nodoBB_t{
    
    private:
    
    Base_t data_;
    
    nodoBB_t* izq_;
    nodoBB_t* der_;
    
    public:
    
    nodoBB_t(Base_t data) : data_(data), izq_(NULL), der_(NULL) {} 
    ~nodoBB_t() {}
    
    Base_t& get_data(){return data_;}
    
    nodoBB_t*& get_izq(){return izq_;}
    nodoBB_t*& get_der(){return der_;}
    
};