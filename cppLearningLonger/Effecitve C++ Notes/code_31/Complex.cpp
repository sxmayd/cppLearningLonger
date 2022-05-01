#include"Complex.h"
#include"Simple1.h" // 注意：隔离变化，在cpp中引入头文件，在h中只是引入声明
#include<iostream>
using namespace std;

void Complex::funMethod(){
	cout << "Complex Method" << endl;
	ps->funMethod();
}



