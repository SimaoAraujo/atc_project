#include "BANK.h"

BANK::BANK() {
	name = "none";
	preIBAN = "PT50";
	preNIB[8] = { 0 };
}

bool BANK::changedata(string & name) {
	this->name = name;

	int i;																						// se necessario criar um função de verificação de igualdade de  NIB
	for (i = 0; i < 8; i++)
		preNIB[i] = rand() % 10;

	return true;
}

bool BANK::add(ACCOUNT& value) {
	if (value.getCardNumber() == 0)
		return false;

	ACCOUNT *new_element = new ACCOUNT (value);
	accounts.emplace_front(new_element);
	return true;
}


ACCOUNT* BANK::searchdata(size_t crdnumber) {
	for (ACCOUNT *x : accounts)
		if (x->getCardNumber() == crdnumber) return x;

	return nullptr;
}

list<ACCOUNT*>::iterator BANK::searchiterator(ACCOUNT *crdnumber) {

	list<ACCOUNT*>::iterator findIter = find(accounts.begin(), accounts.end(), crdnumber);

	return findIter;
}

bool BANK::remove(ACCOUNT& value) {
	accounts.erase(searchiterator(&value));
	return false;
}

ostream& operator<<(ostream& os, BANK& dt)
{
	os << "NAME:"	<< dt.getName()		<< endl
	   << "IBAN:"	<< dt.getpreIBAN()	<< endl 
	   << "NIB:"	<< dt.getpreNIB()	<< endl;
	return os;
}

void BANK::printAccountsdata(void) {
	for (ACCOUNT *x : accounts)
		x->printdata();
}

void BANK::searchAccountsBalances(int min, int max)
{
	for (ACCOUNT *x : accounts)
		if (x->getbankbalance() >= min && x->getbankbalance() <= max)
		{
			x->printdata(); // neste caso nao vai ser print mas sim imprimir num ficheiro
		}
}

string BANK::actionstate(size_t &crdnumber, string action) 
{
	ACCOUNT * aux = searchdata(crdnumber);
	if (action == "watch") return aux->changestate("watch");
	if (action == "lock" || action == "unlock") {
		aux->changestate(action);
		return aux->changestate("watch");
	}
	return "0";
}

void BANK::withdraw(float amount, ACCOUNT* accprovider) {
	accprovider->balancemanagement(amount);
};

void BANK::transfer(float amount, ACCOUNT* receiver, BANK* provider, ACCOUNT* accprovider)
{
	receiver->deposit(amount);
	provider->withdraw(amount, accprovider);
};

BANK::~BANK() {
	//accounts.clear();
}










