
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mset(x,v) memset(x, v, sizeof(x))
#define pb push_back
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define inf (ll)1e18
#define maxsize 20
ll m,n;
vector<ll>mp[100000];
bool isvalid(ll x,ll y){
    return (x>=1 && x<=n && y>=1 && y<=m);
}
ll hashme(ll x,ll y){
    return (x-1)*m+y;
}
 
 
bool vst[1000000];
ll level[1000000];
 
void BFS(ll start){
    queue<ll>q;
    q.push(start);
    vst[start]=1;
    level[start]=0;
 
    while(!q.empty()){
        ll x=q.front() ;
        q.pop();
        for(auto it:mp[x]){
            if(!vst[it]){
                q.push(it);
                level[it]=level[x]+1;
                vst[it]=1;
            }
        }
    }// while end
}
 
void solve(){
 	ll x,y,d,i,j;cin>>m>>n>>y>>x>>d;
    ll matrix[101][101];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            cin>>matrix[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(isvalid(i,j+1) && abs(matrix[i][j+1]-matrix[i][j])<=d)
                mp[hashme(i,j)].pb(hashme(i,j+1));
            if(isvalid(i+1,j) && abs(matrix[i+1][j]-matrix[i][j])<=d)
                mp[hashme(i,j)].pb(hashme(i+1,j));
            if(isvalid(i,j-1) && abs(matrix[i][j-1]-matrix[i][j])<=d)
                mp[hashme(i,j)].pb(hashme(i,j-1));
            if(isvalid(i-1,j) && abs(matrix[i-1][j]-matrix[i][j])<=d)
                mp[hashme(i,j)].pb(hashme(i-1,j));
        }
 
    BFS(1);
    cout<<level[hashme(x,y)]-1<<endl;
 
}
int main(){
 
    ll t;cin>>t;
    while(t--){
        mset(mp,0);mset(vst,0);mset(level,0);
        solve();
    }
 
} 
