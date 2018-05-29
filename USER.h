#pragma once
#include <string>
#include <iostream>
//#include "ACCOUNT.h"
#include <list>

using namespace std;

class USER
{
	//list <ACCOUNT*> accounts;

public:
	string name;
	string birthdate;  /* ANO/MES/DIA */
	string address;
	string phonenumber;
	size_t numbercc;

	USER();
	USER(string , string, string , string , size_t );
	bool changedata(string, string, string, string, size_t, int);
	void printuserdata(void);
	~USER();
};


