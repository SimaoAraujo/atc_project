#include "USER.h"

USER::USER() : USER("0", "0", "0", "0", 0) {};

USER::USER(string name, string birthdate, string address, string phonenumber, size_t numbercc)
{
	this->name = name;
	this->birthdate = birthdate;
	this->address = address;
	this->phonenumber = phonenumber;
	this->numbercc = numbercc;
}

bool USER::changedata(string name , string birthdate, string address, string phonenumber, size_t numbercc, int option=0) {
	switch (option)
	{
											/* Using case 0 to "creat a brand new user". */
	case 0:
		this->name = name;
		this->birthdate = birthdate;
		this->address = address;
		this->phonenumber = phonenumber;
		this->numbercc = numbercc;
		return true;
		break;

	case 1: //address
		this->address = address;
		return true;
		break;
	case 2: //phonenumber
		this->phonenumber = phonenumber;
		return true;
		break;
	};
	return false;
}

void USER::printuserdata(void)
{
	cout << "NAME:"			<< name << endl
		 << "Birthdate:"	<< birthdate << endl
		 << "Address"		<< address << endl
		 << "Phone Number"	<< phonenumber << endl
		 << "Number CC"		<< numbercc << endl;
}

USER::~USER()
{

}