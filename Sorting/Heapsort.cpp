#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100
#define inf 1e18
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define vl vector<ll>
#define pb push_back
#define m_p make_pair
//A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the
// children of that node.
void max_heapify(ll arr[],ll i,ll size){// max heapify does not make entire heap into max heap
// if both left and right child of a node satisfy max heap property but the node itself does not satisfy maxheap ,if we apply max
//heapify on it ,the tree with that node as root will be a max heap.
//O(lgn)
ll n=size;
ll l=2*i+1,r=l+1,max=i;
if(l<=n-1 && arr[l]>arr[i])
    max=l;
if(r<=n-1 && arr[r]>arr[max])
    max=r;
if(max!=i){
swap(arr[i],arr[max]);
max_heapify(arr,max,size);
}
}

void build_maxheap(ll arr[],ll size){//build a max heap using bottom up approach.
// note that the nodes that are leaf nodes are not taken.

// O(n)
ll n=size;
ll i;
for(i=n/2-1;i>=0;i--){
max_heapify(arr,i,n);
}
}

void heapsort(ll arr[],ll n){
ll size=n,i;
while(size!=1){
swap(arr[0],arr[size-1]);
size--;
max_heapify(arr,0,size);
}
}

int main()
{
ll t;sl(t);
while(t--){
ll n;
sl(n);
ll arr[n],i;
rep(i,n)
sl(arr[i]);
build_maxheap(arr,n);
heapsort(arr,n);
for(i=n-1;i>=0;i--)
cout<<arr[i]<<" ";
enter;
}
}
