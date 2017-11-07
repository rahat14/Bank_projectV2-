#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib> //for c_str() function that used in copy function
#include<sstream>
#include<time.h>//for automatic date


using namespace std;

void temp_file_clear();//for clearing temp file
void copy_content(string a,string b); //global declaration
void number_system_put(int n1);//
int number_system_get();//account number automation//for calculating year
void user_menu(int);
void clrscr();
void clrscr()
    {
    cout << string( 100, '\n' );
    }
class user
{
	public:

	char fname[10],lname[10];
	string phone;
	string dob;

		user()
		{
			phone = '\0';
			dob = '\0';
		}

};


class Account : public user
{
	int accountNumber ;
	int passcode ;
	int balance;
	public:
	Account()
	{
		accountNumber = 0;
		balance = 0;
		passcode = 0;
	}
	void CurrentBalance(int);	//bal chack
	void createAccount(); 		//function for openning new account
	void showDetails();
    void update_details(int);
	void login_user(int,int);
	void add(int,int);          //Add Money
	void deduct(int,int);	 	//Deduct Money
	void searchDetails(int);
	void fund_tr(int);
    };
   void Account  :: login_user(int user, int pass)
{
	int flag = 0;

	//getting data from file
	ifstream file_read("cus_details.txt" ,ios::in);
	while(!file_read.eof())
	{

		file_read >> fname;
		file_read >>lname;
		file_read >>phone;
		file_read >>dob;
		file_read >>accountNumber;
		file_read >>passcode;
		file_read >>balance;
		if(file_read.eof())
		{
			break;
		}
		if(user == accountNumber && pass == passcode)
		{
		   cin.clear();
			cout<<"\n Login sucessful !"<<endl;

			user_menu(user);

		}
		else if(user != accountNumber || pass != passcode)
		cout<<"\n User name & Passcode Not matched !"<<endl;

	}

	if(flag == 0 )
	{
		cout<<"\n User name & Passcode Not matched !"<<endl;

	}
	file_read.close();

}

void Account :: createAccount()
{

	cout << "\n\tEnter your First name :";
	cin >>fname;
	cin.clear();

	cout << "\n\tEnter Last name :";
	cin >>lname;
	cin.clear();

	string temp_phone;
	cout << "\n\tEnter phone number :";
	cin >>temp_phone;
	cin.clear();
	if(temp_phone.length()==11)
	{
		phone = temp_phone;

	}
	else
	{

		while(temp_phone.length() != 11)
		{
			cout<<"phone number must be 11 digit\n";
			cout<<"\n input chone number:";
			cin >> temp_phone;
			phone = temp_phone;
		}
	}



	cout << "\n\tEnter Date of Birth :";
	cin >>dob;
	cin.ignore();
	accountNumber = number_system_get();

	cout << "\n\t Your Account Number :"<<accountNumber;

	cout << "\n\t Enter 4 digit Passcode ::";
	cin >> passcode;

	cout <<"\n\t Enter Primary Balance :";
	cin >>balance;

	ofstream file("cus_details.txt",ios::out | ios :: app);
	file << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;

	number_system_put(accountNumber);
	file.close();
}
void Account :: update_details(int user_no) {

	int ch;
	char buff;
	int flag = 0;
	string a = "cus_details.txt";
	string b = "temp.txt";
    Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);

	while(!file_read.eof())
	{

	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>dob;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber){

			cout <<"\n\tAccount Number is : "<<accountNumber;
			cout <<"\n\tFill up Details with new records :\n";

			cout<<"\n\n\t New First name:";

			cin >>fname;
			cin.clear();

			cout <<"\n\t New Last name:";
			cin >> lname;
			cin.clear();

			cout <<"\n\t New  phone:";
			string temp_phone;
			cin>>temp_phone;
	     while(temp_phone.length() != 11)
		{
			cout<<"phone number must be 11 digit\n";
			cout<<"\n input phone number:";
			cin >> temp_phone;
			phone = temp_phone;
		}



			cin.clear();

			cout <<"\n\t New Dob";
			cin >> dob;
			cin.clear();
			cout<<"\n\t Enter your 4 digit password ";
			cin>>passcode;
			cin.clear();
	file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
			flag  = 1;
	}
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}

	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b,a);

	cout<<"\n\t Done ! Details Updated THank You.\n";
	temp_file_clear();

}
void Account :: CurrentBalance(int user_no)
{
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	while(file_read)
	{

	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>dob;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber)
	{

		cout<<"\n\tCurrent Balance           :"<<balance<<"/-TK.";
		cout<<"\n\n\n";
	}


	}

	file_read.close();
}
void Account :: searchDetails(int user_no) //user_no for user session for only specified user can show
{
	int ch;
	int flag = 0;
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	//cout <<"\n\tEnter account  number:";
	//cin >>ch;
	//cin.clear();

	while(file_read)
	{

	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>dob;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber)
	{
		cout<<"\n\tAccount Number is :"<<accountNumber;
		cout<<"\n\tName              :"<<fname<<" "<<lname;
		cout<<"\n\tPhone             :"<<phone;
		cout<<"\n\tDate of birth     :"<<dob;
		cout<<"\n\tBalance           :"<<balance<<"/-TK.";
		cout<<"\n\n\n";
		flag  = 1;
	}


	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_read.close();

}
void Account :: add(int user_no,int amt)
{
	string a = "cus_details.txt";
	string b = "temp.txt";
	char tr_date[9];

	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	while(!file_read.eof())
	{

	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>dob;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber)
	{
			balance = balance + amt;

			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;


	}
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}

	}

	file_temp.close();
	file_read.close();
	copy_content(b,a);
	cout<<"\n\t Done ! Amount Added\n";
	temp_file_clear();

}
void Account :: deduct(int user_no,int amt)
{
	string a = "cus_details.txt";
	string b = "temp.txt";

	int flag = 0;
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	while(!file_read.eof())
	{

	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>dob;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber)
	{
			if(balance != 0 && balance > amt)
			{

				balance = balance - amt;

				file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "
					<<accountNumber<<" "<<passcode<<" "<<balance<<endl;

				flag = 1;
			}
			else
			{

				cout<<"\nyour transection can not be completed balance is Zero or Less than withdrawal amount\n! ";
				file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
			}
	}

	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}

	}

	file_temp.close();
	file_read.close();
	copy_content(b,a);
	if(flag == 1)
	{
		cout<<"\n\t Done ! Amount Deducted\n";

	}

	temp_file_clear();

}
void Account::fund_tr(int user_no)
{
	int user2_no ,amt =0,flag = 0;
	char ans;

	cout <<"\nEnter Reciever   Account Number: ";
	cin >> user2_no;

	cout <<"\nEnter Amount : ";
	cin >> amt;

	string a = "cus_details.txt";
	string b = "temp.txt";

	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	while(!file_read.eof())
	{

	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>dob;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user2_no == accountNumber)
	{
		cout << "\nAccount Holder's name :"<<fname<< " "<<lname<<endl;
		cout<<"enter(Y/N): ";
		cin >>ans;

		if(ans == 'n')
		{
			flag = 1;
			break;
		}


			balance = balance + amt;

			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;


	}
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<dob<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}

	}

	if(flag == 1)
	{
		cout <<"\n NO Account Found";
	}
	file_temp.close();
	file_read.close();
	copy_content(b,a);
	cout<<"\n\t Done ! Amount Added\n";
	temp_file_clear();

	//now time for deducting amount from main user
	deduct(user_no,amt);
	cout << "\n Money Successfully Transferd !";
}
void copy_content(string a,string b)
{
		char ch;
		int flag = 0;
	ifstream temp_read(a.c_str(),ios :: in);
	ofstream file_write(b.c_str(),ios::out);
	while(!temp_read.eof())
	{
		temp_read.get(ch);
		file_write.put(ch);
		flag = 1;
	}
	if(flag != 1)
	{
		cout <<"\n\tFile Error !";
	}

}
int number_system_get()
{
	int number;
	ifstream number_read("number.txt",ios::in);
	number_read >>number;
	return number;
}

void number_system_put(int n1)
{
	n1 = n1+1;
	ofstream number_write("number.txt",ios::out);
	number_write <<n1;
}
void temp_file_clear()
{

	char ch;
	int flag = 0;
	ofstream temp_write("temp.txt",ios :: out);

	temp_write <<" ";
	temp_write.close();

}
void user_menu(int user_sesstion)
{
	int ch;
	int amount = 0;
	Account a;

	start:do{
	cin.clear();

		cout<<"\tWelcome Sir your account number is>>>>>>  "<<user_sesstion<<endl;
		cout<<"\n\t 1.View Your Account.";
		cout<<"\n\t 2.Update Your Details.";
		cout<<"\n\t 3.Transfer Fund.";
		cout<<"\n\t 4.Withdrawal.";
		cout<<"\n\t 5.Add Money.";
		cout<<"\n\t 0.Exit";

		cout<<"\n\t Enter your Choice (1-5)::";
	if(cin >> ch)
	{


		switch (ch)
		{
			case 1:
				system("cls");
				a.searchDetails(user_sesstion);
				break;

			case 2:
				system("cls");
				a.update_details(user_sesstion);
				break;

			case 3:
				system("cls");
				a.fund_tr(user_sesstion);
				break;

			case 4:
				cout<<"\n\tEnter Amount to withdraw :";
				cin >> amount;

				a.deduct(user_sesstion,amount);
				break;

			case 5:
				cout<<"\n\tEnter Amount to Add :=";
				cin >> amount;
				a.add(user_sesstion,amount);
				a.CurrentBalance(user_sesstion);
				break;
             default :
				cout<<"\n\t Worng choise \n";
				break;
		}
	}
		else
		{
			cout<<"\n\t Input only Digits please !";
			getch();
			cin.clear();
		 	cin.ignore();
			ch = 15;
		}


	}while(ch != 0);

}
int main()
{
	int ch;
	int login_state = 0;
	int user;
	int pass;
	Account a;

	do{
		//system("clear");
		system("cls");

		cout<<"\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
		cout<<"\n\t\t| Bank management System      		  |"<<endl;
		cout<<""<<endl;
		cout<<"\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;

		cout <<"\n\t 1.Login To your Account.";
		cout <<"\n\t 2.Open An Account.";
		cout <<"\n\t 0.Exit";

		cout<<"\n\n\tEnter your choice ::";
		if(cin >> ch )
		{
			switch (ch)
			{
				case 1:
					cout << "\n\t Enter Account Number:";
					cin >>user;
					cout <<"\n\t Enter 4-digit passcode :";
					cin >>pass;
					a.login_user(user,pass);
					cout<<"\n\t\twork in progress";

				break;
				case 2:
					a.createAccount();
					break;

				getch();
					break;

			}
		}
		else
		{
			cout<<"\n\t Input only Digits please ! Press Enter To continue";
			getch();
			cin.clear();
		}



	}while(ch !=0);
//	user_menu();
	return 0;
}



