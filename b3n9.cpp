
#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

class Person
{
protected:
    //att
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
    void setpassword()
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
    ~Person()
    {

    }
};

class Client :public Person
{
protected:
    //att
    float balance = 1000;

    //cons
public:
    Client()
    {
        this->balance = 1000;
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
    //methods


};

class Employe :public Client
{
protected:
    int addid; int addpassword;
    float addbalance;
public:
    //cons
    Employe()
    {
        this->addid = 0;
        this->addpassword = 0;
        this->addbalance = 0;
    }
    Employe(int id, int password, float balance, int addid, int addpassword, float addbalance) :Client(id, password, balance)
    {
        this->addid = addid;
        this->addpassword = addpassword;
        this->addbalance = addbalance;

    }
    //setter
    virtual void setaddid()
    {
        this->addid = addid;

    }
    virtual    void setaddpassword()
    {
        this->addpassword = addpassword;
    }
    virtual    void setaddbalance()
    {
        this->addbalance = addbalance;
    }
    //getter
    int getaddid()
    {
        return addid;
    }
    int getaddpassword()
    {
        return addpassword;
    }
    int getaddbalance()
    {
        return addbalance;
    }
    //methods


};

class Screen :public Employe
{
public:

    void welcome()
    {
        cout << "WELCOME" << endl;
    }

    bool login()
    {
        int l;

        cout << "if you want to login as a client press 1\n";
        cout << "if you want to login as a employe press any other number \n";
        cin >> l;
        if (l == 1)
        {
            return true;

        }

        else
        {

            return false;
        }

    }

    bool logcl()
    {


        int cid = 00;
        int cpas = 11;
        int c, p;
        cout << " welcome client ,enter your id then your password" << endl;
        cin >> c >> p;
        if (cid == c && cpas == p)
            return true;
        else
        {
            return false;
            cout << "error" << endl;
        }



    }
    void optioncl()
    {


        cout << "wlcome to our bank , your balance =  " << balance << endl;
        int dec;
        cout << "for add press 1, for take press 2" << endl;
        cin >> dec;
        int value;
        if (dec == 1)
        {

            cout << "how much do you want to add" << endl;
            cin >> value;
            balance = balance + value;
            cout << "your balance= " << balance << endl;
            srand(time(NULL));
            cout << "generated code :  " << rand() % 1000000000000000000;
        }
        else if (dec == 2)
        {
            cout << "how much do you want to take" << endl;
            cin >> value;
            if (balance >= value)
            {
                balance = balance - value;
                cout << "your balance = " << balance << endl;
                srand(time(NULL));
                cout << "generated code :  " << rand() % 1000000000000000000;
            }
            else
                cout << "this amount is larger than your balance" << endl;

        }

    }

    bool logemp()
    {


        int empid = 22;
        int emppas = 33;
        int iemp, pemp;
        cout << " welcome employe , enter your id then your password" << endl;
        cin >> iemp >> pemp;
        if (empid = iemp && emppas == pemp)
        {
            return true;
        }
        else
        {
            return false;
            cout << "error" << endl;
        }



    }
    void optionemp()
    {

        cout << "wlcome to our bank , your balance =  " << balance << endl;
        int dec;
        cout << "for add press 1, for take press 2,for adding a new account press 3" << endl;
        cin >> dec;
        int value;
        if (dec == 1)
        {

            cout << "how much do you want to add" << endl;
            cin >> value;
            balance = balance + value;
            cout << "your balance= " << balance << endl;
            srand(time(NULL));
            cout << "generated code :  " << rand() % 2000000000000000000;
        }
        else if (dec == 2)
        {
            cout << "how much do you want to take" << endl;
            cin >> value;
            if (balance >= value)
            {
                balance = balance - value;
                cout << "your balance = " << balance << endl;
                srand(time(NULL));
                cout << "generated code :  " << rand() % 2000000000000000000;
            }
            else
                cout << "this amount is larger than your balance" << endl;



        }
        else if (dec == 3)
        {
            cout << "add new id" << endl;
            cin >> addid;
            cout << "add new passowrd" << endl;
            cin >> addpassword;
            cout << "add new balance" << endl;
            cin >> addbalance;

            cout << " the account added succussfully" << endl;
            cout << "data of the account is " << endl;
            cout << "the id= " << addid << endl;
            cout << "the password is = " << addpassword << endl;
            cout << "the balance is = " << addbalance << endl;
            srand(time(NULL));
            cout << "generated code :  " << rand() % 2000000000000000000;
        }
        else
            cout << "you must chose 1 or 2 or 3" << endl;



    }
};
int main()
{
    Screen s;
    Client c;
    Employe e;
    s.welcome();

    if (s.login() && s.logcl())
    {
         s.optioncl(); 
        
    }

   else 
    {

        if (s.logemp())
        {
            s.optionemp();

        }
    }

   

    //***************************************
    fstream myfile;
    //client
    myfile.open("clientid.txt", ios::out);//write

    if (myfile.is_open())
    {

        myfile << "00" << endl;
        myfile.close();
    }

    myfile.open("clientpassword.txt", ios::out);

    if (myfile.is_open())
    {

        myfile << "11" << endl;
        myfile.close();
    }
    /////////////////////////////////////

    //employe
    myfile.open("employeid.txt", ios::out);//write

    if (myfile.is_open())
    {

        myfile << "22" << endl;
        myfile.close();
    }

    myfile.open("employepassword.txt", ios::out);

    if (myfile.is_open())
    {

        myfile << "33" << endl;
        myfile.close();
    }


    //*******************************************
    myfile.open("basicbalance.txt", ios::out);//write

    if (myfile.is_open())
    {

        myfile << "1000" << endl;
        myfile.close();
    }

    ////if i want to read
    //myfile.open("id.txt", ios::in);//read

    //if (myfile.is_open())
    //{
    //    string line;
    //    while (getline(myfile, line))
    //    {
    //        //cout << line << endl;

    //    }


    //    myfile.close();
    //}


    //myfile.open("password.txt", ios::in);//read

    //if (myfile.is_open())
    //{
    //    string line2;
    //    while (getline(myfile, line2))
    //    {
    //        //cout << line2 << endl;

    //    }

    //    myfile.close();
    //}





}

