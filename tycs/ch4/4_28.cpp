// Use case : Try to access this pointer inside the static fucntion

#include <iostream>

using namespace std;

class sample1
{
    private:
        static int i;
    public:
        static void fun() 
        {
//            cout << "Address of the current object is "<< this;  // This line give comilation error, as you can not use this pointer inside the static member function.
        }
        friend void friend_funciton1();
        friend void friend_funciton2(sample1 s);
    
      // static  
           sample1 & operator + (const sample1 &s)
        {
            cout << "Inside operator + function"<<endl;
        }
};

int sample1 :: i = 10;

void friend_funciton1()
{
    // This is friend fucntion with class sample1.
    // A friend frunction can access the private members of the class.
    
    sample1::i = 10;

}

void friend_funciton2(sample1 s)
{
// Following stattememnt gives compilation error, as there is no associative this pointer here.
//    cout << "This pointer is "<< this<<endl;   

       cout << s.i;
}

int main()
{
    cout << "Hello World" <<endl;
       sample1 s1;
       sample1 s2;
       sample1 s3 = s1 + s2;
}



/*
 *  You can access thsi pointer inside the constuctors
 *  You can access this pointer inside the destructors
 *  You can access this pointer operator function, normatl memeber functions etc.
 *  You can not access this pointer inside the static functions.
 *
 *
 *
 *
 *  Write a code for 
 *      1. accessing this pointer inside the friend function.
 *          // Not accessible
 *      2. static operator functions.
 *          // Not possible
 *
 *
 * */

