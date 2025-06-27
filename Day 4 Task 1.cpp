#include<iostream>
using namespace std;

int main(){
       int num;
       int reversedNum;
       cout<<"Enter a number : ";
       cin>>num;
       if(num >= 0 && num <= 9){          //Edge Case
       	  cout<<"Reversed number is : "<<num<<endl;
       	  return 0;
	   }
	   
	   for(num ; num != 0 ; num /= 10){       //Loop to iterate and reverse number by extracting a digit in each iteration
	   	int digit = num % 10;
	   	reversedNum = reversedNum * 10 + digit;
	   	}
	   	
	   	cout<<"Reversed number is : "<<reversedNum<<endl;         //Printing Reversed Number
	   	return 0;
}
