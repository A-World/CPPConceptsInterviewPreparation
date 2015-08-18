// Initilize static data members
#include <iostream>

using namespace std;

class item
{
private:
	static int count;
	int number;

	public:
	void getdata(int n)
	{
		number = n;
		count++;
	}
	void getcount (int c)
	{
		cout << "count " <<count<<endl;
	}
};

// Please note that, count is private here, also it is defined outside the class.
int item::count = 10;

int main()
{
	cout <<"Hello World" <<endl;
}