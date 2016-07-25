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
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define dbg(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define pb push_back
#define fe first
#define se second
ll power(ll x,ll y){// This can also be done using recursive approach
ll n=3;
ll ld,temp,ans=1;
ld =y%2;
y=y/2;
temp=x%n;
if(ld==1)
ans=temp;
while(y!=0){
ld =y%2;
y=y/2;
temp=(temp*temp)%n;
if(ld==1){
ans=(ans*temp)%n;
}
}
return ans;
}

// 1 based indexing
ll tree[2*mag],arr[mag+1];

void build(ll node,ll st,ll en){// call with node=1
    if(st==en)
        tree[node]=arr[st];
    else{
        ll mid=(st+en)/2;
		ll diff=en-(mid+1)+1;
//		dbg(mid,2*node,2*node+1);
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node]=power(2,diff)*tree[2*node]+tree[2*node+1];
		tree[node]=tree[node]%3;    
}
}

ll query(ll node,ll st,ll en,ll l,ll r){
	ll mid=(st+en)/2;
	ll zero=0;	
    if(en<l || st>r)//range represented by node lies completely outside l and r
        return 0;
    else if(st>=l && en<=r )//range represented by node lies b/w l and r
        return (power(2,r-en)*tree[node])%3;
    else
        return (query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r))%3;
}

void update(ll node,ll st,ll en,ll idx){
    ll mid=(st+en)/2;
    tree[node]=tree[node]+power(2,en-idx);
	tree[node]%=3;
    if(st==en){
        arr[idx]=1;
        tree[node]=1;
    }
    else if(idx<=mid){
        update(2*node,st,mid,idx);
    }
    else{
        update(2*node+1,mid+1,en,idx);
        }
}

int main()
{
ll n;cin>>n;
string s;cin>>s;
for(ll i=1;i<=n;i++)
arr[i]=(s[i-1]=='0'?0:1);
build(1,1,n);
ll q;cin>>q;
while(q--){
ll type,x,y;cin>>type;
if(type==1){
cin>>x;
x++;
if(arr[x]==0)
update(1,1,n,x);}
else{
cin>>x>>y;
x++;y++;
cout<<query(1,1,n,x,y)<<endl;
}
}

}
