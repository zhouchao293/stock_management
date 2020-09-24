//stock_class_method.cpp -- implementing method of stock class
//version 00
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

void stock::show()
{
    cout << "company:" << company <<'\n'
         << "shares:"  << shares <<'\n'
         << "price:"   << price <<'\n'
         << "total_val:$" << total_val <<'\n';
}

