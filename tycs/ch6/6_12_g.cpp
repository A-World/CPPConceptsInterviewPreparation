// Use of const member funciton

#include <iostream>

using namespace std;


class sample
{	
	int i;
	public:
	int func1() const
	{
	//	i = 82;  // Modifying this shall result in compilation error, as all data members are const.
		return i;
	}
	int func2(const int &ii) // const argument,
	{
		//ii = 9;
	}
};


int main()
{
	cout << "Hello World" <<endl;
	
	sample s;
	int p = 9;
	p = s.func1();
	s.func2(p);
}

