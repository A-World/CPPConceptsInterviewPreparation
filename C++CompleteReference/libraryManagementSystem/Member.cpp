#include"Generic.h"
#include"Menu.h"



void Member::init()
{
	ifstream in("members.txt");
	MemberID m;
	in >> m;
	while (!in.fail())
	{
		if (m.membership == "Student")
			membs.push_back(Student(m.name,m.address,m.email,m.tel,m.books));
		if (m.membership == "Teacher")
			membs.push_back(Teacher(m.name, m.address, m.email, m.tel, m.books));
		if (m.membership == "Universtiy")
			membs.push_back(Universtiy(m.name, m.address, m.email, m.tel, m.books));
		if (m.membership == "Other")
			membs.push_back(Other(m.name, m.address, m.email, m.tel, m.books));
		in >> m;
	}
	in.close();
}

void Member::save()
{
	ofstream out("members.txt");
	for (uint i = 0; i < membs.size(); i++)
	{
		out << membs[i] << endl;
	}
	out.close();
}

void Member::add(string name, string addres, string email, int tel, int type)
{
	if (type == 1)
	{
		membs.push_back(Student(name, addres, email, tel, 0));
	}
	if (type == 3)
	{
		membs.push_back(Universtiy(name, addres, email, tel, 0));
	}
	if (type == 2)
	{
		membs.push_back(Teacher(name, addres, email, tel, 0));
	}
	if (type == 4)
	{
		membs.push_back(Other(name, addres, email, tel, 0));
	}
}

void Member::list()
{
	for (uint i = 0; i<membs.size(); i++)
	{
		cout<<"name          : " << membs[i].name<<endl;
		cout<<"address       : " << membs[i].address<<endl;
		cout<<"email         : " << membs[i].email<<endl;
		cout<<"tel           : " << membs[i].tel << endl;
		cout<<"Membership    : "<<membs[i].membership<<endl;
		cout<<"No of books   : " << membs[i].books << endl << endl;
	}
}

void Member::find(string name)
{
	bool l = false;

	for (uint i = 0; i<membs.size() && !l; i++)
	{
		if (name == membs[i].name)
		{
			l = true;
			cout << "name          : " << membs[i].name << endl;
			cout << "address       : " << membs[i].address << endl;
			cout << "email         : " << membs[i].email << endl;
			cout << "tel           : " << membs[i].tel << endl;
			cout << "Membership    : " << membs[i].membership << endl;
			cout << "No of books   : " << membs[i].books << endl << endl;
		}
	}
}

void Member::returnB(string name)
{
	for (uint i = 0; i<membs.size(); i++) if (membs[i].name == name) membs[i].books--;
}


bool Member::canLend(string name)
{
	for (uint i = 0; i<membs.size(); i++)
	if (membs[i].name == name)
	{
		return membs[i].books < membs[i].maxbooks;
	}
	return false;
}

void Member::lend(string name)
{
	for (uint i = 0; i<membs.size(); i++)
	if (membs[i].name == name)
	{
		membs[i].books++;
	}
}

int Member::getLendt(string name)
{
	for (uint i = 0; i<membs.size(); i++)
	if (membs[i].name == name)
		membs[i].lendt;
	return 0;
}

istream& operator>>(istream& in, MemberID& m)
{
	getline(in, m.name);
	getline(in, m.address);
	getline(in, m.email);
	string temp;
	getline(in, temp);
	m.tel = atoi(temp.c_str());
	getline(in, m.membership);
	getline(in, temp);
	m.books = atoi(temp.c_str());
	return in;
}

ostream& operator<<(ostream& out, const MemberID& m)
{
	out<<m.name<<endl<<m.address<<endl<<m.email<<endl<<m.tel<<endl<<m.membership<<endl<<m.books;
	return out;
}
















