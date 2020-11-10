/* LIB_2.cpp :*/

#include "H.h"

template<typename T> class TEMPL
{
	vector<T> tmp;
public:
	TEMPL(std::initializer_list<T> l) :tmp{l}{};
	void TEMP_SET(std::initializer_list<T> l)	{ tmp.insert(tmp.end(),l); };
	//Удаление любого количества зачении заданого списком инициализации
	void TEMP_DELETE_LI(std::initializer_list<T> l)
	{ 
		typename vector<T>::iterator it;
		for (auto x : l)
		{ 
			it = tmp.begin();
			while (it!=tmp.end())
			{ 
				if (*it == x)
				{ it = tmp.erase(it); }
				else { ++it; }
			} 
		}
	};
	//Удаление любого количества зачении заданного "ОТ" и "ДО".
	void TEMP_DELETE_RANGE(int a,int b)
	{
		try
		{ 
			tmp.at(a + b);	
			if(a < b) tmp.erase(tmp.begin() + a-1, tmp.begin() + b);
		}
		catch (std::out_of_range) { cout << "out_of_range"; }		
	};
	void SORT()	{sort(tmp.begin(),tmp.end());};
	
	//TEMPL(T* h, T* hh) :tmp{ h,hh } { /*tmp.insert(tmp.end(), h, hh); */ };
	//void TEMP_SET(T* h, T* hh) { tmp.insert(tmp.end(), h, hh); };
	//void TEMP_set(vector<int>::iterator h, vector<int>::iterator hh)<<<<---------------------хочется что-то похожее
};
template<typename T> class TEMP_BUFF
{
	T* TMP = nullptr;
};
template<typename T> class MyUniquePTR
{
	 T* TMP = nullptr;
public:
	MyUniquePTR(T* tmp) :TMP(tmp) {};
	MyUniquePTR(const MyUniquePTR&) = delete;
	MyUniquePTR(MyUniquePTR&& tmp) = default;
	~MyUniquePTR() { delete TMP; };
	T* GetString() { return &TMP; };
	void SetNewString(const char* str) { *TMP = str; };
	T* operator->() { return TMP; };
	T& operator *() { return *TMP; }
	explicit operator bool() const { return TMP == nullptr; };
};
int main()
{
	{
		int M[6] = { 11,12,13,14,14,15 };
		TEMPL<int> q = { 1,2,3,4,4 };
		q.TEMP_SET({ 1,2,11,12,13,14 });
		q.TEMP_DELETE_LI({ 1,2 });
		q.TEMP_DELETE_RANGE(1, 3);
		q.TEMP_SET({ 1,2,11,12,13,14 });
		q.SORT();
		NOP
	}
	{

		NOP
	}
	{
		MyUniquePTR<string> p1(new string("abc"));
		std::cout << p1->front();
		p1->append("qwerty");
		string s2 = *p1;
		MyUniquePTR<string> p2 = move(p1);
		if (p1) { cout << "No object!" << endl; }
		MyUniquePTR<string> p3(new string("vvv"));
		//p3 = p2;//И здесь компилятор должен выдавать ошибку
		vector< MyUniquePTR < string >> v;
		list< MyUniquePTR < string >> l;
		
		/*copy + move iterators*/
		NOP
	}
}
