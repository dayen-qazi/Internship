#include<iostream>
using namespace std;

int main(){
         float sub1;
         float sub2;
         float sub3;
         float total = 0;
         
         cout<<"Enter marks of first subject : ";
         cin>>sub1;
         cout<<"Enter marks of second subject : ";
         cin>>sub2;
         cout<<"Enter marks of third subject : ";
         cin>>sub3;
         total = sub1+sub2+sub3;
         float average = total/3;
         cout<<endl;
         
         cout<<"Result : "<<endl;
         cout<<"Your total marks are : "<<total<<endl;
         cout<<"The average of your marks is : "<<average<<endl;
         if(average <= 100 && average >= 90){
         	cout<<"Grade : A+"<<endl;
		 }
         else if(average < 90 && average >= 80){
         	cout<<"Grade : A"<<endl;
		 }
		 else if(average < 80 && average >= 70){
		 	cout<<"Grade : B"<<endl;
		 }
		 else if(average < 70 && average >= 60){
		 	cout<<"Grade : C"<<endl;
		 }
		 else if(average < 60 && average >= 50){
		 	cout<<"Grade : D"<<endl;
		 }
		 else{
		 	cout<<"Grade : F"<<endl;
		 }
	
	return 0;
}
