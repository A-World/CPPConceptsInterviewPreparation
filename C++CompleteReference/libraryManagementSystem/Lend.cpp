#include"Generic.h"
#include"Menu.h"

void LendBook::init()
{
	ifstream in("lend.txt");
	Lend l;
	in >> l;
	while (!in.fail())
	{
		add(l.date, l.name, l.bookid);
		in >> l;
	}
	in.close();
}

void LendBook::save()
{
	ofstream out("./source/lends.las");
	for (uint i = 0; i<lends.size(); i++) 
	if (lends[i].open)
		out << lends[i] << endl;
	out.close();
}


void LendBook::add(int d, string name, string bookid)
{
	lends.push_back(Lend(d, name, bookid));
}

void LendBook::list()
{
	for (uint i = 0; i < lends.size(); i++)
	{
		if (lends[i].open)
		{
			cout<<"Name    : "<<lends[i].name<<endl;
			cout<<"Book ID : "<<lends[i].bookid<<endl;
			cout<<"Date    : "<< lends[i].date << endl << endl;
		}
	}
}

void LendBook::find(string name)
{
	for (uint i = 0; i < lends.size(); i++)
	if (lends[i].name == name)
	{
		cout << "Name    : " << lends[i].name << endl;
		cout << "Book ID : " << lends[i].bookid << endl;
		cout << "Date    : " << lends[i].date << endl << endl;
	}
}

int LendBook::returnBook(string bid, string &name)
{
	for (uint i = 0; i<lends.size(); i++)
	if (lends[i].bookid== bid)
	{
		if (!lends[i].open) return 0;
		lends[i].open = false;
		name = lends[i].name;
		return lends[i].date;
	}
	return 0;
}

istream& operator>>(istream& in, Lend& l)
{
	getline(in, l.name);
	getline(in, l.bookid);
	string temp;
	getline(in, temp);
	l.date = atoi(temp.c_str());
	return in;
}

ostream& operator<<(ostream& out, const Lend& l)
{
	out<<l.name<<endl<<l.bookid<<endl<<l.date;
	return out;
}

