#include<iostream>
using namespace std;

class Shape{
	public:
	virtual void draw(){
		cout<<"Drawing a shape ..."<<endl;
	}
};

class Circle : public Shape{
	public:
		void draw() override{
			cout<<"Drawing a circle ..."<<endl;
		}
};

class Rectangle : public Shape{
	public:
		void draw() override{
			cout<<"Drawing a rectangle ..."<<endl;
		}
};

class Triangle : public Shape{
	public:
		void draw() override{
			cout<<"Drawing a triangle ..."<<endl;
		}
};

int main(){
	Shape* shape[3];
	shape[0] = new Circle();
	shape[1] = new Rectangle();
	shape[2] = new Triangle();
	
	for(int i = 0 ; i < 3 ; i++){
		shape[i]->draw();
	}
	
	for(int i = 0 ; i < 3 ; i++){
		delete shape[i];
	}
	return 0;
}
