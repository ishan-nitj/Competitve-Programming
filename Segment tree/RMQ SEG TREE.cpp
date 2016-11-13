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
#define mag 100000
// 1 based indexing
//In update ,it also updates arr.
ll tree[4*mag],arr[mag+1];

void build(ll node,ll st,ll en){// call with node=1//Time complexity O(n)
    if(st==en)
        tree[node]=arr[st];
    else{
        ll mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

ll query(ll node,ll st,ll en,ll l,ll r){
    if(en<l || st>r)//range represented by node lies completely outside l and r
        return 1e18;
    else if(st>=l && en<=r )//range represented by node i.e. b/w st and en lies b/w l and r
        return tree[node];
    else
        return min(query(2*node,st,(st+en)/2,l,r),query(2*node+1,(st+en)/2+1,en,l,r));
}

void update(ll node,ll st,ll en,ll idx,ll val){
    ll mid=(st+en)/2;
    if(st==en){
        arr[idx]=val;
        tree[node]=val;
    }
    else if(idx<=mid){
        update(2*node,st,mid,idx,val);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int main(){
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
 	ll q;cin>>q;
 	while(q--){
 		char ch;cin>>ch;
 		if(ch=='u')
 			{ll x,y;cin>>x>>y;update(1,1,n,x,y);}
 		else
 			{ll x,y;cin>>x>>y;cout<<query(1,1,n,x,y)}
 			cout<<endl;
	}

}

