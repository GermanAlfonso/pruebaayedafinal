#pragma once
#include <cstdlib>

static const char alphanum[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

namespace AyEDA
{
	//double comparaciones= 0;
	typedef unsigned int DNI_inx_t;
	class DNI_t
	{
		private:
			DNI_inx_t DNI_;
			char letra_;
			
		public:
			DNI_t(DNI_inx_t DNI=(std::rand()));
			DNI_t(const DNI_t &x);
			~DNI_t(void);
			bool operator<(const DNI_t &x) const;
			bool operator<=(const DNI_t &x) const;
			bool operator>(const DNI_t &x) const;
			bool operator>=(const DNI_t &x) const;
			bool operator==(const DNI_t &x) const;
			bool operator!=(const DNI_t &x) const;
			DNI_inx_t operator%(DNI_inx_t x) const;
			DNI_t& operator=(const DNI_t &x);

			operator unsigned int(void) const;
			
	};	
}