// This creates the class stack.
#include "Generic.h"

#define SIZE 100
class stack
{
	int stck[SIZE];
	int tos;
public:
	stack(); // Stack constructor declaration
	// void init(); // As we are using constructor to intilize, so we'll not any of the init() function
	void push(int i);
	int pop();

	// Introducing Destructor
	~stack();
};

stack::stack() // Constructor defination
{
	tos = 0;
	cout << "Stack initilized successfully by constructor \n";
}

stack :: ~stack()
{
	cout << " Inside the destroctor\n";
}

// Class Function Definations
int stack::pop()
{
	int a = -1;
	if (tos == 0)
	{
		cout << "\nStack empty\n";
	}
	else
	{
		tos--;
		a = stck[tos];
	}
	return a;
}
// As we are using constructor to intilize, so we'll not any of the init() function
/*void stack::init()
{
	tos = 0;
}*/

void stack::push(int i)
{
	if (tos >= SIZE)
	{
		cout << "Stack is full"<<endl;
	}
	else
	{
		stck[tos] = i;
		tos++;
	}
}

void stackOperation()
{
	cout << "Creating stack objects" << endl;
	stack s1, s2;
	//s1.init(); // As we are using constructor to intilize, so we'll not any of the init() function
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);

	cout << "Element Popped is " << s1.pop() << endl;
	cout << "Element Popped is " << s1.pop() << endl;
	cout << "Element Popped is " << s1.pop() << endl;
	cout << "Element Popped is " << s1.pop() << endl;
	cout << "Element Popped is " << s1.pop() << endl;
	cout << "Element Popped is " << s1.pop() << endl;
}



/*****************************************   Parametered Constructor example  **********************************/
const int IN = 1;
const int CHECKED_OUT = 0;
class book 
{
	char author[40];
	char title[40];
	int status;
public:
	book(char *n, char *t, int s);
	int get_status() { return status; }
	void set_status(int s) { status = s; }
	void show();
};
book::book(char *n, char *t, int s)
{
	strcpy(author, n);
	strcpy(title, t);
	status = s;
}
void book::show()
{
	cout << title << " by " << author;
	cout << " is ";
	if (status == IN) cout << "in.\n";
	else cout << "out.\n";
}
void test_parametered_const()
{
	book b1("Twain", "Tom Sawyer", IN);
	book b2("Melville", "Moby Dick", CHECKED_OUT);
	b1.show();
	b2.show();
}

class X 
{
	char a[80];
public:
	X(char x[]) { strcpy(a,x); }
	char * geta() { return a; }
};
void test_parametered_const_2()
{
	X ob = "Test abc my test"; // passes 99 to j
	cout << ob.geta(); // outputs 99
}

/********************************** Introduction to Static Members **************************************/
/*
	All static variables are initialized to zero before the first object is created.

	When you declare a static data member within a class, you are not defining it. (That
	is, you are not allocating storage for it.) Instead, you must provide a global definition
	for it elsewhere, outside the class. This is done by redeclaring the static variable using
	the scope resolution operator to identify the class to which it belongs. This causes
	storage for the variable to be allocated. (Remember, a class declaration is simply a
	logical construct that does not have physical reality.)	
*/
class shared
{
	int b;
public : 
	static int a;
	void set(int i, int j) { a = i, b = j; }
	void show();
};
int shared::a = 50; // Define a
void shared::show()
{
	cout << "This is static a :: " << a<<endl;
	cout << "This is non static b ::" << b<<endl;
}

void test_static_data_member()
{
	cout << "shared::a  before defination of any variable " << shared::a << endl;
	shared x, y;
	cout << "The size of class  x is " << sizeof(x) << endl;
	cout << "The size of class  y is " << sizeof(y) << endl;

	y.show();
	x.show();
	x.set(10, 10); // set a to 1
	x.show();
	y.set(20, 20); // change a to 2
	y.show();
	x.show(); /* Here, a has been changed for both x and y
			  because a is shared by both objects. */
}

class c1
{
	static int resource;
public :
	int get_resource();
	void free_resource() { resource = 0; }
};

int c1::resource; // Define resource 

int c1::get_resource()
{
	if (resource)
		return 0;
	else
	{
		resource = 1;
		return 1;
	}
}

void test_static_data_member_2()
{
	c1 obj1, obj2;
	if (obj1.get_resource())
		cout << "obj1 has resource \n";
	if (!obj2.get_resource())
		cout << "Obj2 denied resource\n";
	obj1.free_resource();
	if (obj2.get_resource())
		cout << "Obj2 can now use resource \n";
}


// Program to access static private member via friend function without creating any of the objects
void accessPrivate();

class test_static
{
private:
	static int stInt;
public :
	friend void accessPrivate();
};

 int test_static::stInt = 100;
void accessPrivate()
{
	cout << "Accessing the private static member value is " << test_static::stInt << endl;
}


/********************************** Static data member to count no of objects ***********************************/
class counter
{
	static int count;
public:
	counter() { count++; }
	~counter(){ count--; }
	void printNoOfObjects() { cout << "No of objects are " << count << endl; }
};
int counter::count;

void test_static_data_member_count_objects()
{
	counter c1, c2, c3;
	c1.printNoOfObjects();
	c1.~counter();
	c2.printNoOfObjects();
}

/************************************** Introduction to static member functions ********************************/
/*
	They may only be directly refer to other static members of the class 
	Following programs is to preinitilize the static data member
*/
class static_type
{
	static int i;
public:
	static void init(int x){ i = x; }
	void show(){ cout << i << endl; }
};

int static_type::i;

void test_static_member_funciton()
{
	static_type::init(5000);
	static_type x;
	x.show();
	x.init(4000);
	x.show(); 
}

/************************************* Local Classes ***************************************/

int global_var = 500;
void test_local_class()
{
	int static local_var = 45212;

	class myClassTest {
		int i;
	public:
		void put_i(int n) { i = n; }  // Defination is must here, you can not define function outside the class.
		int get_i() { cout << "Printing the global variable " << global_var << endl; cout << "Printing the local variable " << local_var<< endl;  return i; }
	} ob;

	ob.put_i(10);
	cout << ob.get_i();
}



/********************************************  Passing Objects to Functions   ****************************************/
class myClassTest
{
	int i;
public:
	myClassTest(int i);
	myClassTest(myClassTest &i);
	~myClassTest();
	void set_i(int i) { this->i = i; }
	int get_i() { return i; }
};

myClassTest::myClassTest(int n)
{
	i = n;
	cout << "Constructing  object with address " << hex << this << endl;
}
myClassTest::myClassTest(myClassTest &n)
{
	this->i = n.i;
//	cout << "Inside the copy Constructing  " << i << "\n";
	cout << "Constructing  object with address " << hex << this << endl;
}

myClassTest ::  ~myClassTest()
{
	cout << "Destroying    object with address " << hex << this << endl;
	//cout << "Destroying   " << i << "\n";
}

void f(myClassTest obj)
{
	obj.set_i(2);
	cout << "This is local i:   " << obj.get_i();
	cout << "\n";
}

void test_objects_to_function()
{
	myClassTest o(1);
	f(o);
	cout << "This is i in main:  ";
	cout << o.get_i() << "\n";
}


/*************************************** Returning Objects from function *****************************************/
// We'll use the classes declared in previous case only.
myClassTest fun_return_obj()
{
	myClassTest Y(212);
	Y.set_i(41365);
	return Y;
}

void test_return_object_from_function()
{
	myClassTest o(50);
	o = fun_return_obj();
	cout << o.get_i() << "\n";
//	cout << o.get_i() << end;
}