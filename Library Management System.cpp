#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class LibraryItem{
protected:
    int id;
    char title[50];
    char author[50];
    int quantity;

public:
    virtual void input() = 0;
    virtual void display() const = 0;
    virtual int getID() const = 0;
    virtual void update() = 0;
};

class Book : public LibraryItem{

public:
    void input() override{
        cout << "Enter Book ID: "; 
		cin >> id;
        cin.ignore();
        cout << "Enter Title: "; 
		cin.getline(title, 50);
        cout << "Enter Author: "; 
		cin.getline(author, 50);
		cout<<"Enter quantity : ";
		cin>>quantity;
    }

    void display() const override{
    	cout<<endl;
        cout << "ID : " << id << " |  Title : " << title << " |  Author : " << author << " |  Quantity : "<< quantity << endl;
    }

    int getID() const override{
        return id;
    }

    void update() override{
        cout << "Updating Book ID " << id << " : " << endl;
        cin.ignore();
        cout<<endl;
        cout << "Enter New Title: "; 
		cin.getline(title, 50);
        cout << "Enter New Author: "; 
		cin.getline(author, 50);
		cout<<"Enter New Quantity : ";
		cin>>quantity;
    }
};


void addItem(){
    Book b;
    ofstream outFile("library.dat", ios::binary | ios::app);
    b.input();
    outFile.write((char*)&b, sizeof(b));
    outFile.close();
    cout << "Book added successfully !" << endl;
}

void displayItems(){
    Book b;
    ifstream inFile("library.dat", ios::binary);
    cout<<endl;
    cout << " All Books : " <<endl;
    while (inFile.read((char*)&b, sizeof(b))) {
        b.display();
    }
    inFile.close();
}

void searchItem(int id){
    Book b;
    ifstream inFile("library.dat", ios::binary);
    bool found = false;

    while (inFile.read((char*)&b, sizeof(b))){
        if (b.getID() == id) {
        	cout<<endl;
            cout << "Book Data : "<<endl;
            b.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found ! "<<endl;
    }

    inFile.close();
}

void updateItem(int id){
    Book b;
    fstream file("library.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (!file.eof()) {
        streampos pos = file.tellg();
        file.read((char*)&b, sizeof(b));
        if (file && b.getID() == id) {
            b.update();
            file.seekp(pos);
            file.write((char*)&b, sizeof(b));
            cout << "Book updated successfully !"<<endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found !"<<endl;

    file.close();
}

void deleteItem(int id){
    Book b;
    ifstream inFile("library.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    bool found = false;

    while (inFile.read((char*)&b, sizeof(b))){
        if (b.getID() == id) {
            found = true;
            continue;
        }
        outFile.write((char*)&b, sizeof(b));
    }

    inFile.close();
    outFile.close();

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
        cout << "Book deleted successfully !"<<endl;
    else
        cout << "Book not found !"<<endl;
}

void menu(){
    int choice , id , ret;

    do{
    	cout<<endl;
        cout << "=== Library Management System ==="<<endl<<endl;
        cout << "1. Add Book "<<endl;
        cout << "2. Display All Books "<<endl;
        cout << "3. Search Book by ID "<<endl;
        cout << "4. Update Book "<<endl;
        cout << "5. Delete Book "<<endl;
        cout << "6. Exit "<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: 
			addItem();
			cout<<endl;
			cout<<"Enter Any Number To Return To Main Menu : ";
			cin>>ret;
			cout<<endl;
			break;
			
            case 2:
			displayItems(); 
			cout<<endl;
			cout<<"Enter Any Number To Return To Main Menu : ";
			cin>>ret;
			cout<<endl;
			break;
			
            case 3:
                cout << "Enter ID to search: "; 
				cin >> id;
                searchItem(id);
                cout<<endl;
		    	cout<<"Enter Any Number To Return To Main Menu : ";
		        cin>>ret;
			    cout<<endl;
                break;
                
            case 4:
                cout << "Enter ID to update : "; 
				cin >> id;
                updateItem(id);
                cout<<endl;
			    cout<<"Enter Any Number To Return To Main Menu : ";
			    cin>>ret;
			    cout<<endl;
                break;
                
            case 5:
                cout << "Enter ID to delete: "; 
				cin >> id;
                deleteItem(id);
                cout<<endl;
		        cout<<"Enter Any Number To Return To Main Menu : ";
			    cin>>ret;
			    cout<<endl;
                break;
                
            case 6:
            	cout<<endl;
                cout << "Exiting....."<<endl;
                cout<<"Good Bye ! "<<endl;
                break;
                
            default:
                cout << "Invalid choice ! Enter Again "<<endl;
        }
    } while(choice != 6);
}

int main() {
    menu();
    return 0;
}
