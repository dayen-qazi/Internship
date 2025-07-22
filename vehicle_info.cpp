#include<iostream>
#include<vector>
using namespace std;

static int count = 0;

class Vehicle{
	string company;
	int model;
	int year;
	
	public:
	Vehicle(){
		company = "NULL";
		model = 0;
		year = 0;
		count = 0;
 	}
 	
 	Vehicle(string c , int m , int y){
 		company =  c;
 		model = m;
 		year = y;
	 }
	 
	 ~Vehicle(){

	 }
	 
	 void displayInfo(){
	 	cout<<"Company : "<<company<<endl;
	 	cout<<"  Model : "<<model<<endl;
	 	cout<<"  Year : "<<year<<endl;
	 	cout<<endl;
	 }
};

int menu(){
	int choice = -1;
	while(!(choice <= 4 && choice >0)){
		cout<<"1. Add Vehicle "<<endl;
		cout<<"2. Show Vehicle Details "<<endl;
		cout<<"3. Show Vehicle Count "<<endl;
		cout<<"4. Exit "<<endl;
		cout<<"Enter choice : ";
		cin>>choice;
		if(choice <= 0 || choice > 4){
			cout<<"Invalid Input ! Enter Again "<<endl;
		}
	}
	return choice;
}

int main(){
	   vector <Vehicle> vehicles;
	   int choice = -1;
	   int ret = 0;
	   while(choice != 4){
	   	choice = menu();
	   	
	   	if(choice == 1){
	   		string company;
	   		int model;
	   		int year;
	   		cout<<"Enter company : ";
	   		cin>>company;
	   		cout<<"Enter model : ";
	   		cin>>model;
	   		cout<<"Enter Year : ";
	   		cin>>year;
	   		Vehicle v1(company,model,year);
	   		vehicles.push_back(v1);
	   		cout<<"Vehicle added successfully ! "<<endl;
	   		count++;
	   		cout<<"Enter any number to return to main menu : ";
	   		cin>>ret;
		   }
		   
		if(choice == 2){
			for(int i = 0 ; i < vehicles.size() ; i++){
				cout<<i+1<<". ";
				vehicles[i].displayInfo();
			}
			cout<<"Enter any number to return to main menu : ";
	   		cin>>ret;
		}
		
		if(choice == 3){
			cout<<"Current count : "<<count<<endl<<endl;
			cout<<"Enter any number to return to main menu : ";
	   		cin>>ret;
		}
		
		if(choice == 4){
			cout<<endl;
			cout<<"Count before destruction : "<<count<<endl;
			cout<<"Calling destructor ...."<<endl;
			for(int i = 0 ; i < vehicles.size() ; i++){
				vehicles[i].~Vehicle();
				count--;
			}
		   cout<<"Memory has been cleaned !"<<endl;
		   cout<<"Count after destruction : "<<count<<endl;
	 	   cout<<"Good bye ! "<<endl;
	       return 0;
		}
	}
}
