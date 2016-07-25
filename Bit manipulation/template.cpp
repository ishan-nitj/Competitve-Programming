#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

#define enter printf("\n")
#define space printf(" ")
#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

//binary representation of (x-1) can be obtained by
//simply flipping all the bits to the right of rightmost 1 in x and also including the rightmost 1.

bool ispoweroftwo(ll n){//O(1)
if(n==0)
return false;
else return !(n&(n-1));
}

//Count the number of ones in the binary representation of the given number
//  by performing x&(x-1), and storing it in x, will reduce x to
//a number containing number of ones(in its binary form) less than the previous
// state of x, thus increasing the value of count in each iteration.
ll count_one(ll n){
ll count=0;
while(n){
n=n&(n-1);
count++;
}
return count;
}

// Check if the i th bit is set in the binary form
// of the given number
/*Let’s say we have a number N, and to check whether it’s i th bit is set or not, we can AND it with the
number 2 i . The binary form of 2 i contains only i th bit as set (or 1), else every bit is 0 there. When we
will AND it with N, and if the i th bit of N is set, then it will return a non zero number (2 i to be specific),
else 0 will be returned*/
bool check(ll n,ll i){//
//While counting nth bit, we start from LSB with 0th bit.
return (n&(1<<i));
}

void subsets(int a[],ll n){
ll i,j;
for(i=0;i<(1<<n);i++){
   for(j=0;j<n;j++){
        if(i&(1<<j))
        pl(a[j]);
   }
enter;
}//
}

void binary(ll n){
stack<int>s;
while(n){
s.push(n&1);
n=n>>1;
}
while(!s.empty()){
cout<<s.top();
s.pop();}
}



int main(){
ios_base::sync_with_stdio(0);
binary(9);
return 0;
}
