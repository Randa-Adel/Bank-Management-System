#include<iostream>
#include<string>
using namespace std;
struct account
{
	int account_no;
	string account_name;
	char type;
	int intial_amount;
};
account BankAccount[100];
int menu();
void new_account();
void deposit_amount();
void withdraw_amount();
void balance_enquiry();
void all_account_holder_list();
void close_an_account();
void modify_account();
int exit();
void switching(int);


int main()
{
	for (size_t i = 0; i < 100; i++)
	{
			BankAccount[i].account_name = "";
			BankAccount[i].account_no = 0;
			BankAccount[i].intial_amount = 0;
			BankAccount[i].type = ' ';	
	}	
	switching(menu());
	system("pause");
	return 0;
}
void switching(int option)
{
	switch (option)
	{
	case 1:new_account();
		break;
	case 2:deposit_amount();
		break;
	case 3:withdraw_amount();
		break;
	case 4:balance_enquiry();
		break;
	case 5:all_account_holder_list();
		break;
	case 6: close_an_account();
		break;
	case 7:modify_account();
		break;
	case 8:exit();
		break;
	default:
		break;
	}
}
int menu()
{
	int option;
	cout << "01. New Account" << endl;
	cout << "02. Deposit Amount" << endl;
	cout << "03. Withdraw Amount" << endl;
	cout << "04. Balance Enquiry" << endl;
	cout << "05. All Account Holder List" << endl;
	cout << "06. Close An Account" << endl;
	cout << "07. Modify Account" << endl;
	cout << "08. Exit" << endl;
	cout << "Select Your Option (1-8) : ";
	cin >> option;
	return option;
}
void new_account()
{
	int temp;
	string xx;
	cout << "Enter The Account No. : ";
	cin >> temp;
	if (BankAccount[temp].account_no != 0 )
	{
		cout << "This Account Is Reversed " << endl;
		cout << "Please, Enter Another Number ! : ";
		cin >> temp;
			
	}
	else{ BankAccount[temp].account_no = temp; }
	cout << "Enter The Name Of Account Holder : ";
	std::cin.ignore();
    std::getline(std::cin, BankAccount[temp].account_name);
	cout << "Enter The Type Of The Account (c/s) : ";
	cin >> BankAccount[temp].type;
	cout << "Enter The Initial Amount (>=500 For Saving >=1000 For Current ) : ";
	cin >> BankAccount[temp].intial_amount;
	if ((BankAccount[temp].type == 'c' && BankAccount[temp].intial_amount < 1000))
	{
		cout << "can't complite ,Please enter more than 1000 !" << endl;
		cin >> BankAccount[temp].intial_amount;
	}
	else if ((BankAccount[temp].type == 's'&&BankAccount[temp].intial_amount < 500))
	{
		cout << "can't complite ,Please enter more than 500 !" << endl;
		cin >> BankAccount[temp].intial_amount;
	}
	cout << "Account Created..." << endl;
	
	std::cin.ignore();
	std::getline(std::cin,xx);
	system("cls");
	switching(menu());
}
void deposit_amount()
{
	string xx;
	int x;
	int increased_amount;
	cout << "Enter The Account No. : ";
	cin >> x;
	for (size_t i = 0; i < 100; i++)
	{
		if (x == BankAccount[i].account_no)
		{
			cout << "Account Number : ";
			cout << BankAccount[i].account_no << endl;
			cout << "Account Holder Name : ";
			cout << BankAccount[i].account_name << endl;
			cout << "Type Of Account : ";
			cout << BankAccount[i].type << endl;
			cout << "Balance Amount : ";
			cout << BankAccount[i].intial_amount << endl;
			cout << "\t\tTo Deposit Amount\t\t" << endl;
			cout << "Enter the Amount To Be Deposited" << endl;
			cin >> increased_amount;
			BankAccount[i].intial_amount += increased_amount;
			cout << "\t\t Record Updated \t\t" << endl;
		}
	}

	std::cin.ignore();
	std::getline(std::cin, xx);
	system("cls");
	switching(menu());
}
void withdraw_amount()
{
	string xx;
	int x;
	int decreased_amount;
	cout << "Enter The Account No. : ";
	cin >> x;
	for (size_t i = 0; i < 100; i++)
	{
		if (x == BankAccount[i].account_no)
		{
			cout << "Account Number : ";
			cout << BankAccount[i].account_no << endl;
			cout << "Account Holder Name : ";
			cout << BankAccount[i].account_name << endl;
			cout << "Type Of Account : ";
			cout << BankAccount[i].type << endl;
			cout << "Balance Amount : ";
			cout << BankAccount[i].intial_amount << endl;
			cout << "\t\tTo withdraw Amount\t\t" << endl;
			cout << "Enter the Amount To Be withdrawed" << endl;
			cin >> decreased_amount;
			BankAccount[i].intial_amount -= decreased_amount;
			cout << "\t\t Record Updated \t\t" << endl;
		}
	}
	std::cin.ignore();
	std::getline(std::cin, xx);
	system("cls");
	switching(menu());
}
void balance_enquiry()
{
	string xx;
	int x;
	cout << "Enter The Account No. : ";
	cin >> x;
	for (size_t i = 0; i < 100; i++)
	{
		if (x == BankAccount[i].account_no)
		{
			cout << "Account Number : ";
			cout << BankAccount[i].account_no << endl;
			cout << "Account Holder Name : ";
			cout << BankAccount[i].account_name << endl;
			cout << "Type Of Account : ";
			cout << BankAccount[i].type << endl;
			cout << "Balance Amount : ";
			cout << BankAccount[i].intial_amount << endl;
			break;
		}
	}
	std::cin.ignore();
	std::getline(std::cin, xx);
	system("cls");
	switching(menu());
}
void all_account_holder_list()
{
	string xx;
	cout << "\t\t Account Holder List \t\t\t\t" << endl << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "A/C no.\t\t Name \t\t Type \t\t Balance " << endl;
	cout << "-------------------------------------------------------" << endl;
	for (size_t i = 0; i < 100; i++)
	{
		if (BankAccount[i].account_no != 0)
		{
			cout << BankAccount[i].account_no << "\t\t" << BankAccount[i].account_name << "\t\t" << BankAccount[i].type << "\t\t" << BankAccount[i].intial_amount << endl;
			cout << "-------------------------------------------------------" << endl;
		}
	}
	std::cin.ignore();
	std::getline(std::cin, xx);
	system("cls");
	switching(menu());
}
void close_an_account()
{
	string xx;
	int x;
	int i = 0;
	cout << "Enter The Account No. : ";
	cin >> x;
	for (i = 0; i < 100; i++)
	{
		if (x == BankAccount[i].account_no)
		{
			BankAccount[i].account_name = "";
			BankAccount[i].account_no=0;
			BankAccount[i].intial_amount = 0;
			BankAccount[i].type = ' ';
			break;
		}
	}
	cout << "Account Deleted !" << endl;
	std::cin.ignore();
	std::getline(std::cin, xx);
	system("cls");
	switching(menu());
}

void modify_account()
{
	string xx;
	int x;
	int i = 0;
	cout << "Enter The Account No. : ";
	cin >> x;
	for (i = 0; i < 100; i++)
	{
		if (x == BankAccount[i].account_no)
		{
			cout << "Account Number : ";
			cout << BankAccount[i].account_no << endl;
			cout << "Account Holder Name : ";
			cout << BankAccount[i].account_name << endl;
			cout << "Type Of Account : ";
			cout << BankAccount[i].type << endl;
			cout << "Balance Amount : ";
			cout << BankAccount[i].intial_amount << endl;
			break;
		}
	}
	cout << "Enter The New Details Of The Account  " << endl;
	
	cout << "Modify The Account Name : ";
	std::cin.ignore();
	std::getline(std::cin, BankAccount[i].account_name);
	cout << "Modify The Type Of The Account : ";
	cin >> BankAccount[i].type;
	cout << "Modify The Balance : ";
	cin >> BankAccount[i].intial_amount;
	cout << "\t\tRecord Updated\t\t : ";
	std::cin.ignore();
	std::getline(std::cin, xx);
	system("cls");
	switching(menu());

}
int exit()
{
	return 0;
}