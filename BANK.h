#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "ACCOUNT.h"

using namespace std;

class BANK {
	string name;
	string preIBAN;
	int preNIB[8];
	
	list<ACCOUNT*> accounts;

public:
	BANK();
	bool changedata(string & name);
	bool add(ACCOUNT& value);
	bool remove(ACCOUNT& value);
	ACCOUNT* searchdata(size_t crdnumber);
	string getName() { return name; };
	string getpreIBAN() { return preIBAN; };
	int* getpreNIB() { return preNIB; };
	void printAccountsdata(void);
	void withdraw(float, ACCOUNT*);
	void transfer(float, ACCOUNT*, BANK*, ACCOUNT*);
	void searchAccountsBalances(int, int);
	string actionstate(size_t &crdnumber, string action);
	list<ACCOUNT*>::iterator searchiterator(ACCOUNT * crdnumber);

	friend ostream& operator<< (ostream& os, BANK& dt);  //perguntar ao prof como tirar o friend

	~BANK();
};