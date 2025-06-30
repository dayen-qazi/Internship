#include<iostream>
#include<algorithm>
using namespace std;

int factorial(int n){    //Task 1
	if(n > 12){
		cout<<"Number is greater than 12 !"<<endl;
		cout<<" Leaving Factorial Function with value : ";
		return -1;
	}
	if(n == 0){
		return 1;
	}
	
	return n*factorial(n-1);
}

int customMax(int a , int b , int c){    //Task 2
	
	if((a == b) || (b == c) || (c == a)){
		
		if((a == b) && (a+b) > (b+c)){
			return a+b;
		}
		if((b == c) && (b+c) > (c+a)){
			return b+c;
		}
		if((c == a) && (c+a) > (a+b)){
			return c+a;
		}
	}
	
	if(a == b && b == c){
		return 0;
	}
	
	return max({(a+b),(b+c),(c+a)});
}

void printBanner(string message){     //Task 3

	cout<<"===== "<<message<<" ====="<<endl;
}

int main(){
       int num;
       cout<<" Enter a number : ";
       cin>>num;
       int a;
       int b;
       int c;
       cout<<" Enter three numbers : ";
       cin>>a>>b>>c;
       string s = "Student Logic Execution";
       
       printBanner(s);
       cout<<" Factorial : "<<factorial(num)<<endl;
       cout<<" Max Function Result : "<<customMax(a,b,c)<<endl;
       return 0;
}
