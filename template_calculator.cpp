#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        throw runtime_error("Division by zero error.");
    }
    return a / b;
}

template <typename T>
class Calculator {
private:
    T num1, num2;

public:
    Calculator(T a, T b) : num1(a), num2(b) {}

    void performOperations() {
        cout << "Addition: " << add(num1, num2) << endl;
        cout << "Subtraction: " << subtract(num1, num2) << endl;
        cout << "Multiplication: " << multiply(num1, num2) << endl;
        try {
            cout << "Division: " << divide(num1, num2) << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
        cout<<endl;
    }
};


int main(){
	int a , b;
	float f1 , f2;
	double d1 , d2;
	cout<<"Enter two integer values : ";
	cin>>a>>b;
	cout<<"Enter two float values : ";
	cin>>f1>>f2;
	cout<<"Enter two double values : ";
	cin>>d1>>d2;
	
    cout << "--- Integer Calculator ---" << endl;
    Calculator<int> intCalc(a, b);
    intCalc.performOperations();

    cout << "--- Float Calculator ---" << endl;
    Calculator<float> floatCalc(f1, f2);
    floatCalc.performOperations();

    cout << "--- Double Calculator ---" << endl;
    Calculator<double> doubleCalc(d1, d2);
    doubleCalc.performOperations();

    return 0;
}
