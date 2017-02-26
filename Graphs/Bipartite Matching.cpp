//Hopcroft–Karp algorithm
//O(E*sqrt(v))
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

#ifndef ONLINE_JUDGE
#  define dbg(x) (cerr << #x << " = " << (x) << endl)
#else
#  define dbg(x) 0
#endif

#define MAX 100001
#define NIL 0
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

ll xe[5345],ye[5345],xp[5345],yp[5345];

bool meet(ll i,ll j){

    return (xe[i]==xp[j] || ye[i]==yp[j] || abs(xe[i]-xp[j])==abs(ye[i]-yp[j]));
}

void solve(){
    memset(G,0,sizeof(G));
    memset(dist,0,sizeof(dist));
    memset(match,0,sizeof(match));
    ll i,j;cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>xe[i]>>ye[i];
    for(i=n+1;i<=n+m;i++)
        cin>>xp[i]>>yp[i];
    for(i=1;i<=n;i++)
        for(j=n+1;j<=n+m;j++){
            if(meet(i,j)){
                //               cout<<i<<" "<<j<<endl;
                G[i].emplace_back(j);}
        }
    cout<<hopcroft_karp()<<endl;
}

int main(){
    ll q;cin>>q;
    while(q--){
        solve();}
}
