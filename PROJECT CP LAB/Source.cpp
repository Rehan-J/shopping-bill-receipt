#include <iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>

using namespace std;

// Variables Declaration

float sum[50];              // to store total sum of each item
string item[50];          // to store name of each item
int quan[50];             // to store quantity of each item
float price[50];            // to store price of each item
char choice;              // to add more products or generate bill
int index = 0;            // used for arrays
int limit = 0;
string name;              // to input cashier name
string c_name;             // to input customer name
int total_quan = 0;


// Functions Declaration
void Displaybill();
void record();
void Calculations();
void  InputProducts();
void exit();


////////////                                            |\/| /_\  | |\ |                             //////////////////
/////////////                                           |  |/   \ | | \|                             //////////////////      

int main()
{
	system("CLS");
	system("color 1E");
	cout << "\n\n\tEnter cashier's name : ";
	getline(cin, name);

label:
	int pass;
	cout << "\n\n\tEnter password to get access: ";
	cin >> pass;
	cout << endl;

	if (pass == 786) {
		while (1)
		{


			system("CLS");
			system("color 6E");


			cout << "\n\n\t\t\t------------------------------";
			cout << "\n\t\t\tShop Billing Management System";
			cout << "\n\t\t\t------------------------------";
			cout << "\n\n\t\t\tWhat you want to do?";
			cout << "\n\t\t\t1.\tTo enter new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n";

			int option;
			cout << "\n\nEnter your option: ";
			cin >> option;

			switch (option)
			{
			case 1:

				InputProducts();
				cout << endl;
				cout << "Press any key to return to  main menu.....";
				_getch();
				break;
			case 2:

				record();
				cout << endl;
				cout << "Press any key to return to  main menu.....";
				_getch();
				break;
			case 3:
				exit();
				break;

			default:
				system("cls");
				cout << "\n\tChoose a valid opion!" << endl;
				cout << "\n\tPress any key to return to  main menu.....";
				_getch();
				break;
			}

		}

	}
	else {
		cout << "\t\t Incorrect Password!";
		goto label;
	}

	_getch();
	return 0;


}

void  InputProducts() {

	system("cls");
	cout << "Enter customer's name: ";
	cin >> c_name;
	cout << endl;
label:
	do {


		cout << "Enter name of product " << index + 1 << ": ";
		cin >> item[index];
		cout << "Enter quantity :";
		cin >> quan[index];
		cout << "Enter price of product " << index + 1 << ": ";
		cin >> price[index];

		sum[index] = quan[index] * price[index];        //calculating amount of each item
		total_quan += quan[index];                      //calculating total quantity

		cout << "\nPress Y to add another product    Press G to generate your receipt  ";
		cin >> choice;

		cout << endl;
		index++;
		limit++;                              //to restrict data to a limit when displaying
	} while (choice == 'Y' || choice == 'y');

	if (choice == 'G' || choice == 'g') {

		Displaybill();
		Calculations();
		index = 0;
		limit = 0;
	}

	else if (choice != 'G' || choice != 'g' && choice != 'Y' || choice != 'y')
	{
		cout << "Press a valid key!" << endl;
		cin >> choice;
		if (choice == 'G' || choice == 'g') {
			Displaybill();
			Calculations();
			index = 0;
			limit = 0;
		}
		else if (choice == 'Y' || choice == 'y')
			goto label;

	}
}

void Displaybill() {

	ofstream myFile("shopp bill.txt", ios::app);
	system("CLS");

	

	cout << "\t\t\t****************\n";
	cout << "\t\t\tSAR Grocery Shop\n";
	cout << "\t\t\t****************\n";

	myFile << "\t\t\t****************\n";
	myFile << "\t\t\tSAR Grocery Shop\n";
	myFile << "\t\t\t****************\n";

	cout << "Your Bill\n\n Customer: " << c_name << "\t\t\t\tCashier name : " << name << "\n" << endl;
	myFile << "Your Bill\n\n Customer: " << c_name << "\t\t\t\tCashier name : " << name << "\n" << endl;

	cout << "\t------------------------------------------------\n";
	cout << setw(5) << "\tName of Item\tQuantity\tPrice\tAmount\n";
	cout << "\t------------------------------------------------\n";

	myFile << "\t------------------------------------------------\n";
	myFile << setw(5) << "\tName of Item\tQuantity\tPrice\tAmount\n";
	myFile << "\t------------------------------------------------\n";


	for (int index = 0; index < limit; index++) {
		cout << "\t" << item[index] << "\t\t" << quan[index] << "\t\t" << price[index] << "\t" << sum[index] << '\n';

		myFile << "\t" << item[index] << "\t\t" << quan[index] << "\t\t" << price[index] << "\t" << sum[index] << '\n';
	}



}

void Calculations() {

	ofstream myFile("shopp bill.txt", ios::app);
	float cash = 0;
	int total = 0;
	for (int index = 0; index < limit; index++)
	{
		total += sum[index];
	}
	cout << "\n\t_________________________________________________";
	myFile << "\n\t_______________________________________________";
	cout << "\n\tTotal Quantity:" << total_quan << "\t\t   Total: " << total;
	myFile << "\n\tTotal Quantity:" << total_quan << "\t\t   Total: " << total;
	cout << "\n\t_________________________________________________";
	myFile << "\n\t_______________________________________________";
pay:

	cout << "\n\n\t\t\t*PAYMENT SUMMARY*\n";
	myFile << "\n\n\t\t\t**PAYMENT SUMMARY\n";
	cout << "\n\t\t\tTotal cash given: ";
	myFile << "\n\t\t\tTotal cash given: ";
	cin >> cash;
	myFile << cash;

	if (cash >= total) {
		cout << "\n\t\t\tBalance: " << cash - total << '\n';
		myFile << "\n\t\t\tBalance: " << cash - total << '\n';
	}
	else
	{
		cout << "\n\t\t\tCash given is less than total amount!!!";
		myFile << "\n\t\t\tCash given is less than total amount!!!";
		goto pay;
	}
	cout << "\n\n\t\t Thankyou for shopping with us " << endl;
	cout << "\n\tItems can be retuned or exchanged within 3 days" << endl;
}

void record() {

	system("CLS");
	ifstream myFile("shopp bill.txt");
	char ch[1000];

	if (!myFile) {
		cout << "File could not be opened";
		exit(0);
	}

	while (!myFile.eof()) {

		myFile.getline(ch, 1000);
		cout << ch << endl;


	}


}

void exit() {

	system("cls");

	cout << "\n\t\t\t*Program Terminated*\n" << endl;
	cout << "\tDeveloped by:\n\n\tRehan Jamil Satti\n\n\tMuhammad Ahmed Shahid\n\n\tMuhammad Sharjeel Shakeel\n\n\t\t\t Hope you like it.\n\n";
	exit(0);

}