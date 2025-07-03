#include<iostream>
using namespace std;

bool isOdd(int n){
	if(n%2 == 0){
		return false;
	}
	return true;
}

int absDifference(int *x , int* y){
	if(*x > *y){
		return *x-*y;
	}
	else{
		return *y-*x;
	}
}

void conditionalSwap(int *x , int* y){
	 int absDiff = absDifference(x,y);
	 if(absDiff > 10){
	 	int temp = *x;
	 	*x = *y;
	 	*y = temp;
	 }
}

void printArrayViaPointer(int* arr , int size){
	for(int i = 0 ; i < size ; i++){
		cout<<*(arr+i)<<" @ "<<(arr+i)<<endl;
	}
}

int* findFirstEven(int* arr , int size){
	for(int i = 0 ; i < size ; i++){
		if(*(arr+i)%2 == 0){
			return (arr+i);
		}
	}
	return nullptr;
}

void incrementOddsByAddress(int *arr , int size){
	  for(int i = 0 ; i < size ; i++){
	  	bool odd = isOdd(*(arr+i));
	  	if(odd == true){
	  		*(arr+i) += 1;
		  }
	  }
	  
	  for(int i = 0 ; i < size ; i++){
	  	cout<<*(arr+i)<<" ";
	  }
}

int main(){
	   int a;
	   int b;
	   int size = 5;
	   cout<<"Enter Two Numbers : ";
	   cin>>a>>b;
	   int arr[size];
	   cout<<"Enter 5 Numbers For Array : ";
	   for(int i = 0 ; i < size ; i++){
	   	      cin>>arr[i];
	   }
	   cout<<endl;
	   
	   cout<<"=== Pointer Logic Execution ==="<<endl;
	   cout<<"Before Swap : a = "<<a<<" , b = "<<b<<endl;
	   conditionalSwap(&a,&b);
	   cout<<"After Swap : a = "<<a<<" , b = "<<b<<endl;
	   cout<<"Array Elements (Value @ Address) : "<<endl;
	   printArrayViaPointer(arr,size);
	   int* firstEven = findFirstEven(arr,size);
	   if(firstEven == nullptr){
	   	 cout<<"First Even Number : Null"<<endl;
	         }
	   else{
	   cout<<"First Even Number : "<<*firstEven<<endl;
        }
	   cout<<"Modified Array (Odds Incremented) : ";
	   incrementOddsByAddress(arr,size);
	   
	   return 0;
}
