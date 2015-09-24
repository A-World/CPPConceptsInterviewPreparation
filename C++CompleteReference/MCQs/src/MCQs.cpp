#include"MCQs.h"
void sub()
{
	cout << "Global sub:\n";
}
void sum()
{
	cout << "Global sum :\n";
}
void sum(int abce) 
{ 
	cout << "Global sum :\n";
}
class abcd
{
public:
	int a, mm, ld;
	// abcd()	{	}  // Need not have constructor when class instance is used inside union.
	static int myInt;  // This can be there.

	void sum()
	{
		sub();
		// sum();  // This calls same class member function again and again into infinite loop. 

		// sum(20);  //  Compiler can not find global sum(int abd) function. this reports compiler error.
		// Compiler tries to find member function with signation sum(int abcdsdfs);
		::sum();  // Call global function
		::sum(20);  // Call global function
		cout << "local sum :\n";
	}

	inline void dummy()
	{}
};

int abcd::myInt;
union myUnion
{
	int i;
	abcd a; // If class has a constructor then, it can not be a member of union.
	// virtual void abcd() {}

	// You can not have static data member inside the union, but can have static member function inside the union
};

// union xss : public abcd {}; // Compilation error.
// class xdfe : public myUnion{};// enum/union cannot be used as a base class	
// As union does not support inheritance, no question of virtual functions inside union

//Anonymous unions cannot contain private or protected elements.
//Global anonymous unions must be specified as static.
class TEST;
class sample
{
public:
	int i;
	sample()
	{
		cout << "Inside constructor\n" << endl;
	}

	~sample()
	{
		cout << "Inside destructor\n" << endl;
	}
	TEST *p;
	// TEST t; // You can not use instance of TEST class till you define it completely, compiler flashes error.
};

// static sample s[10];

class testStatic
{
	int abcdl;
	public:
		static void test(int abcd){}
		// static void asdf(int abcd)const {} // static function can not be const
		// virtual static void test(){} // compilation error

		// static member function can only access static data members and other static member functions
		// Static member function do not use this pointer.

};


/*		Revisting freiend functions
	- Derived class does not inherit friend function 
	- friend function may not be declared as static or extern
*/

int main()
{

	cout << "This to test or solve various c++ questions that are asked in interview \n" ;
	cout << "Pitfalls and Special Questions in c++\n\n\n\n" ;

	abcd a;
	a.sum();
//	Qusetion1 ();
//	Qusetion2 ();
//	Qusetion3 ();
//	Qusetion4 ();
//	Qusetion5 ();
//	Qusetion6 ();
//	Qusetion7 ();
//	Qusetion8 ();
//	Qusetion9 ();
//	Qusetion10();
//	Qusetion11();
//	Qusetion12();
//	Qusetion13();
//	Qusetion14();
//	Qusetion15();
//	Qusetion16();
//	Qusetion17();
//	Qusetion18();
//	Qusetion19();
//	Qusetion20();
//	Qusetion21();
//	Qusetion22();
//	Qusetion23();
	Qusetion24();
	Qusetion25();

	cout << "\n\n\n\n\n";
}

/*
		Question 1 : In which cases copy constructors are invoked

		Assume class TEST. Which of the following statements is/are responsible to invoke copy constructor?

		a. TEST T2(T1)
		b. TEST T4 = T1
		c. T2 = T1
		d. both a and b
		e. All of these

		ANS : d

		---------------------------------------------------------------------------------------------
		1. You can have a private constructor, but you need to define ways to access it privately.
		2. In any case you can not have a private destructor.
		3. You can use this pointers inside constructor to get access to address of object.
		4. You cannot take the address of a constructor (C++98 Standard 12.1/12 Constructors - "12.1-12 Constructors - "The address of a constructor shall not be taken.")
*/

class TEST
{
private : 
	TEST(int a)
	{
		cout << "Private constructor\n";
	}

	/* You can not have a private destrctor. so make is public */
public:
	~TEST()
	{
		cout << "Private Destructor for object at address " << this << endl;
	}

public :
	TEST()
	{
		cout << "Default public constructor for object at  " << this << endl;
	}

	// Copy constructor
	TEST(TEST &t)
	{
		cout << "Public Copy constructor for object at  " << this << endl;
	}

	void private_constructor()
	{
		TEST  t(40);
		cout << "Here i have created an object with private constructor\n";
	}

	void access_constructor_with_address()
	{
		// Define function pointer for constructor;
		// General syntax is 
		// void(*foo)(int);

		// (TEST::*functionPointerToConstructor)(int) = &(TEST::TEST);

		// As we tried to access address of constructor function, compiler flashs error. Addess can not be taken.
		
		// Defining function pointer to private_constructor function.
		//void(TEST::*functionPointerToConstructor)() = (TEST::private_constructor);
	}
};

void Qusetion1()
{
	TEST T1;
	TEST T2(T1);
	TEST T4 = T1;
	T2 = T1;
	T1.private_constructor();
	// TEST T5(10); // Cannot access private constructor
}

/*
		Question 2 : Explicit keyword and usage

		The purpose of explicit keyword is to tell the compiler that 
		a certain constructor may not be used to implicitly cast an expression to its class type.

*/


class A 
{
public:
//	explicit  A(int);
};

void f(A) {}

void Qusetion2()
{
	// A a1 = 37;
	//A a2 = A(47);
	//A a3(57);
	//a1 = 67;
	//f(77);
}

/*
		Question 3 :

		Which of the followings are true about Virtual functions?
		a. They must be non-static member function of the class
		b. They cannot be friends
		c. Constructor Functions cannot be virtual
		d. All of these
		ANSWER: d. All of these

		If abstract class is inherited by derived class, then_______________

		a. Derived class should provide definition for all the pure virtual functions
		b. Derived class also become abstract if fails to implement pure virtual functions
		c. Objects of derived class can’t be created if it fails to implement pure virtual functions
		d. All of these
		View Answer / Hide Answer

		ANSWER: d. All of these
*/

/*
int x = 5;
void Qusetion3()
{
	int x = x;
	cout << " x is  "<< x;
}
*/
const int x = 5;
void Qusetion3()
{
	int x[x];

	int y = sizeof(x) / sizeof(int);

	cout << x << endl;
	cout << y << endl;
}

/*
		Question 4 :
*/

const int SIZE = 5;

struct tester
{
    int array[SIZE];

    enum 
    {
        SIZE = 3
    };

    void size()
    {
        std::cout << sizeof(array) / sizeof(int);
    }
};

struct tester1
{

	/*
		Names defined at any point in a class are in scope in all member functions of the class. 
		Thus the enum SIZE is in scope in the function foo and hides the global variable SIZE.
	*/
	void foo()
	{
		std::cout << SIZE << std::endl;
	}

	enum
	{
		SIZE = 3
	};
};

void Qusetion4()
{
	tester t;
	t.size();
	tester1 t1;
	t1.foo();

}

/*
		Question 5 :
*/

namespace standards
{
	struct datastructure
	{
	};

	void foo(const datastructure& ds)
	{
	}

	void bar()
	{
	}
}

void Qusetion5()
{
	standards::datastructure ds;

	foo(ds);

	// bar();  // You will not get any defination for bar() function
	/*
	This is called koenig lookup or argument dependent name lookup. In this case, 
	the namespace 'standards' is searched for a function 'foo' because its argument 
	'ds' is defined in that namespace. For function 'bar', no additional 
	namespaces are searched and the name is not found. More details are in 3.4.2.
	*/
}

/*
		Question 6 :
*/

void Qusetion6()
{
	int a = 2;
	int* b = &a;
	int const* c = b;
	// b = c;//	a value of type "const int *" cannot be assigned to an entity of type "int *"

//	int x = int() = 3;

//	std::cout << x << std::endl;

}

/*
		Question 7 :
*/

struct Foo
{
	int x;
	int y;
};
void Qusetion7()
{
	Foo f;

	if (&f.x < &f.y)
	{
		std::cout << "Hello World" << std::endl;
	}
}

/*
		Question 8 :
*/
struct Foo1
{
};

struct Bar1
{
};
void Qusetion8()
{
	Foo1* f = new Foo1;
	Bar1* b = new Bar1;
	/*
		if (f == b)  // Can not use compare operator to compare objects of dfferent types
			std::cout << "EQUAL" << std::endl;
		else
			std::cout << "NOT EQUAL" << std::endl;
	*/


	int x = 0;
	int y = 0;

	if (x++ && y++)
	{
		y += 2;
	}

	std::cout << x + y << std::endl;

}

/*
		Question 9 :
*/

struct Foo2
{
	int x;

	operator int()
	{
		cout << "Inside int operator function \n";
		return 21;
	}
};


void Qusetion9()
{
	cout << "\n\n\n\nQuestion 9\n";
	Foo2 f;
	f.x = 11;
	f;
	f;
	std::cout << (0 ? 3 : f) << std::endl;
	std::cout << f << std::endl;

}

/*
		Question 10 :
*/

void Qusetion10()
{
#ifdef PROGRAM_WILL_NOT_COMPILE
	cout << "\n\n\n\nQuestion 10\n";
	int x = 3;

	switch (x)
	{
	case 0:
		//int x = 1;
		std::cout << "case 0 "<< x << std::endl;
		break;
	case 3:
		std::cout << "case 3 " << x << std::endl;
		break;
	default:
		x = 2;
		std::cout << "case default " << x << std::endl;
	}
#endif
}

/*
		Question 11 :
*/

struct myStruct
{
	myStruct()
	{
		cout << "This is constructor for empty structure\n";
	}
};

class myclass
{
public:
	myclass()
	{
		cout << "This is constructor for empty class\n";
	}
};
struct Foo3
{
	Foo3(int d) : x(d) {}
	int x;
};

void Qusetion11()
{
	myStruct s;
	myclass c;
	cout << "Size of elements are "<<sizeof(s)<<endl;
	cout << "Size of elements are "<<sizeof(c)<<endl<<endl <<endl;

	double x = 3.14;

	// std::cout << f.x << std::endl;
}

/*
		Question 12 :
*/

void Qusetion12()
{
	int sum = 0;

	// int array[3][] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	int array[][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 2; j < 3; j++)
		{
			sum += array[i][j];
		}
	}

	std::cout << "Sum is "<<sum << std::endl;
}

/*
		Question 13 :
*/

int g_x = 44;
struct Foo4
{
	int m_x;

	static int s_x;

	Foo4(int x) : m_x(x) {}

	int a(int x = g_x)
	{
		return x + 1;
	}

	//int b(int x = m_x) // This statement gives compilation error.
	//{
	//	return x + 1;
	//}

	int c(int x = s_x)
	{
		return x + 1;
	}
};

struct C
{
	virtual int foo(int x = 100)
	{
		cout << "Inside the virtual function of the A\n";
		return x * 2;
	}
};

struct B : public C
{
	int foo(int x = 40)
	{
		cout << "Inside the foo function of the B\n";
		return x * 3;
	}
};
void Qusetion13()
{
	C* a = new B;
	cout << "\n\n\n";
	std::cout << a->foo() << std::endl;  // It takes the default argument from the parent function.

}

/*
		Question 14 :
*/

class Foo6
{
public:

	char c;
	//static double sd;  // We have not defined it yet.
	double d;
	int i;
};
//double Foo6::sd = 0;  // You need not to define static data member till you use it.

void Qusetion14()
{
	Foo6 f = { 72, 3.14 };
//	f.sd = 40.00;
	std::cout << f.c + f.d + f.i << std::endl;
	cout << "Size of char is " << sizeof(char) << endl;
	cout << "Size of int is " << sizeof(int) << endl;
	cout << "Size of double is " << sizeof(double) << endl;
	cout << "Size of class is " << sizeof(f) << endl;

//	int x = 3;
//	int* rpx = &x; // Error
//	std::cout << rpx << std::endl;
}

/*
		Question 15 :
*/

struct BS
{
	BS()
	{
		std::cout << "Hello World" << std::endl;
	}
	unsigned int color;
};

struct mid1 : virtual public BS { };
struct mid2 : virtual public BS { };
struct mid5 : virtual public BS { };
struct mid6 : virtual public BS { };
struct mid3 : public BS { };
struct mid4 : public BS { };
struct mid7 : public BS { };
struct mid8 : public BS { };

struct DR : public mid1, public mid2,
	public mid3, public mid4, public mid5, public mid6, public mid7, public mid8 { };

void Qusetion15()
{
	DR d;  // This example show how many times a funciton gets called and hello world is printed.
}



/*
		Question 16 :
*/

struct Shape
{
	virtual void print()
	{
		std::cout << "SHAPE" << std::endl;
	}
	virtual ~Shape() {}
};

struct Box : public virtual Shape
{
	void print()
	{
		std::cout << "BOX" << std::endl;
	}
};

struct Sphere : public virtual Shape
{
	void print()
	{
		std::cout << "SPHERE" << std::endl;
	}
};

struct GeoDisc : virtual public Box, virtual public Sphere
{
	// This method has to be there.
	void print()
	{
		std::cout << "GeoDisc " << std::endl;
	}
};

void Qusetion16()
{
	Shape* s = new GeoDisc;

	s->print();

	delete s;

}

/*
		Question 17 :
*/

struct Shape1
{
	virtual Shape1* duplicate()
	{
		return new Shape1;
	}
	virtual void print()
	{
		std::cout << "SHAPE1" << std::endl;
	}
	virtual ~Shape1() {}
};

struct Box1 : public Shape1
{
	virtual Box1* duplicate()
	{
		return new Box1;
	}
	virtual void print()
	{
		std::cout << "BOX1" << std::endl;
	}
};

void Qusetion17()
{
	Shape* s1 = new Box;
	//Box* b1 = s1->duplicate();
	//b1->print();
}

/*
		Question 18 :
*/

class Bar
{
protected:
	static int x;
	int y;
};

int  Bar::x = 33;

class Barrel : public Bar
{
public:
	void foo(Bar* b, Barrel* d)
	{
//		b->y = 0;
		d->y = 0;
		Bar::x = 0;
		Barrel::x = 0;
	}
};

void Qusetion18()
{

}

/*
		Question 19 :
*/

struct MyFoo
{
	MyFoo(int n) : x(n++), y(n++), z(n++) {}
	int x;
	int y;
	int z;
};

void Qusetion19()
{
	MyFoo f(3);
	cout << "\n\n\n\nX is  " << f.x << endl;
	cout << "Y is  " << f.y << endl;
	cout << "Z is  " << f.z << endl;
}

/*
		Question 20 :
*/


struct Car
{
	Car() : price(20000) {}
	Car(double b) : price(b*1.1) {}
	double price;
};

struct Toyota : virtual public  Car
{
	Toyota(double b) : Car(b) {}
};

struct Prius : virtual public Toyota
{
	Prius(double b) : Toyota(b)  { cout << "Prius constuctor\n"; }
};

void Qusetion20()
{
	Prius p(30000);
	std::cout << p.price << std::endl;
}

/*
		Question 21 :
*/
class Test {
public:

	Test()  { cout << "Constructor is executed\n"; 
	x = 4; y = 10;
	}
	~Test() { cout << "Destructor is executed\n"; }
	int x;
	mutable int y;
};
void Qusetion21()
{
	const Test t1;
	t1.y = 20;
	cout << t1.y;
	Test();  // Explicit call to constructor
	Test t; // local object
	t.~Test(); // Explicit call to destructor
}

/*
		Question 22 :
*/

void Qusetion22()
{
	int numb = 0;
	while (numb<10>9) 
	{
		cout << "Invalid input, please re-enter: ";
		cin >> numb;
	}
}

/*
		Question 23 :
*/
class abc
{
	int ab;
public :
	abc() { ab = 54;  cout << "\n\n\n Inside constructor\n "; }
	void change()
	{
		// ab = 20;
	}
};
void fun(abc const & a)
{
	cout << "abc const & a\n";
	// a.change();  // Error  Can use function c, can not convert const & abc to this pointer.
}

void fun(abc *a)
{
	cout << "abc *a\n";
	// a.change();  // Error  Can use function c, can not convert const & abc to this pointer.
}


typedef auto_ptr<abc> abcptr;

void Qusetion23()
{
	abc a;
	abc c();    // This is c function declartion.
	abc *x;
	abcptr p(new abc());
	x = &a;
	fun(a);
	fun(x);
	fun(*p);
	//fun(abcptr);
}

/*
		Question 24 :
*/

class myTest
{
public:
	myTest( int a, int b)
	{
		cout << "Parametered constructor \n";
	}
	myTest(myTest & t)
	{
		cout << "Copy constructor \n";
	}
	myTest(int a = 20)
	{
		cout << "constructor with single paramter\n";
	}

	//myTest()
	//{
	//	cout << "Default constructor \n";
	//}
};

void Qusetion24()
{

	// Different ways in which we call constructors 
	myTest t(10, 12);
	myTest abcd = myTest(40, 50);
	myTest sadf = { 15, 50 };
	myTest tasdf = 78778;
	myTest ss = t;
	myTest e; // You must define default constructor.
}

/*
		Question 25 :
*/

/*
class student
{
private:
	int roll;
public:
	// constructor
	student(int r) :roll(r) {}

	// A const function that changes roll with the help of const_cast
	void fun() const
	{
		(const_cast <student*> (this))->roll = 4;
		(const_cast <student*> (this))->roll = 5;
	}

	int getRoll()  { return roll; }
};
*/

class student
{
private:
	const int roll;
public:
	// constructor
	student(int r) :roll(r) {}

	// A const function that changes roll with the help of const_cast
	void fun() const
	{
		// (const_cast <student*> (this))->roll = 5;
	}

	int getRoll()  { return roll; }
};

int fun(int* ptr)
{
	*ptr = *ptr + 10;
	return (*ptr);
}


class CDummy {
	int i;
};

class CAddition {
	int x, y;
public:
	CAddition(int a, int b) { x = a; y = b; }
	int result() { return x + y; }
};


void Qusetion25()
{
	const int val = 10;
	const int *ptr = &val;
	int *ptr1 = const_cast <int *>(ptr);
	cout << fun(ptr1);


	int a1 = 40;
	const int* b1 = &a1;
	char* c1 = (char *)(b1);
	*c1 = 'A';


	CDummy d;
	CAddition * padd;
	padd = (CAddition*)&d;
	cout << padd->result();

}

