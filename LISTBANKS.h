#pragma once

#include <list>
#include "BANK.h"
#include "ACCOUNT.h"

class LISTBANKS
{
string name;
list<BANK> listBanks;
public:
	LISTBANKS();
	bool add(BANK);
	BANK* search(string); /* procura pelo nome do banco e retorna esse banco */
	void printdata(int option);
	BANK* searchaccountbank(size_t); /* procura pelo banco onde esta a conta */
	~LISTBANKS();
};

