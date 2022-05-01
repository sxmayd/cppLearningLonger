#include<iostream>
using namespace std;

int main(){

    float f = 16625; // f = 1.0;
    //float ff = 256.0;
    //float c = *(short* )&f;
    float c = 123;

    cout << "c = " << c << endl;
    cout << "c's address = " << &c << endl;
    cout << "f's address = " << &f << endl;
    cout << sizeof(float) << endl;
    //cout << "ff's address = " << &ff << endl;

    return 0;
}