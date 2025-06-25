#include<iostream>
using namespace std;

int main(){
	string name;
	int age;
	float gpa;
	
	cout<<"Enter Your Name : ";
	getline(cin,name);
	cout<<"Enter Your Age : ";
	cin>>age;
	cout<<"Enter Your GPA : ";
	cin>>gpa;
	cout<<endl;
	
	cout<<"Your Entered Information Is : "<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"Age : "<<age<<endl;
	cout<<"GPA : "<<gpa<<endl;
	
	return 0;
}
