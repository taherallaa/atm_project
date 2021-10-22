#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Atm {
private:
	long int account_no;
	string name;
	int pin;
	double balance;
	string mobile_no;
public:
	void setdata(long int  account_no_a, string name_a, int pin_a, double balance_a, string mobile_no_a) {
		account_no = account_no_a;
		name = name_a;
		pin = pin_a;
		balance = balance_a;
		mobile_no = mobile_no_a;
	}
	
	long int getAccountNO() {
		return account_no;
	}
	string getName() {
		return	name;
	}
	int getPin() {
		return pin;
	}
	double getBalance() {
		return balance;
	}
	string getMobileNO() {
		return mobile_no;
	}

	void setMobileNo(string mob_prev, string mob_new) {
		if (mob_prev == mobile_no)
		{
			mobile_no = mob_new;
			cout << "Successfully Updated Mobile number.";
			_getch();
		}
		else {
			cout << "Incorrect !!! Old Mobile no";
			_getch();
		}
	}

	void cashWithDraw(int amount_a) {
		if (amount_a > 0 && amount_a < balance)
		{
			balance -= amount_a;
			cout << endl << "Please Collect Your Cash";
			cout << endl << "Available Balance: " << balance;
			_getch();
		}else{
			cout << endl << "Invalid Input or Insufficient Balance";
			_getch();
		}
	}
};

int main()
{
	int choice = 0, enterPIN;
	long int enterAccountNo;
	system("cls");

	// create user(object)
	Atm user1;
	user1.setdata(10, "taher", 123, 45000.0, "01152914475");

	do 
	{
		system("cls");
		cout << endl << "\t*******Welcome to you in Bank El_ahaly*******";
		cout << endl << endl <<"Enter Your Account Number: ";
		cin >> enterAccountNo;

		cout << endl << "enter your Pin: ";
		cin >> enterPIN;

		if (enterAccountNo == user1.getAccountNO() && enterPIN == user1.getPin())
		{
			do 
			{
				int amount = 0;
				string oldMobileNo, newMobileNo;
				system("cls");
				cout << endl << "\t Welcome to you in Bank El_ahaly.";
				cout << endl << endl << "Select your Options";
				cout << endl << endl << "1.Check Balance.";
				cout << endl << "2.Cash Withdraw.";
				cout << endl << "3.Show User Details.";
				cout << endl << "4.Update Your Mobile Number.";
				cout << endl << "5.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << endl << "Your Balance is " << user1.getBalance();
					_getch();
					break;
				case 2:
					cout << endl << "Enter the mount that you want to withdraw it ";
					cin >> amount;
					user1.cashWithDraw(amount);
					break;
				case 3:
					cout << endl << "your Details about your account are:-";
					cout << endl << "-> Account number is " << user1.getAccountNO();
					cout << endl << "-> The Name is " << user1.getName();
					cout << endl << "-> the Balance is " << user1.getBalance();
					cout << endl << "-> The Mobile Number is  " << user1.getMobileNO();

					_getch();
					break;
				case 4:
					cout << "Enter Your Old Mobile Number: ";
					cin >> oldMobileNo;
					cout << "Enter Your New Mobile Number: ";
					cin >> newMobileNo;

					user1.setMobileNo(oldMobileNo, newMobileNo);
						_getch();
						break;
				case 5:
					exit(0);

				default:
					cout << endl << "Please Enter Valid Number !!!";
				}
			} while (1);
		}else{
			cout << endl << "User Details are Invalid";
			_getch();
		}

	} while (1);

	return 0;
}