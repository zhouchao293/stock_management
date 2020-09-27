//stock_class_method.cpp -- implementing method of stock class
//version 1.2
#include <iostream>
#include "stock_class.h"
using namespace std;

stock::stock()  //default constructor
{
    cout << "default constructor.\n";
    company = "???";
    shares = 0;
    price = 0.00;
    total_val = 0.0;
}

stock::stock(const std::string & co, long num, double pr)//a different constructor.
{
    cout << "constructor using " << co << " called\n";
    company = co;
    if(num < 0)
    {
        cout << "the num of your share shouldn't be negative."
             << company << "shares set to 0.\n";
    }
    else
        shares = num;
    update_total_val(pr);
}

stock::~stock()
{
    cout << "destructor is called.\n";
    cout << "see you "<< company <<endl;
}

void stock::set_total_val()
{
    total_val = shares * price;
}

void stock::update_total_val(double pr)
{
    price = pr;
    set_total_val();
}

/*
void stock::acquire(const std::string & co, long num, double pr)
{
    company = co;
    if(num < 0)
    {
        cout << "the num of your share shouldn't be negative."
             << company << "shares set to 0.\n";
    }
    else
        shares = num;
    update_total_val(pr);
}
*/

void stock::buy(long num, double pr)
{
    if(num <= 0)
    {
        cout << "the num of your share shouldn't be negative or zero!"
             << "transaction is aborted\n";
    }
    else
    {
        shares+=num;
        update_total_val(pr);
    }
}

void stock::sell(long num, double pr)
{
    if(num < 0)
    {
        cout << "the num of your share shouldn't be negative."
             << "transaction is aborted\n";
    }
    else if(num > shares)
    {
        cout << "you can't sell more than you have!"
             << "transaction is aborted\n";
    }
    else
    {
        shares-=num;
        update_total_val(pr);
    }
}

void stock::show() const
{
    using std::cout;
    using std::ios_base;
    //set format to X.XXX
    ios_base::fmtflags ori = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize pre = cout.precision(3);

    cout << "company:" << company <<'\n'
         << "shares:"  << shares <<'\n'
         << "price:"   << price <<'\n';
    //set format to X.XX
    cout.precision(2);
    cout << "total_val:$" << total_val <<'\n';
    //restore original format
    cout.setf(ori, ios_base::floatfield);
    cout.precision(ori);
}

const stock & stock::topval(const stock & s) const
{
    if(s.total_val >= total_val)
        return s;
    else
        return *this;//return the object that is calling function topval()now.
}

