
#include"Chapter14.h"

int main()
{
	cout << "Hello World ! - Welcome to chapter 14 " << endl << endl;
	prog1 ();
	prog2 ();
	prog3 ();
	prog4 ();
	prog5 ();
	prog6 ();
	prog7 ();
	prog8 ();
	prog9 ();
	prog10();
	prog11();

	cout << "\n\n\n ";
}


/************************************************  Program 1    **************************************************/
int myfun(int i);
double myfun(double i);

void prog1()
{
	cout << myfun(10) << endl;
	cout << myfun(5.4) << endl;
}
double myfun(double i)
{
	return i;
}
int myfun(int i)
{
	return i;
}



/************************************************  Program 2    **************************************************/
class date
{
	int day, month, year;
public:
	date(char *d);
	date(int m, int d, int y);
	void show_date();
};
date::date(char *d)
{
	/***
		Reading integer from character string
		***/
	sscanf(d, "%d%*c%d%*c%d", &month, &day, &year);
}

date::date(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}

void date::show_date()
{
	cout << month << "/" << day;
	cout << "/" << year << "\n";
}

void prog2()
{
	date ob1(12, 4, 2011), ob2("10/22/2001");
	ob1.show_date();
	ob2.show_date();
}
/************************************************  Program 3 Allowing both Initilized and Un initilized objects   **************************************************/
class powers
{
	int x;
public:
	powers(){ x = 0; }
	powers(int n){ x = n; }
	int getx(){ return x; }
	void setx(int n){ x = n; }
};

void prog3()
{
	powers ofTwo[] = { 1, 2, 4, 8, 16 };
	powers ofThree[5];
	powers *p;
	int i;

	// Show powers of two
	cout << "Powers of two  ";
	for (i = 0; i < 5; i++)
	{
		cout << ofTwo[i].getx() << " ";
	}
	cout << "\n\n";

	// Set powers of three
	ofThree[0].setx(1);
	ofThree[1].setx(3);
	ofThree[2].setx(9);
	ofThree[3].setx(27);
	ofThree[4].setx(81);

	// SHow powers of 3
	cout << "Powers of Three ";
	for (i = 0; i < 5; i++)
	{
		cout << ofThree[i].getx() << " ";
	}
	cout << "\n\n";


	// Now dynamically allocatin array
	try
	{
		p = new powers[5];
	}
	catch (bad_alloc xa)
	{
		cout << "Failed to allocate memory";
		return;
	}
	(*(p + 0)).setx(4);
	(*(p + 1)).setx(16);
	(*(p + 2)).setx(64);
	(*(p + 3)).setx(256);
	(*(p + 4)).setx(1024);

	// Show powers
	cout << " \n dynamic powers of 4 \n";
	for (i = 0; i < 5; i++)
	{
		cout << p[i].getx() << "   ";
	}

	// Without fail, delete memory allocated
	delete[] p;

}

/************************************************  Program 4  Copy constrcutor  **************************************************/
class array
{
	int * p;
	int size;
public:
	array(int size)
	{
		try
		{
			p = new int[size];
		}
		catch (bad_alloc xa)
		{
			cout << "Allocation failed";
			exit(EXIT_FAILURE);
		}
		this->size = size;
	}
	~array(){ delete[] p; }
	// copy constructor
	array(const array & a);
	void put(int i, int j)
	{
		if (i >= 0 && i < size)
			p[i] = j;
	}
	int get(int i)
	{
		return p[i];
	}
};
// Copy Constructor
array::array(const array &a) {
	int i;
	try {
		p = new int[a.size];
	}
	catch (bad_alloc xa) {
		cout << "Allocation Failure\n";
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < a.size; i++) p[i] = a.p[i];
}
void prog4()
{
	array num(10);
	int i;
	for (i = 0; i < 10; i++) num.put(i, i);
	for (i = 9; i >= 0; i--) cout << num.get(i) << "   ";
	cout << "\n";
	// create another array and initialize with num
	array x(num); // invokes copy constructor
}

/************************************************  Program 5 Finding address of overloaded function   **************************************************/

int fun(int a);
int fun(int, int);

void prog5()
{
	int(*fp)(int a);
	fp = fun;
	cout << fp(5);
}

int fun(int a)
{
	return a;
}
int fun(int a, int b)
{
	return a*b;
}


/************************************************  Program 6 Default Funciton argument   **************************************************/
void clrscr(int size = 25);
void prog6()
{
	register int i;
	for (i = 0; i < 30; i++)
	{
		cout << i << endl;
	}
	cin.get();
	clrscr();

	for (i = 0; i < 30; i++)
	{
		cout << i << endl;
	}
	cin.get();
	clrscr(10);
}

void clrscr(int size)
{
	for (; size; size--) cout << endl;
}

/************************************************  Program 7    **************************************************/

/* This will generate compilation error
int myfuncNew(float f, char *str, int i = 10, int j);
*/
void iputs(char *str, int indent = -1);

void prog7()
{
	iputs("Hello there", 10);
	iputs("This will be indented 10 spaces by default");
	iputs("This will be indented 5 spaces", 5);
	iputs("This is not indented", 0);
}

void iputs(char *str, int indent)
{
	static int i = 0;
	if (indent >= 0)
		i = indent;
	else
		indent = i;
	for (; indent; indent--) cout << " ";
	cout << str << "\n";
}


/************************************************  Program 8    **************************************************/

class cube
{
	int x, y, z;
public:
	// cube(){ x = 1; y = 1; z = 1; }  // Enabling this defination will result in compilation error : multiple defination, ambugity
	cube(int i = 0, int j = 0, int k = 0)
	{
		cout << "inside paramtered constructor\n";
		x = i; y = j; z = k;
	}
	int volume()
	{
		return x*y*z;
	}

};
void prog8()
{
	cube a(2, 3, 4), b;
	cout << a.volume() << endl;
	cout << b.volume();
}


/************************************************  Program 9  Overlaoded function vs Default arguments  **************************************************/
void mystrcat(char *s1, char *s2, int len = -1);

void prog9()
{
	char str1[80] = "This is a test";
	char str2[80] = "0123456789";
	mystrcat(str1, str2, 5); // concatenate 5 chars
	cout << str1 << '\n';
	strcpy(str1, "This is a test"); // reset str1
	mystrcat(str1, str2); // concatenate entire string
	cout << str1 << '\n';
}

void mystrcat(char *s1, char *s2, int len)
{
	// find end of s1
	while (*s1) s1++;
	if (len == -1) len = strlen(s2);
	while (*s2 && len) {
		*s1 = *s2; // copy chars
		s1++;
		s2++;
		len--;
	}
	*s1 = '\0'; // null terminate s1

}

/************************************************  Program 10   **************************************************/
float  abc(float a);
double abc(double a);

void prog10()
{
	abc(10.0);
	abc(10.1);
}

float  abc(float a){ cout << "Inside float function \n"; return a; }
double abc(double a){ cout << "Inside double function \n"; return a; }

/************************************************  Program 11   **************************************************/
void f(int a)
{
	cout << "Inside funciton void f(int a) \n";
}
void f(int &c)
{
	cout << "Inside funciton void f(int &a) \n";
}
void prog11()
{

}

