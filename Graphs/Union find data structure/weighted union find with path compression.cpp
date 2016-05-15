#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second
// 1 based indexing.// arr[0]=0 and size[0]=0
vector<ll>arr,size;

ll root(ll i){//
while(arr[ i ] != i)
{
arr[ i ] = arr[ arr[ i ] ] ;//we are also changing the exiting arr
i = arr[ i ];
}
return i;
}

bool find_(ll x,ll y){//
return(root(x)==root(y));
}

void weightedunion(ll A,ll B)// note that here the size of existing roots which are getting merged are not getting
//decreased to zero thats not needed after. We can add an addl. statement for this.
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

int main(){
ll n,i;cin>>(n);
size.resize(n+1);
arr.resize(n+1);
rep(i,n+1){
arr[i]=i;
size[i]=1;
}
// Initially root of each element is the element itself
ll k;cin>>(k);//no of queries
while(k--){
ll i,j;cin>>i>>j;
}
}
