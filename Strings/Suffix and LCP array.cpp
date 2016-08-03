// Code borrowed from Vedaanta Agarwalla//may be he borrowed from someone else
//Here the last term in LCP array is zero
//Applications:
//1)Finding minimum lexiographic rotation of a string.
//2)(verify)Finding longest palindromic substring.//concatenate : string +'#'+string_reverse ..Here '#' is assumed to have lowest ascii value.
//3)Finding the number of occurrences of a pattern.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second
#define maxn 1000005

string S;
ll sa[maxn], pos[maxn], tmp[maxn], lcp[maxn], N, gap, freq[maxn],m;

bool Sufcmp(ll i, ll j){
	if(pos[i] != pos[j]){
		return pos[i] < pos[j];
	}
	i += gap; j += gap;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(){
	N = S.size();
	for(ll i = 0; i < N; i++){
		sa[i] = i;
		pos[i] = S[i];
	}

	tmp[0] = 0;
	for(gap = 1; ; gap = (gap << 1)){
		sort(sa, sa + N, Sufcmp);
		for(ll i = 0; i < N-1; i++) tmp[i+1] = tmp[i] + Sufcmp(sa[i], sa[i+1]);
		for(ll i = 0; i < N; i++) pos[sa[i]] = tmp[i];
		if(tmp[N-1] == N-1) break;
	}
}

void buildLCP(){
	N = S.size();
	lcp[N-1] = 0;
	for(ll i = 0, k = 0; i < N; i++){
		if(pos[i] != N-1){
			for(ll j = sa[pos[i]+1]; S[i+k] == S[j+k]; )
				k++;
			lcp[pos[i]] = k;
			if(k) k--;
		}
	}
}

int main()
{	string t1,t2,s;
	cin>>s>>t1>>t2;
    cin>>S;
    buildSA();
    buildLCP();
	//print_array(sa,S.size());cout<<endl;
	//print_array(lcp,S.size());

}
