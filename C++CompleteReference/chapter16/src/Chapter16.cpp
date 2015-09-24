
#include"Chapter16.h"

/* 
	This chaptr deals with the inheritance
*/

int main()
{
	cout << "Hello World ! - Welcome to chapter 16 " << endl << endl ;
//	prog1 ();
//	prog2 ();
//	prog3 ();
//	prog4 ();
//	prog5 ();
	prog6 ();
//	prog7 ();
//	prog8 ();
//	prog9 ();
//	prog10();
//	prog11();
//	prog12();
//	prog13();
//	prog14();
	prog15();
	prog16();
	prog17();
	prog18();
	prog19();
	prog20();
	prog21();
	prog22();
	prog23();
	prog24();
	prog25();

	cout << "\n\n\n ";
}


/*
	- The base class access specifier must be either public, private or protected.
	- Default is private for class.
	- Default is public for structures.

*/

/************************************************  Program 1    **************************************************/
/*
		Test of public access specifier of base class
*/

class base1
{
	private: int i;
	public:	int j;
	protected: int k;

	private:   int return_i() { cout << " Private of bsae1 \n" ;return i; }
	public:	   int return_j() { cout << " Public of bsae1 \n" ;return j; }
	protected: int return_k() { cout << " Protected of bsae1 \n" ;return k; }
};

// We are now deriving from public base 1 class
class derived1 : public base1
{
	// Empty class
public:

//  // So finally you can not access the private of base.
//	int access_private_of_base1()
//	{
//		return return_i(); 
		/*
			The above statement also flashes error
			// Compiler flashes error, can not access private member declaread in class base1.
		*/

//	}
	int access_protected_of_base1()
	{
		return return_k();
	}

};

void prog1()
{
	// Now create object of derived class and try to access public, private and protected members.
	derived1 d;
	// d.return_i();   // Compiler flashes error, can not access private member declaread in class base1.
	d.return_j();
	// d.return_k();		// Compiler flashes error, can not access protected member declaread in class base1.

	// So  conclusion is that, public is public only
	// Now private and protected members are not accessible from outside. So i write a covering function in derived class to access private and protected members of base class;
//	d.access_private_of_base1();  // You can not access private of base in any manner.
	d.access_protected_of_base1();

}

/************************************************  Program 2    **************************************************/
/*
		Inheritance with the private access specifier
*/

class base2
{
private:
	int i;
	int return_private() { cout << "Private of base \n"; return i; }
public:
	int j;
	int return_public() { cout << "public of base \n"; return j; }
protected:
	int k;
	int return_protected() { cout << "protected of base \n"; return k; }

	/*
		This is to show that all private, public, protected members can access anything of private, protected or public.
		It compiles successfully.
	*/
public:
	void print_all_public() { cout << " i = " <<i << " j = " << "k = " <<k << endl; }
private:
	void print_all_private() { cout << " i = " <<i << " j = " << "k = " <<k << endl; }
protected:
	void print_all_protected() { cout << " i = " <<i << " j = " << "k = " <<k << endl; }
};

class derived2 : private base2
{
	// Public of base will be private to derived.
	// Protected of base will be private to derived.
};
void prog2()
{
	// derived2 d;
	// Public of base 
	// d.return_public();// is not accessible because derived2 uses private to inherit from base2
}

/************************************************  Program 3    **************************************************/
/*
		Protected base class inheritance
*/

class base3
{
private:
	int i;
	int return_private() { cout << "Private of base \n"; return i; }
public:
	int j;
	int return_public() { cout << "public of base \n"; return j; }
protected:
	int k;
	int return_protected() { cout << "protected of base \n"; return k; }
};

// Derived class inherited as protected one.

class derived3 : protected base3
{
	// Public of base are now protected in derived.
	// Protected of base are now protected in derived.

};

void prog3()
{
	// Try to access derived class's public members
}

/************************************************  Program 4    **************************************************/
/*
	inheriting two or more base classes
*/
// An example of multiple base classes.
class base4a 
{
protected:
	int x;
public:
	void showx() { cout << x << "\n"; }
};
class base4b 
{
protected:
	int y;
public:
	void showy() { cout << y << "\n"; }
};
// Inherit multiple base classes.
class derived4 : public base4a, public base4b 
{
public:
	void set(int i, int j) { x = i; y = j; }  // here we are able to use x and y.
};

void prog4()
{
	derived4 d;
	// We have inheriated base4a and base4b in derived publically. So we'll be able to access public of both parent classes.

	d.showx();
	d.showy();

}

/************************************************  Program 5    **************************************************/
/*
		Inheritance : Constructors and Destructors

Ques 1 : When are base class constructors and destructors are executed?
Ans	   : Base class constructors are first executed and then derived class constructors
         Destrctors are executed in reverse order
		 constructor functions are executed in order of derivation. 
		 Because a base class has no knowledge of any derived class, any
		 initialization it needs to perform is separate from and possibly prerequisite to any
		 initialization performed by the derived class. Therefore, it must be executed first.

		 In cases of multiple inheritance (that is, where a derived class becomes the base
		 class for another derived class), the general rule applies: Constructors are called in
		 order of derivation, destructors in reverse order.
*/
class base5
{
public:
	base5() { cout << " Base class constructor \n"; }
	~base5() { cout << " Base class destructor\n"; }
};

class derived5 : public base5
{
public:
	derived5() { cout <<  " Derived class constructor \n";}
	~derived5() { cout << " Derived class destructor \n";}
};

void prog5()
{
	{
		derived5 d;
	}
	{
		base5 b;
	}
}

/************************************************  Program 6    **************************************************/
/*
		Multiple inheritance
*/

class base6
{
public:
	base6()
	{
		cout << "base6 class constructor \n";
	}
	~base6()
	{
		cout << "base6 class destructor \n";
	}
};

class derived6a : private base6
{
public:
	derived6a()
	{
		cout << "derived6a class constructor \n";
	}
	~derived6a()
	{
		cout << "derived6a class destructor \n";
	}
};

class derived6b : private derived6a
{
public:
	derived6b()
	{
		cout << "derived6b class constructor \n";
	}
	~derived6b()
	{
		cout << "derived6b class destructor \n";
	}
};

void prog6()
{
	derived6b a;

	/*
		  // If following statement is added then the output is 
			base6 class constructor
			derived6a class constructor
			derived6b class constructor
			derived6b class destructor
			derived6a class destructor
			base6 class destructor
			derived6b class destructor
			derived6a class destructor
			base6 class destructor

			why??

	a.~derived6b();
	*/
	// Now chaning the access specifer from public to private
}

/************************************************  Program 7    **************************************************/
class abc
{
public:
	abc()
	{
		cout << "abc ctor \n";
	}
	~abc()
	{
		cout << "abc dtor \n";
	}

};
void prog7()
{
	abc a;
	a.~abc();

	/*
		In above case and below case destructor is being called 2 times. 
		Do not explicitly call a destructor. THIS IS PERFECTLY VALID CASE.
	*/
	abc *t = new abc;
	t->~abc();
	delete t;    // do not forget this, or the constructor is not being called at all
}


/************************************************  Program 8    **************************************************/
/*
		Passing parameters to base class constructor

		Use an expanded form of the derived class's constructor declaration
		that passes along arguments to one or more base-class constructors. 
		The general form of this expanded derived-class constructor declaration is shown here:

			derived-constructor(arg-list) : base1(arg-list),
											base2(arg-list),
											// ...
											baseN(arg-list)
			{
					// body of derived constructor
			}


			You specify which arguments will be passed to which base class constructor function. 
			Write down program on your own to check this concept.
*/

class base8a
{
	int i, j;
public:
	base8a(int i, int j)
	{
		cout << "Base8a ctor\n";
		this->i = i;
		this->j = j;
	}
};

class base8b
{
	int a, b;
public:
	base8b(int i, int j)
	{
		cout << "Base8b ctor\n";
		this->a = i;
		this->b = j;
	}
};

class derived8 : public base8a, public base8b
{
	int c, d;
public :

	/*
	One final point to keep in mind when passing arguments to base-class constructors:
The argument can consist of any expression valid at the time. This includes function
calls and variables. This is in keeping with the fact that C++ allows dynamic
initialization.	
	*/
	derived8(int i, int j) : base8a(i+i, i+j), base8b(j+j, i+i+j*2) // even you can use valid function calls
	{
		cout << "Derived8 ctor\n";
		this->c = i;
		this->d = i + i;
	}


	derived8(int i) : base8a(i, i), base8b(i, i)
	{
		cout << "Derived8 ctor\n";
		this->c = i;
		this->d = i+i;
	}
	derived8(int i, int j, int a, int b, int c, int d) : base8a(c, d), base8b(a,b)
	{
		cout << "Derived8 ctor\n";
		this->c = i+a+c;
		this -> d = j+b+d;
	}
};

void prog8()
{
	derived8 d1(10, 12, 13, 14, 15, 16);
	derived8 d2(1);
	derived8 d3(10,50);

}

/************************************************  Program 9    **************************************************/
/*
		Granting the access
		Although a member is inherited as private, you can make it public
*/

class base9
{
protected:
	int i;
	int return_i() { return i; }

};

class derived9 : private base9
{
	// So protected members are now private to this class
	// Now grating access to them as public

public:
	base9::i;
	base9::return_i;
};

void prog9()
{
	derived9 a;
	a.i = 10;
	cout << a.return_i();
}

/************************************************  Program 10   **************************************************/
/*
		Introduction to virtual base class
*/
class base10
{
public :
	int i; 
};

class derived10a : public base10
{
public:
	int j;
};

class derived10b : public base10
{
public:
	int k;
};

// Now we derive a class derived10c from derived10a and derived10b

class derived10c : public derived10a, public derived10b
{
public:
	int sum;
};

void prog10()
{
	derived10c ob;
//	ob.i = 10;   // We get compilation error as ambiguos access of i
	ob.j = 20;
	ob.k = 30;

	ob.derived10a::i = 50;		// You can access individual i from derived10a or derived 10b
	ob.derived10b::i = 60;      // This scenario is prefectly valid
}

/************************************************  Program 11   **************************************************/

/*
In above case with scope resoulution opertor, 2 copies of are availble, one derived from derived10a and another from
derived10b. You can access any one of it or even both.

But what if you only require single copy? how to achieve it??
This is achieved with virtual base class.

When two or more objects are derived from a common base class, you can prevent
multiple copies of the base class from being present in an object derived from those
objects by declaring the base class as virtual when it is inherited.
*/

class base11
{
public:
	int i;
};

// In this simnple case, what is meaning of virtual keyword
class derived11a : virtual public base11
{
public:
	int j;
};

class derived11b : virtual public base11
{
public:
	int j;
};


class derived11c : public derived11a, public derived11b
{
public :
	int sum;
};

void prog11()
{
	derived11a d;
	d.i = d.j = 20;
	cout << d.i << endl;
	cout << d.j << endl;
	derived11c ob;
	ob.i = 10; // now unambiguous

	ob.derived11a::j = 20; // J is now ambiguos
	ob.derived11b::j = 40; // J is now ambiguos

	// Now i want onlyt single copy of variable j, How can i achieve it.
	// It doesn't work
	// ob.j = 50;

	ob.sum = 30;


}

/************************************************  Program 12   **************************************************/
void prog12()
{

}

/************************************************  Program 13   **************************************************/
void prog13()
{

}

/************************************************  Program 14   **************************************************/
void prog14()
{

}

/************************************************  Program 15   **************************************************/
void prog15()
{

}

/************************************************  Program 16   **************************************************/
void prog16()
{

}

/************************************************  Program 17   **************************************************/
void prog17()
{

}

/************************************************  Program 18   **************************************************/
void prog18()
{

}

/************************************************  Program 19   **************************************************/
void prog19()
{

}


/************************************************  Program 20   **************************************************/
void prog20()
{

}


/************************************************  Program 21   **************************************************/
void prog21()
{

}

/************************************************  Program 22   **************************************************/
void prog22()
{

}

/************************************************  Program 23   **************************************************/
void prog23()
{

}

/************************************************  Program 24   **************************************************/
void prog24()
{

}

/************************************************  Program 25   **************************************************/
void prog25()
{

}
