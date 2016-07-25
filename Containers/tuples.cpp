#include <bits/stdc++.h>
using namespace std;
#define ll int
#define lll __int128
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second

int main(){
tuple<ll,ll,ll>t1,t2;
t1=make_tuple(2,30,4);
cout<<get<0>(t1)<<get<1>(t1)<<get<2>(t1);
t2=make_tuple(20,0,4);
auto t=min(t1,t2);//comparison of tuples is in lexiographic order//so we can use std::sort
}
