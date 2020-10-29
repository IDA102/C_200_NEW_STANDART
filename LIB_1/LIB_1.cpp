﻿/*
 Практика 1:
 enum class
 initializer_list и универсальные списки инициализации
 auto
 decltype
 lambda 
*/

#include "H.h"
bool sortString(const char* a, const char* b){	return (strcmp(a, b) < 0);	};
class SortString_functor
{
public:
	bool operator()(const char* a, const  char* b) const	{ return sortString(a, b); }
};
string operator*(string &T,int TT)
{
	if (typeid(string) == typeid(T))
	{
		for (char &c :T)
		{
			if ((c > 64) & (c < 91)) { c = c + 32; }
			else if ((c > 96) & (c < 123)) { c = c - 32; }
		}
		NOP
		return T;
	}
	return T;

};
template <typename T> void PrintAnyCont(const T &CASE)
{	for (const auto &value : CASE)	{	cout << value << endl; } }
template <typename T> void NegateAll(T &CASE)
{		for (auto &value : CASE)	{		value = value * -1;	}	}
template <typename T> void absSort(T &CASE)
{
	//ИЛИ ЧЕРЕЗ ЗАХВАТ ОБЪЕКТА С MUTABLE
	auto iter_begin = std::begin(CASE);
	auto iter_end = std::end(CASE);
	for_each(iter_begin, iter_end, [](auto &x) { return x = abs(x); });//Я не понимаю, что я здесь сделал с auto(или чем его заменить);
	sort(iter_begin, iter_end);
	NOP
}
template <typename T, typename TT> auto SumCont(const T& V, const TT &L)
{

	auto iter_begin_V = std::begin(V);
	auto iter_end_V = std::end(V);

	auto iter_begin_L = std::begin(L);
	auto iter_end_L = std::end(L);
	
	//size_t SIZE_V = std::size(V);
	//size_t SIZE_L = std::size(L);

	size_t SIZE = (std::size(V) > std::size(L))? std::size(V) : std::size(L);
	vector<decltype(*iter_begin_V + *iter_begin_L)> tmp(SIZE); //Тут не правильно задаётся размерность


	//if (SIZE_V > SIZE_L) { std::copy(iter_begin, iter_end, tmp.push_back()); }
	//else { std::copy(iter_begin, iter_end, tmp.push_back()); }


	
	std::copy(iter_begin_V, iter_end_V, inserter(tmp, tmp.begin()));
	//auto sum = [](auto a, auto b) {return a+b};
	transform(iter_begin_L, iter_end_L, tmp.begin(), tmp.begin(), [](auto a, auto b) {return a + b; });
	return tmp;
	NOP  
}

/*void PrintAnyCont(vector<double> &T)
{
	for (const auto &value : T)
	{
		cout << value << endl;
	}
}*/

int main()
{
	/****************************************************/
	/* Задание 1 */ 
	{
		enum class months:unsigned char { January, February, March, April, May, June, July, August, September, October, November, December };
		enum class weekDays:unsigned char { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

		months m = months::January;
	/*а) уберите проблемы (это значит, что КОМПИЛЯТОР не должен позволять программисту осуществлять опасные сравнения!)*/

		//if (m == weekDays::Monday) {}

	/*б) оптимизируйте использование памяти*/
		months year[] = { months::January , months::February , months::March };
		size_t n = sizeof(year); //3 байта
		
		NOP;
		system("cls");
	}
	/****************************************************/
	/* Задание 2 */
	/*
		Создайте и с помощью списка инициализации заполните значениями вектор с элементами - string
		С помощью range-based for преобразуйте все буквы в верхний регистр а остальные символы должны остаться неизменными
	*/
	{
		vector<string> VS = { "QWE","zxc","1q2","w1e","qweQWE1q2w3e" };

		for (string&S:VS)
		{
			string OLD_S = S;
			//string::iterator pS_begin = S.begin();
			//string::iterator pS_end = S.end(); 
			for (char &c : S)
			{
				if ((c > 64) & (c < 91)) { c = c + 32; }
				else if ((c > 96) & (c < 123)){ c = c - 32; }
			}
			cout << S << "	" << OLD_S << "\n" << endl;
		}
		NOP
		system("cls");
	}

	/**********************************************************/
	/* Задание 3 */
	/*
		Создайте и заполните значениями map таким образом, чтобы он содержал в качестве ключа букву,
		а в качестве значения отсортированную по  алфавиту совокупность слов (string), начинающихся с этой буквы
	*/ 
	{
		const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
		map<char, set<const char*, SortString_functor>> mWords;
		for (size_t i = 0; i < 6; i++) { (mWords[*s[i]]).insert(s[i]); }
		NOP
	}
	/* 3а. */
	/*
		Проинициализируйте map "вручную" посредством списка инициализации
		С помощью range-based for и structured binding	распечатайте содержимое, например: A: any, apple, away
	*/
	{
		//map<char, string> mcs = { {'A',"AAA"} , {'B',"BBB"} , {'C',"CCC"} };
		//for (const auto [c,s]:mcs)	{	cout << c << " " << s << endl;	}
		//NOP
		//system("cls");
	}
	/* 3б. */
	/*
		Создайте пустой map и используйте заданный массив для выполнения задания.
		С помощью range-based for и structured binding распечатайте содержимое, например: A: any, apple, away
	*/
	{
		//дано (например):
		//const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
		//string q(s);
		//map<char, string> mcs = { {'A', s} };
		NOP
	//	for (const auto &[c,s]rM:mcs)
	//	{
	//		cout << c << s << endl;
	//	}	
		NOP
		system("cls");
	}
	/*********************************************************/
	/* Задание 4 */
	/*
		Cоздать функцию для вывода на печать	элементов последовательностей, заданных ниже:
	*/
	{
	 	vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		
		NOP
		system("cls");
	}
	/********************************************************/
	/* Задание 5 */
	/*
		Cоздать функцию для "отрицания" значений, например:
		было: {1, -2, 5}, стало: {-1, 2, -5})
		изменение объектов типа std::string может выглядеть "aBc1" -> "AbC1" элементов последовательностей, заданных ниже:
	*/
	{
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);
		PrintAnyCont(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		PrintAnyCont(ls);

		int ar[]{ 1, 2, 3 };
		NegateAll(ar);
		PrintAnyCont(ar);

		NOP
		system("cls");
	}
	/********************************************************/
	/* Задание 6 */
	/*
		Реализовать функцию сортировки по модулю	элементов последовательностей, заданных ниже
		Собственно для сортировки можно использовать обобщенный алгоритм sort(), а для задания условия - лямбда-функцию
	*/
	{
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		absSort(vd);
		NOP

		int ar[] = { -3, 2, -1 };
		absSort(ar);
		NOP
		system("cls");
	}

	/********************************************************/
	/* Задание 7 */
	/*
		Напишите функцию, которая будет формировать и возвращать вектор, каждый элемент которого является суммой элементов двух 
		последовательностей РАЗНОЙ длины и с элементами РАЗНОГО типа.

		Подсказка 1: так как последовательности могут быть разной длины, логично сделать размер результирующего
		вектора максимальным из двух

		Подсказка 2: подумайте о возможности использования алгоритмов copy() и transform(), в котором трансформирующее действие
		удобно в свою очередь задавать лямбда-функцией.

		например:
	*/
	{
		std::vector<int>  v{ 1  , 2  , 3  , 4 };
		std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };
		SumCont(v, l);
		auto Q = SumCont(v, l);
		NOP

		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		//auto Q = SumCont(ar, ll);
		NOP

		std::set<std::string> s{ "abc", "qwerty", "my" };
		std::deque<const char*> d{ "111", "22" };
		//auto Q = SumCont(s, d);

		NOP
	}

	/********************************************************/
	/*
		Задание 8. Реализуйте функцию, которая принимает следующие параметры:	
		сформированную последовательность любого типа с элементами любого типа, 
		два (пустых) контейнера любого типа из vector, list, deque, set 
		с элементами того же типа, что и у сформированной последовательности 

		Функция должна "разложить" значения заданной последовательности в два пустых контейнера 
		согласно заданному условию. Условие задать лябда-функцией
		Исходная последовательность при этом не меняется
	{
		Например:
		std::vector<int> v{ 1,2,3,4,5 };
		std::list<int> l; //сюда четные
		std::deque<int> d; //а сюда нечетные
		//Separate(v, l, d, <условие>);

		NOP
	}
	*/

	/********************************************************/
	/*
		Задание 9. C помощью алгоритма for_each()!!! 
		(а не count_if()) посчитать сколько букв в верхнем регистре.
		Использовать лямбда функцию
	*/
	//{
	//	char s[] = "Hello World!";
	//	//for_each
	//NOP
	//}

	/********************************************************/
	/*
		Задание 10. Реализовать конвертацию enum в строковое представление  - enumToString и наоборот - stringToEnum

		Подсказки: 
		1. Соответствующие именованным константам строки все равно нужно где-то хранить =>
		1.1 Именованные константы в перечислении должны быть уникальными => соответствующие строки
		тоже должны быть уникальными, => уникальные строки могут быть использованы в качестве
		ключа в std::map

		1.2 а вот значения (соответствующие именованым константам)
		могут быть любыми и даже могут повторяться (упрощаем задачу, считая, что значения НЕ повторяются) 
		=> подходит контейнер std::map<string,<значение> >

		1.3 Согласно стандарту С++11 переменные перечислимого типа могут быть разного размера и типа,
		а хотелось бы обеспечить универсальную конвертацию 

		2. Так как типы перечислений разные, то enumToString и stringToEnum должны быть шаблонными
		2.1 Пользователь может ошибиться или злонамеренно передать в функции значения, которым ничего не соответствует => защита!
		2.2 В функциях enumToString и stringToEnum (в зависимости от типа перечисления) нужно будет
		  анализировать соответствующий используемому типу перечисления контейнер

		3. Чтобы действия с map<string, <значение> > не зависили от типа перечисления, логично реализовать "обертку":
	*/
	/*
		template<typename T> struct EnumMap
		{
			static std::map<std::string, T> m_eMap;
			static const auto& getMap() { return m_eMap; }
		};
	*/

	//{
	//	//Например:
	//	/*
	//		COLORS c1;
	//		try {
	//			c1 = stringToEnum<COLORS>("blue");
	//		}
	//		catch (...)
	//		{
	//		//...
	//		}
	//		
	//		auto Str = enumToString(c1);
	//	*/

	//	NOP
	//}


	return 0;
}