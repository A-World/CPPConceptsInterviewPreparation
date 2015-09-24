#include"Generic.h"
#include"Menu.h"


void BookShelf::init()
{
	ifstream in("books.txt");
	Book b;
	in >> b; // Need Overload >>  operator 
	while (!in.fail())
	{
		booklist.push_back(b);
		in >> b;// Need Overload >>  operator 
	}
	in.close();
}

void BookShelf::save()
{
	ofstream out("books.txt");
	for (uint i = 0; i < booklist.size(); i++)
	{
		out << booklist[i] << endl;  // Need to define this operator also
	}
	out.close();
}

void BookShelf::add(string author, string title,int isbn)
{
	string id = makeID(author, title);
	Book b(author, title, id,isbn);
	booklist.push_back(b);
}

void BookShelf::list()
{
	for (uint i = 0; i < booklist.size(); i++)
	{
		cout << "Author    :  " << booklist[i].author << endl;
		cout << "Title     :  " << booklist[i].title << endl;
		cout << "ISBN      :  " << booklist[i].ISBN << endl;
		cout << "ID        :  " << booklist[i].id << endl;
		cout << "Available :  ";
		if (booklist[i].availibity == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

void BookShelf::find(string title)
{
	for (uint i = 0; i < booklist.size(); i++)
	{
		if (booklist[i].title == title)
		{
			cout << "Book Found\n";
			cout << "Author    :  " << booklist[i].author << endl;
			cout << "Title     :  " << booklist[i].title << endl;
			cout << "ISBN      :  " << booklist[i].ISBN << endl;
			cout << "ID        :  " << booklist[i].id << endl;
			cout << "Available :  ";
			if (booklist[i].availibity == true)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
bool BookShelf::available(string bid)
{
	for (uint i = 0; i<booklist.size(); i++) 
		if (booklist[i].id == bid && booklist[i].availibity) 
			return true;
	return false;
}
void BookShelf::changeAV(string bid)
{
	for (uint i = 0; i<booklist.size(); i++)
	if (booklist[i].id == bid)
	{
		booklist[i].changeAV();
		//if (true == booklist[i].availibity)
		//{
		//	booklist[i].availibity = false;
		//}
		//else
		//{
		//	booklist[i].availibity = true;
		//}
	}
}

string BookShelf::makeID(string author, string title)
{
	string id;
	id = author[0]; id += author[1]; id += title[0]; id += title[1];
	int c = 1;
	bool l = false;
	while (!l)
	{
		stringstream ss;
		ss << c;
		string tempid = id;
		tempid += ss.str();
		bool j = false;
		for (uint i = 0; i<booklist.size() && !j; i++) if (booklist[i].id == tempid) j = true;
		if (j) c++;
		else { id = tempid; l = true; }
	}
	return id;
}

void Book::changeAV()
{
	if (Book::availibity)
		Book::availibity = false;
	else
		Book::availibity = true;
}


ifstream & operator >> (ifstream &in, Book &b)
{
	getline(in, b.author);
	getline(in, b.title);
	getline(in, b.id);
	string temp;
	getline(in, temp);
	b.ISBN = atoi(temp.c_str());
	getline(in, temp);
	b.availibity = atoi(temp.c_str());
	return in;
}

ofstream & operator << (ofstream &out, Book &b)
{
	out << b.author << endl << b.title << endl << b.id << endl << b.ISBN << endl << b.availibity;
	return out;
}









