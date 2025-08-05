#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DivideByZeroException{
public:
    string what() const{
        return "Error: Division by zero.";
    }
};

class InvalidOperatorException{
private:
    string message;
public:
    InvalidOperatorException(const string& op){
        message = "Error: Invalid operator '" + op + "'";
    }

    string what() const{
        return message;
    }
};

void logException(string errorMessage){
    ofstream logFile("error_log.txt", ios::app); 
    if(logFile){
        logFile << errorMessage << endl;
        logFile.close();
    } else{
        cout << "Unable to open file for writing." << endl;
    }
}

double calculate(double a, double b, char op){
    switch(op){
        case '+': 
		return a + b;
        case '-': 
		return a - b;
        case '*': 
		return a * b;
        case '/':
            if(b == 0){
                throw DivideByZeroException();
            }
            return a / b;

        default:
            throw InvalidOperatorException(string(1, op));
    }
}

int main(){
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;


    try {
        double result = calculate(num1, num2, op);
        cout << "Result: " << result << endl;
    }
    catch (const DivideByZeroException& e) {
        string msg = e.what();
        cout << msg << endl;
        logException(msg);
    }
    catch (const InvalidOperatorException& e) {
        string msg = e.what();
        cout << msg << endl;
        logException(msg);
    }

    return 0;
}
