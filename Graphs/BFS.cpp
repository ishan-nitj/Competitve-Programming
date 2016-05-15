//Time complexity of BFS is O(V + E)
//Applications:
//1) Determine the level of each node in the given tree.
//2) BFS can be used in finding minimum distance from one node of graph to another,
//provided all the edges in graph have same weight.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);
#define mag 1000000
#define enter printf("\n")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
ll nodes,edges;
map<ll,ll>level;// level
map<ll,ll>color;

void BFS(vector<ll>* mp,ll nodes,ll start){
bool vst[nodes+1];
mset(vst,0);
queue<ll>q;

q.push(start);
vst[start]=1;
level[start]=0;
color[start]=0;
while(!q.empty()){
ll x=q.front() ;
q.pop();
//pl(x);
vector<ll>::iterator it=mp[x].begin() ;
for(;it!=mp[x].end();it++){
if(!vst[*it]){
q.push(*it);
level[*it]=level[x]+1;
color[*it]=(level[*it]%2==0?0:1);
vst[*it]=1;
}
}// for end

}// while end

}

bool isbipartite(vector<ll>* mp){
ll i,j;
for(i=1;i<=nodes;i++)
{
vector<ll>::iterator it1;
for(it1=mp[i].begin();it1!=mp[i].end();it1++){
if(color[*it1]==color[i])
    return false;
}
}
return true;
}

int main()
{
//freopen("IP.txt","r",stdin);
//freopen("OP.txt","w",stdout);
ll x, y,i;
sl(nodes);
sl(edges);
vector<ll>mp[nodes+1];

rep(i,edges){
sl(x);sl(y);
mp[x].push_back(y);
mp[y].push_back(x);// undirected graph
}

BFS(mp,nodes,2);
pl(isbipartite(mp));
return 0;
}
