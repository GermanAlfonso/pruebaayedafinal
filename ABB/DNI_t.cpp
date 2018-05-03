#include "DNI_t.hpp"

//double test= 0;

namespace AyEDA
{

	DNI_t::DNI_t(DNI_inx_t DNI):
		DNI_(DNI%100000000),
		letra_(alphanum[rand() % 25])
		{}
	
	DNI_t::DNI_t(const DNI_t &x):
		DNI_(x.DNI_),
		letra_(alphanum[rand() % 25])
		{}

	DNI_t::~DNI_t(void)
	{}

	bool DNI_t::operator<(const DNI_t &x) const
	{
		//test++;
		if(DNI_==x.DNI_){return (letra_<x.letra_);}
		return(DNI_<x.DNI_);
	}

	bool DNI_t::operator<=(const DNI_t &x) const
	{
		//test++;
		if(DNI_==x.DNI_){return (letra_<=x.letra_);}
		return(DNI_<=x.DNI_);
	}

	bool DNI_t::operator>(const DNI_t &x) const
	{
		//test++;
		if(DNI_==x.DNI_){return (letra_>x.letra_);}
		return(DNI_>x.DNI_);
	}

	bool DNI_t::operator>=(const DNI_t &x) const
	{
		//test++;
		if(DNI_==x.DNI_){return (letra_>=x.letra_);}
		return(DNI_>=x.DNI_);
	}

	bool DNI_t::operator==(const DNI_t &x) const
	{
		//test++;
		if(DNI_==x.DNI_){return (letra_==x.letra_);}
		return(DNI_==x.DNI_);
	}

	bool DNI_t::operator!=(const DNI_t &x) const
	{
		//test++;
		if(DNI_==x.DNI_){return (letra_!=x.letra_);}
		return(DNI_!=x.DNI_);
	}

	DNI_inx_t DNI_t::operator%(DNI_inx_t x) const
	{	//No funciona atm, tengo que areglar el sobrecargado inicial
		return(DNI_%x);
	}

	DNI_t& DNI_t::operator=(const DNI_t &x)
	{
		DNI_= x.DNI_;
		letra_= x.letra_;
		return(*this);
	}
	

	DNI_t::operator unsigned int(void) const
	{
		return(DNI_);
	}
}