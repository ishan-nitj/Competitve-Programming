//Time complexity: O(ElgV+ElgE).
//1) Min. spanning tree algo can be converted to max. spanning tree by multiplying  the costs with -1or sorting the edges in reverse order.
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

vector<ll>arr,size;

ll root(ll i){
while(arr[ i ] != i)
{
arr[ i ] = arr[ arr[ i ] ] ;
i = arr[ i ];
}
return i;
}

bool find_(ll x,ll y){
return(root(x)==root(y));
}

void weightedunion(ll A,ll B)
{
    ll root_A = root(A);
    ll root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
arr[ root_A ] = arr[root_B];
size[root_B] += size[root_A];
}
    else
    {
arr[ root_B ] = arr[root_A];
size[root_A] += size[root_B];
}
}

ll kruskal(pair<ll,pair<ll,ll> >* p,ll edges){
ll mincost=0,i;
rep(i,edges){
if(root(p[i].second.first)!=root(p[i].second.second))
{
mincost+=p[i].first;
weightedunion(p[i].second.first,p[i].second.second);
}
}//
return mincost;
}

int main()
{
freopen("IP.txt","r",stdin);
freopen("OP.txt","w",stdout);

ll x, y, wt,nodes, edges,i;
sl(nodes);
sl(edges);

size.resize(nodes+1);// for union find
arr.resize(nodes+1);
rep(i,nodes+1){
arr[i]=i;
size[i]=1;
}

pair<ll,pair<ll,ll> >p[edges];
rep(i,edges){
sl(x);sl(y);sl(wt);
p[i]=make_pair(wt,make_pair(x,y));
}
sort(p,p+edges);
ll mincost=kruskal(p,edges);
pl(mincost);
return 0;
}

