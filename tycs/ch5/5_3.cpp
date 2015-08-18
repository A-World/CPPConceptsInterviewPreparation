#include <iostream>

using namespace std;

class sample
{
	private:
		int i;
	public:
		void func()
		{
			delete this;
		}
};

int main()
{
	sample * s = new sample;
	s->func();
	sample s1 ;
	// s1.func(); // This statement gives run time error.
}