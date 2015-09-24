#include"Generic.h"

class Book
{
public:
	int ISBN;
	string author, title, id;
	bool availibity;

	Book()
	{
		debug << "Constructor ";
	}
	Book(string author, string title, string id, int ISBN) : author(author), title(title), id(id), ISBN(ISBN), availibity(true) {}

	void changeAV();

	/*  Friend functions  */
	friend ifstream & operator >> (ifstream &in, Book &b);
	friend ofstream & operator << (ofstream &out, Book &b);
};

class BookShelf
{
public:
	BookShelf()
	{
		debug << "Constructor ";
	}

	void init();
	void add(string author, string title, int isbn);
	void list();
	void save();
	void find(string title);
	void changeAV(string);
	string makeID(string, string);
	bool available(string bid);
	
private:
	/* Data members */
	vector<Book> booklist;   // Vector of book type.
};

class MemberID
{
public:

	string name, address, email, membership;
	int tel, lendt, books, maxbooks;

	MemberID()
	{
		debug << "Constructor";
	}
	MemberID(string n, string a, string e, int t, string m, int l, int b, int mx) : name(n), address(a), 
		email(e), membership(m), tel(t), lendt(l), books(b), maxbooks(mx)	{	}
	/*	Friend functins	*/	
	friend istream& operator>>(istream& in, MemberID& m);
	friend ostream& operator<<(ostream& out, const MemberID& m);
};

class Student : public MemberID 
{
public:
	Student(string n, string a, string e, int t, int b) : MemberID(n, a, e, t, "Student", b, 10, 2) {}
};

class Teacher : public MemberID 
{
public:
	Teacher(string n, string a, string e, int t, int b) : MemberID(n, a, e, t, "Teacher", b, 10, 2) {}
};
class Universtiy : public MemberID 
{
public:
	Universtiy(string n, string a, string e, int t, int b) : MemberID(n, a, e, t, "Universtiy", b, 10, 2) {}
};
class Other : public MemberID 
{
public:
	Other(string n, string a, string e, int t, int b) : MemberID(n, a, e, t, "Other", b, 10, 2) {}
};


class Member
{
public:
	void init();
	void add(string name, string address,string email, int tel, int type );
	void list();
	void save();
	void find(string name); 
	bool canLend(string name);
	void lend(string name);
	void returnB(string name);
	int getLendt(string name);

private:
	vector <MemberID> membs;
};

class Lend
{
public:
	Lend()
	{
		debug << "constructor" << endl;
	}
	Lend(int d, string name, string Bookid) : date(d), name(name), bookid(bookid), open(true)
	{
	}
	int date;
	string name;
	string bookid;
	bool open;

	friend std::istream& operator>>(std::istream& in, Lend& l);
	friend std::ostream& operator<<(std::ostream& out, const Lend& l);

};

class LendBook
{
public:
	void init();
	void save();
	void list();
	void find(string name);
	void add(int, string, string);
	int returnBook(string bid, string &name);

private:
	vector<Lend> lends;
};

class Menu
{
public:
	Menu()
	{
		debug << "Constructor ";
	}


	void run();
private:
	void authenticatation();
	void mainMenu();
	void lendingMenu();
	void newEnteryMenu();
	void listMenu();
	void searchMenu();
	void changePassword();

	/*	Data Members	*/
	string		password;
	BookShelf	b;
	Member		m;
	LendBook	l;
};