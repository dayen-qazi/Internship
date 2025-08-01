#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Student {
	public:
    string name;
    string department;
    vector<int> marks;

    void display() const {
        cout << "Name: " << name << endl << "Department: " << department << endl << "Marks: ";
        for (int m : marks){
		cout << m << " , ";
       }
        cout << endl;
    }
};

vector<Student> students;
set<string> uniqueDepartments;
map<string, int> departmentCount;

void addStudent() {
    Student s;
    int numMarks;

    cout << "Enter student name: ";
    cin >> ws;
    getline(cin, s.name);

    cout << "Enter department: ";
    getline(cin, s.department);

    cout << "Enter number of subjects: ";
    cin >> numMarks;
    s.marks.resize(numMarks);

    for (int i = 0; i < numMarks; ++i) {
        cout << "Enter marks of subject " << i+1 << ": ";
        cin >> s.marks[i];
    }

    students.push_back(s);
    uniqueDepartments.insert(s.department);
    departmentCount[s.department]++;
    cout << "Student added successfully !"<<endl;
}

void searchStudent() {
    string name;
    cout << "Enter name to search: ";
    cin >> ws;
    getline(cin, name);

    bool found = false;
    for (Student s : students) {
        if (s.name == name){
        	cout<<endl<<"--- STUDENT DATA ---"<<endl;
            s.display();
            found = true;
        }
    }

    if (!found)
        cout << "Student not found !" <<endl;
}

void deleteStudent() {
    string name;
    cout << "Enter name to delete: ";
    cin >> ws;
    getline(cin, name);

    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->name == name) {
            string dept = it->department;
            departmentCount[dept]--;
            if (departmentCount[dept] == 0) {
                uniqueDepartments.erase(dept);
                departmentCount.erase(dept);
            }
            students.erase(it);
            cout << "Student deleted successfully "<<endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found !"<<endl;
}

void updateStudent() {
    string name;
    cout << "Enter name to update: ";
    cin >> ws;
    getline(cin, name);

    for (auto& s : students) {
        if (s.name == name) {
            string oldDept = s.department;

            cout << "Enter new name: ";
            getline(cin, s.name);

            cout << "Enter new department: ";
            getline(cin, s.department);

            int numMarks;
            cout << "Enter number of marks: ";
            cin >> numMarks;
            s.marks.resize(numMarks);
            for (int i = 0; i < numMarks; ++i) {
                cout << "Enter mark " << i+1 << ": ";
                cin >> s.marks[i];
            }

            if (oldDept != s.department) {
                departmentCount[oldDept]--;
                if (departmentCount[oldDept] == 0) {
                    uniqueDepartments.erase(oldDept);
                    departmentCount.erase(oldDept);
                }
                departmentCount[s.department]++;
                uniqueDepartments.insert(s.department);
            }

            cout << "Student updated successfully"<<endl;
            return;
        }
    }

    cout << "Student not found !"<<endl;
}


void showDepartments() {
    cout << "Unique Departments : "<<endl;
    for (auto dept : uniqueDepartments)
        cout << dept <<endl;
}

void showDepartmentCounts() {
    cout << "Department-wise Student Count:\n";
    for (auto depts : departmentCount)
        cout << depts.first << ": " << depts.second << " students"<<endl;
}

int main() {
    int choice;
    int ret;
    while(true){
        cout << "\n--- Student Management ---"<<endl;
        cout << "1. Add Student"<<endl;
        cout << "2. Search Student"<<endl;
        cout << "3. Delete Student"<<endl;
        cout << "4. Update Student"<<endl;
        cout << "5. Show Unique Departments"<<endl;
        cout << "6. Show Department-wise Student Count"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			addStudent(); 
			cout<<"Enter any number to return to main menu : ";
			cin>>ret;
			break;
            case 2: 
			searchStudent();
			cout<<"Enter any number to return to main menu : ";
			cin>>ret; 
			break;
            case 3: 
			deleteStudent(); 
			cout<<"Enter any number to return to main menu : ";
			cin>>ret;
			break;
            case 4: 
			updateStudent(); 
			cout<<"Enter any number to return to main menu : ";
			cin>>ret;
			break;
            case 5: 
			showDepartments(); 
			cout<<"Enter any number to return to main menu : ";
			cin>>ret;
			break;
            case 6: 
			showDepartmentCounts(); 
			cout<<"Enter any number to return to main menu : ";
			cin>>ret;
			break;
            case 7: 
			cout<<"Exiting program "<<endl; 
			cout<<"Good Bye ! "<<endl;
			return 0;
            default: 
			cout<<"Invalid choice ! Try again"<<endl;
        }
    }

}
