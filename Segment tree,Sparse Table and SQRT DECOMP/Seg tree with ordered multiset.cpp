#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define dbg(x) cout<<#x<<" ="<<x<<endl;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define pii pair<int,int>
#define N 12345 
typedef tree<
pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update>ordered_set;

struct seg{
    int data[N];
    ordered_set Tree[4*N];

    ordered_set join(ordered_set o1,ordered_set o2){
        ordered_set o;
        for(auto it:o1)
            o.insert(it);
        for(auto it:o2)
            o.insert(it);
        return o;
    }

    void build(ll node,ll st,ll en){
        if(st==en)
            Tree[node].insert(make_pair(data[st],st));
        else{
            ll mid=(st+en)/2;
            build(2*node,st,mid);
            build(2*node+1,mid+1,en);
            Tree[node]=join(Tree[2*node],Tree[2*node+1]);
        }
    }
    void update(ll node,ll st,ll en,ll idx,ll preV,ll neW){// set value at idx from prev to new
        ll mid=(st+en)/2;
        if(st==en){
            data[idx]=neW;
            Tree[node].erase(make_pair(preV,idx));
            Tree[node].insert(make_pair(neW,idx));
        }
        else if(idx<=mid){
            update(2*node,st,mid,idx,preV,neW);
            Tree[node].erase(make_pair(preV,idx));
            Tree[node].insert(make_pair(neW,idx));
        }
        else{
            update(2*node+1,mid+1,en,idx,preV,neW);
            Tree[node].erase(make_pair(preV,idx));
            Tree[node].insert(make_pair(neW,idx));
        }
    }

}seg;

int main(){

    ll n,i;cin>>n;
    for(i=1;i<=n;i++)
        cin>>seg.data[i];
    seg.build(1,1,n);
    //   seg.update(1,1,n,1,seg.data[1],8);

    //debug
    //     for(i=1;i<=7;i++){
    //         auto elem=seg.Tree[i];
    //         for(auto it:elem){
    //             cout<<it.first<<it.second<<" ";
    //         }
    //         cout<<endl;
    //     }

}
