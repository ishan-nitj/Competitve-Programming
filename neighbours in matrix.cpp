#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mag (ll)1e3+1
#define mset(x,v)memset(x,v,sizeof(x))
ll vst[mag][mag];
ll arr[mag][mag];

ll n;

bool isvalid(ll x,ll y){
    return x>=0 && x<n && y>=0 && y<n;
}

vector<pair<ll,ll> >neighbours(ll x,ll y){
    vector<pair<ll,ll> >valid;
    if(isvalid(x-1,y))
        valid.pb({x-1,y});
    if(isvalid(x+1,y))
        valid.pb({x+1,y});
    if(isvalid(x,y-1))
        valid.pb({x,y-1});
    if(isvalid(x,y+1))
        valid.pb({x,y+1});
    if(isvalid(x-1,y-1))
        valid.pb({x-1,y-1});
    if(isvalid(x+1,y+1))
        valid.pb({x+1,y+1});
    if(isvalid(x-1,y+1))
        valid.pb({x-1,y+1});
    if(isvalid(x+1,y-1))
        valid.pb({x+1,y-1});
    return valid;
}

void dfs(ll x,ll y){
    vst[x][y]=1;
    auto neighbourS=neighbours(x,y);
    for(auto it:neighbourS){
        ll f=it.first;
        ll s=it.second;
        if(vst[f][s])
            continue;
        if(arr[f][s]==-1)
            continue;
        else if(arr[f][s]!=0)
            vst[f][s]=1;
        else{
            dfs(f,s);
        }
    }


}


ll dfsmain(){
    mset(vst,0);
    ll clicks=0;
    ll i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {//cout<<i<<" "<<j<<endl;
            if(arr[i][j]==0 && vst[i][j]==0)
            {dfs(i,j);
                //cout<<i<<" "<<j<<endl;
                clicks++;
            }

        }
    return clicks;
}

void make(){
ll i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
    if(arr[i][j]==-1)
        continue;
        auto neighbourS=neighbours(i,j);
    for(auto it:neighbourS){
        ll f=it.first;
        ll s=it.second;
        if(arr[f][s]==-1)
            arr[i][j]++;
    }
    

    }

}
int main(){
    freopen("IP.txt","r",stdin);
    freopen("OP.txt","w",stdout);
    ll t;cin>>t;
    ll K=1;
    while(t--){
        mset(arr,0);
        cin>>n;
        //        ll arr[n][n];
        ll i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                char ch;cin>>ch;
                if(ch=='.')
                    arr[i][j]=0;
                else
                    arr[i][j]=-1;
            }
       make();
      ll ans=dfsmain();
       //cout<<dfsmain();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        if(vst[i][j]==0 && arr[i][j]!=-1)
            ans++;         
        }
        //cout<<endl;
    }
    cout<<"Case #"<<K++<<": "<<ans<<endl;
    //cout<<ans;
    }

}


