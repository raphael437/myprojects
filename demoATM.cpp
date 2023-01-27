#include <iostream>
#include<fstream>
#include<string>
using namespace std;
class Person
{
	//att
public:
	int id;
	int password;

	//cons
public:
	Person()
	{
		this->id = 0;
		this->password = 0;
	}

	Person(int id, int password)
	{
		this->id = id;
		this->password = password;
	}
	//setter
	void setid(int id)
	{
		this->id = id;
	}
	void setpassword(int password)
	{
		this->password = password;
	}
	//getter
	int getid()
	{
		return id;
	}
	int getpassword()
	{
		return password;
	}

	//decons
	~Person() {};
};

class Client :public Person
{
public:
	//att
	float balance;
public:
	Client()
	{
		this->balance = 0;

	}

	Client(int id, int password, float balance) :Person(id, password)
	{
		this->balance = balance;
	}
	//setter
	void setbalance(float balance)
	{
		this->balance = balance;
	}
	//getter
	float getbalance()
	{
		return balance;
	}
	bool login(int id, int password)
	{

		cout << "enter your id and passowrd" << endl;
		cin >> id;
		cin >> password;

		int thetrueid = 1111;
		int thetruepas = 9999;
		if (thetrueid == id && thetruepas == password)
		{
			cout << "welcome" << endl;
			cout << "your balance= " << balance << endl;
			return true;
		}


		/// <summary>
		/// /«·„›—Ê÷ ·Ê ’Õ Ì—ÊÕ ⁄·Ï job
		/// </summary>
		/// <param name="id"></param>
		/// <param name="password"></param>
		else
		{
			cout << "error" << endl;
			return false;
		}

	}
	void job()
	{
		int value;
		int choice;
		cout << "for add click 1" << endl;
		cout << "for take click 2" << endl;

		cin >> choice;
		if (choice == 1)
		{

			cout << "how much you want to add" << endl;
			cin >> value;
			balance = balance + value;
			cout << "your balance is = " << balance << endl;


		}
		if (choice == 2)
		{

			cout << "how much you want to take" << endl;
			cin >> value;
			if (value <= balance)
			{
				balance = balance - value;
				cout << "your balance " << balance << endl;
			}
			else
				cout << "you dont have enough money " << endl;
		}
		if (choice != 1 && choice != 2)
			cout << "you must to choce 1 or 2" << endl;







	}
};
class Employe :public Client
{
protected:
	//att
	float salary;
	//cons
public:
	Employe()
	{
		this->salary = 0;
	}
	Employe(int id, int password, float balance, float salary) :Client(id, password, balance)
	{
		this->salary = salary;
	}
	//setter
	void setsalary(float salary)
	{
		this->salary = salary;
	}
	//getter
	float getsalary()
	{
		return salary;
	}
	void setbalance(float balance)
	{
		this->balance = balance;
	}


};
class Admin :public Employe
{
private:
	int add;
	int remove;

public:
	Admin()
	{
		this->add = 0;
		this->remove = 0;

	}


};
int main()
{

	Employe ahmed;
	Client seif;
	Admin magdy;



	cout << "welcome" << endl;


	seif.setbalance(1000);



	if (seif.login(seif.id, seif.password) == true)
	{
		seif.job();

	}
	else
		cout << "wrong log" << endl;


	fstream myfile;
	myfile.open("id.txt", ios::out);//write

	if (myfile.is_open())
	{

		myfile << "1111" << endl;
		myfile.close();
	}

	myfile.open("password.txt", ios::out);

	if (myfile.is_open())
	{

		myfile << "9999" << endl;
		myfile.close();
	}

	myfile.open("basicbalance.txt", ios::out);//write

	if (myfile.is_open())
	{

		myfile << "1000" << endl;
		myfile.close();
	}

	//if i want to read
	myfile.open("id.txt", ios::in);//read

	if (myfile.is_open())
	{
		string line;
		while (getline(myfile, line))
		{
			//cout << line << endl;

		}


		myfile.close();
	}


	myfile.open("password.txt", ios::in);//read

	if (myfile.is_open())
	{
		string line2;
		while (getline(myfile, line2))
		{
			//cout << line2 << endl;

		}

		myfile.close();
	}




}
