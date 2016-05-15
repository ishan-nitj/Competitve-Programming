#include<bits/stdc++.h>
using namespace std;
#define n 7
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);

#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

int v[n],w[n];

int O(int k,int j){
if(j==-1)
return 0;
else if (w[j]<=k)
return (max(O(k,j-1),v[j]+O(k-w[j],j-1)));
else
return O(k,j-1);
}

int max(int x,int y){
if(x>y) return x;
else return y;
}
int main(){
ios_base::sync_with_stdio(0);
int i;
rep(i,n)
cin>>v[i];
rep(i,n)
cin>>w[i];
cout<<O(10,6);
}
