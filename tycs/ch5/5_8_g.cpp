
// Use parametered constructor to initlize values to array.

#include <iostream>
using namespace std;

class sample
{
	private :
		int i;
	public:
		sample(int ii)
		{
			cout << "Inside constructor" <<endl;
			i = ii;
		}
		//sample* operator new 
};


int main()
{
	sample *s = new (10) sample(10,10);

}