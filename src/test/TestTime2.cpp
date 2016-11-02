/*
 * TestTime2.cpp
 *
 *  Created on: 02-Nov-2016
 *      Author: sirisha
 */


#include <iostream>

using namespace std;

class Singleton
{
private:
    static bool instanceFlag;
    static Singleton *single;
    Singleton()
    {
        //private constructor
    }
public:
    static Singleton* getInstance();
    void method();
    ~Singleton()
    {
        instanceFlag = false;
    }
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! single)
    {
        single = new Singleton();
        //instanceFlag = true;
        cout << "getInstance: " << single << endl;
        return single;
    }
    else
    {
    	cout << "getInstance: " << single << endl;
        return single;
    }
}

void Singleton::method()
{
    cout << this << "  Method of the singleton class" << endl;
}

#if 0
int main()
{
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    return 0;
}

#endif
