// This class defination and implementaions are copied from the complete reference c++ pg 291 ed 3
/*
Restricitions 
There are a few restrictions that apply to class members.A non - static member
variable cannot have an initializer.No member can be an object of the class that is
being declared. (Although a member can be a pointer to the class that is being
declared.) No member can be declared as auto, extern, or register.

*/

#include "Generic.h"

class employee 
{
	char name[80]; // private by default
public:
	void putname(char *n); // these are public
	void getname(char *n);
private:
	double wage; // now, private again
public:
	void putwage(double w); // back to public
	double getwage();
};
void employee::putname(char *n)
{
	strcpy(name, n);
}
void employee::getname(char *n)
{
	strcpy(n, name);
}
void employee::putwage(double w)
{
	wage = w;
}
double employee::getwage()
{
	return wage;
}
void test_class_2()
{
	employee ted;
	char name[80];
	ted.putname("Ted Jones");
	ted.putwage(75000);
	ted.getname(name);
	cout << name << " makes $";
	cout << ted.getwage() << " per year.";
}



// All public data members example
class myclass
{
public :
	int i, j, k;
};

void test_Access_All_Public()
{
	myclass a, b;
	a.i = 40;
	a.j = 30;
	a.k = a.j * a.i;
	b.k = 500;
	cout << "a.k = "<<a.k <<" b.k = " << b.k << endl;
	cout << "a.k = "<<a.k <<" b.k = " << b.k << endl;
}

/* Introduction to structures in C++
In fact, the only
difference between a class and a struct is that by default all members are public in a
struct and private in a class.
*/

// Just to change strct to class enbale class mystr and public : 

//class mystr
struct mystr
{
// public : // class
	mystr();
	~mystr();

	void builStr(char *);
	void showStr();
private:
	char str[255];
};


mystr::mystr()
{
	cout << "Inside the constructor " << endl;
}

mystr :: ~mystr()
{
	cout << "Inside the Destructor" << endl;
}
void mystr::builStr(char *s)
{
	if (!*s)
		*str = '\0';
	else
		strcat(str, s);
}
void mystr::showStr()
{
	cout << "str :::::    " << str << endl;
}

void test_structure()
{
	mystr s;
	s.builStr("");
	s.builStr("Hello ");
	s.builStr("There ");
	s.showStr();

	s.builStr("Hello ");
	s.builStr("There ");
	s.showStr();

}


// Union and classes 
// Union is used to swap the bytes that makes up an unsigned short integer.


union swap_byte
{
	void swap();
	void set_byte(unsigned short i);
	void show_word();
	unsigned short u;
	unsigned char c[2];
};

void swap_byte::swap()
{
	unsigned char t;
	t = c[0];
	c[0] = c[1];
	c[1] = t;
}

void swap_byte::show_word()
{
	cout << u;
}

void swap_byte::set_byte(unsigned short i)
{
	u = i;
}

void test_union()
{
	swap_byte b;
	b.set_byte(49034);
	b.swap();
	b.show_word();
}


// Introduction to Anonymous unions
/*
There is a special type of union in C++ called an anonymous union. An anonymous
union does not include a type name, and no objects of the union can be declared.
Instead, an anonymous union tells the compiler that its member variables are to
share the same location. However, the variables themselves are referred to directly,
without the normal dot operator syntax.
*/


void test_anonymous_union()
{
	// define anonymous union
	union {
		long l;
		double d;
		char s[4];
	};

	// Now access the data members directly with there names

	// now, reference union elements directly
	l = 100000;
	cout <<"l =  " << l << " "<<endl;
	d = 123.2342;
	cout <<"d  =  "<< d << " " << endl;
	strcpy(s, "hi");
	cout << "s =  "<< s<<endl;
}
