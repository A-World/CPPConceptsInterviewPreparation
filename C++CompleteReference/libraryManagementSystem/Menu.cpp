#include"Generic.h"
#include"Menu.h"



void Menu::run()
{
	debug << "Run ";

	// Open a file for password
	ifstream in("pwd.txt");
	Menu::password = "PASSWORD";
	Menu::b.init();
	Menu::m.init();
	Menu::l.init();
	
	in.close();
	
	Menu::authenticatation();
	Menu::mainMenu();
}

void Menu::authenticatation()
{
	// This method will authenticate the user.
	string pwd;
	int i = 3; // 3 attempts
	bool l = false;
	for (i = 0; i < 3; i++)
	{
		cout << "\nEnter Password : ";
		cin >> pwd;
		if (pwd == Menu::password)
		{
			l = true;
			debug << "Password match";
			break;
		}
	}
	if (l == false)
	{
		debug << "Exiting as authetication failed\n\n";
		exit(1);
	}
}

void Menu::mainMenu()
{
	cout << "Please select the following options\n";
	cout << "1. Rental\n";
	cout << "2. Add new Entry\n";
	cout << "3. List down\n";
	cout << "4. Search\n";
	cout << "5. Change Password\n";
	cout << "6. Logout\n";
	cout << "Reply menu option :: ";

	int i = 0;
	cin >> i;
	switch (i)
	{
		case 1: Menu::lendingMenu();
			break;
		case 2: Menu::newEnteryMenu();
			break;
		case 3: Menu::listMenu();
			break;
		case 4: Menu::searchMenu();
			break;
		case 5: Menu::changePassword();
			break;
		case 6:
			cout << "\nSaving data and exiting\n";
			exit(2);
			break;
	}
	Menu::mainMenu();
}

void Menu::lendingMenu()
{
	cout << "Please select the following options\n";
	cout << "1. Rental\n";
	cout << "2. Back the book\n";
	cout << "3. Back\n";
	cout << "Reply menu option :: ";
	int x;
	cin >> x;

	switch (x)
	{
		case 1:
		{
			  int date;
			  string name, bid;
			  cout << "date :";
			  cin >> date;
			  cout << "Name :";
			  getline(cin, name);
			  cout << "Paper :";
			  cin >> bid;
			  if (Menu::b.available(bid))
			  {
				  if (Menu::m.canLend(name))
				  {
					  b.changeAV(bid);
					  m.lend(name);
					  l.add(date, name, bid);
				  }
				  else
				  {
					  cout << "The member can not borrow books or may not be named member!" << endl;
				  }
			  }
			  else
			  {
				  cout << "The book does not or can not borrow such books" << endl;
			  }
			  system("pause");
		}
		break;
	case 2:
		{
			  int date;
			  cout << "date :"; cin >> date;
			  string bid;
			  cout << "Paper :"; getline(cin,bid);
		
			  string name;
			  int ldate = l.returnBook(bid, name);
			  if (ldate == 0)
			  {
				  cout << "There is no such RENTALS" << endl;
			  }
			  else
			  {
				  m.returnB(name);
				  b.changeAV(bid);
				  int year1 = date / 10000;
				  int month1 = (date - date / 10000) / 100;
				  if (month1 == 1) { month1 == 13; year1++; }
				  if (month1 == 2) { month1 == 14; year1++; }
				  int x1 = 365 * year1 + year1 / 4 - year1 / 100 + year1 / 400 + date + (153 * month1 + 8) / 5;

				  int year2 = ldate / 10000;
				  int month2 = (ldate - ldate / 10000) / 100;
				  if (month2 == 1) { month2 == 13; year2++; }
				  if (month2 == 2) { month2 == 14; year2++; }
				  int x2 = 365 * year2 + year2 / 4 - year2 / 100 + year2 / 400 + ldate + (153 * month2 + 8) / 5;
				  if ((x1 - x2) > m.getLendt(name))
				  {
					  cout << "The book is bringing back late!" << endl;
				  }
				  else
				  {
					  cout << "The book has been successfully bringing back!" << endl;
				  }
			  }
		}
		break;	
	case 3:
			break;
	}
}

void Menu::newEnteryMenu()
{
	cout << "Please select the following options\n";
	cout << "1. New Book Application\n";
	cout << "2. New member application\n";
	cout << "3. Back\n";
	cout << "Reply menu option :: ";
	int x;
	cin >> x;

	switch (x)
	{
	case 1 :
		{
			   string author, title;
			   int isbn;
			   cout << "Author : "; getline(cin, author);
			   cout << "Title : "; getline(cin, title);
			   cout << "ISBN :"; cin >> isbn;
			   b.add(author, title, isbn);
		}
		break;
	case 2:
		{
			  string name, address, email;
			  int tel;
			  cout << "Type of membership: " << endl;
			  cout << "[1] Student" << endl;
			  cout << "[2] Teacher" << endl;
			  cout << "[3] University Citizen" << endl;
			  cout << "[4] Other" << endl;
			  cout << "Reply to menu: ";
			  int x;
			  cin >> x;
			  cout << "Name : "; getline(cin, name);
			  cout << "Address : "; getline(cin, address);
			  cout << "Email : "; getline(cin, email);
			  cout << "Tel : "; cin>> tel;
			  m.add(name,address,email,tel,x);

		}
		break;
	case 3 :
		Menu::mainMenu();
		break;
	}
}

void Menu::listMenu()
{
	cout << "Please select the following options:\n";
	cout << "[1] Member List Directory\n";
	cout << "[2] Book List Directory \n";
	cout << "[3] Rental List Directory\n";
	cout << "[4] Back\n";
	cout << "Kindly Enter an option: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		m.list(); 
		break;
	case 2:
		b.list();
		break;
	case 3:
		l.list();
		break;
	}
}

void Menu::searchMenu()
{
	cout << "Please select the following options:\n";
	cout << "[1] Member\n";
	cout << "[2] Books\n";
	cout << "[3] Back\n";
	cout << "Enter option: ";
	int x;
	cin >> x;
	switch (x)
	{
		case 1:
		{
			string name;
			cout << "Name :"; getline(cin, name);
			m.find(name);
			cout << endl;
			l.find(name);
			cout << endl;

		}
			break;
		case 2:
		{
			string title;
			cout << "Title : "; getline(cin, title);
			b.find(title);
		}
			break;
		case 3 :
			break;
	}
}

void Menu::changePassword()
{
	//string pwd1, pwd2;
	cout << "\nEnter New Password :"; getline(cin, Menu::password);

	cout << "\nPassword change properly\n";
}












