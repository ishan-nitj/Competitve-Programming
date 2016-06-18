//
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
// for a directed graph
int main()
{
ll nodes,edges,i,j;
sl(nodes);sl(edges);
ll gr[nodes+1][nodes+1];
mset(gr,0);
rep(i,edges){
ll x,y;sl(x);sl(y);
gr[x][y]=1;
// for undirected graph gr[y][x]=1;
}
// for displaying
for(i=1;i<=nodes;i++)
{
    for(j=1;j<=nodes;j++){
    pl(gr[i][j]);space;
    }
enter;
}
}
