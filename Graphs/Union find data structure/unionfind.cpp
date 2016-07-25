#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second

vector<ll>arr;

ll root(ll x){
    while(x!=arr[x]){
        x=arr[x];
    }
    return x;
}

bool find(ll x,ll y){// checks whether x and y are in the same set
    return(root(x)==root(y));
}

void union(ll x,ll y){//
    arr[root(y)]=root(x);
}

int main(){
    ll n,i;cin>>(n);
    arr.resize(n+1);
    rep(i,n+1)
        arr[i]=i;// Initially root of each element is the element itself
    ll k;cin>>(k);//No of queries
    while(k--){
        ll i,j;cin>>(i)>>(j);
        union(i,j);//
    }
}
