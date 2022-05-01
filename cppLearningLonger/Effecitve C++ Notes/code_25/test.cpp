#include <iostream>
#include "test.h"
#include "stdlib.h"
using namespace WidgetStuff;
 

int main()
{
	WidgetImpl<int>* wimpl_1 = new WidgetImpl<int>(1,2);
	WidgetImpl<int>* wimpl_2 = new WidgetImpl<int>(2,4);
	
	
	Widget<int> w_1 = Widget<int>(wimpl_1);
	Widget<int> w_2 = Widget<int>(wimpl_2);
	
	std::cout << "before swap: " << std::endl;
	w_1.Print();
	w_2.Print();
	
	swap(w_1, w_2);
	
	std::cout << "after swap: " << std::endl;
	w_1.Print();
	w_2.Print();
	
	return 0;
}