//This is an optimized algorithm running in O(E*log(V))//
//note that pq may contain duplicates

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);
#define enter printf("\n")
#define space printf(" ")
#define mag 1000000
#define MOD 1000000007
#define inf 1e18
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
vector<ll>t,s;
ll nodes, edges;

struct func
{
bool operator()(const ll lhs, const ll rhs) const {
  return(t[lhs] > t[rhs]);
}

};

void dijkstra(ll src,vector<pair<ll,ll> > mp[]){
priority_queue<ll,vector<ll>,func>pq;

for(ll i=1;i<=nodes;i++){
t[i]=inf;
s[i]=0;
}

t[src]=0;
pq.push(src);

while(!pq.empty()){
ll w=pq.top();
pq.pop();

if(s[w]==1)
continue;
else
s[w]=1;

vector<pair<ll,ll> >::iterator it;
for(it=mp[w].begin();it!=mp[w].end();it++){
if(s[it->first]==0){
t[it->first]=min(t[it->first],t[w]+it->second);
pq.push(it->first);
}
}

}

}

int main()
{
//freopen("IP.txt","r",stdin);
ll x, y, wt,i;
sl(nodes);
sl(edges);
vector<pair<ll,ll> >mp[nodes+1];//1 based indexing of nodes
t.resize(nodes+1);s.resize(nodes+1);

rep(i,edges){
sl(x);sl(y);sl(wt);
mp[x].push_back(make_pair(y,wt));
mp[y].push_back(make_pair(x,wt));
}
ll src;sl(src);
dijkstra(src,mp);

for(i=1;i<=nodes;i++)
cout<<i<<" "<<t[i]<<endl;
}

// displaying graph
//for(i=1;i<=nodes;i++)
//{
//pl(i);cout<<"->";
//vector<pair<ll,ll> >::iterator it1;
//for(it1=mp[i].begin();it1!=mp[i].end();it1++){
//cout<<it1->first<<"("<<it1->second<<")"<<" ";
//}
//enter;
//}


