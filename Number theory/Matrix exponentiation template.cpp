#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100
#define inf 1e18
#define MOD 1000000007
#define enter printf("\n")
#define space printf(" ")
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
ll g[26][26];
ll a[26][26];
ll r[26][26];
ll C[26][26];

void matmul(ll A[][26],ll B[][26])//a b b d
{//This multiplies two matrices ,stores the result temporarily in C and then copy it back to the first
    //array.
    int i,j,k;
    for(i=0;i<26;i++)//a
    {
        for(j=0;j<26;j++)//d
        {
            C[i][j] = 0;
            for(k=0;k<26;k++)//b
            {
                C[i][j] += (A[i][k]*B[k][j]);
                if(C[i][j]>=MOD)
                    C[i][j] %= MOD;
            }
        }
    }
    for(i=0;i<26;i++)
        for(j=0;j<26;j++)
            A[i][j] = C[i][j];
}

void matpow(int k)//make sure that k=0 is not passed.//final result stored in r matrix.
{
k--;
    while(k)
    {
        if(k&1)
            matmul(r,a);
        matmul(a,a);
        k >>= 1;
    }
}

int main()
{
    int t,i,j;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            cin>>g[i][j];
        }
    }
    cin>>t;
    assert(1 <= t && t <= 100);
    while(t--)
    {
        char ch;
        int l;
        cin>>ch>>l;
        assert('a' <= ch && ch <= 'z');
        assert(1 <= l && l <= 10000000);
        ll ans = 0;
        int u = ch - 'a';
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                r[i][j] = a[i][j] = g[i][j];
            }
        }
        l-=1;
        matpow(l);
        for(i=0;i<26;i++)
        {
            ans = (ans + r[i][u])%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
