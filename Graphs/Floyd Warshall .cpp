//Floyd Warshall Algorithm can be used, we can calculate the distance matrix dist[V][V] using Floyd Warshall,
//if dist[i][j] is infinite, then j is not reachable from i, otherwise j is reachable and value of dist[i][j] will be
//less than inf.
//Time Complexity: O(V^3)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define mag 100000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second
int main()
{
ll nodes,edges,i,j,k;
cin>>nodes>>edges;
ll gr[nodes+1][nodes+1];// 1based indexing
vector<ll>path[nodes+1][nodes+1];
mset(gr,0);

for(i=1;i<=nodes;i++)
for(j=1;j<=nodes;j++)
if(i!=j)
gr[i][j]=inf;

rep(i,edges){
ll x,y,wt;cin>>x>>y>>wt;
gr[x][y]=wt;
//gr[y][x]=wt;// for undirected graph
}

for(k=1;k<=nodes;k++)
for(i=1;i<=nodes;i++)
for(j=1;j<=nodes;j++){
if(gr[i][k]+gr[k][j]<gr[i][j])
    path[i][j].pb(k);
gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
}

for(i=1;i<=nodes;i++){
for(j=1;j<=nodes;j++){
cout<<gr[i][j]<<" ";
}
cout<<endl;
}

for(i=1;i<=nodes;i++)
for(j=1;j<=nodes;j++){
    cout<<"Path from "<<i<<"to"<<j<<":"<<endl;
    cout<<i<<" ";
    for(auto it:path[i][j])
        cout<<it<<" ";
    cout<<j;
cout<<endl;
}

}
