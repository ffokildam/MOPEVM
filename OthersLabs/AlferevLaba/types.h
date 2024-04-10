#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct date{
	int year;
	int month;
	int day;
};
struct adress{
	string street_name;
	int house_num;
};

struct person{
	int uid;
    date birthdate;
	adress adress;
	long long int phonenumber;
	string name;
	string surname;
	char sex;
	short int height;
	short int weight;
	bool is_on_list;
	void addPerson(){
		char dot;
		cout<<"Input name: ";
		cin>>name;
		cout<<"Input surname: ";
		cin>>surname;
		cout<<"Input height: ";
		cin>>height;
		cout<<"Input weight: ";
		cin>>weight;
		cout<<"Input date in format DD.MM.YY: ";
		cin>>birthdate.day>>dot>>birthdate.month>>dot>>birthdate.year;
		cout<<"Input phone number: ";
		cin>>phonenumber;
		cout<<"Input adress in format Street Housenumber: ";
		cin>>adress.street_name>>adress.house_num;
		cout<<endl;
		cout<<"Successfully added new person!"<<endl;
		cout<<endl;
	}
	void showPerson(){
		ofstream fout;
  		fout.open("people.txt", ios_base::app); 
		fout<<name<<endl;
		fout<<surname<<endl;
		fout<<height<<endl;
		fout<<weight<<endl;
		fout<<birthdate.day<<'.'<<birthdate.month<<'.'<<birthdate.year<<endl;
		fout<<'+'<<phonenumber<<endl;
		fout<<adress.street_name<<endl<<adress.house_num<<endl;
		fout.close();
	}
	void scan_f(bool &end_of_list){
		ifstream fin;
		fin.open("people.txt", ios_base::app);
		char dot;
		string temp;
		fin>>name;
		fin>>surname;
		fin>>height;
		fin>>weight;
		fin>>birthdate.day>>dot>>birthdate.month>>dot>>birthdate.year;
		fin>>phonenumber;
		fin>>adress.street_name>>adress.house_num;
		fin.ignore(1000,'\n');
		if(name==""){
			end_of_list=true;
		}
		
	}
	void showPersonConsole(){
		cout<<"Name: ";
		cout<<name<<endl;
		cout<<"Surname: ";
		cout<<surname<<endl;
		cout<<"Height: ";
		cout<<height<<endl;
		cout<<"Weight: ";
		cout<<weight<<endl;
		cout<<"B-day: ";
		cout<<birthdate.day<<'.'<<birthdate.month<<'.'<<birthdate.year<<endl;
		cout<<"Phone number: ";
		cout<<'+'<<phonenumber<<endl;
		cout<<"Home adress: ";
		cout<<adress.street_name<<","<<adress.house_num<<endl;
	}
};

bool ichar_equals(char a, char b)
{
    return tolower(static_cast<unsigned char>(a)) ==
           tolower(static_cast<unsigned char>(b));
}

bool iequals(const string& a, const string& b)
{
    return equal(a.begin(), a.end(), b.begin(), b.end(), ichar_equals);
}