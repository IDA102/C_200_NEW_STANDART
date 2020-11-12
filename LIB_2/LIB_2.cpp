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
template<typename T> class MyQueue
{
	size_t CAP = 0;
	size_t N = 0;
	size_t FIRST = 0;
	size_t LAST = 0;

	T* TMP = nullptr;
public:
	MyQueue(std::initializer_list<T> l)
	{
		size_t q = l.size();
		TMP = new T[q+2];
		typename initializer_list<T>::iterator it = l.begin();
		size_t k = 0;
		while (it !=l.end())
		{
			TMP[k] = *it;
			++it;
			++k;
		}
		FIRST = 0;
		LAST = FIRST+q-1;
		CAP = q+2;
		N = q;
	};
	MyQueue(int x, T y)
	{
		TMP = new T[x + 2];
		for (int i = 0; i < x ; i++)
		{ 
			TMP[i] = y; 
		}
		FIRST = 0;
		LAST = FIRST + x - 1;
		CAP = x + 2;
		N = x;
	};
	MyQueue(const MyQueue& x)
	{
		CAP = x.CAP;
		N = x.N;
		FIRST = x.FIRST;
		LAST = x.LAST;
		TMP = new T[CAP];
		//memcpy(x.TMP, TMP,/*размер*/);// Это для класса MyString, там массив встроен в класс.
		for (int i = 0 ; i<N ; i++)	{TMP[i] = x.TMP[i];	}
	}
	MyQueue(MyQueue& x)
	{
		CAP = x.CAP;
		N = x.N;
		FIRST = x.FIRST;
		LAST = x.LAST;
		TMP = new T[CAP];
		//memcpy(x.TMP, TMP,/*размер*/);// Это для класса MyString, там массив встроен в класс.
		for (int i = 0; i < N; i++) { TMP[i] = x.TMP[i]; }
	}
	MyQueue(MyQueue&& x)
	{
		CAP = x.CAP;
		N = x.N;
		FIRST = x.FIRST;
		LAST = x.LAST;
		TMP = x.TMP;
		x.TMP = nullptr;
	}
	MyQueue(const MyQueue&& x)
	{
		CAP = x.CAP;
		N = x.N;
		FIRST = x.FIRST;
		LAST = x.LAST;
		TMP = x.TMP;
		x.TMP = nullptr;
	}
	const T* begin() { return TMP; };
	const T* end() { return  TMP + N + 1; };
	void push(T &A)
	{
		if (!(CAP-N)) {/*Расширение массива*/ }
		else
		{
			LAST = (FIRST + N) % CAP;
			TMP[LAST] = A;
			++N;
			NOP
		}
	}
	void push(const T &A)
	{
		if (!(CAP - N)) {/*Расширение массива*/ }
		else
		{
			LAST = (FIRST + N) % CAP;
			TMP[LAST] = A;
			++N;
			NOP
		}
	}
	T pop()
	{
		T tm = TMP[FIRST];
		//ШУТКИ РАДИ ЧЕРЕЗ IF
		if		(FIRST < LAST)					  { ++FIRST; --N; }
		else if((FIRST > LAST) & (FIRST != --CAP)){	++FIRST; --N;}
		else if((FIRST > LAST) & (FIRST == --CAP)){	FIRST = 0; --N;}
		return tm;
	};
	void operator= (const MyQueue<T> & x)
	{
		if ( CAP < x.N)
		{
			auto t = new T[x.N + 2];
			delete[] TMP;
			TMP = t;
		}
		for (int i = 0; i < x.N; i++) { TMP[i] = x.TMP[i]; }
		N = x.N;
		FIRST = x.FIRST;
		LAST = x.LAST;
		CAP = x.CAP;
		N = x.N;
		FIRST = x.FIRST;
		LAST = x.LAST;
	};
	~MyQueue(){ delete[] TMP; }
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
		//initializer_list<string> r = { string("zzz"),string("xxx"),string("ccc") };
		//string * q = new string[3]{r};// Почему так не работает
		//string * q = new string[3]{ string("AAA"),string("qwe") }; // А так работает
		
		MyQueue<string> q1{ string("AAA"),string("qwe") };
		for (auto el : q1) { std::cout << el << ' '; }//Что тут перегрузить что бы были корректные итераторы based for
		string s("123");
		q1.push(s);
		q1.push(string("456"));
		string s1 = q1.pop();
		q1.push("qqq");
		MyQueue<string> q2 = q1;
		MyQueue<string> q22 = std::move(q1);
		MyQueue<string> q3{ 10 , string("!") };
		q1 = q3;
		q2 = MyQueue<string>(5, string("?"));//<---- правильней вызывать move
		q1 = { string("bbb"), string("ssss") };
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
