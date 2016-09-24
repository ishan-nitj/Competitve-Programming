#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mset(x,v) memset(x, v, sizeof(x))
#define pb push_back
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define inf (ll)1e18
#define maxsize 1000005
#define mag 50
#define MOD 1000000007



ll l,r;

ll isprime[maxsize]; //isprime->1 no is prime
ll mark[maxsize];

void prime(){
    for(ll i=0;i<=100000;i++)
        isprime[i]=1;
    int i,j;
    isprime[0]=0;isprime[1]=0;
    for(i=2;i<=mag;i++){
        if(isprime[i]==1)
        {
            for(j=2*i;j<=mag;j=j+i){
                isprime[j]=0;
            }
        }
    }
}

ll segmentSeive(double l,double r){//returns no of prime no's b/w l to r
    ll i;
   ll ans=0;
   
    if(r<=mag){//no need of segmented seive
        for(i=l;i<=r;i++){
            if(isprime[i])
                ans++;
        }
    return ans;
    }
   
    vector<ll>prime;
    for(i=2;i*i<=r;i++){
        if(isprime[i])
            prime.pb(i);
    }
     
    for(auto it:prime){
       
        ll st=(ceil(l/it))*it;//first no in range[l,r] that is divisible by it
      
        for(ll i=st;i<=r;i+=it){//l->1 r->r-l+1
     
            mark[i-(ll)l+1]=1;}
    }

    for(i=1;i<=r-l+1;i++){
       
        if(mark[i]==0)
            ans++;
    
    }
    return ans;
   
}


int main(){
    prime();
    cout<<segmentSeive(80,100);
}



