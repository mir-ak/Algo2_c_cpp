#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <ctime>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <exception>

using namespace std;

typedef struct Contact{
	string firstName;
	string lastName;
	list<string> numbers;
} Contact;

typedef struct Call{
	struct tm callDateTime;
	string userNumber;
}Call;

string secure_read_string(const string message);
int secure_read_int(const string message);

bool add_new_contact(list<Contact> &listContact){
	Contact newContact;
	int nbPhoneNumbers;
	string number;
	bool noMatches;
	list<Contact>::iterator it;
	int temp=0;
	bool isInserted=false;

	cout<<"\n----------Add a new contact---------"<<endl;
	cout << "Enter First Name: ";
	getline(cin,newContact.firstName);
	cout << "Enter Last Name: ";
	getline(cin,newContact.lastName);

	//check if the contact already exists
	do {
	noMatches=true;

	for (it = listContact.begin(); it != listContact.end(); it++)
	{
			if(((*it).firstName == newContact.firstName)&&((*it).lastName == newContact.lastName)){
				noMatches = false;
				cout << "First Name and Last Name already exist. Try again! \n";
				cout << "Enter First Name: ";
				getline(cin,newContact.firstName);
				cout << "Enter Last Name: ";
				getline(cin,newContact.lastName);
			}
			cout<<"\n";
		}
	} while (!noMatches);	


	cout<<"How many numbers do you want to store? ";
	cin>> nbPhoneNumbers;cin.ignore();

	for (int i=0;i<nbPhoneNumbers;i++){
		cout<<"Enter Phone Number:";
		getline(cin, number);
		newContact.numbers.push_back(number);
	}

	for (it = listContact.begin(); it != listContact.end(); it++)
	{
		if(!isInserted && (newContact.firstName.compare(((*it).firstName))>=0)){
			listContact.insert(it,newContact);
			isInserted=true;
			break;
		}
		temp++;
	}
	if(listContact.size()==0)
		listContact.push_back(newContact);
	return true;
}


void printcontact(Contact contact){
	list<string>::iterator phoneNumber_it;
	cout << "First Name: " << contact.firstName<< endl; 
	cout << "Last Name: " << contact.lastName<< endl; 
	
	for (phoneNumber_it = (contact.numbers).begin(); phoneNumber_it != (contact.numbers).end(); phoneNumber_it++)
	{
		cout << "Phone Number: "<<*phoneNumber_it << endl; 
	}
}


bool search_contact_by_first_name(list<Contact> &listContact){
	bool isFound=false;
	string firstName;
	list<Contact> foundListcontact;
	list<Contact>::iterator it;

	cout<<"\n----------Search contact by first name--------"<<endl;
	cout << "Enter first name: ";
	cin>>firstName;
	int c=0;
	for (it = listContact.begin(); it != listContact.end(); it++)
	{
		if(it->firstName==firstName){
			c++;
			foundListcontact.push_back(*it);
			isFound=true;
		}
	}
	cout << c << " Found contact(s): \n";

	//List all found elements
	for (it = foundListcontact.begin(); it != foundListcontact.end(); it++)
	{
		printcontact(*it);
		cout<<"-----------------\n";
	}

	cout<<endl<<endl;

	return isFound;
}

bool search_contact_by_last_name(list<Contact> &listContact){
		bool isFound=false;
		string lastName;
		list<Contact> foundListcontact;
		list<Contact>::iterator it;


		cout<<"\n----------Search contact by last name--------"<<endl;
		cout << "Enter last name: ";
		cin>>lastName;

		for (it = listContact.begin(); it != listContact.end(); it++)
		{
			if(it->lastName==lastName){
				cout << "Found ";
				foundListcontact.push_back(*it);
				isFound=true;
			}
		}

		//List all found element
		for (it = foundListcontact.begin(); it != foundListcontact.end(); it++)
		{
			printcontact(*it);
		}

		cout<<endl<<endl;
		return isFound;
}


void print_List_of_contacts(list<Contact> &listContact){
	cout<<"\n----------Print List of contacts---------"<<endl;
	// Iterate the contact list from the end to the begin
	list<Contact>::reverse_iterator it;
	for (it = listContact.rbegin(); it != listContact.rend(); it++)
	{
		printcontact(*it);
		cout<<"\n";
	}
	if(listContact.size()==0) cout<<"No contact Entered"<<endl;
	cout<<endl<<endl;
}

bool update_existing_contact(list<Contact> &listContact){
	bool isUpdated= false;
	int nbPhoneNumbers;
	string number;
	string firstName = secure_read_string("Enter First Name");
	string lastName  = secure_read_string("Enter Last Name");
	list<Contact>::iterator it;

	for (it = listContact.begin(); it != listContact.end(); it++)
	{
		if(((*it).firstName == firstName)&&((*it).lastName == lastName)){
			cout<<"Enter a new First Name:";
			getline(cin,(*it).firstName);
			cout<<"Enter a new Last Name:";
			getline(cin,(*it).lastName);
			cout<<"how many numbers do you want to store:";
			cin>> nbPhoneNumbers;cin.ignore();

			for (int i=0;i<nbPhoneNumbers;i++){
				cout<<"Enter a new phone Number:";
				getline(cin, number);
				(*it).numbers.clear();
				(*it).numbers.push_back(number);
			}
			isUpdated = true;
		}
		cout<<"\n";
	}
	return isUpdated;
}

bool delete_existing_contact(list<Contact> &listContact){
		bool isDeleted= false;
		string number;
		string firstName = secure_read_string("Enter the Contact's first name");
		string lastName  = secure_read_string("Enter the Contact's last name");;

		list<Contact>::iterator it;

		for (it = listContact.begin(); it != listContact.end(); it++)
		{

			if(((*it).firstName == firstName)&& ((*it).lastName == lastName)){
				listContact.erase(it);//to be checked
				isDeleted = true;
				break;
			}
			cout<<"\n";
		}

		return isDeleted;
}

void printMenu(){
	cout << "\n+===================================================+" << endl;
	cout << "|              Address Book Main Menu               |" << endl;
	cout << "|						    |" << endl;
	cout<<"(1) Add a new contact"<<endl;
	cout<<"(2) Update existing contact"<<endl;
	cout<<"(3) Print List of contacts"<<endl;
	cout<<"(4) Delete existing contact"<<endl;
	cout<<"(5) Search contact by first name"<<endl;
	cout<<"(6) Search contact by last name"<<endl;
	cout<<"(7) Add a missed call(s)"<<endl;
	cout<<"(8) List of all missed calls"<<endl;
	cout<<"(9) Delete missed calls"<<endl;
	cout<<"(10) Make a call"<<endl;
	cout<<"(11) List all calls"<<endl;
	cout<<"(12) List a specific call"<<endl;
	cout<<"(13) Delete Calls"<<endl;
	cout<<"(14) Exit program"<<endl;
	cout << "+===================================================+" << endl;
	cout << " " << endl;

	cout << "Please enter your choice by inputting a number between 1 and 14." << endl;
	cout << "Your choice: "; 
}

struct tm generateNewDateTime(){
	 struct tm *localTime;
	 time_t currentTime;
	 time( &currentTime );                   // Get the current time
	 localTime = localtime( &currentTime );
	 localTime->tm_hour= rand()%24;
	 localTime->tm_min= rand()%60;

	return *localTime;
}


void missed_call(list<Call> &listMissedCalls){
	Call newCall;
	int nbCalls;
	string tempNumber;
	cout<<"N° of missed calls: ";
	cin>> nbCalls; cin.ignore();

	for(int i=0;i<nbCalls;i++){
		cout<<"Enter missed call number:";
		getline(cin, newCall.userNumber);

		newCall.callDateTime =generateNewDateTime();
		listMissedCalls.push_back(newCall);
	}
	cout << "You have " << nbCalls << " missed call(s)";
	cout<<endl<<endl;
}

void list_all_missed_calls(list<Call> &listMissedCalls,list<Contact> &listContact){

	list<Call>::iterator it_call;
	list<Contact>::iterator it_listContact;
	list<string>::iterator phoneNumber_it;
	char buffer[80];
	bool phoneNumberIdentified=false;

	cout<<"\n----------list all missed calls--------"<<endl;

	for (it_call = listMissedCalls.begin(); it_call != listMissedCalls.end(); it_call++)
	{
		cout<<"\nNumber:"<<it_call->userNumber;
		cout<<"  Date Time:";

		strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",&(it_call->callDateTime));
		std::string str(buffer);
		std::cout << str;

		phoneNumberIdentified=false;
		for (it_listContact = listContact.begin(); it_listContact != listContact.end(); it_listContact++)
		{
			for (phoneNumber_it = (it_listContact->numbers).begin(); phoneNumber_it != (it_listContact->numbers).end(); phoneNumber_it++)
			{
				if(*phoneNumber_it==it_call->userNumber){
					phoneNumberIdentified =true;
					cout<<endl<<"UserName: ";
					printcontact(*it_listContact);
					break;
				}
			}
		}
		if(!phoneNumberIdentified){
			cout<<"UserName: Unknown"<<endl;
		}
	}
	cout<<endl<<endl;
}

void delete_missed_call(list<Call> &listMissedCalls){
	int nbCalls=listMissedCalls.size();
	listMissedCalls.clear();
	cout << "You have deleted " << nbCalls << " missed call(s)";
	cout<<endl<<endl;
}


void make_a_call(list<Call> &listCalls){
	Call newCall;
	int nbCalls;
	string tempNumber;
	cout<<"How many calls do you want to add?";
	cin>> nbCalls; cin.ignore();

	for(int i=0;i<nbCalls;i++){
		cout<<"Enter User Number:";
		getline(cin, newCall.userNumber);

		newCall.callDateTime =generateNewDateTime();
		listCalls.push_front(newCall);
	}
	cout << "You have done " << nbCalls << " call(s)";
	cout<<endl<<endl;
}


void list_all_calls(list<Call> &listCalls,list<Contact> &listContact){

	list<Call>::iterator it_call;
	list<Contact>::iterator it_listContact;
	list<string>::iterator phoneNumber_it;
	char buffer[80];
	bool phoneNumberIdentified=false;

	cout<<"\n----------list all calls--------"<<endl;

	for (it_call = listCalls.begin(); it_call != listCalls.end(); it_call++)
	{
		cout<<"\nNumber:"<<it_call->userNumber;
		cout<<"  Date Time:";

		strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",&(it_call->callDateTime));
		std::string str(buffer);
		std::cout << str;


		phoneNumberIdentified=false;
		for (it_listContact = listContact.begin(); it_listContact != listContact.end(); it_listContact++)
		{
			for (phoneNumber_it = (it_listContact->numbers).begin(); phoneNumber_it != (it_listContact->numbers).end(); phoneNumber_it++)
			{
				if(*phoneNumber_it==it_call->userNumber){
					phoneNumberIdentified =true;
					cout<<endl<<" UserName: ";
					printcontact(*it_listContact);
					break;
				}
			}
		}
		if(!phoneNumberIdentified){
			cout<<" UserName: Unknown"<<endl;
		}
	}
	cout<<endl<<endl;
}

void list_specific_call(list<Call> &listCalls,list<Contact> &listContact){
	cout<<"\n----------list specific call--------"<<endl;

	string contactNumber;
	list<Call>::iterator it_call;
	list<Contact>::iterator it_listContact;
	list<string>::iterator phoneNumber_it;
	char buffer[80];
	bool phoneNumberIdentified=false;

	cout<<"Enter contact number:";
	getline(cin,contactNumber);

		for (it_call = listCalls.begin(); it_call != listCalls.end(); it_call++)
		{
		  if(it_call->userNumber==contactNumber){

			cout<<"\nNumber:"<<it_call->userNumber;
			cout<<"  Date Time:";

			strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",&(it_call->callDateTime));
			std::string str(buffer);
			std::cout << str;

			phoneNumberIdentified=false;
			for (it_listContact = listContact.begin(); it_listContact != listContact.end(); it_listContact++)
			{
				for (phoneNumber_it = (it_listContact->numbers).begin(); phoneNumber_it != (it_listContact->numbers).end(); phoneNumber_it++)
				{
					phoneNumberIdentified =true;
					cout<<endl<<"UserName: Known:";
					printcontact(*it_listContact);
					break;
				}
			}
			if(!phoneNumberIdentified){
				cout<<"UserName: Unknown"<<endl;
			}
		  }
		}
		cout<<endl<<endl;
}

void delete_calls(list<Call> &listCalls){
	int nbCalls=listCalls.size();
	listCalls.clear();
	cout << "You have deleted " << nbCalls << " missed call(s)";
	cout<<endl<<endl;
}

//function to read a string from the user
string secure_read_string(const string message){
	string entered_data="";

	do{
		cout<<message<<":";
		getline(cin,entered_data);
		if (entered_data !="") break;
	}while(entered_data=="");

	return entered_data;
}

int main(){
	std::srand(std::time(nullptr));

	list<Contact> listContacts;
	list<Call> listCalls;
	list<Call> listMissedCalls;
	int choice;
	bool result;

	while(choice!=14){
		printMenu();
		cin>> choice; cin.ignore();
		switch(choice){
		case 1:
			result = add_new_contact(listContacts);
			if(result) cout<<"Done \n";
			break;
		case 2:
			update_existing_contact(listContacts);
			cout<<"Done \n";
			break;
		case 3:
			print_List_of_contacts(listContacts);
			cout<<"Done \n";
			break;
		case 4:
			delete_existing_contact(listContacts);
			cout<<"Done \n";
			break;
		case 5:
			search_contact_by_first_name(listContacts);
			break;
		case 6:
			search_contact_by_last_name(listContacts);
			break;
		case 7:
			missed_call(listMissedCalls);
			break;	
		case 8:
			list_all_missed_calls(listMissedCalls,listContacts);
			break;
		case 9:
			delete_missed_call(listMissedCalls);
			break;
		case 10:
			make_a_call(listCalls);
			break;
		case 11:
			list_all_calls(listCalls,listContacts);
			break;
		case 12:
			list_specific_call(listCalls,listContacts);
			break;
		case 13:
			delete_calls(listCalls);
			break;
		case 14:
			cout << "Thank you for using the program. Goodbye!" << endl;
			break;
		default:
			cout<<"Feature not supported"<<endl;
			return 0;
		}
	}
	return 0;
}
