
        
#include"AdvancedCPP.h"
#include<cstdlib>
/* 
	This chaptr deals with the Advanced Topics in C++
*/

int main()
{
	cout << "Hello World ! - Welcome to Advanced C++ topics  " << endl << endl ;
//	prog1 ();
//	prog2 ();
//	prog3 ();
//	prog4 ();
//	prog5 ();
//	prog6 ();
//	prog7 ();
//	prog8 ();
//	prog9 ();
//	prog10();
	prog11();
	prog12();
	prog13();
	prog14();
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

	cout << "\n\n\n";
}

// Use of typeid operator, ned to include typeinfo header file.

#include<typeinfo>
class myClass1 {};
class myClass2 {};

void prog1()
{
	myClass1 m1;
	myClass2 m2;

	cout << "Type of object m1 is : " << typeid(m1).name() <<endl;
        cout << "Type of object m2 is : " << typeid(m2).name() <<endl;        
}

/*	-- Concept 1 --
	The most important use of typeid occurs when it is applied through a pointer of a polymorphic base class.
	In this case it will automatically return the type of actual object being pointed to which may be base class object 
	or derived class object.
*/

/* Test to concept 1  */

class base1
{
	virtual	void fun() {};
public :
	base1() {} 
	base1(base1 &b ) { cout << "Base Copy Constuctor \n";  }
};

class derived1 : public base1
{
public :
	derived1() {} 
	derived1(derived1 &b ) : base1() { cout << "derived1 Copy Constuctor \n";  }
};

class derived2 : public base1
{
	void fun() {};

public : 
	derived2() {}
	derived2(derived2 &b ):base1() { cout << "derived2 Copy Constuctor \n";  }
};

void whatobj(base1  &b)  // No copy constuctor is called here.
{	
	cout << "Reference  pointing to object of class : " << typeid(b).name() <<endl;
}

/*

void whatobj(base1  b) // Copy constuctor of base is called.
{	
	cout << "Reference  pointing to object of class : " << typeid(b).name() <<endl;
}

//  If you disable following two function then copy constructor of base class is only called.

void whatobj(derived1  b) 
{	
	cout << "Reference  pointing to object of class : " << typeid(b).name() <<endl;
}

void whatobj(derived2  b)
{	
	cout << "Reference  pointing to object of class : " << typeid(b).name() <<endl;
}

*/
void prog2()
{
	base1 b;
	derived1 d1;
	derived2 d2;
	base1 b2 = b;
	// derived1 d11 = b;  // This line results in compiler error.
	
	// With base class pointer
	base1 *bp;
	bp = & b;
	cout << "Base pointer pointing to object of class : " << typeid(*bp).name() <<endl;
	
	bp = & d1;
	cout << "Base pointer pointing to object of class : " << typeid(*bp).name() <<endl;

	bp = & d2;
	cout << "Base pointer pointing to object of class : " << typeid(*bp).name() <<endl;

	// With reference

	base1 &br1 = b;
	cout << "Base reference  pointing to object of class : " << typeid(br1).name() <<endl;
	
	base1 &br2 = d1;
	cout << "Base reference  pointing to object of class : " << typeid(br2).name() <<endl;
	
	base1 &br3 = d2;
	cout << "Base reference  pointing to object of class : " << typeid(br3).name() <<endl;

	// Impelemtation of whatobj() function 
	whatobj(b);
	whatobj(d1);
	whatobj(d2);
}

/*
	Problem statement :  Write a function factory() to create instances of various types of 
			     derived classes from main class.

	Solution : We'll use the above classes and solve in following prog3().
*/

 base1 * factory()
{

	int randomNumber = rand()%3;
	switch(randomNumber)
	{
		case 0 :
			return new base1; break;
		case 1 :
			return new derived1; break;
		case 2 :
			return new derived2; break;
	}
}

void prog3()
{
	int i = 0 ;

	// Generating 4 objects of different types
	for(i = 0; i < 4; i++ )
	{
		base1 *bp = factory();
		cout << "The object generated is of type : " << typeid(*bp).name()<<endl;
	}

}

/*
	Typeid to templates
*/
template<class T> class myTemplate
{
	T a;
};

void prog4()
{
	myTemplate <int > intTemplate;
	myTemplate <char> charTemplate;
	myTemplate <float> floatTemplate;
	myTemplate <myClass1> myClass1Template;

	cout << "Type of object is : " << typeid(intTemplate).name() <<endl;
	cout << "Type of object is : " << typeid(charTemplate).name() <<endl;
	cout << "Type of object is : " << typeid(floatTemplate).name() <<endl;
	cout << "Type of object is : " << typeid(myClass1Template).name() <<endl;
}

/************************** Introduction to Casting Operations  **************************/
/*
	C++ has 5 casting operators
	1. () : Normal c type casting.
	2. dynamic_cast
	3. const_cast
	4. static_cast
	5. reinterpret_cast
*/

/*
	dynamic_cast : Performs run time cast that verifies validity of cast. If cast is invalid then dynamic_cast fails
		
	General syntax :

	dynamic_cast<target> (expression)

	target type must be of a pointer of reference type.
	expression must evaluate to a pointer or reference type

Uses : 
	- A dynamic_cast can always cast a pointer of derived class into pointer of base class (also for references).
	- A dynamic_cast can base pointer to derived pointer only if object being pointed to derived class object.
Suceess test :
	- dynamic_cast will succeed if pointer being cast is a pointer to either an object of target type or an object
	  derived from target type.
	- If cast fails, then dynamic_cast evaluates to null, also bad_cast exeception is thrown.

	Base *bp, b_ob;
	Derived *dp, d_ob;
	bp = &d_ob;		  	         // Base pointer points to object of derived class.
	dp = dynamic_cast<Derived *> (bp);       // Type cast bp pointer to derived * class type. 
	if(dp)
		cout <<"Cast OK";
	
	// Seems dynamic_cast returns pointer of derived *.
*/

class Base 
{
public : 
	virtual void func() { cout << "Inside Base \n"; }
};

class Derived : public Base
{
public:
	void func() {  cout << "Inside Derived\n"; }
};

void prog5()
{
	Base *bp, b_ob;
	Derived *dp, d_ob;
	bp = & d_ob;	
	int a;
	

	// dp = dynamic_cast<Derived *> (&a); // Run time operator 
	// Compiler detectes at compiler time and flashes error.

#if CONCEPT_DYNAMIC_CAST
	 Result   		Assignment  	Target  	Xpression      
	  Pass      	   	   B*         	  D*       	  &d_ob
	  Pass      	   	   D*         	  D*       	  &d_ob
	  Pass      	   	   B*         	  B*       	  &d_ob
	  Compilation Error        D*         	  B*       	  &d_ob

	  Fail      	   	   B*         	  D*       	  &b_ob		[Compiler warning]
	  Fail      	   	   D*         	  D*       	  &b_ob		[Compiler warning]
	  Pass      	   	   B*         	  B*       	  &b_ob
	  Compilation Error        D*         	  B*       	  &b_ob


	 Result   		Assignment  	Target  	XpressionInputPointer   InputPointerTarget     
	  Pass      	   	   B*         	  B*       	         bi                   b_ob
	  Pass      	   	   B*         	  B*       	         bi                   d_ob
	  Compilation Error        B*         	  B*       	         di                   b_ob
	  Pass      	   	   B*         	  B*       	         di                   d_ob

	  Fail      	   	   B*         	  D*       	         bi                   b_ob
	  Pass      	   	   B*         	  D*       	         bi                   d_ob
	  Compilation Error        B*         	  D*       	         di                   b_ob
	  Pass      	   	   B*         	  D*       	         di                   d_ob


	  Compilation Error        D*         	  B*       	         bi                   b_ob
	  Compilation Error        D*         	  B*       	         bi                   d_ob
	  Compilation Error        D*         	  B*       	         di                   b_ob
	  Compilation Error        D*         	  B*       	         di                   d_ob

	  Fail      	   	   D*         	  D*       	         bi                   b_ob
	  Pass      	   	   D*         	  D*       	         bi                   d_ob
	  Compilation Error        D*         	  D*       	         di                   b_ob
	  Pass      	   	   D*         	  D*       	         di                   d_ob

	Fails when target is derived * and object is expression is base object.
	Compilation Error when base pointer to derived pointer in assignment. or derived pointer points to base object.
#endif

	Base *bi;
	Derived *di;

	
	di = & d_ob;
	dp = dynamic_cast<Derived *> (di);
	if(dp)
	{
		cout << "CAST Successful\n";
	}
	else
	{
		cout << "CAST Unsuccessful\n";	
	}

/*

	dp = dynamic_cast<Derived *> (&d_ob); // Run time operator 
	if(dp) 
	{
		cout << "Cast from Derived * to Derived * OK.\n";
		dp->func();
	} 
	else
	{
		cout << "Error\n";
	}

	bp = dynamic_cast<Base *> (&d_ob);
	if(bp) 
	{
		cout << "Cast from Derived * to Base * OK.\n";
		bp->func();
	}
	 else
		cout << "Error\n";

	cout << endl;

	bp = dynamic_cast<Base *> (&b_ob);
	if(bp) 
	{
		cout << "Cast from Base * to Base * OK.\n";
		bp->func();
	}
	 else
		cout << "Error\n";
	
	cout << endl;
	
	dp = dynamic_cast<Derived *> (&b_ob); // dynamic_cast will fail here.
	if(dp)
	{
		cout << "Error\n";
		dp->func();  // Control will not fall here, so this will not be called.
	}
	else
	{
		cout << "Cast from Base * to Derived * not OK.\n";
		// dp->func(); // Null pointer so seg fault.
	}
	cout << endl;

	bp = &d_ob; // bp points to Derived object
	dp = dynamic_cast<Derived *> (bp);
	if(dp) 
	{
		cout << "Casting bp to a Derived * OK\n" <<
		"because bp is really pointing\n" <<
		"to a Derived object.\n";
		dp->func();
	}
	 else
		cout << "Error\n";
	cout << endl;

	bp = &b_ob; // bp points to Base object
	dp = dynamic_cast<Derived *> (bp);
	if(dp)
		cout << "Error";
	else 
	{
		cout << "Now casting bp to a Derived *\n" <<
		"is not OK because bp is really \n" <<
		"pointing to a Base object.\n";
	}

	cout << endl;

	dp = &d_ob; // dp points to Derived object
	bp = dynamic_cast<Base *> (dp);
	if(bp) 
	{
		cout << "Casting dp to a Base * is OK.\n";
		bp->func();
	}
	 else
		cout << "Error\n";
*/
}


/*
	Replacing typeid with dynamic_cast
*/

class BASE
{
public : 
	virtual void f()
	{
		cout <<"f in BASE \n";
	}

};

class DERIVED : public BASE
{
public:
	void derivedOnly()
	{
		cout << "Inside derived class only \n";
	}	
};

void prog6()
{
	BASE *bp , b_ob;
	DERIVED *dp, d_ob;

	// ************************************
		// use typeid
	// ************************************
	bp = &b_ob;
	if(typeid(*bp) == typeid(DERIVED)) 
	{
		dp = (DERIVED *) bp;
		dp->derivedOnly();
	}	
	else
		cout << "Cast from Base to Derived failed.\n";

	bp = &d_ob;
	if(typeid(*bp) == typeid(DERIVED)) 
	{
		dp = (DERIVED *) bp;
		dp->derivedOnly();
	}
	else
		cout << "Error, cast should work!\n";	

// Given above logic, represent the same using dynamic_cast

	bp = & b_ob;
	dp = dynamic_cast<DERIVED *> (bp);
	if(dp)
	{
		dp->derivedOnly();
	}
	else
	{
		cout << "Cast from base to derived failed.\n";
	}

	bp = & d_ob;
	dp = dynamic_cast <DERIVED *> (bp);
	if(dp)
	{
		dp->derivedOnly();
	}
	else
	{
		cout << "Error, cast should worl! \n";
	}

}

/*
	dynamic_cast with template class
*/

template <class T> 
class Num 
{
protected : 
	T val;
public : 
	Num (T x) : val(x) {}
	virtual T getval() { return val;}
};

template <class T> class SqrNum : public Num<T>
{
public:
	SqrNum(T x) : Num<T> (x) {}
	T getval() { return Num<T>::val * Num<T>::val ; }//val * val; }
};

void prog7()
{
	Num <int > *bp, numInt_ob(2);
	SqrNum <int> *dp, sqrInt_ob(3);
	Num<double> numDouble_ob(3.3);

	bp = dynamic_cast < Num <int>* > (&sqrInt_ob);
	if(bp)
	{
		cout << "Cast from sqrInt_ob to numInt OK\n";
		cout << "value is "<< bp->getval() <<endl;
	}
	else
	{
		cout << "Error\n";
	}

	dp = dynamic_cast<SqrNum<int> *> (&numInt_ob);
	if(dp)
		cout << "Error\n";
	else 
	{
		cout << "Cast from Num<int>* to SqrNum<int>* not OK.\n";
		cout << "Can't cast a pointer to a base object into\n";
		cout << "a pointer to a derived object.\n";
	}
	cout << endl;

	bp = dynamic_cast<Num<int> *> (&numDouble_ob);
	if(bp)
		cout << "Error\n";
	else
		cout << "Can't cast from Num<double>* to Num<int>*.\n";
	cout << "These are two different types.\n";

}

/*
	Introduction to const_cast
Usage :
	- To used to explicitly override const and/or volatile in a cast.
	- The target type must be same as source type.
	- The comman use of const_cast is to remove the const-ness.

*/

void sqrval(  const int  *  val)
{
	int *p;
	// Cast away const-ness.
	p = const_cast<int*> (val); // P pointing where var pointing
	*p = *val * *val; 

	// Following lines generate compiler error.
	// To make it working function prototype should be 
	//  void sqrval (int * const val)

//	int *p1 = val;  
//	*p1 = *val * *val;
	
}

void sqrval(  const int  & val)
{
	// Cast away const-ness.
	 const_cast<int &> (val) = (val * val);	
}
void prog8()
{
	int x = 10;
	cout << "x before call: " << x << endl;
	sqrval(&x);
	cout << "x after call: " << x << endl;
	sqrval(x);
	cout << "x after call: " << x << endl;
}

/*
	Introduction to static_cast
Usage :
	- It performs a non polymorphic cast.
	- No run time check s are performed.
	- It is substitute of original cast opertor.
*/

// Program to cast int value to double.
void prog9()
{
	int i;
	for(i = 0 ; i < 10 ; i++)
	{
		cout << static_cast <double> (i) / 3 << " " ;
	}
}

/*
		Introduction to reinterpret_cast 

	- It converts one type into a fundamentally different type.
	- It can change pointer into integer or integer into pointer.
	- It can be used for casting inherently incompatible pointer types.
*/

void prog10()
{
	int i;
	char *p = "This is a string ";
	i = reinterpret_cast<int> (p);
	cout << i;

}

/*
	Introduction to conversion functions.

	- Special Operator functions.
	
syntax :
	operator type () 
	{return value;}
	- type is target type yo which you are converting to .
	- It returns data of type type.
	- No parameters may be included.
	- It must be member function of the class.
	- Are inherited and they may be virtual.

*/

const int SIZE=100;
// this creates the class stack
class stack 
{
	int stck[SIZE];
	int tos;
public:
	stack() { tos=0; }
	void push(int i);
	int pop(void);
	operator int() { return tos; } // conversion of stack to int
};

void stack::push(int i)
{
	if(tos==SIZE) 
	{
		cout << "Stack is full.\n";
		return;
	}	
	stck[tos] = i;
	tos++;
}

int stack::pop()
{
	if(tos==0) 
	{
		cout << "Stack underflow.\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

void prog11()
{
	stack stck;
	int i, j;
	for(i=0; i<20; i++) stck.push(i);
	j = stck; // convert to integer
	cout << j << " items on stack.\n";
	cout << SIZE - stck << " spaces open.\n";
}

/************************************************  Program 12   **************************************************/
/*
	If you do not want this implicit conversion to be made, you can prevent it by using
	explicit. The explicit specifier applies only to constructors. A constructor specified as
	explicit will only be used when an initialization uses the normal constructor syntax.
*/


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
