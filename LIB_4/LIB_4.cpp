#include "H.h"

template <typename T,typename TT> void ADD(T& a ,const TT b)
{
	bool BOOL = is_same<T, vector<TT>>::value;
	if (BOOL)
	{	for (size_t x = 0; x < a.size(); ++x){a[x] = a[x] + b;} 	}
};
template<typename T> void OUT(const T& a)
{	
	if constexpr (is_pointer<remove_reference<decltype(*begin(a))>::type>::value) 
	{
		for (auto val : a){cout << *val << " ";}
		cout << endl;
	}
	else 
	{
		for (auto val : a){cout << val << " ";}
		cout << endl;
	}
};
template<typename T>void DA(T A)
{
	size_t n = A.size();
	if constexpr (is_same< T, priority_queue<T::value_type>>::value)
	{
		if constexpr (is_same<T, priority_queue<T::value_type, T::container_type, T::value_compare>>::value) 
		{
			if constexpr (is_pointer<T::value_type>::value) 
			{
				for (size_t i = 0; i < n; i++)
				{
					cout << *(A.top()) << " ";
					A.pop();
				}
			}
			else
			{
				for (size_t i = 0; i < n; i++)
				{
					cout << A.top() << " ";
					A.pop();
				}
			}
			cout << endl;
		}
	}
	else if constexpr (is_same<T, queue<T::value_type, T::container_type>>::value) 
	{
		if constexpr (is_pointer<T::value_type>::value) 
		{
			for (size_t i = 0; i < n; i++)
			{
				cout << *(A.front()) << " ";
				A.pop();
			}
		}
		else
		{
			for (size_t i = 0; i < n; i++)
			{
				cout << A.front() << " ";
				A.pop();
			}
		}
		cout << endl;
	}
	else if constexpr (is_same<T, stack<T::value_type, T::container_type>>::value)
	{
		if constexpr (is_pointer<T::value_type>::value)
		{
			for (size_t i = 0; i < n; i++)
			{
				cout << *(A.top()) << " ";
				A.pop();
			}
		}
		else
		{
			for (size_t i = 0; i < n; i++) 
			{
				cout << A.top() << " ";
				A.pop();
			}
		}
		cout << endl;
	}
}
int main()
{
	/***************************************************************/
	/* Задание 1 */
	/*
		Реализуйте шаблон функции для печати любых последовательностей (vector, list, deque, set и встроенного массива), которые могут содержать:
		•	как объекты любого типа,
		•	так и указатели на объекты любого типа (указатели распечатывать неинтересно => в этом случае следует получать значение по адресу)
		Подсказки: if constexpr
	*/
	{
		vector<int> v{ 1,2,3,4,5 };
		list<int> l{ 6,7,8,9 };
		deque<double> d{ 1.1,2.2,3.3,4.4 };
		set<int> s{ 1,3,5,7,9};
		int M[] = { 10,20,30,40,50,60,70,80,90 };
		vector<string*> pV{ new string("a"),new string("b") ,new string("c") };
		OUT(v);	system("cls");
		OUT(l);	system("cls");
		OUT(d);	system("cls");
		OUT(s);	system("cls");
		OUT(M);	system("cls");
		OUT(pV);system("cls");
		NOP
	}
	/***************************************************************/
	/* Задание 2 */
	/* Реализуйте шаблон функции сложения двух значений.
		Если первое слагаемое является вектором, то все элементы вектора нужно увеличить на значение второго параметра. При этом элементы вектора и второй параметр должны быть
		одного и того же типа.
		Подсказки: if constexpr, is_same
	*/
	{
		vector<int> q = { 1,2,3,4,5 };
		float f = 2;
		int in = 1;
		ADD( q , in );
		NOP
	}
	/***************************************************************/
//Задание 3.
	/* 	Реализуйте шаблон функции вывода на печать значений элементов любого адаптера (stack, queue, priority_queue)
		Подсказки: if constexpr, is_same
		Предусмотрите вывод значений, если в адаптере хранятся указатели.
	*/
	{
		stack<int> st;
		stack<int*> stPtr;
		queue<int> q;
		queue<int*> qPtr;
		priority_queue<int> pq;
		priority_queue<int*> pqPtr;

		for (int i = 0; i < 5; i++) {
			st.push(i + 1);
			stPtr.push(new int(i + 10));

			q.push(i - 1);
			qPtr.push(new int(i + 25));

			pq.push(i + 100);
			pqPtr.push(new int(i + 111));
		}

		DA(st);
		DA(stPtr);

		DA(q);
		DA(qPtr);

		DA(pq);
		DA(pqPtr);
		NOP
	}

	/***************************************************************/
	//Задание 4.
	{
		//Дан массив элементов типа string
		std::string strings[] = { "abc", "123", "qwerty", "#$%" };
		//До завершения фрагмента строки должны существовать в единственном экземпляре.
		//Требуется обеспечить манипулирование строками а) без копирования и б) без изменения порядка
		//элементов в массиве!

		//В std::set "складываем" по алфавиту обертки для строк, которые содержат только буквы 


		__asm nop
		/******************************************************************************************/

		//В std::vector "складываем" обертки для строк, которые содержат только цифры 
		//Выводим на экран
		//Находим сумму

		//std::vector<std::shared_ptr < std::string>>

		/******************************************************************************************/
		//сюда "складываем" обертки для строк, которые не содержат ни символов букв, ни символов цифр
		//и просто выводим


	}


	/******************************************************************************************/
	//Задание 5. 
	{
		//Дано:
		std::string ar[] = { "my","Hello", "World" };
		std::vector < std::shared_ptr<std::string>> v = { std::make_shared<std::string>("good"), std::make_shared<std::string>("bye") };



		//а) Требуется добавить в вектор обертки для элементов массива, НЕ копируя элементы массива! 
		//б) Отсортировать вектор по алфавиту и вывести на экран
		//в) Обеспечить корректное освобождение памяти


		__asm nop
	}
	/***************************************************************/
		//Задание 6. shared_ptr и weak_ptr
		//Создаем генеалогическое дерево посредством класса human. В классе хранятся:
		//имя - string
		//возможно признак: жив или уже нет...
		//родители - shared_ptr (родители не всегда известны...)
		//дети - контейнер из weak_ptr (чтобы избежать циклических зависимостей)

		//Методы класса human:
		//конструктор - для инициализации имени и признака
		//конструктор копирования, оператор присваивания, move ???
		//статический метод child() - 
		//				должен создать создать и вернуть обертку для родившегося человека
		//				+ сформировать все связи ребенка с родителями и наоборот

		//Ввести возможность распечатать генеалогическое дерево для указанного индивидума

	{
		//История должна с кого-то начинаться => "Жили-были дед да баба, например, Адам и Ева"
		//(то есть на самом деле два деда и две бабы):


		//std::shared_ptr<human> grandM1(new human("Eva"));
		//...

		//у них появились дети - child():


		//а у детей в свою очередь свои дети:


		//...
		__asm nop
	}



	//***************************************************************/
	//Задание 7.

		/*Пользовательский deduction guide – для вывода типов параметров шаблона
		Задан шаблон класса, который инкапсулирует внедренный ограниченный массив известной
		размерности с элементами любого типа. */
		/*
		template<typename T, size_t size> class MyArray
			{
				T ar[size]; //как обеспечить инициализацию элементов базового типа по умолчанию нулем?
				…
			};

		*/
		/*
		//Требуется обеспечить работоспособность приведенных примеров использования.
			{
				MyArray<int, 5> ar1;//MyArray<int,5>
				MyArray ar2{"ABC"}; //MyArray<char,4>
				int ar[] = { 1,2,3 };
				MyArray ar3{ ar };

			}
		*/

	__asm nop

}