#include "ACCOUNT.h"
#include "BANK.h"

using namespace std;

ACCOUNT::ACCOUNT()//:  ACCOUNT(0.1)             //a parir aqui!!!
{
}

ACCOUNT::ACCOUNT(double bankbalance, string creationdate = "0000/00/00") //: USER()    //: USER ("none", "none", "none", "none", 0)
{ // se necessario criar um função de verificação de igualdade de  NIB
	int i;				
	size_t *x = &cardnumber;
	for (i = 0; i < 14; i++)
		x[i] = rand() % 10;
	this->bankbalance = bankbalance;
	this->creationdate = creationdate;
	this->state = "desbloqueada";
}

struct insufficientbalance : public runtime_error
{
	insufficientbalance() : runtime_error("Insufficient money.") {}
};

struct negativeamount : public logic_error
{
	negativeamount() : logic_error("Negative money.") {}
};

bool ACCOUNT::operator== ( const ACCOUNT& a) const {
	return cardnumber == a.cardnumber;
}

bool ACCOUNT::changedata(double bankbalance, string creationdate)
{
	this->bankbalance = bankbalance;
	this->creationdate = creationdate;

	return true;
}

bool ACCOUNT::changeuserdata(string name, string birthdate, string address, string phonenumber, size_t numbercc, int option = 0)
{
	aux->USER::changedata(name, birthdate, address, phonenumber, numbercc, option);
	return true;
}

void ACCOUNT::printdata(void) {
	aux->printuserdata();
	cout << "Card Number"		<< cardnumber	<< endl
		 << "Bank Balance"		<< bankbalance	<< endl
		 << "Creation Date"		<< creationdate << endl << endl;
}

string ACCOUNT::changestate(string action) {
	if (action == "watch") return state;
	if (action == "lock" || action == "unlock") {
		state = action; return "1";
	}
	else return "0";
}

/* Para saber saldo mandar "0". */
double ACCOUNT::balancemanagement(double cash) 
{
	if ((bankbalance - cash) >= 0) {
		bankbalance -= cash;
		return bankbalance;
	}
	throw insufficientbalance();
}

/* Depositar um estranho pode faze-lo, logo aqui nesta função não retorna o valor com que ficou pois so o banco so pode ter acesso a tal! */
void ACCOUNT::deposit(float amount)  
{
	if (amount > 0) {
		bankbalance += amount;
	}
	throw negativeamount();
};




void STUDENT::monthlyrate(void)
{
//	https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
//	http://en.cppreference.com/w/cpp/chrono
	//return true;
}

void NORMAL::monthlyrate(void)
{



	//return true;
}

void RETIRED::monthlyrate(void)
{



	//return true;
}

STUDENT::STUDENT() : ACCOUNT() {
	transferrate = 0.5; monthlypayment = 0;
};

NORMAL::NORMAL() : ACCOUNT() { 
	transferrate = 0.5; monthlypayment = 2; 
};

RETIRED::RETIRED() : ACCOUNT() { 
	transferrate = 0; monthlypayment = 3; 
};

//string *x = &birthdate;
//char year[4];
//year[0] = *x[0];
//year[1] = x[1];
//year = x[2];
//year += x[3];
//int year = year;
//if ((year - "2018") < 30  )