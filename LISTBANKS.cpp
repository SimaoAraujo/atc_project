#include "LISTBANKS.h"

LISTBANKS::LISTBANKS()
{
	name = "PORTUGAL";
}

bool LISTBANKS::add(BANK bnk)
{
	listBanks.emplace_front(bnk);
	return true;
}

BANK* LISTBANKS::search(string name)
{
	for (auto &x : listBanks)
		if (x.getName() == name)
			return &x;

	return nullptr;
}

BANK* LISTBANKS::searchaccountbank(size_t cardnumber) 
{
	ACCOUNT * auxaccount = nullptr;
	for (auto &x : listBanks)
	{
		auxaccount = x.searchdata(cardnumber);
		if (auxaccount != nullptr)
			return &x;
	}
}

void LISTBANKS::printdata(int option)
{
	cout << "List of banks:" << endl;
	for (auto &x : listBanks)
	{
		switch (option)
		{
		case 1:
			cout << x;
			break;

		case 2:
			cout << x;
			x.printAccountsdata();
			break;
		}
	}
}

LISTBANKS::~LISTBANKS()
{
}
