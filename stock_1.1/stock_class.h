//stock00.h --stock class
//version 00
#ifndef STOCK_CLASS_H_
#define STOCK_CLASS_H_

#include <string>
using namespace std;

class stock
{
    private:
        /*std::*/string company;
        long shares;
        double price;
        double total_val;

    public:
        stock();//declare default constructor
        stock(const std::string & co, long num=0, double price = 0.0);
        ~stock();//declare destructor
        void set_total_val();
        void update_total_val(double pr);
        //void acquire(const std::string & co, long num, double price);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

#endif
