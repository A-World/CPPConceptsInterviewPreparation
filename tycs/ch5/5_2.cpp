/*
	Allocate memory using new, and expand using realloc fuction

*/

#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
	int *p = new int [5];
	p[1] = 3;
	p = (int *) realloc(p, sizeof(int) * 5);
	cout <<p[1]<<endl;

}