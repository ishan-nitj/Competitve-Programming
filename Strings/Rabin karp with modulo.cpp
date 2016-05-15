#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 1000000 //10^6
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fi first
#define se second
string s;
ll window_size;

ll arr[mag+1],pw[mag+1];

ll val(char ch){
return (ch-'a'+1);
}

ll sum(ll a,ll b){
return (a%MOD+b%MOD)%MOD;
}

ll diff(ll a,ll b){
return (a-b+MOD)%MOD;
}

ll pro(ll a,ll b){
return ((a%MOD)*(b%MOD))%MOD;
}

void precomputation_of_powers(){
pw[0]=1;
for(ll i=1;i<=mag;i++)
    pw[i]=pro(pw[i-1],27);//
}

void rabin_karp(){
ll i,sum1=0;
for(i=0;i<window_size;i++){
sum1=sum(pro(sum1,27),val(s[i]));
}
arr[0]=sum1;
for(i=1;i<=(s.size()-window_size);i++){
sum1=arr[i-1];
sum1=diff(sum1 ,pro(val(s[i-1]),pw[window_size-1]));
sum1=sum(pro(sum1,27),val(s[i+window_size-1]));
arr[i]=sum1;
}
}

int main(){
cin>>s;
cin>>window_size;
precomputation_of_powers();
rabin_karp();
for(ll i=0;i<=(s.size()-window_size);i++)
    cout<<arr[i]<<endl;
}
