#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 100000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define pb push_back
#define fe first
#define se second
//Note that in miller rabin we have to take care of overflow.So in modular exp for miller rabin (a*b)%c might overflow.
//To avoid this we are using a separate function to caluclate (a*b)%c.

//Note that fermat primality test is very simple but it fails for Carmichael numbers.
ll mulmod(ll a,ll b,ll c){
 
  ll x=0,y=a%c;
 
  while(b){
 
    if(b&1){
 
      x=(x+y)%c;
 
    }
 
    y=(y*2)%c;
 
    b/=2;
 
  }
 
  return x%c;
}
//modular expo
ll power(ll x, unsigned long long int  y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res=mulmod(res,x,p);
 
        y = y>>1;
        x=mulmod(x,x,p);
    }
    return res%p;
}
 
//Withj k iterations ,the probability of test failing is (4^-k).
bool miller_rabin(ll p,ll iter){
if(p==2 || p==3)
return true;
else if(p<2 || p%2==0)
return false;
ll s=p-1,d=0;
while(s%2==0){//p-1=2^d*s// s is odd and d>=1
s=s/2;
d++;
}
for(ll i=1;i<=iter;i++){
	ll a=rand()%(p-1)+1;//numbers b/w 1 and p-1
	ll x=power(a,s,p);
	if(x==1 || x==p-1 )
	continue;
	ll j=2*s;
	bool flag=0;
		while(j!=(p-1)){
		x=power(a,j,p);
		dbg2(x,j);
		if(x==p-1){
		flag=1;
		break;}
		j=2*j;
		}
	if(flag==0)
		return false;		
}
return true;
}

int main(){
ll t;cin>>t;
while(t--){
ll n;cin>>n;
if(miller_rabin(n,20))
cout<<"prime";
else
cout<<"composite";
cout<<endl;
}

}

//Ishan Bansal
//Resources used:https://www.topcoder.com/community/data-science/data-science-tutorials/primality-testing-non-deterministic-algorithms/
//https://prrateekk.wordpress.com/
