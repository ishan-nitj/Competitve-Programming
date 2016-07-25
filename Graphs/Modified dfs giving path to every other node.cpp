//Ishan Bansal
//Suppose we want to find the path from node 1 to every other node. Do DFS from node 1 and mark predecessor of every other node.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);
#define mag 100
#define inf 1e18
#define enter printf("\n")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
// mag ->maximum no of nodes
bool vst[mag+1];
int pi[mag+1][mag+1];
vector<int>mp[mag+1];
int nodes,edges;
int n,m;

void DFS(int start,int v){
pi[start][v]=-1;
vst[v]=1;
//cout<<v;//
vector<int>::iterator it;
for(it=mp[v].begin();it!=mp[v].end();it++){
if(!vst[*it]){
DFS(start,*it);
pi[start][*it]=v;}
}
}





