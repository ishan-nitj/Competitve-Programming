//verify code by doing a question
// https://www.quora.com/Algorithms/What-are-the-specifics-in-implementing-an-O-N-log-N-Lowest-Common-Ancestor-algorithm
//http://csengerg.github.io/2015/12/24/lowest-common-ancestor.html
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

#define N 1000000 //10^6
#define LGN 25

bool vst[N+1];
ll parent[LGN+1][N+1];
ll depth[N+1];
vector<ll>mp[N+1];
ll nodes, edges;

void dfs(ll u){//calculates depth of each node and 1st(2^0) parent of each node
vst[u]=1;
for(ll i=0;i<mp[u].size();i++){
    ll x=mp[u][i];
    if(vst[x]==0)
        {
          depth[x]=depth[u]+1;
          parent[0][x]=u;
          dfs(x);
        }
}

}

//http://csengerg.github.io/images/post-images/lowest-common-ancestor.svg
//Let x be  2^i parent of a node n and y  is the 2^(i-1) parent of n. Then x is the 2^i-1 parent of y.
void dp_processing(){
ll i,j;
for(i=1;i<=ceil(log2(nodes));i++)
    for(j=1;j<=nodes;j++){
    if(parent[i-1][j]!=-1)
        parent[i][j]=parent[i-1][parent[i-1][j]];
}
}

ll get_parent(ll u,ll k){// get the parent at height k above the node
for(ll i=0;i<=ceil(log2(nodes));i++){
    if(k&1)
        u=parent[i][u];
    k>>=1;}
return u;
}

ll lca(ll u,ll v){//finding lca
if(depth[u]<depth[v])
    v=get_parent(v,depth[v]-depth[u]);
else if(depth[u]>depth[v])
    u=get_parent(u,depth[u]-depth[v]);
if(u==v) return u;
for(ll i=ceil(log2(nodes));i>=0;i--){
    if(parent[i][u]!=parent[i][v]){
    u=parent[i][u];
    v=parent[i][v];
    }
}
return parent[0][u];
}

int main()
{
//freopen("IP.txt","r",stdin);
ll x, y,i,j;
cin>>nodes>>edges;
rep(i,edges){
cin>>x>>y;
mp[x].push_back(y);
mp[y].push_back(x);// for undirected graph
}

mset(parent,-1);// If a particular parent doesnt exists ,set it to -1
mset(vst,0);

depth[1]=0;
dfs(1);//1 is the root node
dp_processing();

ll q;cin>>q;
while(q--){
ll x,y;cin>>x>>y;
cout<<lca(x,y)<<endl;
}
}
//for(i=1;i<=nodes;i       //depth checker
//cout<<depth[i]<<endl;

////for(i=0;i<=ceil(log2(nodes));i { //parent checker
////    for(j=1;j<=nodes;j++)
////        cout<<parent[i][j]<<" ";
////        cout<<endl;}






