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
#define mag 20
ll n;
ll arr[mag],edge[mag][mag];
ll dp[mag][1<<mag];

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
ll m,k,i,j,K;cin>>n>>m>>K;

rep(i,n)cin>>arr[i];
while(K--){ll x,y,wt;cin>>x>>y>>wt;edge[x-1][y-1]=wt;}
ll ans=0;

for(j=0;j<1<<n;j++)
for(i=0;i<n;i++){
if(!(j&(1<<i)))
continue;
for(k=0;k<n;k++){
if(!(j&(1<<k)))
continue;
ll mask=j-(1<<i);//unset ith bit
dp[i][j]=max(dp[i][j],dp[k][mask]+edge[k][i]+arr[i]);
if(count_one(j)==m)
ans=max(ans,dp[i][j]);
}//k loop end

}//i loop end
cout<<ans;
}


//clock_t start = clock();
//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);

