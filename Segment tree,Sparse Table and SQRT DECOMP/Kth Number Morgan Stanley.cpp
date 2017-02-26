#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 100005
#define dbg(x) cout<<#x<<" "<<x<<endl;

vector<ll>tree[4*mag];
ll arr[mag];
ll x;
void build(ll node,ll st,ll en){
    if(st==en)
        tree[node].push_back(arr[st]);
    else{
        ll mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
    }
}

ll query(ll node,ll st,ll en,ll k){
    //dbg(node);
    //dbg(k);
    if(st==en){
        return *tree[node].begin();}
    auto pos=lower_bound(tree[2*node].begin(),tree[2*node].end(),x);
    ll cnt=-distance(tree[2*node].end(),pos);
    //dbg(cnt);
    if(cnt>=k)
        return query(2*node,st,(st+en)/2,k);
    else
        return query(2*node+1,(st+en)/2+1,en,k-cnt);
}

int main(){
    ll i,n;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
    while(q--){
        ll k;
        cin>>x>>k;
        cout<<query(1,1,n,k)<<endl;
    }
}
