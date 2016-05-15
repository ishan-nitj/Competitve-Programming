#include<iostream>
using namespace std;
class time{
int hrs;int mins;
public:
time(int x){// data type of arguement same as that of basic type
hrs=x/60;mins=x%60;
}
time(){// a default constructor is also needed else it will show error

}
void display(){
cout<<hrs<<endl<<mins;
}
};

int main(){
time t;
t=80;//t derived // 80 basic
t.display();
}
