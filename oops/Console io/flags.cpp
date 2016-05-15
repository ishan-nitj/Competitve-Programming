#include<iostream>
using namespace std;
int main(){// note that if a flag i set and then another flag is set, then until first flag is not unset ,the first flag
// remains set.// as is happening here.
cout.setf(ios::adjustfield,ios::right);
cout.fill('*');// point is also calculated in the space of width.
cout.width(10);
cout<<-23.22<<endl;
cout.setf(ios::adjustfield,ios::left);
cout.fill('*');// point is also calculated in the space of width.
cout.width(10);
cout<<-23.22<<endl;
cout.setf(ios::adjustfield,ios::internal);
cout.fill('*');// point is also calculated in the space of width.
cout.width(10);
cout<<-23.22<<endl;
}
