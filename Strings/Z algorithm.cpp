#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 1000000 //10^8
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
//Two important points:
//1) When to write z[i]>=val  and z[i]=val
//2) abcabcabc type of string.

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

vector<ll> z_algorithm(string s){//little bit slower
vector<ll>z;
ll n=s.size();
z.resize(n);
ll l=0,r=0;
z[0]=-inf;///////////////////////////////////////////////
for(ll i=1;i<n;i++){
    if(i<=r)
        z[i]=min((r-i+1),z[i-l]);// Case 2.a and 2.b
    while(i+z[i]<n && s[z[i]]==s[i+z[i]])
        ++z[i];//Case 1 and 2.c
    if(i+z[i]-1>r)// Changing the values of l and r if required
        l=i;r=i+z[i]-1;
}
return z;
}

int main()
{
//freopen("IP.txt","r",stdin);

}







