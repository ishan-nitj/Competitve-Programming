//Always use iterative LCS(i and ii ) --its easy to understand
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
string s1,s2;

int main(){
//freopen("OP.txt","r",stdin);
//freopen("IP.txt","w",stdout);
cin>>s1>>s2;
ll n=s1.size(),m=s2.size(),i,j;
s1="+"+s1;s2="+"+s2;
ll len[n+1][m+1];
ll lcs[n+1][m+1];
mset(len,0);mset(lcs,0);

ll ans1=0,ans2=0;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(s1[i]==s2[j]){
len[i][j]=1+len[i-1][j-1];
ans1=max(ans1,len[i][j]);
}
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(s1[i]==s2[j])
lcs[i][j]=1+lcs[i-1][j-1];
else
lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
ans2=lcs[n][m];
dbg2(ans1,ans2);
}

//clock_t start = clock();
//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);

