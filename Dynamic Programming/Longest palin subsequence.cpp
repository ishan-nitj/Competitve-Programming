#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100
#define inf 1e18
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define vl vector<ll>
#define pb push_back
string s;
ll dp[mag][mag];
ll lps(ll i,ll j){
ll ans;
if(dp[i][j]!=-1)
    return dp[i][j];
if(i==j)
     ans=1;
else if(j==i+1 && s[j]==s[i])//important step
    ans= 2;
else {
if(s[i]==s[j])
    ans= 2+lps(i+1,j-1);
else
    ans= max(lps(i+1,j),lps(i,j-1));
}
dp[i][j]=ans;
return ans;
}

pair<ll,ll>func(string s){
ll i=0;ll j=s.size()-1;
while(1){
ll ans=dp[i][j];
while(dp[i][j]==ans)
i++;
i--;
while(dp[i][j]==ans)
j--;
j++;
i++;j--;
if(ans==3)
    break;
}
//cout<<"range for middle character is "<<i<<"to"<<j<<endl;
return make_pair(i,j);
}

int main(){
//freopen("IP.txt","r",stdin);
ll t;sl(t);
while(t--){
pair<ll,ll>p1,p2;
string s1,s2;
mset(dp,-1);
cin>>s1;
s=s1;
ll k1=lps(0,s1.size()-1);
if(k1%2==1 )
{
if(k1==1)
p1=make_pair(0,s1.size()-1);
else
p1=func(s1);
}

mset(dp,-1);
cin>>s2;
s=s2;
ll k2=lps(0,s2.size()-1);
if(k2%2==1){
pair<ll,ll>p2;
if(k2==1)
p2=make_pair(0,s2.size()-1);
else
p2=func(s2);
}

ll final_ans;

if(k1%2==1 && k2%2==1){
ll i,j;
ll flag=0;
for(i=p1.first;i<=p1.second;i++)
    for(j=p2.second;j<=p2.second;j++)
    if(s1[i]==s2[j])
    flag=1;
if(flag==0)
final_ans=k1+k2-1;
else
final_ans=k1+k2;
}
else
final_ans=k1+k2;

cout<<final_ans<<endl;
}

}





