 #include<iostream>
 #include<vector>
 #include<iomanip>
 using namespace std;
 
 class Student{
 	private:
 	int rollNo;
 	string name;
 	int marks1;
 	int marks2;
 	int marks3;
 	char grade;
 	int total;
 	float average;
 	
 	public:
 		
     char calculateGrade(){
	 	if(average >= 85){
	 		return 'A';
		 }
		else if(average < 85 && average >= 70){
			return 'B';
		} 
		else if(average < 70 && average >= 60){
			return 'C';
		}
		else if(average < 60 && average >= 50){
			return 'D';
		}
		else{
			return 'F';
		}
	 }
	 
 	Student(int roll,string n,int m1,int m2,int m3){
 		rollNo = roll;
 		name = n;
 		marks1 = m1;
 		marks2 = m2;
 		marks3 = m3;
 		total = m1+m2+m3;
 		average = total/3;
 		grade = calculateGrade();
	 }
	 
	 int getRollNo(){
	 	return rollNo;
	 }
	 
	 void display(){
	 	cout<<"  "<<rollNo<<setw(20)<<name<<setw(20)<<total<<setw(22)
	 	<<average<<setw(20)<<grade<<endl;
	 }
 	
 };
 
 void banner(){
 	cout<<"============================================================================================="<<endl;
 	cout<<" "<<"ROLL NO"<<"             "<<"NAME"<<"              "<<"TOTAL MARKS"<<"              "
 	<<"AVERAGE"<<"              "<<"GRADE"<<endl;
 	cout<<"============================================================================================="<<endl;
 }
 
 void searchStudentByID(vector <Student> students , int target){
 	 bool found = false;
 	 for(int i = 0 ; i < students.size() ; i++){
 	 	int rollNo = students[i].getRollNo();
 	 	if(rollNo == target){
 	 		   banner();
 	 	       students[i].display();
 	 	       found = true;
		  }
	  }
	  
	  if(!found){
	  	cout<<"Student With Roll No "<<target<<" Not Found"<<endl;
	  }
 }
 
 
 int menu(){
 	int choice;
 	while(!(choice <= 4 && choice > 0)){
 	cout<<"1. Add Student"<<endl;
 	cout<<"2. Display All Students"<<endl;
 	cout<<"3. Display Student By ID"<<endl;
 	cout<<"4. Exit"<<endl;
 	cout<<"Enter Choice : ";
 	cin>>choice;
 	if(choice <= 0 || choice > 4){
 		cout<<"Invalid Input ! Enter Again "<<endl;
	 }
    }
    return choice;
}
 
 int main(){
 	vector <Student> students;
 	int choice = 0;
 	int back;
 	
 	while(!(choice == 4)){
 		choice = menu();
 		
 		if(choice == 1){
 			int rollNo;
 	        string name;
         	int marks1 = -1;
 	        int marks2= -1;
 	        int marks3 = -1;
 			cout<<"Enter Roll No : ";
 			cin>>rollNo;
 			cout<<"Enter Name : ";
 			cin>>name;
 			while(!(marks1 >= 0 && marks1 <= 100)){
 			cout<<"Enter Marks Of First Subject : ";
 			cin>>marks1;
 			if(marks1 < 0 || marks1 > 100){
 				cout<<"Invalid Marks ! Enter Again "<<endl;
			 }
 		    }
 		    while(!(marks2 >= 0 && marks2 <= 100)){
 			cout<<"Enter Marks Of Second Subject : ";
 			cin>>marks2;
 			if(marks2 < 0 || marks2 > 100){
 				cout<<"Invalid Marks ! Enter Again "<<endl;
			 }
 		    }
 		    while(!(marks3 >= 0 && marks3 <= 100)){
 			cout<<"Enter Marks Of Third Subject : ";
 			cin>>marks3;
 			if(marks3 < 0 || marks3 > 100){
 				cout<<"Invalid Marks ! Enter Again "<<endl;
			 }
 	    	}
 	    	
 			Student s1(rollNo,name,marks1,marks2,marks3);
 			students.push_back(s1);
 			cout<<"Added Successfully !"<<endl;
 			cout<<"Enter Any Number To Return To Main Menu : ";
 			cin>>back;
		 }
		 
		 if(choice == 2){
		 	banner();
		 	for(Student student : students){
		       student.display();
			 }
			 cout<<endl<<endl;
			 cout<<"Enter Any Number To Return To Main Menu : ";
 			 cin>>back;
		 }
		 
		 if(choice == 3){
		 	int roll;
		 	cout<<"Enter Roll No To Search : ";
		 	cin>>roll;
		 	searchStudentByID(students,roll);
		 	cout<<"Enter Any Number To Return To Main Menu : ";
 			cin>>back;
		 }
		 
		 if(choice == 4){
		   cout<<endl<<endl;
		   cout<<"Good Bye !"<<endl;
		   return 0;
		 }
	 }
 	
}
