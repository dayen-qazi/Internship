#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;


void banner(){
	cout << "--------------------------------------------------------"<<endl;
    cout << "ACCOUNT ID" << "           " << "ACCOUNT NAME" << "            " << "BALANCE" << endl;
    cout << "--------------------------------------------------------"<<endl;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == string::npos) ? "" : str.substr(first, last - first + 1);
}


class Account{
	public:
	int accNum;
	string name;
	float balance;
	
	void setter(int num , string n , float bal){
		accNum = num;
		name = n;
		balance = bal;
	}
	
	void addAccountToFile(const string filename){
	ofstream outFile(filename,ios::app);
	if(!outFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	outFile << accNum << " | " << name << " | "  << balance << endl;
	outFile.close();
	cout<<"Account Added Successfully "<<endl;
   }
   
   
   void displayAccountByID(string fileName, int targetNum){
   	 bool check = false;
	 ifstream inFile(fileName,ios::in);
	 if(!inFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	 while(!(inFile.eof())){
	 char line[400];
    while (inFile.getline(line, 400)) {
        char* piece[4];
        int i = 0;
        
        char* token = strtok(line, "|");
        while (token != NULL && i < 4) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';
            
            piece[i++] = token;
            token = strtok(NULL, "|");
        }

        if (i == 3 && atoi(piece[0]) == targetNum) {
        	cout<<endl;
            cout<< "ACCOUNT DATA"<<endl;
            banner();
            cout<<"   "<<piece[0]<<setw(23)<<piece[1]<<setw(20)<<piece[2]<< endl;
            check = true;
            break;
        }
	 
     }
   
   if(check == false){
   	cout<<"ID not found"<<endl;
   }
}
  inFile.close();
   }
	
};

 Account parseItem(string line) {
    stringstream ss(line);
    string part;
    Account a1;

    getline(ss, part, '|');
    a1.accNum = stoi(trim(part));

    getline(ss, part, '|');
    a1.name = trim(part);

    getline(ss, part, '|');
    a1.balance = stoi(trim(part));


    return a1;
}


void deposit(string fileName, int targetNum){
   	    vector <Account> accounts;
        ifstream infile(fileName);
        string line;

       while (getline(infile, line)) {
        if (!line.empty()) {
            accounts.push_back(parseItem(line));
        }
    }
        
    bool found = false;

    for(int i = 0 ; i < accounts.size() ; i++){
        if (accounts[i].accNum == targetNum){
        	int deposit;
        	while(!(deposit > 0)){
        	cout<<"Enter Deposit Amount : ";
            cin>>deposit;
            if(deposit <= 0){
            	cout<<"Invalid amount ! "<<endl;
			}
        }  
            accounts[i].balance += deposit;
            found = true;
            break;
        }
    }

    if(found){
        ofstream outfile(fileName);
        if(!outfile){
        	cout<<"Error opening file !"<<endl;
        	return;
		}
        for(Account account : accounts){
        outfile << account.accNum << " | " << account.name << " | " << account.balance <<endl;
       }
        cout << "Deposited successfully."<<endl;
    } 
	else {
        cout << "Account with ID " << targetNum << " not found."<<endl;
    }
   }

   
   void withdraw(string fileName, int targetNum){
   	    vector <Account> accounts;
        ifstream infile(fileName);
        string line;

       while (getline(infile, line)) {
        if (!line.empty()) {
            accounts.push_back(parseItem(line));
        }
    }
        
    bool found = false;

    for(int i = 0 ; i < accounts.size() ; i++){
        if (accounts[i].accNum == targetNum){
        	int withdraw;
        	while(!(withdraw <= accounts[i].balance && withdraw > 0)){
        	cout<<"Enter Withdraw Amount : ";
            cin>>withdraw;
            if(withdraw > accounts[i].balance){
            	cout<<"Withdrawal amount exceeds balance amount ! Enter Again "<<endl;
			}
			if(withdraw < 0){
				cout<<"Invalid Amount"<<endl;
			}
        }  
            accounts[i].balance -= withdraw;
            found = true;
            break;
        }
    }

    if(found){
        ofstream outfile(fileName);
        if(!outfile){
        	cout<<"Error opening file !"<<endl;
        	return;
		}
        for(Account account : accounts){
        outfile << account.accNum << " | " << account.name << " | " << account.balance <<endl;
       }
        cout << "Withdrawn successfully."<<endl;
    } 
	else {
        cout << "Account with ID " << targetNum << " not found."<<endl;
    }
   }



int displayMenu(){
	int choice;
	int ret;
	cout<<"1. Add Account"<<endl;
	cout<<"2. Display Account Info By ID"<<endl;
	cout<<"3. Deposit"<<endl;
	cout<<"4. Withdraw"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Enter Choice : ";
	cin>>choice;
	if(choice > 5 || choice <= 0){
		cout<<"Invalid Input ! "<<endl;
	}
	
	return choice;
}

int main(){
	Account a1;
	string fileName = "accountsdata.txt";
	 int ret;
	 int accNum;
	 string name;
	 int balance;
	 int choice = 0;
	 while(!(choice == 5)){
	     choice = displayMenu();
	
	if(choice == 1){
	cout<<"Enter Account Number : ";
	cin>>accNum;
	cout<<"Enter Account Name : ";
    cin>>name;
	balance = -1;
	while(!(balance >= 0)){
	cout<<"Enter Balance : ";
	cin>>balance;
	if(balance < 0){
		cout<<"Invalid Input ! "<<endl;
	}
  }  

    a1.setter(accNum,name,balance);
	a1. addAccountToFile(fileName);
	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 2){
  	int id;
  	cout<<"Enter Account ID To Search : ";
  	cin>>id;
  	a1.displayAccountByID(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 3){
  	int id;
  	cout<<"Enter Account ID : ";
  	cin>>id;
  	deposit(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  	
  }
  
  if(choice == 4){
  	int id;
  	cout<<"Enter Account ID : ";
  	cin>>id;
    withdraw(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 5){
    cout<<endl<<endl;
  	cout<<"Good bye !"<<endl;
  	return 0;
  }
  
  }
	
}
