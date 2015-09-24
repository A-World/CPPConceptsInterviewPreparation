#include "Generic.h"

#if 1 /* My code not working beacause i used abs function, 
         which is system defined, i was overloading same again, so more than one defination for
		 same function. So to remove i remaned function with abs -> myAbs */
/* Overload the myAbs function which returns the absolute value of the given integer, float and long */
int myAbs(int a);
double myAbs(double a);
long myAbs(long a);

void test_simple_function_overloading()
{
	myAbs(-1);
	myAbs(-1.54);
	myAbs(-10000545L);
	cout << myAbs(-10) << "\n";
	cout << myAbs(-11.0) << "\n";
	cout << myAbs(-9L) << "\n";
}

int myAbs(int a)
{
	cout << "Inside interger myAbs" << endl;
	if (a < 0)
		return -a;
	else
		return a;
}
double myAbs(double a)
{
	cout << "Inside double myAbs" << endl;
	if (a < 0.0)
		return -a;
	else
		return a;
}
long myAbs(long a)
{
	cout << "Inside long myAbs" << endl;
	if (a < 0L)
		return -a;
	else
		return a;
}
#else
// Copied Code from C++ The complete referece .pdf page 275
int myAbs(int i);
double myAbs(double d);
long myAbs(long l);

void test_simple_function_overloading()
{
	cout << myAbs(-10) << "\n";
	cout << myAbs(-11.0) << "\n";
	cout << myAbs(-9L) << "\n";
}

int myAbs(int i)
{
	cout << "Using integer myAbs()\n";
	return i<0 ? -i : i;
}

double myAbs(double d)
{
	cout << "Using double myAbs()\n";
	return d<0.0 ? -d : d;
}

long myAbs(long l)
{
	cout << "Using long myAbs()\n";
	return l<0 ? -l : l;
}

#endif


void stradd(char *s1, char *s2);
void stradd(char *s1, int i);

void test_2nd_function_overloading()
{
	char str[80];
	strcpy(str, "Hello");
	stradd(str, "There");
	cout << str << "\n";
	stradd(str, 100);
	cout << str << "\n";
}

void stradd(char *s1, char *s2)
{
	strcat(s1, s2);
}

void stradd(char *s1, int i)
{
	char temp[80];
	sprintf(temp, "%d", i);
	strcat(s1, temp);
}
