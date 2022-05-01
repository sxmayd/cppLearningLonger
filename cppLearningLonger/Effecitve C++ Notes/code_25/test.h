#ifndef _TEST_H_
#define _TEST_H_



namespace WidgetStuff{

template<typename T>
class WidgetImpl{
public:
    WidgetImpl(const T& _a, const T& _b):a(_a),b(_b) {}

    T a,b;
};

template<typename T>
class Widget{
public:
	Widget(WidgetImpl<T>* _pImpl){
		this->pImpl = _pImpl;
	}

    Widget(const Widget& rhs); //拷贝构造函数
	
    Widget& operator=(const Widget& rhs){ //不太完美的拷贝赋值操作符
		*pImpl = *(rhs.pImpl) ;
    }
	
	
	void swap(Widget& rh){
		using std::swap;
		swap(pImpl, rh.pImpl);
		std::cout << "special for Widget" << std:: endl;
	}
	
	
	
	void Print(){
		std::cout << "(" << (pImpl->a) << ", " << (pImpl->b) << ")" << std::endl; 
	}
private:
    WidgetImpl<T>* pImpl;
};

template<typename T>
void swap(Widget<T>&a, Widget<T>&b) // non-member swap函数，这里并不属于std命名空间
{
	using std::swap;
	a.swap(b);
}

} //namespace WidgetStuff

#endif