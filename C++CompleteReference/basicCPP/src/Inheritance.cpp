
#include"Generic.h"

/**		
		Main Class Defination
**/
class building
{
	int rooms;
	int floors;
	int area;
public :
	void set_rooms(int rooms);
	void set_floors(int floors);
	void set_area(int area);
	int get_floors();
	int get_rooms();
	int get_area();
};

/*  function Defintions	*/
void building :: set_rooms(int rooms)
{
	this->rooms = rooms;
}
void building :: set_floors(int floors)
{
	this->floors = floors;
}
void building :: set_area(int area)
{
	this->area = area;
}
int  building :: get_floors()
{
	return floors;
}
int  building :: get_rooms()
{
	return rooms;
}
int  building :: get_area()
{
	return  area;
}
/** 	Derived class	**/
class house : public building		// Derived publically 
{
	int bedrooms;
	int baths;

public :
	void set_bedrooms(int bedrooms);
	void set_baths(int baths);
	int get_baths();
	int get_bedrooms();
};

/*  function Defintions	*/
void house::set_bedrooms(int bedrooms)
{
	this->bedrooms = bedrooms;
}
void house::set_baths(int baths)
{
	this->baths = baths;
}
int  house::get_baths()
{
	return baths;
}
int  house::get_bedrooms()
{
	return bedrooms;
}

class school : public building
{
	int classrooms;
	int offices;
public:
	void set_classrooms(int classrooms);
	void set_offices(int offices);
	int get_classrooms();
	int get_offices();
};

/*  function Defintions	*/
void school::set_classrooms(int classrooms)
{
	this->classrooms = classrooms;
}
void school::set_offices(int offices)
{
	this->offices = offices;
}
int  school::get_classrooms()
{
	return classrooms;
}
int  school::get_offices()
{
	return offices;
}



/***  Testing inheritance
		We should be able to access the public members of the parent 
***/
void test_inheritance()
{
	school		mySchool; 
	house		myHouse;
	building	myBuilding;
	// Sizes of each instance of the class are
	cout << "Size of class is mySchool     " << sizeof(mySchool)   <<endl;
	cout << "Size of class is myHouse      " << sizeof(myHouse)	   <<endl;
	cout << "Size of class is myBuilding   " << sizeof(myBuilding) <<endl;

	// Now accessing public members of parents
	mySchool.set_area(200);
	mySchool.set_classrooms(200);
	mySchool.set_offices(200);
	mySchool.set_floors(200);
	mySchool.set_rooms(200);

	house h;
	school s;
	h.set_rooms(12);
	h.set_floors(3);
	h.set_area(4500);
	h.set_bedrooms(5);
	h.set_baths(3);
	cout << "house has " << h.get_bedrooms();
	cout << " bedrooms\n";

	s.set_rooms(200);
	s.set_classrooms(180);
	s.set_offices(5);
	s.set_area(25000);

	cout << "school has " << s.get_classrooms();
	cout << " classrooms\n";
	cout << "Its area is " << s.get_area();
}