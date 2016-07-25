include <bits/stdc++.h>
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

// by default greatest element is at the top
struct func{
bool operator()(ll x,ll y){
return x<y;
}
};

priority_queue<ll,vector<ll>,func>pq;

int main(){
pq.push(2);
pq.push(23);
pq.push(24);
cout<<pq.top()<<endl;
pq.pop();
cout<<pq.empty();
}

//It arranges for the largest element to be at the top - that is, the element for which func(top_element, any_other_element) is
//never true
