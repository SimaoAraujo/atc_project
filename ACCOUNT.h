#pragma once
#include <iostream>
#include <string>
#include <list>
#include "USER.h"
#include <stdexcept>

using namespace std;                                                 // criar uma função para atribuir a um user ja criado uma conta ( atribuir a uma conta (aux) os dados desse user);

class ACCOUNT : private USER 
{
	USER *aux;
	size_t cardnumber;
	double bankbalance;
	string creationdate;
	string state;

public:
	ACCOUNT();
	ACCOUNT( double , string );
	bool operator== ( const ACCOUNT& a)const;
	bool changedata(double bankbalance, string creationdate);
	bool changeuserdata(string name, string birthdate, string address, string phonenumber, size_t numbercc, int option);
	void printdata(void);
	virtual void monthlyrate(void) {};

	/* Para saber saldo mandar "0". */
	double balancemanagement(double cash);
	void deposit(float);

	size_t getCardNumber(void)  { return cardnumber; };
	double getbankbalance(void) { return bankbalance; };
	string changestate(string);
};

class STUDENT : public ACCOUNT
{
	float transferrate;
	int monthlypayment;

	public:
		STUDENT();
		void monthlyrate(void);
};

class NORMAL : public ACCOUNT
{
	float transferrate;
	int monthlypayment;
	
	public:
		NORMAL();
		void monthlyrate(void);
};

class RETIRED : public ACCOUNT
{
	float transferrate;
	int monthlypayment;
	
	public:
		RETIRED();
		void monthlyrate(void);
};
