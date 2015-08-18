/*
		This program runs into infinite loop, please fix it.
*/

#include <iostream>
using namespace std;

class time24;

class time12
{
	int hour;
	int minute;
	int second;
	public :
	time12 (int h, int m, int s);
	operator time24();
};
class time24
{
	int hour;
	int minute;
	int second;
	public :
	time24(int h, int m, int s);
	operator time12();
};

time12 :: time12(int h, int m, int s)
{
	hour = h; minute = m;second = s;
}

time12 :: operator time24()
{
	time12 t (hour,minute,second);
	return t;
}

time24 ::time24 (int h, int m, int s)
{
	hour = h; minute = m ; second = s;
}
time24 :: operator time12()
{
	time12 t (hour, minute,second);
	return t;
}

int main()
{
	time12 a(11,23,45);
	time24 b(10,35,23);
	
	a = b;
	b = a;
}
























#ifdef THIS_PROGRM_IS_IN_INFINITE_LOOP
class time12;
class time24;

class time12 
{
	int sec;
	int min;
	int hr;
	public:
		time12(int s = 0, int m = 0 , int h = 0)
		{
			cout << "time12 constructor"<<endl;
			sec = s; min = m; hr = h;
		}
		operator time24();
			
};

class time24 
{
	int sec;
	int min;
	int hr;
	public :
	time24(int s = 0, int m = 0 , int h = 0)
		{
			cout << "time24 constructor"<<endl;
			sec = s; min = m; hr = h;
		}
	public :
		operator time12();
};

time12 :: operator time24()
{
	time12 t;
	return t;
}

time24 :: operator time12()
{
	time24 t;
	return t;
}

int main()
{
	cout << "Hello World" <<endl;
	
	time12 t12 ;
	time24 t24 ;
	time12 t12_1 () ;
	time24 t24_1 () ;
	t12 = t24;
	t24 = t12;
}

#endif





