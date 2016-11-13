#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll a[4][4];
ll r[4][4];
ll C[4][4];

void matmul(ll A[][4],ll B[][4])
{//This multiplies two matrices ,stores the result temporarily in C and then copy it back to the first array.
    ll i,j,k;
    for(i=0;i<4;i++)//a
    {
        for(j=0;j<4;j++)//d
        {
            C[i][j] = 0;
            for(k=0;k<4;k++)//b
            {
                C[i][j] =C[i][j]%MOD+(A[i][k]%MOD*B[k][j]%MOD)%MOD;
             }
        }
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            A[i][j] = C[i][j];
}

void matpow(ll k)//make sure that k=0 is not passed.//final result stored in r matrix.
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

ll g[4][4]={{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};

int main()
{
    ll l,i,j;cin>>l;        
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            r[i][j] = a[i][j] = g[i][j];
        }
    } 
    matpow(l); 
    cout<<r[3][3];
    return 0;
}
