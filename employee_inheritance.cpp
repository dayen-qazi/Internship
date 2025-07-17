#include<iostream>
using namespace std;

class Employee{
	protected:
		string name;
		int id;
		int salary;
		
	public :
		Employee(){
		}
		Employee(string n , int ID , int sal){
			name = n;
			id = ID;
			salary = sal;
		}
		
		virtual void displayInfo(){
			cout<<"Name : "<<name<<endl;
			cout<<"ID : "<<id<<endl;
			cout<<"Salary : "<<salary<<endl;
		}
};

class Manager : public Employee{
	protected:
		int bonus;
		
	public:
		Manager(){
		}
		Manager(string n , int ID , int sal , int bon){
			name = n;
			id = ID;
			salary = sal;
			bonus = bon;
		}
		
		void displayInfo() override{
			cout<<"Name : "<<name<<endl;
			cout<<"ID : "<<id<<endl;
			cout<<"Salary : "<<salary<<endl;
			cout<<"Bonus : "<<bonus<<endl;
		}
};

class Developer : public Manager{
	protected:
		string programLang;
		
	public:
		Developer(string n , int ID , int sal , int bon , string prog){
			name = n;
			id = ID;
			salary = sal;
			bonus = bon;
			programLang = prog;
		}
		
     	void displayInfo() override{
			cout<<"Name : "<<name<<endl;
			cout<<"ID : "<<id<<endl;
			cout<<"Salary : "<<salary<<endl;
			cout<<"Bonus : "<<bonus<<endl;
			cout<<"Programming Language : "<<programLang<<endl;
		}	
};

int menu(){
	int choice = -1;
	while(!(choice <= 3 && choice > 0)){
		cout<<"1. Add Information "<<endl;
		cout<<"2. Display Information "<<endl;
		cout<<"3. Exit "<<endl;
		cout<<"Enter Your Choice : "<<endl;
		cin>>choice;
		
		if(choice > 3 || choice <= 0){
			cout<<endl;
			cout<<"Invalid Input ! Enter Again "<<endl;
		}
	}
	
	return choice;
}

int addInfoMenu(){
	int choice = -1;
	while(!(choice <= 4 && choice > 0)){
		cout<<"1. Add Employee Information "<<endl;
		cout<<"2. Add Manager Information "<<endl;
		cout<<"3. Add Developer Information "<<endl;
		cout<<"4. Return To Main Menu "<<endl;
		cout<<"Enter Your Choice : "<<endl;
		cin>>choice;
		
		if(choice > 4 || choice <= 0){
			cout<<endl;
			cout<<"Invalid Input ! Enter Again "<<endl;
		}
	}
	
	return choice;
}

int displayInfoMenu(){
	int choice = -1;
	while(!(choice <= 4 && choice > 0)){
		cout<<"1. Display Employee Information "<<endl;
		cout<<"2. Display Manager Information "<<endl;
		cout<<"3. Display Developer Information "<<endl;
		cout<<"4. Return To Main Menu "<<endl;
		cout<<"Enter Your Choice : "<<endl;
		cin>>choice;
		
		if(choice > 4 || choice <= 0){
			cout<<endl;
			cout<<"Invalid Input ! Enter Again "<<endl;
		}
	}
	
	return choice;
}


int main(){
	Employee* emp[3];
	int choice = 0;
	int ret;
	while(!(choice == 3)){
		choice = menu();
		
		if(choice == 1){
			int select = 0;
			while(!(select == 4)){
				select = addInfoMenu();
				if(select == 1){
						int id;
						string name;
						int salary;
						
						cout<<"Enter Employee Name : ";
						cin>>name;
						cout<<"Enter ID : ";
						cin>>id;
						cout<<"Enter Salary : ";
						cin>>salary;
						emp[0] = new Employee(name,id,salary);
						cout<<"Information Added Successfully !"<<endl;
						cout<<"Enter Any Number To Return Back : ";
						cin>>ret;
					}
						
					if(select == 2){
						int id;
						string name;
						int salary;
						int bonus;
						
						cout<<"Enter Manager Name : ";
						cin>>name;
						cout<<"Enter ID : ";
						cin>>id;
						cout<<"Enter Salary : ";
						cin>>salary;
						cout<<"Enter Bonus : ";
						cin>>bonus;
						emp[1] = new Manager(name,id,salary,bonus);
						cout<<"Information Added Successfully !"<<endl;
						cout<<"Enter Any Number To Return Back : ";
						cin>>ret;
				}
					if(select == 3){
						int id;
						string name;
						int salary;
						int bonus;
						string progLang;
						
						cout<<"Enter Developer Name : ";
						cin>>name;
						cout<<"Enter ID : ";
						cin>>id;
						cout<<"Enter Salary : ";
						cin>>salary;
						cout<<"Enter Bonus : ";
						cin>>bonus;
						cout<<"Enter Programming Language : ";
						cin>>progLang;
						emp[2] = new Developer(name,id,salary,bonus,progLang);
						cout<<"Information Added Successfully !"<<endl;
						cout<<"Enter Any Number To Return Back : ";
						cin>>ret;
					}
					
					if(select == 4){
						break;
					}
				}
				
			}
		
		if(choice == 2){
			int option = 0;
			while(!(option == 4)){
				option = displayInfoMenu();
				
				if(option == 1){
					emp[0]->displayInfo();
						cout<<"Enter Any Number To Return Back : ";
						cin>>ret;
				}
				
				if(option == 2){
					emp[1]->displayInfo();
						cout<<"Enter Any Number To Return Back : ";
						cin>>ret;
				}
				
				if(option == 3){
					emp[2]->displayInfo();
						cout<<"Enter Any Number To Return Back : ";
						cin>>ret;
				}
				
				if(option == 4){
					break;
				}
			}
		}
		
		if(choice == 3){
			for(int i = 0 ; i < 3 ; i++){
				delete emp[i];
			}
			cout<<endl<<endl;
			cout<<"Good Bye ! ";
			return 0;
		}
	}
}
