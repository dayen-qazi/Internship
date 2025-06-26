#include<iostream>
using namespace std;

int main(){
       string name;
       int age;
       float cgpa;
       
       cout<<"Enter your name : ";
       getline(cin,name);
       cout<<"Enter your age : ";
       cin>>age;
       cout<<"Enter your CGPA : ";
       cin>>cgpa;
       cout<<endl;
       
       if(age >= 18){
       	  if(cgpa >= 2.5){
       	  	cout<<"Eligible"<<endl;
			 }
		  else{
		  	cout<<"CGPA too low"<<endl;
		  }
	   }
	   else{
	   	cout<<"Under Age"<<endl;
	   }
	   
	return 0;
}
