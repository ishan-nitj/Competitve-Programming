#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 10000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
vector<ll>vst;

void DFS(vector<ll>* mp,ll nodes,ll start){
stack<ll>s;

s.push(start);
vst[start]=1;

while(!s.empty()){
ll x=s.top() ;
s.pop();

vector<ll>::iterator it=mp[x].begin() ;
for(;it!=mp[x].end();it++){
if(!vst[*it]){
s.push(*it);
vst[*it]=1;
}
}// for end

}// while end


}


int main()
{
ll t;sl(t);
while(t--){
ll x, y, nodes, edges,i;
sl(nodes);
sl(edges);
vector<ll> mp[nodes+1];
vst.resize(nodes+1);

for(i=1;i<=nodes;i++){
vst[i]=0;
}

rep(i,edges){
sl(x);sl(y);
mp[x].push_back(y);
mp[y].push_back(x);// undirected graph
}

ll count=0;

for(i=1;i<=nodes;i++){
if(!vst[i]){
DFS(mp,nodes,i);
count++;
}

}

pl(count);
enter;
}
return 0;
}
