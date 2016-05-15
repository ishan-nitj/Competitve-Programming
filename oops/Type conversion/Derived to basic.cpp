#include<iostream>
using namespace std;

class time{
int hrs;int mins;
public:
void get(){
cin>>hrs>>mins;
}

operator int(){// casting operator is always a member func. of the class
// it has no parameters//It has no return type//It has data type in which derived class is getting converted
return (hrs*60+mins);// since it is a member func. we can directly use data members.
}

};

int main(){
time t;
t.get();
int x=t;// int x=int(t) // same thing
cout<<x;
}
