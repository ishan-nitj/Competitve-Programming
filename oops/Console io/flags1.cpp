#include<iostream>
using namespace std;
int main(){// the flags set through setf function remains active throughout the program unless deactivated through
// unsetf
cout.precision(3);// it can be written after setf statement also
cout.setf(ios::floatfield,ios::fixed);cout.setf(ios::showpos);
cout<<646.3<<endl;// in case of floatfield , the precision is calculated taking in account the digits after decimal.
//trailing zeroes after padded in case precision is lesser.
//
// showpoint is used to show trailing zeroes in the default.
// showpos is used to show + sign.
}
