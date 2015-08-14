#include <iostream>

using namespace std;

class sample
{
		int i;
	public:
		sample(int ii)
		{
			i = ii;
		}
		
		sample operator + (sample s)
		{
			return sample (i + s.i);
		}
		
		sample operator += (sample s)
		{
			return sample ( i += s.i);
		}
		bool operator <= (sample s)
		{
			if(i <= s.i)
				return true;
			else
				return false;
		}
		bool operator >= (sample s)
		{
			if(i >= s.i)
				return true;
			else
				return false;
		}
		bool operator != (sample s)
		{
			if(i != s.i)
				return true;
			else
				return false;
		}
		bool operator == (sample s)
		{
			if(i == s.i)
				return true;
			else
				return false;
		}		
};

int main()
{
	cout << "Hello World" <<endl;
	sample a(1), b(2), c(0);
	c = a + b;
	
	if(a<=b)
		cout << "a is less than b "<<endl;
	a += b;
	
	if(a >= b)
	{
		cout << " a >= b " <<endl;
	}
	if(a != b)
	{
		cout << " a != b " <<endl;
	}	
	if(a == b)
	{
		cout << " a == b " <<endl;
	}
}
















