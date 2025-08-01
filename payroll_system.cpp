#include<iostream>
using namespace std;

class Taxable{
	public:
		virtual void calculateTax() = 0;
};

class Person : public Taxable{
	protected:
		int id;
		string name;
		double perDaySalary;
		int workDays;
		public : 
		virtual void calculateSalary() = 0;
		virtual void displayInfo() = 0;
};

class Employee : public Person{
	   public:
	   Employee(int i , string n , int sal , int d){
	   	id = i;
	   	name = n;
	   	perDaySalary = sal;
	   	workDays = d;
	   }
	   
	   void displayInfo() override{
	   	cout<<"Name : "<<name<<endl;
	   	cout<<"ID : "<<id<<endl;
	   	cout<<"Position : Employee"<<endl;
	   }
	   
	   void calculateSalary() override{
	   	int salary = perDaySalary*workDays;
	   	cout<<"Salary : " << salary << endl;
	   }
	   
	   void calculateTax() override{
	   	int salary = perDaySalary*workDays;
	   	cout<<"Tax : " << salary*0.15 << endl << endl;  //15% Tax
	   }
	   
};

class Intern : public Person{
	public:
	Intern(int i , string n , int sal , int d){
	   	id = i;
	   	name = n;
	   	perDaySalary = sal;
	   	workDays = d;
	   }
	   
	   void displayInfo() override{
	   	cout<<"Name : "<<name<<endl;
	   	cout<<"ID : "<<id<<endl;
	   	cout<<"Position : Intern"<<endl;
	   }
	   
	   void calculateSalary() override{
	   	int salary = perDaySalary*workDays;
	   	cout<<"Salary : " << salary << endl;
	   }
	   
	   void calculateTax() override{
	   	int salary = perDaySalary*workDays;
	   	cout<<"Tax : " << salary*0.10 << endl << endl;  //10% Tax
	   }
	   
};

int main(){
	Person* p[2];
	int id , workDays;
	double perDaySalary;
	string name;
	cout<<"=== Enter Employee Information ==="<<endl;
	cout<<"Enter Name : ";
	cin>>ws;
	getline(cin,name);
	cout<<"Enter ID : ";
	cin>>id;
	cout<<"Enter Per Day Salary : ";
	cin>>perDaySalary;
	cout<<"Enter Working Days : ";
	cin>>workDays;
	Taxable* t1 = new Employee(id,name,perDaySalary,workDays);
	cout<<endl<<endl;
	
	cout<<"=== Enter Intern Information ==="<<endl;
	cout<<"Enter Name : ";
	cin>>ws;
	getline(cin,name);
	cout<<"Enter ID : ";
	cin>>id;
	cout<<"Enter Per Day Salary : ";
	cin>>perDaySalary;
	cout<<"Enter Working Days : ";
	cin>>workDays;
	Taxable* t2 = new Intern(id,name,perDaySalary,workDays);
	
	p[0] = dynamic_cast<Employee*>(t1);
	p[1] = dynamic_cast<Intern*>(t2);
	
	cout<<endl<<endl;
	
	p[0]->displayInfo();
	p[0]->calculateSalary();
	p[0]->calculateTax();
	p[1]->displayInfo();
	p[1]->calculateSalary();
	p[1]->calculateTax();
	return 0;
}
