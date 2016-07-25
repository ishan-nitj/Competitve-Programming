//Code is very untidy....
//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second
#define mag 12

ll dp[mag][mag][1<<mag];

ll count_one(ll n){
ll count=0;
while(n){
n=n&(n-1);
count++;
}
return count;
}


int main(){
std::ios::sync_with_stdio(false);
cin.tie(0);
//freopen("OP.txt","r",stdin);
//freopen("IP.txt","w",stdout);
ll t;cin>>t;
while(t--){
mset(dp,0);
ll n,i;cin>>n;
ll arr[n],p[n];
rep(i,n)
cin>>arr[i];
rep(i,n)
cin>>p[i];
ll j,k,l;
ll ans=inf;
//O(n^3*2^n)
for(k=0;k<(1<<n);k++)
for(i=0;i<n;i++)
for(j=0;j<n;j++)
dp[i][j][k]=inf;

for(k=0;k<(1<<n);k++)
for(i=0;i<n;i++){
for(j=0;j<n;j++){
//dbg3(i,j,k);
if(i!=j && k&(1<<i) && k&(1<<j) ){
{

if(count_one(k)==2)
dp[i][j][k]=0;
else
//i 2nd last // j last
for(l=0;l<n;l++){//l 3rd last
if(k&(1<<l) && l!=i && l!=j){
//dbg1(l);
dp[i][j][k]=min(dp[i][j][k],(arr[i]^arr[j]^arr[l])*p[count_one(k)-1]+dp[l][i][k-(1<<j)]);}
}//l loop end
//dbg1(dp[i][j][k]);
if(count_one(k)==n)
ans=min(ans,dp[i][j][k]);
}//k loop end

}

}//j loop
}//i loop
cout<<ans<<endl;
//cout<<"ha";

}

}


//clock_t start = clock();
//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);

