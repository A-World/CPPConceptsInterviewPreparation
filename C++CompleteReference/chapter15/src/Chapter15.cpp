
#include"Chapter15.h"

int main()
{
	cout << "Hello World ! - Welcome to chapter 15  Introduction to operator overloading " << endl << endl ;
	//prog1 ();
	prog2 ();
	//prog3 ();
	prog4 ();
	prog5 ();
	prog6 ();
	prog7 ();
	prog8 ();
	prog9 ();
	prog10();
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

	cout << "\n\n\n ";
}


/************************************************  Program 1     **************************************************/
class abc 
{
	int i;
public:
	abc()
	{		
		i = 0; 
		cout << "Default constructor \n";
	}
	abc(abc &a)
	{ 
		this->i = a.i; 
		cout << "Copy constructor \n";
	}
};

void prog1()
{
	abc a, b;
	//abc c = a;
	b = a;  // In this case no constructor is called. but byte byte data is copied.
}

/************************************************  Program 2    **************************************************/
/*
	1. Operator function can be either members or non members of a class
	2.  Nonmember operator funtions are almost always friend functions.

	General form 
		ret-type class-name::operator#(arg-list)
		{
			// operations
		}
*/

class loc
{
	int longitude, latitude;
public:
	loc()	{ 
		cout << "Constctor called\n";
	}
	loc(int lg, int lt)
	{
		cout << "Constctor called\n";
		longitude = lg;
		latitude = lt;
	}
	~loc()
	{
		cout << "Destructor called\n";
	}
	void show()
	{
		cout << longitude << " ";
		cout << latitude << "\n";
	}

	// Operator member function 

	// loc operator + (loc op2);     // valid
//	void operator + (loc op2);		// valid
//	int operator + (loc op2);		// valid
//	int operator + (int op2);		// valid
// But you can have only one function for operator + ()

	int operator + ();
	loc operator-(loc op2);
	loc operator=(loc op2);
	loc operator++();
	loc operator++(int);
};

// Defination of function 
//void loc :: operator+(loc op2)
//{
//	loc temp;
//	temp.longitude = op2.longitude + longitude;
//	temp.latitude = op2.latitude + latitude;
////	return temp;
//
//}
//int loc :: operator+(loc op2)
//{
//	loc temp;
//	temp.longitude = op2.longitude + longitude;
//	temp.latitude = op2.latitude + latitude;
//	return 10;
//}
//int loc :: operator+(int op2)
//{
//	return 10;
//}

int loc :: operator+()
{
	return 10;
}

loc loc:: operator-(loc op2)
{	
	loc temp;
	temp.longitude = longitude - op2.longitude;
	temp.latitude = latitude - op2.latitude;
	return temp;
}
loc loc:: operator=(loc op2)
{
	longitude = op2.longitude;
	latitude = op2.latitude;
	return *this; // i.e., return object that generated call
}
loc loc:: operator++()
{
	cout << "Preincrement operator\n";
	longitude++;
	latitude++;
	return *this;
}

// Post increment , 2nd parameter must be int 

loc loc:: operator++(int )
{
	cout << "Post increment operator\n";
	longitude++;
	latitude++;
	return *this;
}

void prog2()
{
	int abcd;
	loc ob1(10, 20), ob2(5, 30);
	ob1.show(); // displays 10 20
	ob2.show(); // displays 5 30
	//ob1 = 
	// abcd =	ob1 + ;

	//ob1 = 
	abcd =	ob1.operator+();

	ob1++;
	++ob1;

	ob1.show(); // displays 15 50
}

/************************************************  Program 3 Continued....  **************************************************/
void prog3()
{
	loc ob1(10, 20), ob2(5, 30), ob3(90, 90);
	ob1.show();
	ob2.show();
	++ob1;
	ob1.show(); // displays 11 21
	ob2 = ++ob1;
	ob1.show(); // displays 12 22
	ob2.show(); // displays 12 22
	ob1 = ob2 = ob3; // multiple assignment
	ob1.show(); // displays 90 90
	ob2.show(); // displays 90 90
}

/************************************************  Program 4  Prefix and profix ++ --  **************************************************/
void prog4()
{

}

/************************************************  Program 5    **************************************************/
void prog5()
{

}

/************************************************  Program 6    **************************************************/
void prog6()
{

}

/************************************************  Program 7    **************************************************/
void prog7()
{

}


/************************************************  Program 8    **************************************************/
void prog8()
{

}

/************************************************  Program 9    **************************************************/
void prog9()
{

}

/************************************************  Program 10   **************************************************/
void prog10()
{

}

/************************************************  Program 11   **************************************************/
void prog11()
{

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
