/***
	It is possible to grant a nonmember function access to the private members of a class
	by using a friend.

	A friend function has access to all private and protected members 
	of the class for which it is friend

	To declare a friend function include its prototype within class preceding it with 
	keyword friend 
***/

#include "Generic.h"


/************************************ Friened Function Type 1 *********************************************/
/***************************  External Function friend with a class  **************************************/

class myclass
{
private:
	int a, b;

public:
	friend int sum(myclass x);
	void set_ab(int a, int b);
};

int sum(myclass x)
{
	int c;
	c = x.a + x.b;
	return c;
}






void myclass::set_ab(int a, int b)
{
	this->a = a;
	this->b = b;
}

void test_friend_1_function()
{
	myclass abc;
	abc.set_ab(10, 50);
	cout << "The sum is " << sum(abc) << endl;

}

/****
	Why to use friend functions?
	1. friends can be useful when you are overloading certain types of operators. (chapter 14)
	2. friend functions make the creation of some types of I/O functions easier. (chapter 18)
	3. In some cases, two ormore classes may contain members that are interrelated
	   relative to other parts of your program (Below example)
****/


/************************************ Friened Function Type 1 *********************************************/
/*************************** External Function friend with two class   **************************************/

const int IDLE = 0;
const int INUSE = 1;

class c2; // Forward declaration

class c1
{
	int status;
public :
	void setStatus(int);
	friend int idle(c1 a, c2 b);
};
class c2 
{
	int status;
public:
	void setStatus(int);
	friend int idle(c1 a, c2 b);
};
void c1::setStatus(int st)
{
	status = st;
}
void c2::setStatus(int st)
{
	status = st;
}
int idle(c1 a, c2 b)
{
	if (a.status || b.status)
		return 0;
	else
		return 1;
}

void test_friend_2_function()
{
	c1 x;
	c2 y;
	x.setStatus(IDLE);
	y.setStatus(IDLE);

	if (idle(x, y)) 
		cout << "Screen can be used.\n";
	else
		cout << "In use.\n";

	x.setStatus(INUSE);

	if (idle(x, y)) 
		cout << "Screen can be used.\n";
	else
		cout << "In use.\n";
}

/************************************ Friened Function Type 2 *********************************************/
/********************* A friend of one class may be a member of another class   ***************************/

class C2;
class C1
{
	int status;
public : 
	void set_status(int state);
	int idle(C2 b);			// idle is member function of class C1
};
class C2
{
	int status;
public:
	void set_status(int state);
	friend int C1::idle(C2 b);
};

void C1::set_status(int state)
{
	status = state;
}

int C1::idle(C2 b)
{
	if (this->status || b.status)
		return 0;
	else
		return 1;
}
void C2::set_status(int state)
{
	status = state;
}


void test_friend_3_function()
{
	C1 x;
	C2 y;
	x.set_status(IDLE);
	y.set_status(IDLE);
	if (x.idle(y)) cout << "Screen can be used.\n";
	else cout << "In use.\n";
	x.set_status(INUSE);
	if (x.idle(y)) cout << "Screen can be used.\n";
	else cout << "In use.\n";
}


class frd2;
class frd1
{
	int a;
public :
	frd1()
	{
		a = 25540;
	}
	int sum(class frd2);
};
class frd2
{
	int b;
public:
	frd2()
	{
		b = 100;
	}
	friend int frd1::sum(frd2);
};
int frd1::sum(frd2 x)
{
	return (a + x.b);
}

void test_friend_4_function()
{
	frd1 a;
	frd2 b;
	cout << "friend function sum is " << a.sum(b)<<endl;
}

/************************************ Friened Class *********************************************/
/************************ One class to be a friend of another class  ****************************/


class TwoValues
{
	int a;
	int b;
public:
	TwoValues(int i, int j) { a = i; b = j; }
	friend class Min;
};

class Min
{
public :
	int min(TwoValues x);
};

int Min::min(TwoValues x)
{
	return x.a < x.b ? x.a : x.b;
}
void test_friend_5_function()
{
	TwoValues ob(20, 20);
	Min m;
	cout << m.min(ob);
}

/* When a function is defined inside a class declaration, it is automatically made into an inline
function(if possible). */