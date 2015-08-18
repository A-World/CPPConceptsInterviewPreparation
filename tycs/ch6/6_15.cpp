/*
	//TODO : Add changes  in assignment oprator funciton, so that i shall not create new object.

	write class date,, implement assignment operator and copy constructor.
*/

#include <iostream>
using namespace std;

class date
{
	int day;
	int month;
	int year;
	
	public:
	date(int d = 0, int m = 0, int y = 0)
	{
		cout << "Default constructor"<<endl;
		day = d; month = m; year = y;
	}
	
	// Copy constructor
	
	date(const date &d)
	{
		cout << "Copy Constructor" <<endl;
		day = d.day;
		month = d.month;
		year = d.year;
	}
	
	date  operator = (const date &d)
	{
		cout<< "Assignment operator"<<endl;
		day = d.day;
		month = d.month;
		year = d.year;
		return d;
	}
};

int main()
{
	cout <<"Hello World" <<endl;
	date d1 (25,9,2019);
	date d2 = d1;
	date d3;
	d3 = d2;
}




















