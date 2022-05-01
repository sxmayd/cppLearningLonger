#include<iostream>
using namespace std;

template<typename T>
class Base{
public:
	void foo(){
		cout << "Base::foo()" << endl;
	}
};

// 提供一个全特化的版本
template<>
class Base<int>{
public:
	void fun(){ //全特化版本不提供foo()接口
		cout << "Base::fun()" << endl;
	}
};

template<typename T>
class Derived: public Base<T>{
public:
	// 法2“
	//using Base<T>::foo;

	void bar(){
		this->foo(); //法1“
		cout << "Derived::bar()" << endl;
	}
};

int main(){
	Derived<double> d;
	d.bar();	
	
	return 0;
}