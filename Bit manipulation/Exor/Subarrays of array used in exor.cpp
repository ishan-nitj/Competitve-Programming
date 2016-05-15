#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 1000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define maxsize 3
int main(){
freopen("IP.txt","r",stdin);
ll t;sl(t);
while(t--){
ll n,k,i,j;sl(n);
ll a[n],arr[n+1];// Here arr is corresponding to the subarrays of a.//If we select any two of its elements and ^ them,
// we will get exor of a subarray of the original array.
rep(i,n){
sl(a[i]);
if(i==0)
arr[i]=a[i];
else
arr[i]=arr[i-1]^a[i];
}
arr[n]=0;// a zero is also added (else the subarrays starting with the 0th index wont be covered)
}

}
