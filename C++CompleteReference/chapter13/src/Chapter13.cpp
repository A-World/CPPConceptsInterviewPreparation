
#include"Chapter13.h"

int main()
{
	cout << "Hello World ! - Welcome to chapter 13 " << endl << endl ;
//	prog1();
//	prog2();
//	prog3();
//	prog4();
//	prog5();
//	prog6();
//	prog7();
	prog8();
//	prog9();
	prog10();
//	prog11();
//	prog12();
//	prog13();
//	prog14();
//	prog15();
//	prog16();
//	prog17();
//	prog18();
//	prog19();
//	prog20();
//	prog21();
//	prog22();

	cout << "\n\n\n ";
}


/************************************************  Program 1 Arrays of Objects  **************************************************/
class cl {
	int i;
public:
	void set_i(int j) { i = j; }
	int get_i() { return i; }
};
void prog1()
{
	cl ob[3];
	int i;
	for (i = 0; i<3; i++) ob[i].set_i(i + 1);
	for (i = 0; i<3; i++)
		cout << ob[i].get_i() << "\n";
}

/*********************************************  Program 2 Arrays initilizaion synthax ***********************************************/
class c2
{
	int i;
	int j;
public:
	c2(int k) { i = k; }
	c2(int k, int l) { i = k; j = l; }
	int get_i(){ return i; }
	void set_i_j(int i, int j) { this->i = i; this->j = j; }
	void print_i_j() { cout << "i =  " << i <<"  j =   " << j << endl; }

};

void prog2()
{
	c2 obj[3] = { 2, 4, 5 };
	c2 ob[3] = { c2(1), c2(2), c2(3) };   // For initlization, we used class name as constructor not obect names
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "i = " << obj[i].get_i() << endl;
		cout << "i = " << ob[i].get_i() << endl;
	}
	c2 obj2(10, 20);
	obj2.set_i_j(40, 50);
	obj2.print_i_j();

	/* More than 1 parameters in array objects */

//	c2 obj2_array[3] = { c2(10, 12), c2(20, 22), c2(30, 32) }; // For initlization, we used class name as constructor not obect names
	// This syntax is also valid
	c2 obj2_array[3] = { { 10, 12 }, { 20, 22 }, c2(30, 32) }; // For initlization, we used class name as constructor not obect names
	for (i = 0; i < 3; i++)
	{
		obj2_array[i].print_i_j();
	}
}


/*********************************************  Program 3 Initilized vs Unintilized arrays ***********************************************/
class c3
{
	int i;
public:
	c3() {}
	c3(int j = 0 ){ i = j; }
	int get_i() { return i; }
};

void prog3()
{
	c3 obj[10];  // You must provide default constructor 
}

/**************************************************  Program 4 Accessing objects using pointers **************************************************/
class c4 
{
	int i;
public:
	c4(int j) { i = j; }
	int get_i() { return i; }
};

void prog4()
{
	c4 ob(88), *p;
	p = &ob; // get address of ob
	cout << p->get_i()<<"\n"; // use -> to call get_i()
}


/********************************************  Program 5 Accessing Array objects using pointers **************************************************/
// In this program we'll use the class c4 

void prog5()
{
	int i;
	c4 obj[4] = { 88,98,108,118 }, *p;
	p = &obj[0]; // get address of ob
	for (i = 0; i < 3; i++)
	{
		cout << p->get_i() << "\n"; // use -> to call get_i()
		p++;
	}
}

/********************************************  Program 6 pointer to members of object **************************************************/
class c5
{
public:
	int i;
	c5(int j) { i = j; }
	int get_i() { return i; }
};
void prog6()
{
	c5 obj(101);
	int *p;
	// Assign address of the data member i of obje to pointer.
	p = &(obj.i);
	cout << "Data is " << *p;
}

/*
	C++ has strong typechcking
	int *pi;
	float *pf;
	then, pi = pf // this gives error;
*/

/********************************************  Program 7 Introduction to this pointer **************************************************/

class pwr
{
	double b;
	int e;
	double value;
public :
	pwr(double base, int exp);
	double get_pwr();
};

pwr::pwr(double base, int exp)
{
	b = base;
	e = exp;
	value = 1;
	if (exp == 0)
		return;
	for (; exp > 0; exp--)
	{
		value = value * base;
	}
}

double pwr::get_pwr()
{
	return value;
}

void prog7()
{
	pwr x(4.0, 6), y(2.5, 6), z(5.7, 0);
	cout << x.get_pwr() << "\n";
	cout << y.get_pwr() << " \n";
	cout << z.get_pwr() << "\n";
}

/********************************************  Program 8 + 9 Pointer to derived Types **************************************************/

/*
	Rules 
1.	A base class pointer can also be used as a pointer to an object of any class derived from that base
2.  Although you can use a base pointer to point to a derived object, you can access only the
	members of the derived type that were imported from the base.
3.  You can cast a base pointer into a derived pointer and gain full access to the entire derived class
4.	When a base pointer pointing to object of derived class, is incremented, will not point to object of 
    next derived class.
*/

class base
{
	int i;
public:
	void set_i(int l){ i = l; }
	int get_i() { return i; }
};

class derived : public base
{
	int j;
public : 
	void set_j(int num){ j = num; }
	int get_j() { return j; }
};

class derived2 : public derived
{
	int k;
public:
	void set_k(int num) { k = num; }
	int get_k() { return k; }
};

void prog8()
{
	base *bp;
	derived d;
	bp = &d; // Base pointer pointing to object of derived class
	bp->set_i(10);
	cout << bp->get_i() << " ";
	/*  You can not access derived class members directly.
	bp->set_j(88); // error
	cout << bp->get_j(); // error
	*/

	// Type cast and use base pointer.
	((derived*)bp)->set_j(88);
	cout << ((derived*)bp)->get_j() << " ";

	derived2 d2;
	bp = &d2;
	bp->set_i(30);
	cout << bp->get_i() << " ";
}

void prog9()
{
	base *bp;
	derived d[2];
	bp = d;
	d[0].set_i(10);
	d[1].set_i(20);

	cout << bp->get_i() << " ";
	bp++; // relative to base, not derived
	cout << bp->get_i(); // garbage value displayed

}


/************************************************ Prog 10-12  Pointers to class member ***********************************************/
/*
	Totally new concept
	C++ allows you to generate a special type of pointer that "points" generically to a
	member of a class, not to a specific instance of that member in an object. This sort of
	pointer is called a pointer to a class member or a pointer-to-member, for short. A pointer to
	a member is not the same as a normal C++ pointer. Instead, a pointer to a member
	provides only an offset into an object of the member's class at which that member can
	be found. Since member pointers are not true pointers, the . and -> cannot be applied to
	them. To access a member of a class given a pointer to it, you must use the special
	pointer-to-member operators .* and –>*. Their job is to allow you to access a member of
	a class given a pointer to that member.
*/
class C1
{
public:
	C1(int i){ val = i; d = 0; }
	int val;
	double d;
	int double_val() { return val + val; }
};

void prog10()
{
	int C1 :: *data;// Data member pointer
	int(C1:: *func)(); // Function member pointer
	C1 ob1(1), ob2(3);

	data = &C1::val; // Get offset of val
	func = &C1::double_val; // Get offset of double val

	cout << "Here are values :  ";
	cout << ob1.*data << " " << ob2.*data << "\n";
	cout << "Here they are doubled: ";
	cout << (ob1.*func)() << " ";
	cout << (ob2.*func)() << "\n";

	/*
	// Now data pointing to double variable;
	data = &C1::d;
	cout << "Here are values :  ";
	cout << ob1.*data << " " << ob2.*data << "\n";
	*/
	// So i can not use same variable i need to declare another variable of type double 

	double C1 :: *dataInDouble;// Data member pointer
	dataInDouble  = &C1::d;
	cout << "Here are values :  ";
	cout << ob1.*dataInDouble << " " << ob2.*dataInDouble << "\n";

}

void prog11()
{
	int C1::*data;			// Data pointer 
	int (C1::*func)();		// Function Pointer

	C1 obj1(100), obj2(200);
	C1 *p1, *p2;
	p1 = &obj1;
	p2 = &obj2;

	data = &C1::val;
	func = &C1::double_val;

	cout << "Values before are " << p1->*data << "   " << p2->*data <<endl;
	cout << "Values after doubling are " << (p1->*func)() << "  " << (p2->*func)() <<endl;
}

/*
// Todo : Revisit 

// In above examples, we have used only single data member inside the class, 
// now we'll use more than 1 data members and members functions inside class
// and check the behaviour of the pointer to member (answer is you need define different pointer to different class variables.)
// Pointer to members for private / public members??  (answer is Only public )


// I didn't get any solution today, i'll revisit it again (Revisted today)
class PointerToMember
{
private :
	int  a,b;
	char c[10];
	double d;
public:
	int  x,y;
	char w[10];
	double z;
	PointerToMember(int a, int b, int x, int y, char c[], char w[]) 
	{
		this->a = a;
		this->b = b;
		this->x = x;
		this->y = y;
		strcpy(this->w,  w);
		strcpy(this->c, c);
	}

	int    get_a() { return a; }
	char *   get_c() { return c; }
	double get_d() { return d; }

	int		get_x() { return x ;}
	char*	get_w() { return  w;}
	double	get_z() { return  z;}
};


void prog12()
{
	char PointerToMember :: *data;// Data member pointer
	char (PointerToMember:: *func)(); // Function member pointer
	PointerToMember ob1(10, 20, 30, 40, "Private1", "public1"), ob2(50, 60, 70, 80, "Private2", "public2");

	data = &(PointerToMember::w); // Get offset of val
	func = &(PointerToMember::get_w); // Get offset of double val

	cout << "Here are values :  ";
	cout << ob1.*data << " " << ob2.*data << "\n";
	cout << (ob1.*func)() << " ";
	cout << (ob2.*func)() << "\n";
}


*/


/************************************************ Prog 13 Introduction to references ***********************************************/
/*
	There are 2 ways for call by reference 
	1. Pointer to argument
	2. Use of reference parameter
*/

void negRef(int & i)
{
	i = -i;
}

void neg(int *i)
{
	*i = -*i;
}
void prog13()
{
	int x;
	x = 10;
	cout << x << "  Negated is  ";
	neg(&x);
	cout << x << endl;	
	cout << x << "  Negated is  ";
	negRef(x);
	cout << x << endl;

}

// Using references swap the variables
void swap(int &x, int &y)
{
	int t;
	t = x; 
	x = y;
	y = t;
}

void prog14()
{
	int a = 20, b = 30;
	swap(a, b);
	cout << a << "  " << b;
}


/******************************************* Prog 15 Passing references to Objects *************************************************/



class A {
	int id;
public:
	int i;
	A(int i);
	~A();
	void neg(A &o) { o.i = -o.i; } // no temporary created  // You used . opertor for reference
};


A::A(int num)
{
	cout << "Constructing " << num << "\n";
	id = num;
}
A::~A()
{
	cout << "Destructing " << id << "\n";
}

void prog15()
{
	A o(1);
	o.i = 10;
	o.neg(o);                      // You are using object o to call a member function neg. and you are passing refrence to same object here .
	cout << o.i << "\n";
}

/************************************ Prog 16 REtruning Referece **********************************************/
char & replace(int i);// Will return a charater reference 
char s[80] = "Hello there ";
char &replace(int i)
{
	return s[i];
}

void prog16()
{
	replace(8) = 'X';
	cout << s;
}

/********************************** Prog 17 Independent Reference **********************************/
void prog17()
{
	int a;
	int &ref = a;

	a = 10;
	cout << a << " " << ref << "\n";
	ref = 100;
	cout << a << " " << ref << "\n";
	int b = 19;
	ref = b; // this puts b's value into a
	cout << a << " " << ref << "\n";
	ref--; // this decrements a
	// it does not affect what ref refers to
	cout << a << " " << ref << "\n";

}

/*************************************** References to derived types **********************************************/
/* 
	Same as pointers to derived types
	Rules
1.	You cannot reference another reference. Put differently, you cannot obtain the address of a reference. 
2.  You	cannot create arrays of references. 
3.  You cannot create a pointer to a reference. 
4.  You cannot reference a bit-field
5.  A reference variable must be initialized when it is declared unless it is a member of
    a class, a function parameter, or a return value. 
6.  Null references are prohibited.
*/


/*********************************  Prog 18 Dynamic memory allocations Operators *******************************************/
/*
	The general forms of new and delete are shown here:
		p_var = new type;
		delete p_var;
	Here, p_var is a pointer variable that receives a pointer to memory that is large enough
	to hold an item of type type.

1.  new automatically allocates enough memory to hold an object of the specified type.
	You do not need to use the sizeof operator. Because the size is computed automatically,
	it eliminates any possibility for error in this regard. 
2.  new automatically returns a pointer of the specified type. You don't need to use an
	explicit type cast as you do when allocating memory by using malloc(). 
3.  Both,new and delete can be overloaded, allowing you to create customized allocation systems.

	Although there is no formal rule that states this, it is best not to mix new and delete
	with malloc() and free() in the same program. There is no guarantee that they are
	mutually compatible.
*/

void prog18()
{
	int *p;
		try
	{
		p = new int;
	}
	catch (bad_alloc xa)
	{
		cout << "Allocation Failure"<<endl;
		return;
	}
	*p = 100;
	cout << "At " << p << " ";
	cout << "is the value " << *p << "\n";
	delete p;
}

/************************************** Prog 19 Initilizing allocated memory  ******************************************/

void prog19()
{
	int *p;
	try {
		p = new int(87); // initialize to 87
	}
	catch (bad_alloc xa) {
		cout << "Allocation Failure\n";
		return ;
	}
	cout << "At " << p << " ";
	cout << "is the value " << *p << "\n";
	delete p;
}


/************************************** Prog 20 Allocated arrays ******************************************/
/*
	You can allocate arrays using new by using this general form:
		p_var = new array_type [size];
	Here, size specifies the number of elements in the array.
	To free an array, use this form of delete:
		delete [ ] p_var;
	Here, the [ ] informs delete that an array is being released.

	One restriction applies to allocating arrays: They may not be given initial values.
	That is, you may not specify an initializer when allocating arrays.
*/
void prog20()
{

	int *p, i;
	try {
		p = new int[10]; // allocate 10 integer array
	}
	catch (bad_alloc xa) {
		cout << "Allocation Failure\n";
		return;
	}
	for (i = 0; i<10; i++)
		p[i] = i;
	for (i = 0; i<10; i++)
		cout << p[i] << " ";
	delete[] p; // release the array

}

/******************************* Prog 21 Allocating Objects *****************************************/
class balance
{
	double curr_bal;
	char name[80];
public:
	balance() { name[0] = '\0'; }
	balance(double n, char *s) 
	{
		cout << "Constructing \n";

		curr_bal = n;
		strcpy(name, s);
	}
	~balance() {
		cout << "Destructing ";
		cout << name << "\n";
	}

	void set(double n, char *s)
	{
		curr_bal = n;
		strcpy(name, s);
	}
	void get_bal(double &n, char *s)
	{
		n = curr_bal;
		strcpy(s,name);
	}
};

void prog21()
{
	balance *p, *q;
	char s[80];
	double n;
	try {
		p = new balance (12387.87, "Ralph Wilson");
	}
	catch (bad_alloc xa) {
		cout << "Allocation Failure\n";
		return ;
	}

	try {
		q = new balance [20];
	}
	catch (bad_alloc xa) {
		cout << "Allocation Failure\n";
		return;
	}

	p->set(12387.87, "Ralph Wilson");
	p->get_bal(n, s);
	cout << s << "'s balance is: " << n;
	cout << "\n";
	delete p;
	delete [] q;
}

/**************************************** prog 22 Np throw Alternative ****************************************/

void prog22()
{
	int *p, i;
	p = new(nothrow) int[32]; // use nothrow option
	if (!p) 
	{
		cout << "Allocation failure.\n";
		return ;
	}
	for (i = 0; i<32; i++) 
		p[i] = i;
	for (i = 0; i<32; i++)
		cout << p[i] << " ";
	delete[] p; // free the memory

}

/* 
	Placement form of New / delete
	Needed for overloading of new and delete
*/




