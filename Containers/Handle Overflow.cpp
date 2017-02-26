#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

#ifndef ONLINE_JUDGE
#  define dbg(x) (cerr << #x << " = " << (x) << endl)
#define dbg2(x,y) (cerr<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl)
#else
#  define dbg(x) 0
#define dbg2(x,y) 0
#endif

const ll inf=(1LL<<60LL);

ll mul(ll a, ll b){
    if(a==0 || b==0)return 0;
    if(b>=inf/a)
        return inf;
    return b*a;
}

ll add(ll a, ll b){
    if(a+b>=inf)
        return inf;
    return a+b;
}

ll POW[123];
ll n;string k;

bool leadingZero(string s){
    if(s.size()==1 && s[0]=='0')
        return false;
    return s[0]=='0';
}

ll dp[123][123];

ll solve(ll idx,ll pos){
    ll i;
    if(idx==-1)
        return 0;
    if(dp[idx][pos]!=-1)
        return dp[idx][pos];
    ll ans=inf;
    for(i=idx;i>=max(0LL,idx-15);i--){
        string tmp=k.substr(i,idx-i+1);
        ll num=stoll(tmp);
        if(leadingZero(tmp))
            continue;
        if(num<n)
            ans=min(ans,add(mul(num,POW[pos]),solve(i-1,pos+1)));
    }
    return dp[idx][pos]=ans;
}


int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    ll curr=1;
    for(ll i=0;i<65;i++){
        POW[i]=curr;
        curr=mul(curr,n);
//        dbg(POW[i]);
    }
    cout<<solve(k.size()-1,0);
}
