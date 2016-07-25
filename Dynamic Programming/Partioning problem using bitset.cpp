#include <bits/stdc++.h>
using namespace std;
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb emplace_back
#define fe first
#define se second
#define ll long long
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);

const int N = 5;
bitset < N * N > bit;

int solve(vector < int > &v){
	int sum = 0;
	for(int x : v){
		sum += x;
	}
	bit.reset();
	bit.set(0);
	for(int x : v){
		bit |= (bit << x);
	}
	int ans = sum;
	for(int i = 0 ; i < sum ; ++i){
		if(bit.test(i)){
			ans = min(ans , abs(i - (sum - i)));
		}
	}
	return ans;
}

int main(){
vector<int>v={3,3,7,3,1};
int sum = 0;
	for(int x : v){
		sum += x;
	}
ll val1=(sum+solve(v))/2;
ll val2=sum-val1;
dbg2(val1,val2);
}

