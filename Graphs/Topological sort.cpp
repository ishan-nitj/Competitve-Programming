#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);
#define mag 1000000
#define inf 1e18
#define enter printf("\n")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
// mag ->maximum no of nodes
bool vst[mag+1];
vector<int>mp[mag+1];
int nodes,edges;
vector<int>topo;

void DFS(int v){
vst[v]=1;
vector<int>::iterator it;
for(it=mp[v].begin();it!=mp[v].end();it++){
if(!vst[*it])
DFS(*it);}
topo.push_back(v);
}

void DFSmain(){
int i;
for(i=1;i<=nodes;i++)
if(!vst[i])
DFS(i);
}



int main(){
//freopen("IP.txt","r",stdin);
//freopen("OP.txt","w",stdout);
mset(vst,0);
int x, y,i;
sl(nodes);
sl(edges);

rep(i,edges){
sl(x);sl(y);
mp[x].push_back(y);
}
DFSmain();

reverse(topo.begin(),topo.end());
cout<<"Topological sort is:"<<endl;
for(i=0;i<topo.size();i++)
cout<<topo[i];
}
