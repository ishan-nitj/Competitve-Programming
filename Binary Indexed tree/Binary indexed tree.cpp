#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

#define enter printf("\n")
#define space printf(" ")
#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
vector<ll>arr;
ll n;
vector<ll>BIT;

void update(ll i,ll val){// increments the value at arr[i] by val.
    ll j;
    for(j=i;j<=n;j=j+(j&(-j))){
        BIT[j]+=val;
    }
}

ll query(ll i){// query(i) yields prefix sum till i.
    ll j,sum=0;
    for(j=i;j>0;j-=j&-j){
        sum=sum+BIT[j];
    }
    return sum;
}

int main(){
    sl(n);// size of the array
    arr.resize(n+1);
    BIT.resize(n+1);
    arr[0]=0;BIT[0]=0;// 1 based indexing
    ll i;
    fill(BIT.begin(), BIT.end(), 0);//
    for(i=1;i<=n;i++){
        ll val;sl(val);
        arr[i]=val;
        update(i,val);
    }
    cout<<query(1)<<query(2)<<query(5)-query(2);enter;
    update(2,1);// increment posn 2 by 1
    cout<<query(0);
}

