#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);

#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))


int main(){
ll n,i,j,temp;
sl(n);
ll a[n],l[n];
rep(i,n){
sl(a[i]);
l[i]=1;
}
rep(i,n){
if(i==0)
l[0]=1;
else {
rep(j,i){
if(a[i]>a[j]){
temp=1+l[j];
if(temp>l[i])
l[i]=temp;
}
}
}
}
cout<<*max_element(l,l+n);
return 0;
}
