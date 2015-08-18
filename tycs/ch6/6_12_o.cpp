/*
	//TODO  please fix copilation error

*/


#include <iostream>
using namespace std;


//orward declaration 
class rectangle;
class circle
{
	private :
		int radius;
	public :
		circle(int r = 0)
		{
			radius = r;
		}
		
		circle operator = ( rectangle r);
};

class rectangle
{
	private :
		int length, breadth;
	public :
		rectangle(int i, int b)
		{
			length = i;
			breadth = b;
		}
		
		operator circle()
		{
			return circle(length);
		}
};

circle circle::operator = ( rectangle r)
{
	return circle(); 
}	

int main()
{
	cout << "Hello World" <<endl;
	rectangle r (20,10);
	circle c;
	c = r;
}













