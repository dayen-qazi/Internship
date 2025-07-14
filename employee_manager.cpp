#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

struct Employee{
	int id;
	char name[50];
	float salary;
	string dept;
};

void copyStringToCharArray(const string& src, char* name) {
    int i = 0;
    for (; i + 1 < 50 && i < src.size(); ++i) {
        name[i] = src[i];
    }
    name[i] = '\0';  
}

void banner(){
	cout << "--------------------------------------------------------"<<endl;
    cout << "ID" << "              " << "NAME" << "          " << "SALARY" << "         "<<"DEPARTMENT" << endl;
    cout << "--------------------------------------------------------"<<endl;
}

void addEmployeeToFile(const Employee& e , const string filename){
	ofstream outFile(filename,ios::app);
	if(!outFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	outFile << e.id << " | " << e.name << " | "  << e.salary << " | " << e.dept << endl;
	outFile.close();
	cout<<"Data Added Successfully "<<endl;
}

void displayEmployeesFromFile(const string filename){
	 ifstream inFile(filename,ios::in);
	 if(!inFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	 string s;
	 
     banner();
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
            cout<<left<<setw(15)<<piece[0]<<setw(15)<<piece[1]<<setw(15)<<piece[2]<<piece[3]<< endl;
        }
    }
   }
   inFile.close();
}

void searchEmployeeByID(const string fileName , int id){
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

        if (i == 4 && atoi(piece[0]) == id) {
        	cout<<endl;
            cout<< "EMPLOYEE DATA"<<endl;
            banner();
            cout<<left<<setw(15)<<piece[0]<<setw(15)<<piece[1]<<setw(10)<<piece[2]<<"       "<<piece[3]<< endl;
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

void deleteRecordByID(const char* fileName, int id){
	ifstream inFile(fileName);
    if (!inFile) {
        cout << "No records found!" << endl;
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
        remove(fileName);
        rename("temporary.txt", fileName);
        cout<<"Data Deleted Successfully"<< endl;
    } else {
        remove("temporary.txt");
        cout<<"ID Not Found"<< endl;
    }
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == string::npos) ? "" : str.substr(first, last - first + 1);
}

 
Employee parseItem(string line) {
    stringstream ss(line);
    string part;
    Employee e1;

    getline(ss, part, '|');
    e1.id = stoi(trim(part));

    getline(ss, part, '|');
    trim(part);
    copyStringToCharArray(part,e1.name);

    getline(ss, part, '|');
    e1.salary = stoi(trim(part));

    getline(ss, part, '|');
    e1.dept = trim(part);

    return e1;
}

void updateSalaryByID(const string fileName , int targetID){
	    vector <Employee> employees;
        ifstream infile(fileName);
        string line;

       while (getline(infile, line)) {
        if (!line.empty()) {
            employees.push_back(parseItem(line));
        }
    }
        
    bool found = false;

    for(int i = 0 ; i < employees.size() ; i++){
        if (employees[i].id == targetID){
        	int salary;
        	cout<<"Enter New Salary : ";
            cin>>salary;
            employees[i].salary = salary;
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
        for(Employee employee : employees){
        outfile << employee.id << " | " << employee.name << " | " << employee.salary << " | "  << employee.dept <<endl;
       }
        cout << "Salary updated successfully."<<endl;
    } 
	else {
        cout << "Employee with ID " << targetID << " not found."<<endl;
    }
}

int displayMenu(){
	int choice;
	int ret;
	cout<<"1. Add Employee Data"<<endl;
	cout<<"2. Display Employee Data"<<endl;
	cout<<"3. Search Employee Record By ID"<<endl;
	cout<<"4. Delete Employee Record by ID"<<endl;
	cout<<"5. Update Salary By ID"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"Enter Choice : ";
	cin>>choice;
	if(choice > 6 || choice <= 0){
		cout<<"Invalid Input ! "<<endl;
	}
	
	return choice;
}

int main(){
	Employee e1;
	string fileName = "employeedata.txt";
	const char* filename = "employeedata.txt";
	 int ret;
	 int choice = 0;
	 while(!(choice == 6)){
	     choice = displayMenu();
	
	if(choice == 1){
	cout<<"Enter Employee ID : ";
	cin>>e1.id;
	cout<<"Enter Employee Name : ";
	cin>>e1.name;
	e1.salary = -1;
	while(!(e1.salary > 0)){
	cout<<"Enter Salary Of Employee : ";
	cin>>e1.salary;
	if(e1.salary <= 0){
		cout<<"Invalid Input ! "<<endl;
	}
  }  
    cout<<"Enter Employee Department : ";
    cin>>e1.dept;
	
	addEmployeeToFile(e1,fileName);
	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 2){
  	displayEmployeesFromFile(fileName);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 3){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	searchEmployeeByID(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  	
  }
  
  if(choice == 4){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	deleteRecordByID(filename,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if (choice == 5){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	updateSalaryByID(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 6){
  	cout<<endl<<endl;
  	cout<<"Good bye !"<<endl;
  	return 0;
      }
  }
	
}
