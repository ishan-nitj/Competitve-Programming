//Make sure you use int here
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>

#ifndef ONLINE_JUDGE
#define dbg(x) (cerr << #x << " = " << (x) << endl)
#define dbg2(x,y) (cerr << #x << " = " << (x) <<" "<<#y<<" = "<<y<< endl)

#else
#define dbg(x) 0
#define dbg2(x,y) 0
#endif
#define MAXN 200005
#define LOGN 20

ll n;
ll A[MAXN];
ll ST1[LOGN][MAXN];
ll B[MAXN];
ll ST2[LOGN][MAXN];

void build1()
{

    ll h = floor(log2(n));

    // base case
    for (ll j = 0; j < n; j++) ST1[0][j] = A[j];

    // iterative dynamic programming approach
    for (ll i = 1; i <= h; i++)
        for (ll j = 0; j + (1<<i) <= n; j++)
            ST1[i][j] = max(ST1[i-1][j], ST1[i-1][j + (1<<(i-1))]);
}

ll query1(ll l, ll r)          // query in range [l,r]
{
    r++;
    ll p = 31 - __builtin_clz((r-l));
    return max(ST1[p][l], ST1[p][r-(1<<p)]);
}


void build2()
{

    ll h = floor(log2(n));

    // base case
    for (ll j = 0; j < n; j++) ST2[0][j] = B[j];

    // iterative dynamic programming approach
    for (ll i = 1; i <= h; i++)
        for (ll j = 0; j + (1<<i) <= n; j++)
            ST2[i][j] = min(ST2[i-1][j], ST2[i-1][j + (1<<(i-1))]);
}

ll query2(ll l, ll r)          // query in range [l,r]
{
    r++;
    ll p = 31 - __builtin_clz((r-l));
    return min(ST2[p][l], ST2[p][r-(1<<p)]);
}

ll solve(ll st)
{
    ll rMin=-1;
    ll l=st,r=n-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll val1=query1(st,mid);
        ll val2=query2(st,mid);
        if(val1>val2 || (val1==val2 && mid!=st && query1(st,mid-1)==query2(st,mid-1)))
            r=mid-1;
        else if(val1<val2)
            l=mid+1;
        else
        {
            rMin=mid;
            break;
        }
    }
    dbg(rMin);
    if(rMin==-1)
        return 0;
    ll rMax=-1;
    l=st,r=n-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll val1=query1(st,mid);
        ll val2=query2(st,mid);
        if(val1>val2)
            r=mid-1;
        else if(val1<val2 || (val1==val2 && mid!=n-1 && query1(st,mid+1)==query2(st,mid+1)))
            l=mid+1;
        else
        {
            rMax=mid;
            break;
        }
    }
    dbg(rMax);
    return rMax-rMin+1;
}

int main()
{
    ll i,j;
    cin>>n;
    for(i=0; i<n; i++)cin>>A[i];
    for(i=0; i<n; i++)cin>>B[i];
    build1();
    build2();
    long long ans=0;
    for(i=0; i<n; i++) //fix l
    {
        ans+=solve(i);
    }
    cout<<ans;
}
