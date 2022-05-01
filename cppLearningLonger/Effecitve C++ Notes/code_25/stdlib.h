#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <iostream>
#include "test.h"

namespace std{
	template<>
	void swap< WidgetStuff::Widget<int> >(WidgetStuff::Widget<int>&a, WidgetStuff::Widget<int>&b) //全特化
	{
		a.swap(b);
		cout << "std::partial" << endl;
	}
} // namespace std

#endif