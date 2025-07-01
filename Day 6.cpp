#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int getSum(int arr[] , int size){
	int sum = 0;
	for(int i = 0 ; i < size ; i++){
		sum += arr[i];
	}
	return sum;
}

int getMaxIndex(int arr[] , int size){
	int maxIndex = 0;
	int max = arr[0];
	for(int i = 1 ; i < size ; i++){
		if(arr[i] > max){
			maxIndex = i;
			max = arr[i];
		}
	}
	return maxIndex;
}

int getMinIndex(int arr[] , int size){
	int minIndex = 0;
	int min = arr[0];
	for(int i = 0 ; i < size ; i++){
		if(arr[i] < min){
			minIndex = i;
			min = arr[i];
		}
	}
	return minIndex;
}

float getAverage(int arr[] , int size){
	float sum = getSum(arr,size);
	float average = sum/size;
	return average;
}

void reorderEvenOdd(int arr[] , int size){
	int arr2[size];
	int index = 0;
	for(int i = 0 ; i < size ; i++){
		if(arr[i]%2 == 0){
			arr2[index] = arr[i];
			index ++;
		}
	}
	
	for(int i = 0 ; i < size ; i++){
		if(arr[i]%2 != 0){
			arr2[index] = arr[i];
			index++;
		}
	}
	for(int i = 0 ; i < size ; i++){
		cout<<arr2[i]<<" ";
	}
}

int main(){
	int size = 5;
	int arr[size];
	cout<<"Enter 5 numbers : ";
	
	for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
	}
	
	float avg = getAverage(arr,size);
	int max = getMaxIndex(arr,size);
	int min = getMinIndex(arr,size);
	cout<<"Sum : "<<getSum(arr,size)<<endl;
	cout<<"Average : "<<fixed<<setprecision(2)<<avg<<endl;
	cout<<"Maximum : "<<arr[max]<<" at position "<<max<<endl;
	cout<<"Minimum : "<<arr[min]<<" at position "<<min<<endl;
	cout<<"Reordered Array : ";
	reorderEvenOdd(arr,size);
	cout<<endl;
	
	return 0;
}
