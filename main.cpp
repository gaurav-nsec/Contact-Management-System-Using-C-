// Name :- Gaurav Kumar Choudhary
// College :- Netaji Subhash Engineering College, Kolkata
// B.Tech (EE 4th Year)

#include<iostream>
#include<string>
using namespace std;

//The maximum number of people stored in the address book
#define Max 1000 //maximum number of people

//define a contact structure
struct Contacts
{
	string cName;		//Name
	int cGender = 1;	//gender
	int cAge = 0;		//age
	string cPhone;		//phone number
	string cAdd;		//address
};

//Define an address book structure
struct AddressBooks
{
	Contacts contactsArry[Max];	//Array of address book contact information
	int aCount = 0;					//The number of people in the address book
};

//show main menu
void showMenu()
{
	cout << "******************************************" << endl;
	cout << "***** Address book management system *****" << endl;
	cout << "******************************************" << endl;
	cout << "*****         1、Add contacts        *****" << endl;
	cout << "*****         2、Show contacts       *****" << endl;
	cout << "*****         3、Delete contact      *****" << endl;
	cout << "*****         4、Find a contact      *****" << endl;
	cout << "*****         5、Edit contacts       *****" << endl;
	cout << "*****         6、Clear Contacts      *****" << endl;
	cout << "*****         0、Exit Contacts       *****" << endl;
	cout << "******************************************" << endl;
	cout << "*****************Version1.0***************" << endl;
	cout << "******************************************" << endl;
}

//Add contacts
void AddContacts(AddressBooks* abs)
{
	//Determine if it is full
	if (abs->aCount == Max)
	{
		cout << "The address book is full and cannot be added！" << endl;
		return;
	}
	else
	{
		//Name
		string name;
		cout << "Please type your name： " << endl;
		cin >> name;
		abs->contactsArry[abs->aCount].cName = name;

		//gender
		int gender;
		cout << "Please enter Gender： " << endl;
		cout << "1 ---- Male " << endl;
		cout << "2 ---- Female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[abs->aCount].cGender = gender;
				break;
			}
			cout << "Incorrect input, please re-enter！" << endl;
		}

		//age
		int age;
		cout << "Please enter your age： " << endl;
		cin >> age;
		abs->contactsArry[abs->aCount].cAge = age;

		//Telephone
		string phone;
		cout << "Please enter phone number： " << endl;
		cin >> phone;
		abs->contactsArry[abs->aCount].cPhone = phone;

		//address
		string add;
		cout << "Please enter short address： " << endl;
		cin >> add;
		abs->contactsArry[abs->aCount].cAdd = add;

		//plus one
		abs->aCount += 1;
		cout << "Added successfully！" << endl;
		system("pause");
		//clear screen
		system("cls");
	}

}

//show contacts
void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "No contact, please add it first!" << endl;
	}
	else
	{
		//show all contacts
		for (int i = 0; i < abs->aCount; i++)
		{
			cout << "Name：" << abs->contactsArry[i].cName <<" ||" << " Gender：" << (abs->contactsArry[i].cGender != 2 ? "Male" : "Female") <<" ||"<< " age：" << abs->contactsArry[i].cAge << " ||" << " Telephone：" << abs->contactsArry[i].cPhone << " ||" << " Address：" << abs->contactsArry[i].cAdd << endl;
		}
	}
	system("pause");
	system("cls");
}

//Check if someone exists
int IsExit(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->aCount; i++)
	{
		if (abs->contactsArry[i].cName == name)
		{
			return i;
		}
	}
	return -1;
}

//delete contact
void DeleteContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "Please enter the name of the user you want to delete：" << endl;
	cin >> name;
	//Check if a contact exists
	int index = IsExit(abs, name);
	//exist
	if (index > -1)
	{
		for (int i = index; i < abs->aCount - 1; i++)
		{
			//forward shift operation
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		//reduce one record
		abs->aCount--;
		cout << "Successfully deleted！" << endl;
	}
	else//does not exist
	{
		cout << "Checked no such person available. " << endl;
	}
	system("pause");
	system("cls");
}

//find a contact
void GetContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "Please enter the name of the user you are looking for : " << endl;
	cin >> name;
	//Check if a contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//exist
		cout << "Name：" << abs->contactsArry[index].cName << endl;
		cout << "Gender：" << abs->contactsArry[index].cGender << endl;
		cout << "Age：" << abs->contactsArry[index].cAge << endl;
		cout << "Telephone：" << abs->contactsArry[index].cPhone << endl;
		cout << "Address：" << abs->contactsArry[index].cAdd << endl;
	}
	else
	{
		//does not exist
		cout << "Checked no such person available. " << endl;
	}
	system("pause");
	system("cls");

}

//Edit contacts
void ModefyContacts(AddressBooks* abs)
{
	//Record the name entered by the user
	string name;
	cout << "Please enter the username you want to edit : " << endl;
	cin >> name;
	//Check if a contact exists
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//exist
		//Name
		string name;
		cout << "Please enter your revised name： " << endl;
		cin >> name;
		abs->contactsArry[index].cName = name;

		//gender
		int gender;
		cout << "Please enter modified Gender： " << endl;
		cout << "1 ---- Male " << endl;
		cout << "2 ---- Female " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[index].cGender = gender;
				break;
			}
			cout << "Incorrect input, please re-enter！" << endl;
		}

		//age
		int age;
		cout << "Please enter a revised age： " << endl;
		cin >> age;
		abs->contactsArry[index].cAge = age;

		//Telephone
		string phone;
		cout << "Please enter your revised phone number： " << endl;
		cin >> phone;
		abs->contactsArry[index].cPhone = phone;

		//address
		string add;
		cout << "Please enter the revised short address： " << endl;
		cin >> add;
		abs->contactsArry[index].cAdd = add;
		cout << "Successfully modified !" << endl;
	}
	else
	{
		//does not exist
		cout << "Check no such person" << endl;
	}
	system("pause");
	system("cls");
}

//clear contacts
void ClearContacts(AddressBooks* abs)
{
	string choose = "N";
	cout << "Are you sure you want to clear your contacts？(Y confirm / N Cancel)" << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << "Incorrect input, please re-enter!!" << endl;
		}
	}

	if (choose == "Y")
	{
		abs->aCount = 0;
		cout << "Cleared successfully!!" << endl;
	}
	else
	{
		cout << "Operation cancelled!!" << endl;
	}
	system("pause");
	system("cls");
}


int main()
{
	//Record the information entered by the user
	int select = 0;
	//Define an address book structure
	AddressBooks abs;
	//Set the current number of people to zero
	abs.aCount = 0;

	while (true)
	{
		//show main menu
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1: //1、Add contacts
			AddContacts(&abs);	//address delivery
			break;
		case 2: //2、show contacts
			ShowContacts(&abs); //address delivery
			break;
		case 3: //3、delete contact
			DeleteContacts(&abs);
			break;
		case 4: //4、find a contact
			GetContacts(&abs);
			break;
		case 5: //5、Edit contacts
			ModefyContacts(&abs);
			break;
		case 6: //6、clear contacts
			ClearContacts(&abs);
			break;
		case 0: //0、Exit Contacts
			cout << "Welcome to use next time，goodbye！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");//Press any key to continue
	return 0;
}