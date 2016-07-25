#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mag (ll)1e6

ll arr[mag];


ll countSplitinv(ll l,ll r){
    ll mid=(l+r)/2;
    ll i=l,j=mid+1;
    ll ans=0;
    ll cum=0;
    vector<ll>v;
    while(i<=mid && j<=r){
        if(arr[i]>arr[j])
        {
            v.pb(arr[j]);
            j++;
            cum++;
        }
        else if(arr[i]<=arr[j])
        {v.pb(arr[i]);
            i++;
            ans+=cum;
        }
    }
    while(i<=mid)
    {v.pb(arr[i++]);ans+=cum;}
    while(j<=r)
        v.pb(arr[j++]);   
    for(i=l;i<=r;i++)
        arr[i]=v[i-l];
    return ans;
}


ll countInv(ll l,ll r){
    ll ans=0;
    if(l<r){
        ll mid=(l+r)/2;
        ans+=countInv(l,mid);
        ans+=countInv(mid+1,r);
        ans+=countSplitinv(l,r);
    }
    return ans;
}

int main(){
    ll t;cin>>t;
    while(t--){
        memset(arr,0,sizeof(arr));
        ll n;cin>>n;
        ll i;
        for(i=0;i<n;i++)
            cin>>arr[i];
        ll a=countInv(0,n-1);
        cout<<a<<endl;
        //for(i=0;i<n;i++)
        //cout<<arr[i];
    }
}
