#include<iostream>
#include<cmath>
using namespace std;

class Complex{
	double real;
	double img;
	
	public:
		Complex(){
			
		}
		Complex(double r , double i){
			real = r;
			img = i;
		}
		
		Complex operator+(Complex& obj){
			return Complex(real + obj.real,img + obj.img);
		}
		
		Complex operator-(Complex& obj){
			return Complex(real - obj.real,img - obj.img);
		}
		
		Complex operator*(Complex& obj){
			return Complex(
			real * obj.real - img * obj.img,
			real * obj.img + img * obj.real
			);
		}
		
		bool operator==(Complex& obj){
			return real == obj.real && img == obj.img;
		}
		
		double magnitude(){
			return sqrt(real*real + img*img);
		}
		
		bool operator>(Complex& obj){
			return this->magnitude() > obj.magnitude();
		}
		
		void display(){
			cout<<real;
			if(img >= 0){
				cout<<"+"<<img<<"i"<<endl;
			}
			else{
				cout<<"-"<<-img<<"i"<<endl;
			}
		}
		
        friend ostream& operator<<(ostream& COUT , Complex& obj);
        friend istream& operator>>(istream& CIN , Complex& obj);
};

ostream& operator<<(ostream& COUT , Complex& obj){
			COUT<<obj.real;
			if(obj.img >= 0){
				COUT<<"+"<<obj.img<<"i";
			}
			else{
				COUT<<"-"<<-obj.img<<"i";
			}
			return COUT;
	}
	
istream& operator>>(istream& CIN , Complex& obj){
			cout<<"Enter real part : ";
			CIN>>obj.real;
			cout<<"Enter imaginary part : ";
			CIN>>obj.img;
			return CIN;
	}
	
int main(){
	Complex c1,c2;
	
	cout<<"Enter First Complex Number : "<<endl;
	cin>>c1;
	cout<<"Enter Second Complex Number : "<<endl;
	cin>>c2;
	cout<<endl;
	
	cout<<"First Number : "<<c1<<endl;
	cout<<"Second Number : "<<c2<<endl;
	cout<<endl;
	
	Complex sum = c1+c2;
	Complex diff = c1-c2;
	Complex prod = c1*c2;
	
	cout<<"Sum : "<<sum<<endl;
	cout<<"Difference : "<<diff<<endl;
	cout<<"Product : "<<prod<<endl;
	cout<<endl;
	
	cout<<"Comparison : ";
	if(c1 == c2){
		cout<<"Equal"<<endl;
	}
	else{
		cout<<"Not equal"<<endl;
	}
	
	cout<<"Magnitude Comparison : ";
	if(c1 > c2){
		cout<<"First is greater"<<endl;
	}
	else{
		cout<<"Second is greater or equal"<<endl;
   	  }
	
	return 0;
}
		
		
