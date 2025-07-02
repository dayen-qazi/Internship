#include<iostream>
using namespace std;

int calculateLength(string s){
	int count = 0;
	for(char ch : s){
		count++;
	}
	return count;
}

string reverseString(string s){
	int length = calculateLength(s);
	string rev = s;
	int index = 0;
	for(int i = length - 1 ; i >= 0 ; i--){
		rev[index] = s[i];
		index++;
	}
	return rev;
}

bool isPalindrome(string s){
	int start = 0;
	int end = calculateLength(s) - 1;
	
	while(start <= end){
		if(s[start] != s[end]){
			return false;
		}
		start++;
		end--;
	}
	return true;
}

int countVowels(string s){
	char prev = s[0];
	int count = 0;
	if(prev == 'a' || prev == 'e' || prev == 'i' || prev == 'o' || prev == 'u'){
			count++;
		}
	int length = calculateLength(s);
	
	for(int i = 1 ; i < length ; i++){
     	if(prev == s[i]){
			continue;
		}
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			count++;
			prev = s[i];
		}
     }
     return count;
}

int main(){
	string s;
	cout<<"Enter a string (No spaces !) : ";
	getline(cin,s);
	
	for(char ch : s){
		if(ch == ' '){
			cout<<"Invalid Input ! Contains Spaces";
			return 0;
		}
	}
	int length = calculateLength(s);
	string rev = reverseString(s);
	int vowels = countVowels(s);
	cout<<endl;
	
	cout<<"=== String Analysis Report ==="<<endl;
	cout<<"Original : "<<s<<endl;
	cout<<"Reversed : "<<rev<<endl;
	cout<<"Length : "<<length<<endl;
	cout<<"Vowels : "<<vowels<<endl;
	
	bool Palindrome = isPalindrome(s);
	cout<<"Palindrome : ";
	if(Palindrome == true){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	
	return 0;
}
