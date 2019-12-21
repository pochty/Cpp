#include <iostream>
#include "Catalog.h"
#include "../00_00-adlib/GetUserInput.cpp"
using namespace std;

size_t CatalogItem::counter = 0;

int main()
{
	Catalog ct;
	ct.Add("company1", "owner1", "phone1", "address1", "activity1");
	ct.Add("company2", "owner2", "phone2", "address2", "activity2");
	ct.Add("company3", "owner3", "phone3", "address3", "activity3");
	ct.Add("company4", "owner4", "phone4", "address4", "activity4");
	ct.Add("company5", "owner5", "phone5", "address5", "activity5");
	ct.Add("company6", "owner6", "phone6", "address6", "activity6");
	ct.Add("company7", "owner7", "phone7", "address7", "activity7");

	while (true)
	{
		system("cls");
		cout << "1. Add item\n2. Print catalog\n3. Save catalog\n4. Load catalog\n5. Search\n0. Exit\n" << endl;
		switch (GetUserInput(1, 0, 5, "Select option"))
		{
		case(1):
		{
			cout << "Input company name: ";
			string companyName;
			cin >> companyName;
			cout << "Input owner: ";
			string owner;
			cin >> owner;
			cout << "Input phone: ";
			string phone;
			cin >> phone;
			cout << "Input address: ";
			string address;
			cin >> address;
			cout << "Input activity: ";
			string activity;
			cin >> activity;
			ct.Add(companyName, owner, phone, address, activity);
		}
			break;
		case(2):
			ct.Print();
			system("pause");
			break;
		case(3):
			ct.FileSave();
			break;
		case(4):
			ct.FileLoad();
			break;
		case(5):
		{
			cout << "\t1. Name\n\t2. Owner\n\t3. Phone\n\t4. Address\n\t5. Activity\n\t0. Back" << endl;
			cout << "\tInput search string: ";
			string str;
			cin >> str;
			switch (GetUserInput(1, 0, 5, "\tSelect search mode"))
			{
			case(1):
				ct.FindCompanyName(str);
				break;
			case(2):
				ct.FindOwner(str);
				break;
			case(3):
				ct.FindPhone(str);
				break;
			case(4):
				ct.FindAddress(str);
				break;
			case(5):
				ct.FindActivity(str);
				break;
			}
			system("pause");
		}
			break;
		default:
			return 0;
		}
	}


}