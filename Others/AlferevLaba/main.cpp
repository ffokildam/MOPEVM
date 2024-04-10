#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "types.h"

using namespace std;

bool is_younger(const person& x, const person& y) { return x.surname < y.surname; }

int main(){
	vector<person> people;
	person temp;
	bool end_of_list;
	ifstream fin;
	string tmp;
	char dot;
	string nameS;
	int intS;
	int resCount=0;
	int dayS;
	int monthS;
	int yearS;
	long long int phonenumberS;
	fin.open("people.txt", ios_base::app);
	while(fin>>temp.name){
		fin>>temp.surname;
		fin>>temp.height;
		fin>>temp.weight;
		fin>>temp.birthdate.day>>dot>>temp.birthdate.month>>dot>>temp.birthdate.year;
		fin>>dot>>temp.phonenumber;
		fin>>temp.adress.street_name;
		fin>>temp.adress.house_num;
		temp.is_on_list = true;
		people.push_back(temp);
	}
	fin.close();
	while(true){
		cout<<"Choose what you want to do:"<<endl;
		cout<<"1 - Add new person to the list."<<endl;
		cout<<"2 - Output list of people to file."<<endl;
		cout<<"3 - Output list of people to console."<<endl;
		cout<<"4 - Find person in the list by parameter."<<endl;
		cout<<"5 - Sort people list."<<endl;
		cout<<"6 - Exit program."<<endl;
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
				temp.addPerson();
				people.push_back(temp);
				break;
			case 6:
				return 0;
				break;
			case 2:
				for (int i = 0; i < people.size(); i++)
				{
					if(people[i].is_on_list == false){
						people[i].showPerson();
						people[i].is_on_list = true;
					}
						
				}
				cout<<endl;
				cout<<"Successfully printed all info to output.txt"<<endl;
				cout<<endl;
				break;
			case 3:
				for (int i = 0; i < people.size(); i++)
					{
						cout<<"########\nPERSON "<<i+1<<"\n########\n";	
						people[i].showPersonConsole();
					}
				cout<<endl;
				break;
			case 5:
				sort(people.begin(),people.end(),is_younger);
				for (int i = 0; i < people.size(); i++)
				{
					people[i].is_on_list = false;
				}
				fin.open("people.txt", ios::out | ios::trunc);
				for (int i = 0; i < people.size(); i++)
				{
					people[i].showPerson();
					people[i].is_on_list = true;	
				}
				cout<<endl;
				cout<<"WARNING! File people.txt was automatically filled with sorted list of people."<<endl;
				cout<<endl;
				break;
			case 4:
				cout<<"Choose parameter to find person: "<<endl;
				cout<<"1 - Name"<<endl;
				cout<<"2 - Surname"<<endl;
				cout<<"3 - Height"<<endl;
				cout<<"4 - Weight"<<endl;
				cout<<"5 - Date"<<endl;
				cout<<"6 - Phone number"<<endl;
				cout<<"7 - Adress"<<endl;
				int choiceSearch;
				cin>>choiceSearch;
				switch (choiceSearch){
					case 1:
						resCount=0;
						cout<<"Enter name: "<<endl;
						cin>>nameS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(iequals(nameS,people[i].name)){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
					case 2:
						resCount=0;
						cout<<"Enter surname: "<<endl;
						cin>>nameS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(iequals(nameS,people[i].surname)){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
					case 3:
						resCount = 0;
						cout<<"Enter height: "<<endl;
						cin>>intS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(intS == people[i].height){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
					case 4:
						resCount = 0;
						cout<<"Enter weight: "<<endl;
						cin>>intS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(intS == people[i].weight){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
					case 5:
						resCount=0;
						cout<<"Enter date(Format DD.MM.YY)"<<endl;
						cin>>dayS>>dot>>monthS>>dot>>yearS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(dayS == people[i].birthdate.day && monthS == people[i].birthdate.month && yearS == people[i].birthdate.year){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
					case 6:
						resCount = 0;
						cout<<"Enter phone number(without +)"<<endl;
						cin>>phonenumberS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(phonenumberS == people[i].phonenumber){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
					case 7:
						resCount = 0;
						cout<<"Enter adress(Format Street Housenumber)"<<endl;
						cin>>nameS>>intS;
						cout<<endl;
						for (int i = 0; i < people.size(); i++)
						{
							if(nameS == people[i].adress.street_name && intS == people[i].adress.house_num){
								resCount++;
								cout<<"Found result: #"<<resCount<<endl;
								people[i].showPersonConsole();
								cout<<endl;
							}
						}
						break;
				}
				cout<<endl;
				cout<<"Total results: "<<resCount<<endl;
				cout<<endl;				
		}
		choice = 0;
	}
}
