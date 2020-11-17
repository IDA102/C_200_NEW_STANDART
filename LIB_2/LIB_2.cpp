/* LIB_2.cpp :*/

#include "H.h"
template <typename T>class ITERATOR
{
	T* element = nullptr;
public:
	ITERATOR(T* m) :element(m) {};
	//ITERATOR(const ITERATOR& q){};
	//ITERATOR& operator=(const ITERATOR& q);
	//ITERATOR& operator=(T); // присвоение нового значения
	T* operator++()	
	{
		//Не понимаю как тут через ноль перенести
		//element = (element + 1) % CAP
		element = (element + 1);
		return element;
		NOP
	};
	bool operator!=(const ITERATOR& q) { return static_cast<bool>(*q.element != *(this->element)); };
	T& operator*() {return *element;};
	T operator*(int unsigned) { return element; };
};
enum PRIZ { LESS, GREATER };
template<typename T> class TEMPL
{
	vector<T> tmp;
public:
	TEMPL(std::initializer_list<T> k)
	{
		set<T> e = k;
		for (auto x : e) {tmp.push_back(x);}
		NOP
	};
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
	void SORT(PRIZ priz)
	{ 
		switch (priz)
		{
			case LESS:
				sort(tmp.begin(), tmp.end(), less<T>());
				break;
			case GREATER:
				sort(tmp.begin(), tmp.end(), greater<T>());
				break;
		}
	};
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
	ITERATOR<T> begin() 
	{
		ITERATOR<T> q = &TMP[FIRST];
		return q;
	};
	ITERATOR<T> end()
	{ 
		ITERATOR<T> q = &TMP[LAST+1];
		return  q; 
	};
	void push(T &A)
	{
		if (!(CAP-N))
		{
			T* PROM = new T[CAP + 2];
			for (size_t i = 0; i < CAP; ++i) 
			{ 
				size_t ind = (FIRST + i) % CAP;
				PROM[i] = TMP[ind];
			};
			CAP = CAP + 2;
			T* PROM2 = TMP;
			TMP = PROM;
			PROM = PROM2;
			delete[] PROM;
		}
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
	MyUniquePTR() = delete;
	MyUniquePTR(T* tmp) :TMP(tmp) {};
	//MyUniquePTR(const  MyUniquePTR &tmp) {};
	MyUniquePTR(MyUniquePTR&& tmp){TMP = tmp.TMP; tmp.TMP = nullptr;};
	//T* GetString() { return &TMP; };
	//void SetNewString(const char* str) { *TMP = str; };
	T* operator->() { return TMP; };
	T& operator *() { return *TMP; }
	MyUniquePTR<T>& operator =(MyUniquePTR &&tmp) { T* SubZero = TMP; TMP = tmp.TMP; tmp.TMP = SubZero; return this; };
	explicit operator bool() const { return TMP == nullptr; };
	~MyUniquePTR() { delete TMP; };
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
		q.SORT(LESS);
		NOP
	}
	{
		MyQueue<string> q1{ string("AAA"),string("qwe") , string("vbn"),string("mjh") };
		//for (string it : q1){std::cout << it << ' ';}
		string s("123");
		q1.push(s);
		q1.push(s);
		q1.push(s);
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
		//initializer_list<string> r = { string("zzz"),string("xxx"),string("ccc") };
		//string * q = new string[3]{r};// Почему так не работает
		//string * q = new string[3]{ string("AAA"),string("qwe") }; // А так работает
	}
	{
		MyUniquePTR<string> p1(new string("abc"));
		std::cout << p1->front();
		p1->append("qwerty");
		string s2 = *p1;
		MyUniquePTR<string> p2 = move(p1);
		if (p1) { cout << "No object!" << endl; }
		MyUniquePTR<string> p3(new string("vvv"));
		//p3 = p2;
		vector<MyUniquePTR <string>> v25;
		v25.push_back(MyUniquePTR<string>(new string("abc")));
		v25.push_back(MyUniquePTR<string>(new string("def")));
		v25.push_back(MyUniquePTR<string>(new string("thy")));
		//list<MyUniquePTR<string>> l(make_move_iterator(v25.begin()), make_move_iterator(v25.end()));
		list<MyUniquePTR<string>> l;
		l.insert(l.end(), make_move_iterator(v25.begin()), make_move_iterator(v25.end()));
		NOP
		/*copy + move iterators*/
	}
}
