#include"H.h"

constexpr int CONV_BIT(const char* z)
{
	//return (*z == '0') ? (1<<1) : 0;
	return (*z == '0') ? (1 << 1) : 0;
}
constexpr int BIT(const char* z)
{
	//return (*z == '\0') ? CONV_BIT(--z) :BIT(++z);
	int x = 0;
	while (*z != '\0')
	{
		if (*z == '1') { x = (x | 1); x = x << 1; }
		else if (*z == '0') { x = (x | 0); x = x << 1; }
		++z;
	}
	return x = x>>1;

}
constexpr int operator""_b(const char* x){	return BIT(x); };
constexpr int factorial(size_t x){	return (x) ? x * factorial(x - 1) : 1; }
string operator""_toBinStr(unsigned long long x) 
{ 
	string str{};
	int ost = 0;
	while (x != 1)
	{
		ost = x % 2;
		x = x / 2;
		str += (ost == 0) ? '0' : '1';
		
	}
	str += '1';
	reverse(str.begin(), str.end());
	return str;
};
template<typename T> class VEC
{ 
	T MAX;
	T MIN;
public:
	constexpr VEC(T x,T y):MIN(x),MAX(y){};
	constexpr T GET_MAX() const { return MAX; }
	constexpr T GET_MIN() const { return MIN; }
	constexpr int FIND_IN(T Z)
	{ 
		if (Z > MAX) return MAX;
		else if (Z < MIN) return MIN;
		else return Z;
	}
};
auto DELITER = [](auto x) { delete[] x; };

int main(){
	/* ������� 1 */
	/*
		����� ��������� �������� (Raw String Literals)
		�������� ������, ��������: my name is "Marina"
		�) ��� ������������� Raw String Literals
		�) ����������� Raw String Literals
		�) �������� ����������� (Delimeter)
	*/
	{
		cout << "my name is \"Marina\"" << endl;
		cout << R"(my name is "Marina")" << endl;
		cout << R"qqq(my name is "Marina")qqq" << endl;
		NOP
		system("cls");
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	/*������� 2*/
	/*
		���������� ���������� ���������� � ������� constexpr-�������.
	
		���������/�����������: 
				- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>; (����!)
				- �� ��� ��������� ����� �������� ����� ������ constexpr � �������, � ��������� �����������
				  ����� 
				- ���� �������� ����������� constexpr- ������� - ��� ���������, ���������� �������� ���������
				  �� ����� ����������

		��������� ��� ����, ��� ���������� ��������� �������� �� ����� ���������� (���� � ��������
						��������� ������������ ���������, ��������� ����������� �� ����� ����������).
						��� �������� ���������� ������� ���������� ������ � ������������, �����������
						����������� constexpr-�������:
	*/
	{	
		//��������:
		int ar[factorial(3)];
		NOP
		//���
		constexpr int n = factorial(5);
		int ar1[n];
		NOP
		//����������:
		int m = 7;
		//constexpr int n1 = factorial(m);// ������ "�� constexpr"
		//int ar1[n1];
		
		//� ���?
		int n2 = factorial(m); //�� ���������
		NOP
		system("cls");
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	/* ������� 3a */ 
	/*
		������� � ������� ����������������� �������� �� ��������� ������������� ���������� � ��������, ��������: 
		������ "100000000" -> � �������� 256
		��������� ��������� ����������� �������� 0b
		����� ����� ����������������� �������� �������� ������ � �������, ��������: 100000000_b	������� ������������ ���������������� 
		������� � ������������ ���������� - const char*

		��� ��� ���� ���� � ���������, ������� ��������� �������� �� ����� ����������
		=> ���������� ���������������� ������� ����������� constexpr - �������
		���������/�����������: 
				- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>;
				- �� ��� ��������� ����� �������� ����� ������ constexpr � �������,
				- ������� ����� ���� ����������� (���� �������� ����� ������� - ��� ���������, ���������� �������� ��������� ������ ����������� ������� �� ����� ����������)
	*/
	{
		//int y = "123"_b;//<---������ ��� ������???
		size_t X = 0b100000000;
		size_t Z = 100000000_b;
		NOP
		system("cls");
	}
	/*������� 3b */
	/*
		������� � ��������� �������� �������������, ��������: 256 -> "0b100000000" 
		��� ��� ������ ����� ���� ����� �����, �������� � ����� ���������� ������ std::string => ������������ �������� �� ����� ���� constexpr!
		���������: ������������ std::bin ���� ��� => �������������� � �������� ������ �������� ������ �������
		���������: ���������� �������� � ����� ���������� ��������� CHAR_BIT - <cstdint>
	*/
	{
		string sBin = 256_toBinStr;
		NOP
		system("cls");
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	/* ������� 4� */
	/*
		constexpr - ������� 
		������� ����� (������ ������?) ��� �������� � ��������������� ���������� ��������.
		� ������ ������ ����:
			���������� ��� �������� ������������ � ������������� ��������,
			������ ��� ��������� ������� �� �������� 
			�����, ������� �������� ����� �������� ������� ���� � ��������� �������������� ��������:
									���� ����������� ���������, �� ��� � ����������
									���� ������ ������������ ��������, ���������� �����������
									���� ������ ������������� ��������, ���������� ������������

		��������� ��� ����, ��� ���������� ��������� �������� �� ����� ����������. 
						��� �������� ���������� ������� ���������� ������ � ������������, �����������
						����������� constexpr-������:
	*/
	{
		constexpr VEC<int> Z(1,5);
		int U[Z.GET_MAX()];
		NOP
	}	
	//////////////////////////////////////////////////////////////////////////////////////////////
	/* ������� 5 */ /*- unique_ptr*/
	{
		/* 5.� - ���������� ���������� ���������� ��������� */
		{
			std::vector<std::string*> v = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			/* ������������ ��� ������ */
			for (string* x : v)	{ cout << *x << endl; }
			NOP
			system("cls");
			for (string* x : v) { delete x; }
		}// ----------------------->>> ������ ������!!!!
		/* 5.b - ������������� ������� 5.�: */
		/*
			���������� ����������� std::unique_ptr: 
			����������� ���������� (��������� ��� ������ ������� ������������ std::unique_ptr), ���������� �������� 
			���������� �� ����������� ����������� ������� std::string, ���������������, � ������������ ��������
		*/	
		{
		 //������������ ��� ������	
			vector<unique_ptr<string>> v;
			v.push_back(make_unique<string>("aa"));
			v.push_back(make_unique<string>("bb"));
			v.push_back(make_unique<string>("cc"));
			for (unique_ptr<string> &x : v) { cout << *x.get() << endl; }
			NOP
			system("cls");
		 //??? ����������� ����������� ��������� ��������?
		} //???
		/* 5.c - ��������� ������� 5.b */
		/*
			�������� ����������� �������� ���������� ������	��������� ������� (��������, �������� ��������� �������: "AAA" -> "AAA_1")  
		*/
		{
			string str{ "_1" };
			vector<unique_ptr<string>> v;
			v.push_back(make_unique<string>("aa"));
			v.push_back(make_unique<string>("bb"));
			v.push_back(make_unique<string>("cc"));
			for (unique_ptr<string> &x : v) { *x+=str; cout << *x.get() << endl; }
			NOP
			system("cls");
		}
		/* 5.d - ������������ ������ �������� */	
		/*
			�������� unique_ptr, ������� �������� �������� ��� ������������� ������� � ���������� std::string.
			� ������� unique_ptr::operator[] ��������� ��������� ������ ����������.	����� ���������� ������������ ������?
		*/
		{
			unique_ptr<string[]> UPT_M = make_unique<string[]>(2);
			UPT_M[0] = move("qwe");
			NOP
			system("cls");
		}//����������� ����������� ��������� ��������	
		/* 5.e - ������� ������������ �������� � ���������������� delete-������� (�������) */
		/*
			����� �������� ������ ���������� �� ����������� ��������� �������. 
			�������� unique_ptr ��� ������ �������.
			���������� ���������������� delete-������� (�������) ��� ����������� ������������ ������.
		 */
		{
			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			//unique_ptr < string[]> UPT_MM = make_unique<string[]>(3);
			unique_ptr < string[],decltype(DELITER)> UPT_M(new  string[3], DELITER);
			UPT_M[0] = move(*arStrPtr[0]);
			UPT_M[1] = move(*arStrPtr[1]);
			UPT_M[2] = move(*arStrPtr[2]);
			cout << UPT_M[2];
			NOP
			system("cls");
		}
		/* 5.f �������� � ��������� ������, ���������� unique_ptr ��� ���������� �� std::string */
		/*
			����������� ��������� copy() ���������� �������� ������� � ������ ������ � ���������� ���� �� ����.
			���������: ������������ ��������� � ������ std::make_move_iterator
		*/
		{
			vector<unique_ptr<string>> v;
			v.push_back(make_unique<string>("aa"));
			v.push_back(make_unique<string>("bb"));
			v.push_back(make_unique<string>("cc"));

			list<unique_ptr<string>> ls(3);
			copy(make_move_iterator(v.begin()), make_move_iterator(v.end()),front_inserter(ls));
			NOP
			system("cls");
		}		
	}
	////////////////////////////////////////////////////////////////////////////////
	/* ������� 6.shared_ptr + ���������������� delete-������� */
	/*
		����������� ����������� ������ � ���� ������ (�������) �� ������ ����������
		(��� ��������� ����� ����������� �������� ��� �������).
		��� ��� ��� "��������" ����� �� ������� ���������� ���� ������ � ���� � ��� �� ����,
		������� ������������ �� ����������� ������������ ����� � ��� �� ���������� FILE* =>
		���������� �������� ��� ������ ��������� �������� shared_ptr
		�. ������ �������� ������ �������/������� ���� ��� ������
		�. ��� ��������� �������� ������ �������������� � �������������
		�. ��������� �������� ��������� ������ ������� ����
		���������: ����������� ������� ������ ����� � ������� ������� rand() 
	*/
	{
		//"��������":
		//������� writer1, writer2
		//��������, ��������� ������:
		char ar1[] = "Writer1 ";
		char ar2[] = "Writer2 ";

		//FILE* fpp = fopen("test.txt", "w");
		//fputs(ar1, fpp);

		shared_ptr<FILE> fp(fopen("T.txt", "w"), [](FILE* pf) {fclose(pf); });
		shared_ptr<FILE> fp2(fp);
		NOP
		//�������� ����� �������� ��������� ������� ��������� ������ �� "���������" �������� � ���� ���� �������
		//���������: ������� ������ ���������� � ���� ����������� ������� fputs()

			for (int i = 1; i < 5; i++)
			{
				size_t RND = (rand())%2;
				if (++RND == 1) { fputs(ar1, &(*fp));}
				else { fputs(ar2, &(*fp)); }
				NOP
			}
  		NOP
	}//�������� �����???
	NOP
}