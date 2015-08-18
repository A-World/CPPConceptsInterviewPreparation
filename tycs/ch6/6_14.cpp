#include <iostream>
using namespace std;

class time12;
class time24;

class time12 
{
	int sec;
	int min;
	int hr;
	public:
		time12(int s = 0, int m = 0 , int h = 0)
		{
			cout << "time12 constructor"<<endl;
			sec = s; min = m; hr = h;
		}
		operator time24();
			
};

class time24 
{
	int sec;
	int min;
	int hr;
	public :
	time24(int s = 0, int m = 0 , int h = 0)
		{
			cout << "time24 constructor"<<endl;
			sec = s; min = m; hr = h;
		}
	public :
};

int main()
{
	cout << "Hello World" <<endl;
	
	time12 t12 ;
	time24 t24 ;
	time12 t12_1 () ;
	time24 t24_1 () ;
	
}







