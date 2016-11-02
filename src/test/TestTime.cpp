/*
 * TestTime.cpp
 *
 *  Created on: 02-Nov-2016
 *      Author: sirisha
 */
using namespace std;
#include "TestHeader.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <ctime>
class TestTime;

class TestTime {

private:
	time_t currentRawTimeInSeconds;
	struct tm currentTime;
	char buf[180];
	static TestTime *testTime_t;

private:
	TestTime() {
		cout << "TestTime costructor..." << endl;
	}

public:
	~TestTime() {
		cout << "TestTime Destructor..." << endl;
	}

public:
	static TestTime* getTimeInstance(void);
	static void destructTimerInstance(void);
	string getCurrentTime(void);
};

TestTime* TestTime::testTime_t = 0;

string TestTime::getCurrentTime(void) {
	this->currentRawTimeInSeconds = time(0);
	this->currentTime = *localtime(&currentRawTimeInSeconds);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &currentTime);

	cout << __func__ << "(" << __LINE__ << ")  Current object address: " << this << endl;
	return buf;

}

TestTime* TestTime::getTimeInstance() {

	if(!testTime_t)
		testTime_t = new TestTime();
	return testTime_t;
	//return 0;

}

void TestTime::destructTimerInstance(void) {
	cout << __func__ <<"(" <<__LINE__ << ")  Invoing destructor manually..."  << endl;
	//~TestTime();
}


#if 1
int main() {

	TestTime *t1, *t2;
	int a;
	int &ra =a ;
	int &rra = ra;
	cout << "ref: " << ra << " , orig: " << a << "ref to ref: " << rra << endl;
	cout << "\naddress of ref:  " << &ra << " , and address of orig: " << &a << endl;
	cout << "sizeof of ref:  " << sizeof(ra) << " , and size of orig: " << sizeof(a) << endl;
	cout << "After modifying ref and orig..." << endl;
	ra=a+4;
	cout << "ref: " << ra << " , orig: " << a << "ref to ref: " << rra << endl;
	cout << "address of ref:  " << &ra << " , and address of orig: " << &a << endl;
	cout << "sizeof of ref:  " << sizeof(ra) << " , and size of orig: " << sizeof(a) << endl;


	cout << "Testing ref to an object..." <<endl;
	t1 = TestTime::getTimeInstance();
	TestTime &rt1 = *t1;
	//cout << "ref-to-an-object: " << rt1 << " , orig: " << t1 << "ref to ref to object: tbd " << endl;
		cout << "address of ref:  " << &rt1 << " , and address of orig: " << t1 << endl;
		cout << "sizeof of ref:  " << sizeof(rt1) << " , and size of orig: " << sizeof(*t1) << endl;

	cout << "Object t1: " << t1->getCurrentTime() << endl;
	sleep(5);
	cout << "Object t1 again: " << t1->getCurrentTime() << endl;

	sleep(10);

	t2 = TestTime::getTimeInstance();
	cout << "Object t2: " << t2->getCurrentTime() << endl;

	cout << "\n main leaving, destructor should get called..."  << endl;
	//TestTime::destructTimerInstance();
	return 0;
}
#endif
