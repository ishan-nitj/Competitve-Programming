#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 1000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define parray(a,x,y) for(i=x;i<=y;i++) {pl(a[i]); enter;}

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
int n=4,k=1;// n -> no of bits//k-> no of bits set
int set = (1 << k) - 1;
int limit = ((1 << n)-1)-((1<<(n-k))-1);
while (set <=limit) {
    // Gosper's hack:
    binary(set);enter;
    int c = set & -set;
    int r = set + c;
    set = (((r^set) >> 2) / c) | r;
}

}
