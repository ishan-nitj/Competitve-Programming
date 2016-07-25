//Use this algo to calculate ancestor parent reln.

//Some new points:
//http://www.geeksforgeeks.org/check-if-two-nodes-are-on-same-path-in-a-tree/
//Time Complexity – O(n) for preprocessing and O(1) per query.


//Ishan Bansal
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100
#define inf 1e18
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define vi vector<int>
#define pb push_back
// mag ->maximum no of nodes
bool vst[mag+1];
vector<ll>mp[mag+1];
ll pi[mag+1];
ll nodes,edges;
vector<pair<ll,ll> >tree_edge,back_edge,cross_edge,forward_edge;

bool isancestor(ll p,ll s){
bool flag=0;
while(pi[s]!=-1){
s=pi[s];
if(s==p)
flag=1;
}
return flag;
}

void DFS1(ll v){
pi[v]=-1;
vst[v]=1;
vector<ll>::iterator it;

for(it=mp[v].begin();it!=mp[v].end();it++){
if(!vst[*it]){
DFS1(*it);
pi[*it]=v;
}

}

}

void DFS1main(){
ll i;
for(i=1;i<=nodes;i++){
if(!vst[i])
DFS1(i);
}
}

void DFS2(ll v){

vst[v]=1;
//cout<<v;//
vector<ll>::iterator it;

for(it=mp[v].begin();it!=mp[v].end();it++){
if(!vst[*it]){
DFS2(*it);
tree_edge.pb(make_pair(v,*it));
}

else{
if(isancestor(*it,v))
back_edge.pb(make_pair(v,*it));
else if(isancestor(v,*it))
forward_edge.pb(make_pair(v,*it));
else
cross_edge.pb(make_pair(v,*it));
}

}

}

void DFS2main(){
ll i;
for(i=1;i<=nodes;i++){
if(!vst[i])
DFS2(i);
}
}

int main(){
freopen("IP.txt","r",stdin);
//freopen("OP.txt","w",stdout);
mset(vst,0);
ll x, y,i;
sl(nodes);
sl(edges);

rep(i,edges){
sl(x);sl(y);
mp[x].push_back(y);
}

DFS1main();
mset(vst,0);
DFS2main();
vector<pair<ll,ll> > :: iterator it;
for(it=back_edge.begin();it!=back_edge.end();it++)
cout<<it->first<<" "<<it->second<<endl;
}
