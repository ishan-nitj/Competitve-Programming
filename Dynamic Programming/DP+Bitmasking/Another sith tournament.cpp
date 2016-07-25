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
#define mag 935358

double arr[18][18];
double dp[18][1<<18];
bool vst[18][1<<18];

ll n;
ll fu(ll n){
ll count=0;
while(n){
n=n&(n-1);
count++;}
return count;
}


double func(ll idx,ll no){
if(vst[idx][no])
return dp[idx][no];
else
vst[idx][no]=1;
double ans=0.0;
ll i;
if(fu(no)==1){
if(no&1)ans=1.0;
else ans=0.0;
}
for(i=0;i<n;i++){
bool flag=no&(1<<i);
if(idx==i || !flag)continue;
else
ans=max(ans,arr[idx][i]*func(idx,no&~(1<<i))+arr[i][idx]*func(i,no&~(1<<idx)));}
dp[idx][no]=ans;
return ans;
}

int main(){
//freopen("OP.txt","r",stdin);
//freopen("IP.txt","w",stdout);
std::ios::sync_with_stdio(false);
cin.tie(0);
ll i,j;cin>>n;
rep(i,n)
rep(j,n)
cin>>arr[i][j];
double ans=0.0;
for(i=0;i<n;i++){
ans=max(ans,func(i,(1<<n)-1));
}
cout.precision(15);
cout<<std::fixed<<ans;
return 0;
}

//clock_t start = clock();
//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);

