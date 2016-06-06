#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 100000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second

string s,sans;

vector<ll> z_algo(string s ){//faster
ll L = 0, R = 0;
ll n=s.size();
vector<ll>z(n);
for (ll i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    ll k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}

void part1(){
ll i;
string srev=s;
reverse(srev.begin(),srev.end());
string st=s+"$"+srev;
vector<ll>z=z_algo(st);
ll ans1=-1;
for(i=z.size()-1;i>=s.size()+1;i--){
ll reqd=z.size()-1-i+1;
if(z[i]==reqd)
ans1=max(ans1,reqd);
}
//print_array(z,z.size());cout<<endl;
//var_val(ans);
st=srev+"$"+s;
z=z_algo(st);
ll ans2=-1;
for(i=z.size()-1;i>=s.size()+1;i--){
ll reqd=z.size()-1-i+1;
if(z[i]==reqd)
ans2=max(ans2,reqd);
}
//print_array(z,z.size());cout<<endl;
//var_val(ans);
sans=srev.substr(0,ans2)+s.substr(0,ans1);
cout<<sans<<endl;
}

void part2(){
vector<ll>z=z_algo(sans);
ll arr[sans.size()+1];
ll dp[sans.size()+1];
mset(arr,0);
mset(dp,0);
z[0]=sans.size();
for(ll i=0;i<z.size();i++){
arr[z[i]]++;
}
dp[sans.size()]=arr[sans.size()];
for(ll i=sans.size()-1;i>=0;i--){
dp[i]=dp[i+1]+arr[i];
}
for(ll i=1;i<=sans.size();i++){
cout<<dp[i]<<" ";
}
}

int main()
{
cin>>s;
part1();
part2();
}


