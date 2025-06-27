#include<iostream>
using namespace std;

int main(){
       int num;
       cout<<"Enter a number : ";
       cin>>num;
       if(num < 0 || num == 0 || num == 1){          //Edge Case
       	  cout<<"Non Prime Number"<<endl;
       	  return 0;
	   }
	   
	   if(num == 2){         //Edge Case
	   	cout<<"Prime Number"<<endl;
	   	return 0;
	   }
	   
	   bool isPrime = true;
	   for(int i = 2 ; i < num ; i++){       // Loop to iterate from 2 to all numbers less than num
	   	if(num % i == 0){           // Condition to check whether num is completely divisible by any number lesser than it
	   		isPrime = false;
	   		break;    // Break statement to avoid unneccessary iterations
		   }
	   }
	   
	   if(isPrime == true){              // Print answer depending on condition
	   	cout<<"Prime Number"<<endl;
	   }
	   else{
	   	cout<<"Non Prime Number"<<endl;
	   }
	   
	   return 0;
}
