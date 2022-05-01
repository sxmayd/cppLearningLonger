#include<iostream>
#include<memory>
using namespace std;

class Point{
public:
	Point(int _x, int _y): x(_x), y(_y){}
	
	void setX(int newVal){ x = newVal;}
	void setY(int newVal){ y = newVal;}
	
	void Print(){
		cout << "(" << x << ", " << y << ")" << endl;
	}
	
private:
	int x;
	int y;
};

struct RectData{
	RectData(Point& _ulhc, Point& _lehc):ulhc(_ulhc), lehc(_lehc){}
	Point ulhc;
	Point lehc;
};

class Rectangle{
public:
	Rectangle(shared_ptr<RectData> _pData):pData(_pData){}
	
	/*
	// 返回handles，导致数据被修改
	Point& upperLeft() const{return pData->ulhc; }
	Point& lowerRight() const{return pData->lehc; }
	*/
	
	// 解决方案很简单
	const Point& upperLeft() const{return pData->ulhc; }
	const Point& lowerRight() const{return pData->lehc; }
	
	void Print(){
		(pData->ulhc).Print();
		(pData->lehc).Print();
	}

private:
	shared_ptr<RectData> pData;
};

int main(){
	Point coord1(0, 0);
	Point coord2(100, 100);
	
	shared_ptr<RectData> p(new RectData(coord1, coord2)); // 注意指针的初始化

	Rectangle rec(p);
	rec.Print();
	
	//rec.upperLeft().setX(50); // 这样就无法修改
	rec.Print();
	
	return 0;
}