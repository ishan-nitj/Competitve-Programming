//1 based indexing of nodes
//Using adjacency matrices
//Ignore the self loops
//If there is cycle, kirchoffs law will be violated there.This code will work.
//O((V^2)*maxflow)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

#ifndef ONLINE_JUDGE
#  define dbg(x) (cerr << #x << " = " << (x) << endl)
#else
#  define dbg(x) 0
#endif
#define mag 12345

ll V[1234][1234];
ll pre[1234];
ll v,e;
ll vis[1234];

ll dfs(ll x){
    vis[x]=1;
    for(ll i=1;i<=v;i++){
        if(!vis[i] && V[x][i]){
            dfs(i);
            pre[i]=x;
        }
    }
}

ll maxFlow(ll s,ll t){
    ll sum=0,k=1;
    while(1){
        memset(pre,-1,sizeof(pre));
        memset(vis,0,sizeof(vis));
        dfs(s);
        if(pre[t]==-1)
            break;
        ll curr=t;
        ll val=LLONG_MAX;
        while(pre[curr]!=-1){
            val=min(val,V[pre[curr]][curr]);
            curr=pre[curr];
        }
        curr=t;
        while(pre[curr]!=-1){
            V[pre[curr]][curr]-=val;
            V[curr][pre[curr]]+=val;
            curr=pre[curr];
        }
        sum+=val;
    }   
    return sum;
}



int main(){
          cin>>v;
          ll i,j;
          for(i=1;i<=v;i++)
          for(j=1;j<=v;j++)
          cin>>V[i][j];

          ll s,t;
          cin>>s>>t;
          cout<<maxFlow(s,t);
}
