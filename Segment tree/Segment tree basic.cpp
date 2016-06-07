//Ishan Bansal
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
#define maxn 1000005
//indexing of array is 0-based but that of segment tree is 1-based.

const ll N = 1e5;  // limit for array size
ll n;  // array size
ll t[2 * N];

void build() {  
  for (ll i = n - 1; i > 0; --i) t[i] = t[2*i] + t[2*i+1];
}

void modify(ll p, ll val) {  // set value at position p
	p+=n;t[p]=val;	
	for (; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
//p>>1 is a parent of p in the tree. Another son of p>>1 is p^1, since x^1 gives you x with reversed parity(last bit).
// p^1 equals to p+1 if p is even, and p-1 if p is odd.

ll query(ll node,ll st,ll en,ll l,ll r){//node represents the range st-en
    if(en<l || st>r)//range represented by node lies completely outside l and r
        return 0;
    else if(st>=en && en<=r )//range represented by node lies b/w l and r
        return t[node];
    else
        return (query(2*node,st,(st+en)/2,l,r)+ query(2*node+1,(st+en)/2+1,en,l,r));
}

int main() {
  scanf("%lld", &n);
  for (ll i = 0; i < n; ++i) scanf("%lld", t + n + i);//Note if i is the posn of a element in array , then the posn of leaf node containing that element is n+i in the segment tree.
  build();
  ll q;cin>>q;
  while(q--){
  ll x,y;cin>>x>>y;
  cout<<query(1,0,n-1,x,y)<<endl;
  }
  return 0;
}

