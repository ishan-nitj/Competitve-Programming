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

// insetion sort left

void bubblesort(ll* arr,ll n){
for(ll i=n-1;i>=1;i--){// >=1
for(ll j=0;j<i;j++){
if(arr[j]>arr[j+1])
swap(arr[j],arr[j+1]);
}
}
}

void selectionsort(ll* arr,ll n){
for(ll i=0;i<n-1;i++){// n-1
ll* minptr=min_element(arr+i,arr+n);
ll j=distance(arr,minptr);
swap(arr[i],arr[j]);
}
}

int main(){
ll n;sl(n);
ll arr[n];
ll i;
rep(i,n)
sl(arr[i]);
bubblesort(arr,n);
rep(i,n)
pl(arr[i]);
}
