#include <iostream>
#include <fstream>

using namespace std;

class shopping {
private:
	int pcode;
	int price;
	float dis;
	string pname;

public:
	void menu();
	void admininstrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
};

void shopping::menu() {
	while (true) { // Replaces the 'goto m;'
		int choice;
		string email;
		string password;

		cout << "\t\t\t\t\t_________________________________\n";
		cout << "\t\t\t\t\t                                 \n";
		cout << "\t\t\t\t\t      SUPERMARKET MAIN MENU      \n";
		cout << "\t\t\t\t\t                                 \n";
		cout << "\t\t\t\t\t_________________________________\n";
		cout << "\t\t\t\t\t                                 \n";
		cout << "\t\t\t\t\t      1 ) ADMINISTRATOR          \n";
		cout << "\t\t\t\t\t                                 \n";
		cout << "\t\t\t\t\t      2 ) BUYER		            \n";
		cout << "\t\t\t\t\t                                 \n";
		cout << "\t\t\t\t\t      3 ) EXIT		            \n";
		cout << "Please make your choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\t\t\t Please login to continue \n";
			cout << "\t\t\t Enter your email: ";
			cin >> email;
			cout << "Enter your password correctly: ";
			cin >> password;

			if (email == "khalfankhalifa544@gmail.com" && password == "cpjsolutons") {
				admininstrator();
			}
			else {
				cout << "Invalid username or password\n";
			}
			break;

		case 2:
			buyer();
			break;

		case 3:
			exit(0);

		default:
			cout << "Please select from the given choices\n";
		}
	}
}

void shopping::admininstrator() {
	while (true) { // Replaces the 'goto m;'
		int choice;
		cout << "\n\n\n\t\t\t ADMINISTRATOR'S MENU \t\t\t";
		cout << "\n\t\t\t| 1)____Add product________|";
		cout << "\n\t\t\t|                          |";
		cout << "\n\t\t\t| 2)____Modify product_____|";
		cout << "\n\t\t\t|                          |";
		cout << "\n\t\t\t| 3)____Delete product_____|";
		cout << "\n\t\t\t|                          |";
		cout << "\n\t\t\t| 4)____Back to main menu__|";
		cout << "\n\n Please enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			add();
			break;

		case 2:
			edit();
			break;

		case 3:
			rem();
			break;

		case 4:
			return; // Exit to the main menu or else calling the main() function would do the same

		default:
			cout << "Invalid choice\n";
		}
	}
}

void shopping::buyer() {
	while (true) { // Replaces the 'goto m;'
		int choice;
		cout << "\n\n\n\t\t\t       BUYER'S MENU    \t\t\t";
		cout << "\n\t\t\t| 1)________Buy product_________|";
		cout << "\n\t\t\t|                               |";
		cout << "\n\t\t\t| 2)____Back to main menu_______|";
		cout << "\n\n Please enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			receipt();
			break;

		case 2:
			return; // Exit to the main menu

		default:
			cout << "Invalid choice!\n";
		}
	}
}

void shopping::add() {
	fstream data;
	int c;
	int token = 0;
	float d;
	float p;
	string n;

	cout << "\n\n\t\t\t ADD A PRODUCT ";
	cout << "\n\n\t\t Enter product code: ";
	cin >> pcode;
	cout << "\n\n\t\t Enter the product name: ";
	cin >> pname;
	cout << "\n\n\t\t Enter the product price: ";
	cin >> price;
	cout << "\n\n\t\t Enter the product discount: ";
	cin >> dis;

	data.open("database.txt", ios::in);

	if (!data) {
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else {
		data >> c >> n >> p >> d;
	}
}
