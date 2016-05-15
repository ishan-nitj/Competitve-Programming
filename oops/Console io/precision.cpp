#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 100
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define size 10
int main(){
// in case of default ,precision calculated taking in account both the digits before and after decimal.
float a=15.03654643;
cout<<a<<endl;// default precision is 6
cout.precision(2);
float b=15.03654643;
cout<<b<<endl;// default precision is 6
cout<<23.5659<<endl;// precision once set remains for all the variables.
cout.precision(4);
cout<<12.350<<endl;// trailing zeroes  are not displayed
cout<<236446661.2323<<endl;// if a number is getting reduced in the magnitude, then it will
// be converted to scientific
//2.364e+008 // 3 bits reserved for the exponential part/
// 2.364 // width=4.
}
