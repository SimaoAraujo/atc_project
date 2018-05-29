#include <string>
#include <list>
#include <math.h>
#include <iostream>

#include "USER.h"
#include "ACCOUNT.h"
#include "BANK.h"
#include "LISTBANKS.h"

using namespace std;

int main()
{
	int action=-1;
	LISTBANKS pt;
	BANK bnk;
//	cout << "chegou aqui 1" << endl;
	ACCOUNT acc;
//	cout << "chegou aqui 2" << endl;
	STUDENT accstud;
	NORMAL accnorm;
	RETIRED accret;


	BANK * auxbank = nullptr;
	BANK * auxbank2 = nullptr;
	ACCOUNT * auxaccount = nullptr;
	ACCOUNT * auxaccount2 = nullptr;
	
	string name, address, phonenumber, birthdate, auxstring;
	size_t numbercc, cardnumber, auxint;
	float auxfloat;

	while (action != 0) {
		cout << "Choose action!" << endl;
		cout << "0 - EXIT" << endl;
		cout << "1 - Create Bank." << endl;
		cout << "2 - Create User." << endl;
		cout << "3 - Open Account." << endl;
		cout << "4 - Search Account." << endl;
		cout << "5 - Change Account Data." << endl;
		cout << "6 - Close Account." << endl;
		cout << "7 - Search Account By Balance." << endl;
		cout << "8 - Block/Unlock account." << endl;
		cout << "9 - Deposit Money." << endl;
		cout << "10 - Raise Money." << endl;
		cout << "11 - Transfer Money." << endl;
		cout << "12 - Print Movements." << endl;
		cout << "13 - Print all Bank all Accounts all Users." << endl;
		//exportar movimentos para o ficheiro e os dados anuais automatico ou opcao

		cin >> action;

		switch (action)
		{
		case 0:										// EXIT
			break;
		case 1:										// Create Bank
			cout << "Insert Bank name." << endl;
			cin >> name;
			bnk.changedata(name);
			pt.add(bnk);
			break;

		case 2:										// Create User
			//cout << "Insert Name." << endl;
			//cin >> name;
			//cout << "Insert birthdate." << endl;
			//cin >> birthdate;
			//cout << "Insert Address." << endl;
			//cin >> address;
			//cout << "Insert Phone number." << endl;
			//cin >> phonenumber;
			//cout << "Insert Citizen Card Number." << endl;
			//cin >> numbercc;
			//acc.changeuserdata(name, birthdate, address, phonenumber, numbercc, 0);
			break;
			//olaaaaaa

		case 3:										// Open Account
			cout << "Log in as user (1) or create user (2)? " << endl;
			while (action != 1 && action != 2) {
				cin >> action;
			};
			switch (action)
			{
			case 1:
				pt.printdata(2);
				cout << "Enter the user name!" << endl;
				cin >> name;

				break;

			case 2:
				cout << "Insert Name." << endl;
				cin >> name;
				cout << "Insert birthdate." << endl;             // fazer uma condição aqui para conforme a idade usar o tipo de conta dela em vez do acc. usar accstud por exemplo
				cin >> birthdate;
				cout << "Insert Address." << endl;
				cin >> address;
				cout << "Insert Phone number." << endl;
				cin >> phonenumber;
				cout << "Insert Citizen Card Number." << endl;
				cin >> numbercc;
				acc.changeuserdata(name, birthdate, address, phonenumber, numbercc, 0);

				cout << "Please enter the creation date!" << endl;
				cin >> auxstring;
				acc.changedata(0, auxstring);

				cout << "Enter the bank of the new account." << endl;
				pt.printdata(1);
				cin >> name;
				auxbank = pt.search(name);

				if (auxbank == nullptr) {
					cout << "Bank not found." << endl;
					break;
				}
				auxbank->add(acc);
				break;
			}
			break;

		case 4:										//Search Account
			break;

		case 5:										//Change Account Data
			break;

		case 6:										//Close Account
			break;

		case 7:										//Search Account By Balance
			break;

		case 8:                                     //Block/Unlock account
			pt.printdata(2);
			auxint = 0;
			cout << "Enter the bank of the account." << endl;
			cin >> name;
			auxbank = pt.search(name);

			if (auxint != 1) {
				cout << "Bank not found." << endl;
			}
			else {
				cout << "Enter the account number." << endl;
				cin >> cardnumber;                                                                               // falta meter condiçao para saber se existe conta
				cout << "Actual account state: " << auxbank->actionstate(cardnumber, "watch") << endl;

				do {
					cout << "Do you want to change state? Possibel action: lock or unlock or nothing";
					cin >> auxstring;
					if (auxstring == "lock" || auxstring == "unlock") auxbank->actionstate(cardnumber, auxstring);
					else if (auxstring != "nothing") cout << "Action not found." << endl;

				} while (auxstring != "lock" || auxstring != "unlock" || auxstring == "nothing");

				cout << "New State:" << auxbank->actionstate(cardnumber, "watch");
			}
			break;

		case 9:										//Deposit Money
			break;

		case 10:									//Raise Money
			break;

		case 11:									//Transfer Money			
			cout << "What quantity do you want to transfer?" << endl; // simao vai melhorar
			cin >> auxfloat;
			cout << "Account number you want to send money to?" << endl;
			cin >> cardnumber;
			cout << "Account number you want to receive money to?" << endl;
			cin >> auxint;
//			try {
			auxbank = pt.searchaccountbank(cardnumber);
			auxaccount = auxbank->searchdata(cardnumber);
			auxbank2 = pt.searchaccountbank(auxint);
			auxaccount2 = auxbank2->searchdata(auxint);

			auxbank->transfer(auxfloat, auxaccount2, auxbank, auxaccount);
			//}
			//catch (int) {
			//	
			//};
			break;

		case 12:									//Print Movements PILA
			break;

		case 13:									//Print all Bank all Accounts all Users	
			pt.printdata(2);
			break;

		case 69:
			break;

		default:
			cout << "Non-existent Action! Choose an available action." << endl;
			break;
		}
		system("PAUSE");
		system("CLS");
	}
	return 0;
}
