#include<iostream>
using namespace std;

class Base{
public:
	virtual void mf1() = 0;
	virtual void mf1(int x){
		cout << "Base mf1(int)" << x << endl;
	}
	virtual void mf2(){
		cout << "Base mf2" << endl;
	}
	void mf3(){
		cout << "Base mf3" << endl;
	}
	void mf3(double x){
		cout << "Base mf3(double)" << x << endl;
	}
};

class Derived : public Base{
public:
	using Base::mf1;
	using Base::mf3;
	
	virtual void mf1(){
		cout << "Derived mf1" << endl;
	}
	void mf3(){
		cout << "Derived mf3" << endl;
	}
	void mf4(){
		cout << "Derived mf4" << endl;
	}
};

int main(){
	int x = 2;
	
	Derived d;
	d.mf1();
	d.mf1(x);  // using Base::mf1; 需要这个才能通过编译
	d.mf2();		
	d.mf3();
	d.mf3(x);  // using Base::mf3; 需要这个才能通过编译
	
	return 0;
}