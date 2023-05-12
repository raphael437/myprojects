
#include <iostream>
using namespace std;


class hotel
{

    //att
protected:

    static int safe;

public:
    //const
    hotel()
    {
        safe++;
    }
    //methods
    int getsafe()
    {
        return safe;
    }

};
class rooms :public hotel
{
private:
    //att
    int safe;

public:
    //cons

    rooms()
    {
        this->safe = 0;
    }

    rooms(int a)
    {
        this->safe = a;
    }

    //methods

    void setsafe(int a)
    {
        this->safe = a;
    }
    int getsafe()
    {
        return safe;
    }

    //decon

    ~rooms()
    {

    }
};

int hotel::safe = 0;



int main()
{
    rooms r;
    int m;
    int arr[5] = { NULL };
    cout << "we have 5 rooms i will show you the cases of each one" << endl;
    arr[0] = 1;
    arr[4] = 1;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == 0)
        {
            cout << "open" << endl;
        }
        else
            cout << "reseived" << endl;
    }
    cout << "which one do you want?" << endl;
    /*cout << "if you want to cancel enter cancel" << endl;
    string s ;
    cin >> s;
    if (s == "cancel")
        return;
    else
    {
        int
        for (int i = 0; i < 5; i++)
        {

        }
    }*/



    int n;
    cin >> n;
    if (n == 1 || n == 5)
    {
        cout << "not allwoed" << endl;

    }
    else
    {
        cout << "your booking is done " << endl;
        cout << "please enter the 100 pound for rent" << endl;
        int e;
        cin >> e;
        if (e == 100)
        {

            r.setsafe(e);

        }

        else
        {
            cout << "pleas enter 100 or it will be canceled" << endl;
            cin >> e;
            if (e == 100)
            {

                r.setsafe(e);

            }
            if (e != 100)
            {
                cout << "sorry you have to enter 100" << endl;
            }
        }
    }







    cout << "*******************************************" << endl;
    cout << "the safe is= ";


    cout << r.getsafe() << endl;
}
