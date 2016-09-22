include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mset(x,v) memset(x, v, sizeof(x))
#define pb push_back
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define inf (ll)1e18
#define maxsize 20
#define MOD 1000000007
string s;
 
 
ll solve(ll st,ll en){
    //both equal
    ll ans=0;
    if(st==en)
        return ('Z'-s[st]);
 
    if(en!=st+1)
        ans=(ans%MOD+solve(st+1,en-1)%MOD)%MOD;
 
    //both >
    if(s[st]!='Z' && s[en]!='Z'){
        ll val1=1;
        for(ll i=st+1;i<=en-1;i++)
            val1=((val1%MOD)*(26))%MOD;
        ans=(ans%MOD+(((val1)*('Z'-s[st]))%MOD*('Z'-s[en]))%MOD)%MOD;
    }
 
    //st > en=
    if(s[st]!='Z'){
        ll val2=1;
        for(ll i=en-1;i>=st+1;i--)
            val2=((val2%MOD)*('Z'-s[i]+1)%MOD)%MOD;
        ans=(ans%MOD+(('Z'-s[st])*val2)%MOD)%MOD;
    }
 
    //st= en>
    if(s[en]!='Z'){
        ll val3=1;
        for(ll i=st+1;i<=en-1;i++)
            val3=((val3%MOD)*('Z'-s[i]+1))%MOD;
        ans=(ans%MOD+(('Z'-s[en])%MOD*(val3%MOD))%MOD);
    }
    return ans;
}
 
int main(){
    cin>>s;
    cout<<solve(0,s.size()-1);
}
