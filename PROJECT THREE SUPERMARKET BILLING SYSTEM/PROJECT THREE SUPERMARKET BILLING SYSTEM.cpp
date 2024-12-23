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
			cout << "\t\t\tEnter your password correctly: ";
			cin >> password;

			if (email == "khalfan" && password == "cpj") {
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
	int token = 0;

	cout << "\n\t\t\t_________ADD PRODUCT_________";
	cout << "\n\t\t\tEnter product's code: ";
	cin >> pcode;
	cout << "\n\t\t\tEnter product's name: ";
	cin >> pname;
	cout << "\n\t\t\tEnter product's price: ";
	cin >> price;
	cout << "\n\t\t\tEnter product's discount: ";
	cin >> dis;

	data.open("database.txt", ios::in);
	if (!data) {
		// If file doesn't exist, create it and write the product
		data.open("database.txt", ios::app | ios::out);
		data << pcode << " " << pname << " " << price << " " << dis << " " <<"\n";
		data.close();
	}
	else {
		// Check for duplicate product
		int c;
		string n;
		int p;
		float d;

		while (data >> c >> n >> p >> d) {
			if (c == pcode) {
				token = 1;  // Product already exists
				break;
			}
		}
		data.close();

		if (token == 1) {
			cout << "\n\t\t\tProduct with this code already exists! Please enter a different code.\n";	
		}
		else {
			// Append the new product if it's not a duplicate
			data.open("database.txt", ios::app | ios::out);
			data << pcode << " " << pname << " " << price << " " << dis << "\n";
			data.close();
			cout << "\n\t\t\tRecord successfully added!";
		}
	}
}

void shopping::edit() {
	fstream data, data1;
	int pkey;
	int c;
	string n;
	float p, d;
	int token = 0;

	cout << "\n\t\t\t Record modification system \t\t\t";
	cout << "\n\t\t\tEnter the product code of the product you want to change: ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\n\t\t\t No data found!";
	}
	else {
		data1.open("database1.txt", ios::out);  // Open the temporary file in write mode

		// Read the data from the file
		while (data >> pcode >> pname >> price >> dis) {
			if (pkey == pcode) {
				// Product found, modify it
				cout << "Enter new product code: ";
				cin >> c;
				cout << "Enter new product name: ";
				cin >> n;
				cout << "Enter new product price: ";
				cin >> p;
				cout << "Enter the new product's discount: ";
				cin >> d;

				// Write the modified product to data1
				data1 << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Congrats, product edited successfully!";
				token++;
			}
			else {
				// Write the existing product to data1 without modification
				data1 << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
		}

		data.close();
		data1.close();

		// If no product was found, show an error message
		if (token == 0) {
			cout << "\n\n\t\tOoops, record not found!";
		}
		else {
			// Remove the old database and rename the temporary file
			remove("database.txt");
			rename("database1.txt", "database.txt");
		}
	}
}

void shopping::rem() {
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\n\t\t\t Record modificaton system \t\t\t";
	cout << "\n\n\t\t Enter the product code of the product you want to delete: ";
	cin >> pkey;
	data.open("database.txt", ios::in);

	if (!data) {
		cout << "\n\n\n\t\t\t Ooops, File does't exist";
	}

	else {
		data1.open("database1.txt", ios::app | ios::in);
		data >> pcode >> pname >> price >> dis;

		while (!data.eof()) {
			if (pcode == pkey) {
				cout << "\n\n\t\t\t Product deleted successfully";
				token++;
			}
			else {
				data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0) {
			cout << "\n\n\t\t\t Ooops, record not found!";
		}
	}
}

void shopping::list() {
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\t\t\t\n\t\tProduct code\t\tName\t\tPrice\n";
	data >> pcode >> pname >> price >> dis;

	while (!data.eof()) {
		cout << "\n\t\t\t" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void shopping::receipt() {
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float ammount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t	RECEIPT";
	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\n Empty database!";
	}

	else {
		data.close();

		list();
		cout << "\n\n|        Please place the oder           |";


		do {
			m:
			cout << "\n\nEnter Product code: ";
			cin >> arrc[c];
			cout << "\n\nEnter the product quantity: ";
			cin >> arrq[c];
			for (int i = 0;i < c;i++)
			{
				if (arrc[c] == arrc[i]) {
					cout << "\n\n Duplicate product code, please try again";
					goto m;
				}
			}
			c++;
			cout << "\n\nDo you want to buy another product? if yes press 'y' if no press 'n' ";
			cin >> choice;
		} 
		while (choice == 'y');

		cout << "\n\n\t\t\t|__________________RECEIPT____________________|";
		cout << "\nProduct No\tProduct name\tProduct quantity\tPrice\tAmmount\tAmmount with disccount\n";

		for (int i = 0;i < c;i++) {
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis; 
			while (!data.eof()) {

				if (pcode == arrc[i]) {
					ammount = price * arrq[i];
					dis = ammount - (ammount * dis / 100);
					total = total + dis;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t\t" << arrq[i] << "\t\t" << price << "\t" << ammount << "\t\t" << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
		}
		data.close();
	}
	cout << "\n\n______________________________________________";
	cout << "\n TOTAL AMMOUNT : " << total;
}

int main(){
	shopping s;
	s.menu();
}
