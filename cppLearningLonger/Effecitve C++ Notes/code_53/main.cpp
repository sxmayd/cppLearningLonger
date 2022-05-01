#include<iostream>
using namespace std;

class Base{
public:
	virtual void fun() const{
		cout << "Base::fun()" << endl;
	}
};

class Derived : public Base{
public:
	using Base::fun;
	virtual void fun() const{
		Base::fun();
		cout << "Derived::fun()" << endl;
	}
};

int main(){
	Base* pd = new Derived;
	//Derived d;
	pd->fun();
	
	
	return 0;
}