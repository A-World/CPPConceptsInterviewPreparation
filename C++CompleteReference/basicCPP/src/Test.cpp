/**   This is first CPP program  
	Which simply prints Hello World
**/

#include "Generic.h"

class myClass
{
public: 
	int who;
	myClass(int id);
	~myClass();
}glob_ob1(1), glob_ob2(2);

myClass::myClass(int id)
{
	//cout << "Initializing " << id << "\n";
	who = id;
}

myClass::~myClass()
{
	//cout << "Destructing " << who << "\n";
}

int main()
{
	cout<< "Hello World !" << endl;
//	sample();
//	input_correct();
//	stackOperation();
//	DevGoogleExample3();
//	test_simple_function_overloading();
//	test_2nd_function_overloading();
//	test_inheritance();
//	test_class_2();
//	test_Access_All_Public();
//	test_structure();
//	test_union();
//	test_anonymous_union();
//	test_friend_1_function();
//	test_friend_2_function();
//	test_friend_3_function();
//	test_friend_4_function();
//	test_friend_5_function();
//	test_parametered_const();
//	test_parametered_const_2();
//	test_static_data_member();
//	test_static_data_member_2();
//	accessPrivate();
//	test_static_data_member_count_objects();
//	test_static_member_funciton();

//	myClass local_ob1(3);
//	cout << "This will not be first line displayed.\n";
//	myClass local_ob2(4);
//	test_local_class();
//	test_objects_to_function();
	test_return_object_from_function();

	cout << "\n\n\n ";
}

// What is the output of following program 
// https://developers.google.com/edu/c++/getting-started

void DevGoogleExample3()
{
	cout << " 1\t2\t3\t4\t5\t6\t7\t8\t9" << endl << "" << endl;
	for (int c = 1; c < 10; c++) {
		cout << c << "| ";
		for (int i = 1; i < 10; i++) {
			cout << i * c << '\t';
		}
		cout << endl;
	}
}
// My output is 
/*
	1	2	3	4	5	6	7	8	9
	1| 1	2	3	4	5	6	7	8	9
	2| 2	4	6	8	10	12	14	16	18
	3| 3	6	9	12	15	18	21	24	27
	4| 4	8	12	16	20	24	28	32	36
	5| 5	10	15	20	25	30	35	40	45
	6| 6	12	18	24	30	36	42	48	54
	7| 7	14	21	28	35	42	49	56	63
	8| 8	16	24	32	40	48	56	64	72
	9| 9	18	27	36	45	54	63	72	81

// Congrats my output is correct	
	*/