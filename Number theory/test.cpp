//This is an optimized algorithm running in O(E*log(V))// verify
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

void bellman_ford(vector<pair<ll,ll> >mp[],ll src){
ll i,j;
for(i=1;i<=nodes;i++){
t[i]=inf;
}
t[src]=0;

vector<pair<ll,ll> > :: iterator it;
for(it=mp[src].begin();it!=mp[src].end();it++)
t[it->first]=min(t[src]+it->second,t[it->first]);

//for(i=1;i<nodes;i++){
//for(j=1;j<=nodes;j++){
//    if(t[j]!=inf)
//    for(it=mp[j].begin();it!=mp[j].end();it++)
//    t[it->first]=min(t[j]+it->second,t[it->first]);
//}
//
//}



}


int main()
{
freopen("IP.txt","r",stdin);
ll x, y, wt,i;
sl(nodes);
sl(edges);
vector<pair<ll,ll> >mp[nodes+1];//1 based indexing of nodes
t.resize(nodes+1);

rep(i,edges){
sl(x);sl(y);sl(wt);
mp[x].push_back(make_pair(y,wt));
mp[y].push_back(make_pair(x,wt));
}

ll src;sl(src);
bellman_ford(mp,src);


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
