#include <iostream>
#include "stock_class.h"
using namespace std;
int main()
{
    cout << "default constructor will be called.\n";
    class stock Mark;//default constructor will be called.
    Mark.show();
    cout << "a different constructor will be called.\n";
    class stock alice("Wuliangye" , 1000, 157.56); //a different constructor will be called.
    alice.show();
    cout << "---fuzhi--- \n";
    Mark = alice;
    Mark.show();
    cout << "---create temp object--- \n";
    alice = stock("Tangyuan Electronic TEC", 5000, 60.70);//create temp object
    alice.show();
    cout << "---new an object--- \n";
    class stock *pstock = new stock("Huichuan" , 100000, 52.14); //destructor will be called.
    pstock->show();
    /*Mark.acquire("ZTE(SH)", 1000, 33.21);
    Mark.show();
    Mark.sell(500, 34.77);
    Mark.show();
    Mark.sell(600, 35.77);
    Mark.show();
    Mark.buy(6000, 30.99);
    Mark.show();
    //Mark.acquire("Maotai(SZ)", 100, 1711);
    Mark.show();*/
    return 0;
}
