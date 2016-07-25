//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second

ll dp[15][1<<15];
string g,f;
ll n;

ll count_one(ll n){// to count no of ones in a binary form of a number
	ll count=0;
	while(n){
		n=n&(n-1);
		count++;
	}
	return count;
}


void iterdp(){
	ll i,j;
	for(j=0;j<(1<<n);j++)
		for(i=0;i<n;i++)
		{
			if(count_one(j)==1){
				if(j&(1<<i))
					dp[i][j]=1;
			}
			else{
				set<char>s;
				ll mask=j&~(1<<i);
				for(ll k=0;k<n;k++){
					if(mask&(1<<k)){
						if(g[k]!=g[i] && s.find(g[k])==s.end() && f[count_one(mask)-1]!=g[k]){
							s.insert(g[k]);
							dp[i][j]=(dp[i][j]%MOD+dp[k][mask]%MOD)%MOD;
						}
					}

				}//k loop
			}//else end
		}
}

int main(){
	mset(dp,0);
	cin>>g>>f;
	n=g.size();
	ll ans=0;
	iterdp();
	set<char>s;
	for(ll i=0;i<n;i++){
		if(s.find(g[i])==s.end()){
			ans=(ans%MOD+dp[i][(1<<n)-1]%MOD)%MOD;
			s.insert(g[i]);	
		}
	}
	cout<<(ans);
}



