#include <iostream>
using namespace std;

class circle
{
	private :
		int radius;
	public :
		circle(int r = 0)
		{
			radius = r;
		}
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


int main()
{
	cout << "Hello World" <<endl;
	rectangle r (20,10);
	circle c;
	c = r;
}













