/*
    Thread Management : Associating thread with functor along with paramters, try out as reference

    - Another approach, use a wrapper class, write the thread1.join inside destructor, 
      whenever thread object goes out of scope, it shall call destructor, and t.join() function. 
      This approach uses RAII concept.
    
    - Thread object can be constructed not only with regular function like function_1, 
      but also with any callable object, such as functor or labmda function.
    
    - To pass string s as paramters to thread creation, pass it as additional paramters.
    
    - A paramter to thread is always pass by value.
    
    Q 1. : if i write t1.join multiple times, what is behaviour
    
*/


#include <iostream>
#include <string>
#include <thread>

using namespace std;

void function_1()
{
    cout << "Beauty is only skin-deep"<<endl;
}

class Fctor
{
    public :
        void operator () (string & msg) 
        {
            cout << "T1 says " <<msg<<endl;
            msg = "Trust is the mother of deceit";
        }
};

int main()
{

    string s = "where there is no trust, there is no love";
    // To pass string s as paramters to thread creation, pass it as additional paramters.
    
    std::thread t1 ((Fctor()), std::ref(s));

    t1.join();
    
    cout << "from main: "  << s << endl;

    return 0;
} 


/*
        Following program runs perfectly fine with visual stdio 2012, but it flashes compilation error in g++ as follows 
        
        
In file included from /usr/include/c++/4.9/thread:39:0,
                 from C++Threading_05.cpp:22:
/usr/include/c++/4.9/functional: In instantiation of ‘struct std::_Bind_simple<Fctor(std::basic_string<char>)>’:
/usr/include/c++/4.9/thread:140:47:   required from ‘std::thread::thread(_Callable&&, _Args&& ...) [with _Callable = Fctor; _Args = {std::basic_string<char, std::char_traits<char>, std::allocator<char> >&}]’
C++Threading_05.cpp:90:33:   required from here  // This line 	std::thread t1((Fctor()), s);
/usr/include/c++/4.9/functional:1665:61: error: no type named ‘type’ in ‘class std::result_of<Fctor(std::basic_string<char>)>’
       typedef typename result_of<_Callable(_Args...)>::type result_type;
                                                             ^
/usr/include/c++/4.9/functional:1695:9: error: no type named ‘type’ in ‘class std::result_of<Fctor(std::basic_string<char>)>’
         _M_invoke(_Index_tuple<_Indices...>)        
        

#include <iostream>
#include <string>
#include <thread>
using namespace std;

class Fctor
{
public:
	void operator () (string & msg)
	{
		cout << "T1 says " << msg << endl;
		msg = "Trust is the mother of deceit";
	}
};
int main()
{
	string s = "where there is no trust, there is no love";	
	std::thread t1((Fctor()), s);
	t1.join();
	cout << "from main: " << s << endl;
	return 0;
}

*/












