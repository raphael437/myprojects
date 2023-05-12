
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class Shopping
{
private:
    //att
    int pcode;
    float price;
    float dis;
    string pname;

public:

    void menu();
    void adminstration();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();



};


void Shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "**************************************" << endl;
    cout << "subermarket main" << endl;
    cout << "**************************************" << endl;

    cout << "please enter : 1) adminstration" << endl;
    cout << "2) buyer" << endl;
    cout << "3)exite" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "enter email" << endl;
        cin >> email;
        cout << "enter password" << endl;
        cin >> password;

        if (email == "raphael22@gmail.com" && password == "enter")
        {
            adminstration();
        }
        else
        {
            cout << "invalide password or email" << endl;
        }
        break;


    case 2:
        buyer();

    case 3:
        exit(0);

    default:
        cout << "please select from given options" << endl;
    }

    goto m;


}
void Shopping::adminstration()
{
m:
    int choice;
    cout << "**************************************" << endl;
    cout << "adminstration main" << endl;
    cout << "**************************************" << endl;

    cout << "please enter : 1) add product" << endl;
    cout << "2) modify product" << endl;
    cout << "3) delete product" << endl;
    cout << "4) back to menu" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "you must choose from the given option" << endl;
    }
    goto m;
}

void Shopping::buyer()
{
m:
    int choice;
    cout << "**************************************" << endl;
    cout << "buyer main" << endl;
    cout << "**************************************" << endl;

    cout << "please enter : 1) buy product" << endl;

    cout << "2) back to menu" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "you must choose from the given option" << endl;
    }

    goto m;
}

void Shopping::add()
{
    fstream data;
m:
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "add new product" << endl;
    cout << "product code of the product" << endl;
    cin >> pcode;
    cout << "name of the product" << endl;
    cin >> pname;
    cout << "price of the product" << endl;
    cin >> price;
    cout << "the discount of the product" << endl;
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }

        data.close();
    }

    if (token == 1)
    {
        goto m;
    }

    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
        cout << "it is done" << endl;
    }
}

void Shopping::edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;



    cout << "modify new product" << endl;
    cout << "enter code of the product" << endl;
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "file is not exist" << endl;
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "product new code" << endl;
                cin >> c;
                cout << "name of the product" << endl;
                cin >> n;
                cout << "price" << endl;
                cin >> p;
                cout << "discount" << endl;
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << " " << endl;
                cout << "record edited" << endl;
                token++;


            }
            else
            {
                data1 << "" << pcode << " " << pname << " " << price << " " << dis << " " << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();


        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "record not founded" << endl;

        }


    }

}
void Shopping::rem()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;

    cout << "remove the product" << endl;
    cout << "enter the product code " << endl;
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "file is not exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {

            if (pkey == pcode)
            {
                cout << "prodect deleted successfully" << endl;
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "record not done" << endl;
        }
    }

}


void Shopping::list()
{


    fstream data;
    data.open("database.txt", ios::in);
    cout << "the products name " << "\t" << "number" << "\t" << "price" << endl;

    data >> pcode >> pname >> price >> dis;

    while (!data.eof())
    {

        cout << pcode << "\t\t " << pname << "\t\t " << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}


void Shopping::reciept()
{
    system("clc");
    fstream data;
    int arrcode[10];
    int arrqu[10];
    int c = 0;
    string choice;
m:
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "*********RECIEPT************" << endl;
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "empty database" << endl;
    }
    else
    {
        data.close();
        list();
        cout << "*****************************" << endl;
        cout << "please select the product" << endl;
        cout << "*******************************" << endl;
        do {

            cout << "please enter the product's code" << endl;
            cin >> arrcode[c];
            cout << "please enter the quantaty" << endl;
            cin >> arrqu[c];
            for (int i = 0; i < c; i++)
            {
                if (arrcode[c] == arrcode[i])
                {
                    cout << "duplcate product code,please try again" << endl;
                    goto m;
                }
            }
            c++;
            cout << "if you want to buy another product press yes else press no" << endl;
            cin >> choice;

        } while (choice == "yes");
        system("clc");

        cout << "*********RECIEPT************" << endl;
        cout << "the products: name " << "\t" << "quantaty\t" << "price\t" << "amount\t" << "" << "\t" << "price\t" << "discount" << endl;
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrcode[i])
                {
                    amount = price * arrqu[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << pcode << pname << arrqu[i] << price << amount << dis;

                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\t***************\t";
    cout << "total amount= " << total << endl;

}

int main()
{

    Shopping s;
    s.menu();


}