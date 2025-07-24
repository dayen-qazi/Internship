#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

class Student{
	int id;
	string name;
	float cgpa;
	string dept;
	
	public:
	Student(){
	
	}
	
	Student(int i , string n , string d , float c){
		id = i;
		name = n;
		dept = d;
		cgpa = c;
	}
	
	void addStudentToFile(const Student& s , const string filename){
	ofstream outFile(filename,ios::app);
	if(!outFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	outFile << s.id << " | " << s.name << " | " << fixed << setprecision(1) << s.cgpa << " | " << s.dept << endl;
	outFile.close();
	cout<<"Data Added Successfully "<<endl;
   }
   
   void displayStudentsFromFile(const string filename){
	 ifstream inFile(filename,ios::in);
	 if(!inFile){
		cout<<"Error Opening File or Invalid Name !"<<endl;
	}
	 string s;
	 
    cout << "----------------------------------------------------------"<<endl;
    cout <<" "<< "ID" << "             " << "NAME" << "          " << "CGPA" << "           " <<"DEPARTMENT" << endl;
    cout << "----------------------------------------------------------"<<endl;
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
            cout<<left<<setw(15)<<piece[0]<<setw(15)<<piece[1]<<setw(15)<<piece[2]<<"  "<<piece[3]<< endl;
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
             cout << "----------------------------------------------------------"<<endl;
             cout <<" "<< "ID" << "             " << "NAME" << "         " << "CGPA" << "           " <<"DEPARTMENT" << endl;
             cout << "----------------------------------------------------------"<<endl;
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

 
Student parseItem(string line) {
    stringstream ss(line);
    string part;
    
    int id;
    string name;
    float cgpa;
    string dept;

    getline(ss, part, '|');
    id = stoi(trim(part));

    getline(ss, part, '|');
    name = trim(part);

    getline(ss, part, '|');
    cgpa = stof(trim(part));

    getline(ss, part, '|');
    dept = trim(part);

    Student s1(id,name,dept,cgpa);
    return s1;
}

void updateRecordByID(const string fileName , int targetID){
	    vector <Student> students;
        ifstream infile(fileName);
        string line;

       while (getline(infile, line)) {
        if (!line.empty()) {
            students.push_back(parseItem(line));
        }
    }
        
    bool found = false;

    for(int i = 0 ; i < students.size() ; i++){
        if (students[i].id == targetID){
        	int id;
        	string name;
        	float cgpa;
        	string dept;
        	
        	cout<<"Enter New ID : ";
            cin>>id;
            cout<<"Enter New Name : ";
            cin>>name;
            cout<<"Enter New CGPA : ";
            cin>>cgpa;
            cout<<"Enter New Department : ";
            cin>>dept;
            students[i].id = id;
            students[i].name = name;
            students[i].cgpa = cgpa;
            students[i].dept = dept;
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
        for(Student student : students){
        outfile << student.id << " | " << student.name << " | " << fixed << setprecision(1) << student.cgpa << " | "  << student.dept <<endl;
       }
        cout << "Data updated successfully."<<endl;
    } 
	else {
        cout << "Student with ID " << targetID << " not found."<<endl;
    }
  }
  
  int displayMenu(){
	int choice;
	int ret;
	cout<<"1. Add Student Data"<<endl;
	cout<<"2. Display Student Data"<<endl;
	cout<<"3. Search Student Record By ID"<<endl;
	cout<<"4. Delete Student Record By ID"<<endl;
	cout<<"5. Update Student Record By ID"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"Enter Choice : ";
	cin>>choice;
	if(choice > 6 || choice <= 0){
		cout<<"Invalid Input ! "<<endl;
	}
	
	return choice;
   }  
};

int main(){
	Student s1;
	string fileName = "studentsdata.txt";
	const char* filename = "studentsdata.txt";
	 int ret;
	 int choice = 0;
	 while(!(choice == 6)){
	     choice = s1.displayMenu();
	
	if(choice == 1){
	int id;
	string name;
	float cgpa;	
	string dept;
	cout<<"Enter Student ID : ";
	cin>>id;
	cout<<"Enter Student Name : ";
	cin>>name;
	cout<<"Enter Department : ";
	cin>>dept;
	cout<<"Enter CGPA : ";
	cin>>cgpa;
	Student s2(id,name,dept,cgpa);
	s1.addStudentToFile(s2,fileName);
	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 2){
  	s1.displayStudentsFromFile(fileName);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 3){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	s1.searchStudentByID(fileName,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  	
  }
  
  if(choice == 4){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	s1.deleteRecordByID(filename,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 5){
  	int id;
  	cout<<"Enter ID To Search : ";
  	cin>>id;
  	s1.updateRecordByID(filename,id);
  	cout<<"Enter any number to return to main menu : ";
	cin>>ret;
	cout<<endl;
  }
  
  if(choice == 6){
  	cout<<"Good bye !"<<endl;
  	return 0;
      }
  }
	
}
