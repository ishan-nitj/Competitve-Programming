 //O(VE)
//As the Bellman-Ford algorithm ONLY works on graphs that don't contain any cycles with negative weights this actually means your un-directed graph mustn't contain any edges with negative weight.
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

//Like other Dynamic Programming Problems, the algorithm calculate shortest paths in bottom-up manner.
//It first calculates the shortest distances for the shortest paths which have at-most one edge in
//the path. Then, it calculates shortest paths with at-nost 2 edges, and so on. After the ith
//iteration of outer loop, the shortest paths with at most i edges are calculated. There can be
//maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times.

//However note that the following implementation doesnot follow the idea that after the ith iteration of outer loop, the
//shortest paths with at most i edges are calculated.For this,see Tim Roughgarden lectures.

//Also note that we cannot use bellman ford for undirected graphs with negative weights.

//To detect if there is any negative weight cycle in the directed graph , we can add an edge from the start vertex to every
//other vertex ,and then apply bellman ford.

void bellman_ford(vector<pair<ll,ll> >mp[],ll src){
ll i,j;
for(i=1;i<=nodes;i++){
t[i]=inf;
}
t[src]=0;

vector<pair<ll,ll> > :: iterator it;

for(i=1;i<nodes;i++){//O(nodes-1) times
    for(j=1;j<=nodes;j++){//O(edges)
        if(t[j]!=inf)
        for(it=mp[j].begin();it!=mp[j].end();it++)
        t[it->first]=min(t[j]+it->second,t[it->first]);
    }
}

bool flag=1;
for(j=1;j<=nodes;j++){//detecting negative cycle if reachable from start vertex
    if(t[j]!=inf)
        for(it=mp[j].begin();it!=mp[j].end();it++)
            if((t[j]+it->second) < t[it->first])
                flag=0;}
var_val(flag);
}

int main()
{
//freopen("IP.txt","r",stdin);

ll x, y, wt,i;
sl(nodes);
sl(edges);
vector<pair<ll,ll> >mp[nodes+1];//1 based indexing of nodes
t.resize(nodes+1);

rep(i,edges){
sl(x);sl(y);sl(wt);
mp[x].push_back(make_pair(y,wt));
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
