#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Source.h"
#include<ostream>

using namespace std;


string first_name;
string last_name;
char choice;
string course;
string section;

void AddRecords()
{

	system("cls");
	ofstream Records;
	Records.open("outfile.csv", ios::app);
	
	cout << "Enter the Firt Name : ";
	cin >> first_name;
	cout << "Enter the Last Name : ";
	cin >> last_name;
	cout << "Enter the Course : ";
	cin >> course;
	cout << "Enter the Section : ";
	cin >> section;
	Records<<"First name"<<","<<"Last name"<<","<<"Course"<<","<<"section"<<"\n";
	Records<< first_name << ","  << last_name << ","  << course << ","  << section << "," << endl;
	
	
	
	
	char exit;
cout << " _______________________ " << endl;
cout << "|				         |" << endl;
cout << "|_______________________|" << endl;
cout << "|  __________________   |" << endl;
cout << "| |   A for menu	  |  |" << endl;
cout << "| |__________________|  |" << endl;
cout << "|  __________________   |" << endl;
cout << "| |   B to stay      |  |" << endl;
cout << "| |__________________|  |" << endl;
cout << "|  __________________   |" << endl;
cout << "| |   C for info     |  |" << endl;
cout << "| |__________________|  |" << endl;
cout << "|_______________________|" << endl;

	cin >> exit;
	if (exit == 'A')
	{
		menu();
	}
	else if (exit == 'C')
		AddRecords();
	else
	{
		cout << "invalid choice\n";
	}
		
	system("pause");
}
void menu()
{
	system("cls");
	cout << "\t\t STUDENT INFORMATION SYSTEM ";
	//cout <<"\n\n ;
	cout << "\n\n";
	cout << "\n \t\t\t 1. Add Records";
	cout << "\n \t\t\t 2. List Records";
	cout << "\n \t\t\t 3. Modify Records";
	cout << "\n \t\t\t 4. Delete Records";
	cout << "\n \t\t\t 5. Account";
	cout << "\n \t\t\t 6. details";
	cout << "\n \t\t\t 7. Purchase history";
	cout << "\n \t\t\t 8. Exit Program";
	cout << "\n\n";
	cout << "\t\t\t Select Your Choice [1-8]";
	cin >> choice;
	switch (choice) {
	case '1':
		cout << "\n \t\t\t 1. Add Records";
		AddRecords();
		break; //optional
	case '2':
		cout << "\n \t\t\t 2. List Records";
		ListRecord();
		break; //optional
	case '3':
		cout << "\n \t\t\t 3. Modify Records";
		break; //optional
	case '4':
		cout << "\n \t\t\t 4. Delete Records";
		break; //optional
	case '5':
		cout << "\n \t\t\t 5. Account";
		break; //optional
	case '6':
		cout << "\n \t\t\t 6. details";
		break; //optional
	case '7':
		cout << "\n \t\t\t 7. Purchase history";
		break; //optional
	case '8':
		cout << "\n \t\t\t 8. Exit Program";
		exit(0);

		
	 // you can have any number of case statements.
	default: //Optional
		cout << "Select Your Choice [1-4]";
	}
}

void ListRecord()
{
	system("cls");
	ifstream ip("outfile.csv");

	if (!ip.is_open()) cout << "ERROR: File Open" << '\n';

	while (ip.peek() != EOF)
	{

		getline(ip, first_name, ',');
		getline(ip, last_name, ',');
		getline(ip, course, ',');
		getline(ip, section, ',');

		cout << "Name: " << first_name + last_name << '\n';
		cout << "Course: " << course << '\n';
		cout << "Section: " << section << '\n';
		cout << "-------------------" << '\n';
	}

	ip.close();
	system("pause");
}
int main()
{

	menu();
	AddRecords();
	ListRecord();
	return (0);
}

