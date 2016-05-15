#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define MAX 100000000

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))



ll etf_func(ll n,vector<ll>mp){// here mp contains all the prime factors of n
 ll i;
 ll etf=n;
 loop(i,2,sqrt(n)){
     if(n%i==0){
        mp.push_back(i);
        etf=(etf*(i-1))/i;
        n=n/i;
            while(n%i==0){
                n=n/i;
            }
             }

 }
 if(n>1){
mp.push_back(n);
etf=(etf*(n-1))/n;
 }
return etf;
 }

int main(){
ll t;sl(t);
while(t--){

}


}
