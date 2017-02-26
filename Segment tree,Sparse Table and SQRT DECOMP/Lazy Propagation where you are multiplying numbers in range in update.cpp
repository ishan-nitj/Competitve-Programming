#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 1234567

ll tree[4*mag],A[mag+1],lazy[4*mag];

ll power(ll a,ll n)// This can also be done using recursive approach
{ll res=1;
    ll temp=a;
    while(n!=0){
        if(n%2==1)
        {
            res=res*(temp);

        }
        n=n/2;
        temp=temp*temp;
    }
    return res;
}

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // llernal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 1)
    { 
        // This node needs to be updated
        tree[node] *=lazy[node];    // Update it//The operation here depends on the kind of update
        //we are doing in the range.In this case ,we are adding a value to each element in the range l to r.//
        if(start != end)
        {
            lazy[node*2] *= lazy[node];                  // Mark child as lazy
            lazy[node*2+1] *= lazy[node];                // Mark child as lazy
        }
        lazy[node] = 1;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] *= val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] *= val;
            lazy[node*2+1] *= val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];    // Updating root with max value 
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 1)
    {
        // This node needs to be updated
        tree[node] *= lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] *= lazy[node];         // Mark child as lazy
            lazy[node*2+1] *= lazy[node];    // Mark child as lazy
        }
        lazy[node] = 1;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}


int main(){
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>A[i];
    for(ll i=1;i<=4*mag;i++)
        lazy[i]=1;
    build(1,1,n);
    cout<<queryRange(1,1,n,1,2)<<endl;
    updateRange(1,1,n,1,2,3);
    updateRange(1,1,n,2,3,3);
    cout<<queryRange(1,1,n,2,3)<<endl;
}

