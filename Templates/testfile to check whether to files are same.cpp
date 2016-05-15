#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define eps 1e-10

int main(){
ifstream inf1,inf2;
inf1.open("E:\\Ishan\\Study\\programs\\Graphs\\OP.txt");
inf2.open("E:\\Ishan\\Study\\programs\\Graphs\\test.txt");
ll a,b;
while(inf1.eof()==0){
inf1>>a;
inf2>>b;
if(a!=b)
cout<<"NO"<<endl;
}

}
