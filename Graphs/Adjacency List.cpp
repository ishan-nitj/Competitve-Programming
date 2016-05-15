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
// for undirected graph mp[y].push_back(x);
}

// for displaying
for(i=1;i<=nodes;i++)
{
cout<<(i);cout<<"->";
vector<ll>::iterator it1;
for(it1=mp[i].begin();it1!=mp[i].end();it1++){
cout<<*it1<<" ";
}
cout<<endl;
}
return 0;
}
