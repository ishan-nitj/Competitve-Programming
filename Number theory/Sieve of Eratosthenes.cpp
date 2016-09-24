#include<bits/stdc++.h>  //Total complexity: N * (½ + ⅓ + ⅕ + … ) = O(NloglogN)


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

ll isprime[10000001] ,primefactors[10000001];// isprime[i] is 1 if i is prime.//
// primefactors[x] contains no. of prime factors of a given no.
// 0 and 1 are not prime. primefactors[0]and  primefactors[1]=0.

void prime(ll n){// Pass the no. upto which you have get isprime and primefactors
int i,j;
isprime[0]=0;isprime[1]=0;
mset(primefactors,0);
for(i=2;i<=n;i++){
if(isprime[i]==1)// i is prime
    {primefactors[i]=1;
    for(j=2*i;j<=n;j=j+i){
      isprime[j]=0;// j is not a prime
    primefactors[j]++;// prime factors of j are increased by one
    }
}
}
}

int main(){
ll i,n;sl(n);
rep(i,n+1)
isprime[i]=1;

prime(n);

return 0;
}
