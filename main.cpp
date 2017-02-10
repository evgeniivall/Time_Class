#include <QCoreApplication>
#include "time_class.h"
#include <iostream>
int main(int argc, char *argv[])
{

   Time t;
   t.SetCurrentTime();

   Time t1(20, 0, 0);
    std::cout << (t1 > t);




    return 0;
}
