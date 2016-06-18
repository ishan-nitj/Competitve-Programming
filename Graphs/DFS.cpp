//Iterative DFS
//Time complexity of DFS is O(V + E)
//Applications:
//1) To find no. of connected components .
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define pb push_back
#define mag 10000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

void  DFS(vector<ll>* mp,ll nodes,ll start){
bool vst[nodes+1];
mset(vst,0);
stack<ll>s;

s.push(start);
vst[start]=1;

while(!s.empty()){
ll x=s.top() ;
s.pop();
pl(x);
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
//freopen("IP.txt","r",stdin);
//freopen("OP.txt","w",stdout);

ll x, y, nodes, edges,i;
sl(nodes);
sl(edges);
vector<ll>mp[nodes+1];

rep(i,edges){
sl(x);sl(y);
mp[x].push_back(y);
mp[y].push_back(x);
}

DFS(mp,nodes,1);
enter;

return 0;
}
