/* LIB_2.cpp :*/

#include "H.h"

template<typename T> class TEMPL
{
	vector<T> tmp;
public:
	TEMPL(std::initializer_list<T> l) :tmp{l}{};//Будет ли тут move?, или требуется принудительно сказать
	TEMPL(T* h, T* hh):tmp{ h,hh } { /*tmp.insert(tmp.end(), h, hh); */};
	//TEMPL(T* h, T* hh) { tmp.insert(tmp.end(), h, hh); };
	void TEMP_SET(std::initializer_list<T> l)	{ tmp.insert(tmp.end(),l); };
	void TEMP_SET(T* h, T* hh) { tmp.insert(tmp.end(), h, hh); };
	void TEMP_DELETE(std::initializer_list<T> l)
	{ 
		tmp.erase(tmp[]); 
	};
	void TEMP_DELETE_ALL() {tmp.clear()};
	//void TEMP_set(vector<int>::iterator h, vector<int>::iterator hh)<<<<---------------------хочется что-то похожее
};


int main()
{
	int M[5] = { 11,12,13,14,15 };
	TEMPL<int> q{1,2,3,4};
	TEMPL<int> qq{ std::begin(M),std::end(M) };
	//q.TEMP_set(std::begin(M),std::end(M));
	NOP
}
