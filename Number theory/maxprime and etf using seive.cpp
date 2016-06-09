#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 10000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

ll maxprime[mag+1];
ll phi[mag+1];
ll s[mag+1];

void maxprimefunc(){
mset(maxprime,0);
maxprime[1]=1;maxprime[0]=0;
// however minprime for 0 and 1 are not defined
ll i,j;
for(i=2;i<=mag;i++){
if(maxprime[i]==0){
    for(j=i;j<=mag;j+=i){
    //if(maxprime[i]==0) // it becomes function for  minprime
    maxprime[j]=i;
    }//
}// if end
}//
}

void etf(){
phi[1]=1;
ll i;
for(i=2;i<=mag;i++){
if(maxprime[i]==i)
phi[i]=i-1;
else{
ll q=i;
ll temp=1;
while(q%maxprime[i]==0){
q=q/maxprime[i];
temp*=maxprime[i];
}
phi[i]=phi[q]*(temp-temp/maxprime[i]);
}
}
}

void solve(){
ll i;
mset(s,0);
for(i=1;i<=mag;i++)
s[i]=s[i-1]+phi[i];
}

int main(){
maxprimefunc();
etf();
solve();
ll t;sl(t);
while(t--){
ll n;sl(n);
pl(s[n]);enter;
}
}
