//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) printf("%I64d ",a[i]);
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second


ll modexp(ll x,ll y,ll n){// This can also be done using recursive approach
ll ld,temp,ans=1;
ld =y%2;
y=y/2;
temp=x%n;
if(ld==1)
ans=temp;
while(y!=0){
ld =y%2;
y=y/2;
temp=(temp*temp)%n;
if(ld==1){
ans=(ans*temp)%n;
}
}
return ans;
}

ll mmi(ll x,ll y){/////////BEWARE !!!!
////first check whether this is applicable or not
return (modexp(x,y-2,y));
}

ll div1(ll x,ll y){
return ( (x%MOD)*(mmi(y,MOD)%MOD) )%MOD;
}

ll pro(ll x,ll y){
return ((x%MOD)*(y%MOD))%MOD;
}

ll add(ll x,ll y){
return (x%MOD+y%MOD)%MOD;
}

ll sub(ll x,ll y){// BEWARE!!!
return (x%MOD-y%MOD+MOD)%MOD;
}

//Note that -7%3=-(7%3).
//Sign of ans will be same as that of numerator

int main(){

}
