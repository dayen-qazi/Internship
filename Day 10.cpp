#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct Item{
	int id;
	char name[50];
	int quantity;
	float price;
};

void copyStringToCharArray(const string& src, char* name) {
    int i = 0;
    for (; i + 1 < 50 && i < src.size(); ++i) {
        name[i] = src[i];
    }
    name[i] = '\0';  
}

void header(){
	         cout << "---------------------------------------------------"<<endl;
             cout << "ID" << "            " << "NAME" << "       " << "QUANTITY" << "        " <<"PRICE" << endl;
             cout << "---------------------------------------------------"<<endl;
}

void addItem(Item i1 , string filename){
	vector <int> ids;
	ofstream outFile(filename,ios::app);
	if(!outFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	ifstream inFile(filename,ios::in);
	 if(!inFile){
		cout<<"Error Accessing File or Invalid Name !"<<endl;
	}
	
	while(!(inFile.eof())){
	 char line[200];
    while (inFile.getline(line,200)) {
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

        if (i == 4) {
           ids.push_back(stoi(piece[0]));
			}
         }
      } 
   inFile.close();
   
   for(int i = 0 ; i < ids.size() ; i++){
   	 if(ids.at(i) == i1.id){
   	 	cout<<"Duplicate ID !"<<endl;
   	 	return;
		}
   }
   
	outFile << i1.id << " | " << i1.name << " | "  << i1.quantity << " | " << i1.price << endl;
	outFile.close();
	cout<<"Item Added Successfully "<<endl;
}

void viewAlltems(string filename){
		 ifstream inFile(filename,ios::in);
	 if(!inFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	 string s;
	 
     header();
	 while(!(inFile.eof())){
	 char line[200];
    while (inFile.getline(line,200)) {
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

        if (i == 4) {
            cout<<left<<setw(14)<<piece[0]<<setw(14)<<piece[1]<<setw(14)<<piece[2]<<piece[3]<< endl;
        }
    }
   }
   inFile.close();
}

void searchItemByID(string filename , int id){
	 ifstream inFile(filename,ios::in);
	 if(!inFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	bool check = false;

	 while(!(inFile.eof())){
	 char line[200];
    while (inFile.getline(line,200)) {
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

        if (i == 4) {
        	if(stoi(piece[0]) == id){
        	  header();	
            cout<<left<<setw(14)<<piece[0]<<setw(14)<<piece[1]<<setw(14)<<piece[2]<<piece[3]<< endl;
            check = true;
        }
      }  
    }
}
   inFile.close();
   if(!check){
   	cout<<"Item Not Found !"<<endl;
   }
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == string::npos) ? "" : str.substr(first, last - first + 1);
}

 
Item parseItem(string line) {
    stringstream ss(line);
    string part;
    Item item;

    getline(ss, part, '|');
    item.id = stoi(trim(part));

    getline(ss, part, '|');
    trim(part);
    copyStringToCharArray(part,item.name);

    getline(ss, part, '|');
    item.quantity = stoi(trim(part));

    getline(ss, part, '|');
    item.price = stod(trim(part));

    return item;
}



void updateQuantity(string filename , int targetID){
        vector <Item> items;
        ifstream infile(filename);
        string line;

       while (getline(infile, line)) {
        if (!line.empty()) {
            items.push_back(parseItem(line));
        }
    }
        
    bool found = false;

    for(int i = 0 ; i < items.size() ; i++){
        if (items[i].id == targetID){
        	int quantity;
        	cout<<"Enter New Quantity : ";
            cin>>quantity;
            items[i].quantity = quantity;
            found = true;
            break;
        }
    }

    if(found){
        ofstream outfile(filename);
        if(!outfile){
        	cout<<"Error opening file !"<<endl;
        	return;
		}
        for(Item item : items){
        outfile << item.id << " | " << item.name << " | " << item.quantity << " | "  << item.price <<endl;
       }
        cout << "Quantity updated successfully."<<endl;
    } 
	else {
        cout << "Item with ID " << targetID << " not found."<<endl;
    }

}


void deleteItemByID(const char* filename , int id){
	ifstream inFile(filename);
    if (!inFile) {
        cout << "No items found!" << endl;
        return;
    }

    ofstream tempFile("temporary.txt");
    if (!tempFile) {
        cout << "Unable To Create Temporary File!" << endl;
        inFile.close();
        return;
    }

    bool found = false;
    char line[200];
    while (inFile.getline(line, 200)) {
        char temporary[200];
        strcpy(temporary, line);
        
        char* token = strtok(temporary, "|");
        if (token) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';
            
            if (atoi(token) != id) {
                tempFile << line << endl;
            } else {
                found = true;
            }
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove(filename);
        rename("temporary.txt", filename);
        cout<<"Data Deleted Successfully"<< endl;
    } else {
        remove("temporary.txt");
        cout<<"ID Not Found"<< endl;
    }
}

int displayMenu(){
	int choice;
	int ret;
	cout<<"1. Add Item"<<endl;
	cout<<"2. View All Items"<<endl;
	cout<<"3. Search By ID"<<endl;
	cout<<"4. Update Quantity"<<endl;
	cout<<"5. Delete Item"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"Enter Choice : ";
	cin>>choice;
	if(choice > 6 || choice <= 0){
		cout<<"Invalid Input ! "<<endl;
	}
	
	return choice;
}

int main(){
	Item i1;
	string fileName = "inventorydata.txt";
	const char* filename = "inventorydata.txt";
	 int ret;
	 int choice = 0;
	 while(!(choice == 6)){
	     choice = displayMenu();
	
	if(choice == 1){	
	cout<<"Enter Item ID : ";
	cin>>i1.id;
	cout<<"Enter Item Name : ";
	cin>>i1.name;
	i1.quantity = -1;
	while(!(i1.quantity > 0)){
	cout<<"Enter Item Quantity : ";
	cin>>i1.quantity;
	if(i1.quantity < 0){
		cout<<"Invalid Input ! "<<endl;
	}
  } 
    cout<<"Enter Item Price : ";
	cin>>i1.price;
	addItem(i1,fileName);
	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 2){
  	viewAlltems(fileName);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 3){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	searchItemByID(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  	
  }
  
  if(choice == 4){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	updateQuantity(filename,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 5){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	deleteItemByID(filename,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 6){system("cls");
  	cout<<"Good bye !"<<endl;
  	return 0;
      }
	
  }

}
   
