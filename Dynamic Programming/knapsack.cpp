#include<bits/stdc++.h>
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
ll max_(ll a,ll b){
if(a>b)
return a;
else
return b;
}

int main(){
ios_base::sync_with_stdio(0);
ll k,j,i,r;
sl(k);sl(j);// k capacity // j items
ll v[j+1],w[j+1];
ll dp[k+1][j+1];
for(i=1;i<=j;i++)// weights and values are assigned from index 1.
sl(v[i]);
for(i=1;i<=j;i++)
sl(w[i]);
for(i=0;i<=j;i++){// traversing column wise// i for column // r for row
for(r=0;r<=k;r++){
if(r==0||i==0)
dp[r][i]=0;
else if (w[i]<=r)
dp[r][i]=max_(dp[r][i-1],v[i]+dp[r-w[i]][i-1]);
else
dp[r][i]=dp[r][i-1];
}//
}//
pl(dp[k][j]);
}
