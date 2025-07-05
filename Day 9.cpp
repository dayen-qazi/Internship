#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct Student{
	int id;
	char name[50];
	float marks;
	char grade;
};

void copyStringToCharArray(const string& src, char* name) {
    int i = 0;
    for (; i + 1 < 50 && i < src.size(); ++i) {
        name[i] = src[i];
    }
    name[i] = '\0';  
}

void addStudentToFile(const Student& s , const string filename){
	ofstream outFile(filename,ios::app);
	if(!outFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	outFile << s.id << " | " << s.name << " | " << fixed << setprecision(1) << s.marks << " | " << s.grade << endl;
	outFile.close();
	cout<<"Data Added Successfully "<<endl;
}

void displayStudentsFromFile(const string filename){
	 Student s1;
	 ifstream inFile(filename,ios::in);
	 if(!inFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	 string s;
	 
    cout << "---------------------------------------------------"<<endl;
    cout <<"  "<< "ID" << setw(16) << "NAME" << setw(15) << "MARKS" << setw(15)<<"GRADE" << endl;
    cout << "---------------------------------------------------"<<endl;
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

void searchStudentByID(const string fileName , int id){
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
            cout<< "STUDENT DATA"<<endl;
            cout<< "----------------------------------------"<<endl;
            cout<<left<<setw(10)<<"ID"<<setw(14)<<"NAME"<<setw(10)<<"MARKS"<<"GRADE"<< endl;
            cout<< "----------------------------------------"<<endl;
            cout<<left<<setw(10)<<piece[0]<<setw(15)<<piece[1]<<setw(10)<<piece[2]<<piece[3]<< endl;
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

int displayMenu(){
	int choice;
	int ret;
	cout<<"1. Add Student Data"<<endl;
	cout<<"2. Display Student Data"<<endl;
	cout<<"3. Search Student Record By ID"<<endl;
	cout<<"4. Delete Student Record by ID"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Enter Choice : ";
	cin>>choice;
	if(choice > 5 || choice <= 0){
		cout<<"Invalid Input ! "<<endl;
	}
	
	return choice;
}

int main(){
	Student s1;
	string fileName = "studentdata.txt";
	const char* filename = "studentdata.txt";
	 int ret;
	 int choice = 0;
	 while(!(choice == 5)){
	     choice = displayMenu();
	
	if(choice == 1){
	cout<<"Enter Student ID : ";
	cin>>s1.id;
	cout<<"Enter Student Name : ";
	cin>>s1.name;
	s1.marks = -1;
	while(!(s1.marks <= 100 && s1.marks >= 0)){
	cout<<"Enter Marks Of Student : ";
	cin>>s1.marks;
	if(s1.marks > 100 || s1.marks < 0){
		cout<<"Invalid Input ! "<<endl;
	}
  }  
	if(s1.marks >= 85){
		s1.grade = 'A';
	}
	else if(s1.marks >= 70 && s1.marks < 85){
		s1.grade = 'B';
	}
	else if(s1.marks >= 50 && s1.marks < 70){
		s1.grade = 'C';
	}
	else{
		s1.grade = 'F';
	}
	
	addStudentToFile(s1,fileName);
	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 2){
  	displayStudentsFromFile(fileName);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 3){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	searchStudentByID(fileName,id);
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
  
  if(choice == 5){
  	cout<<"Good bye !"<<endl;
  	return 0;
      }
  }
	
}
