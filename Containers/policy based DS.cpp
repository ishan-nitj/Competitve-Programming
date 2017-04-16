//donot use distance here.




//http://codeforces.com/blog/entry/11080
//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll int
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second
typedef tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>ordered_set;

int main(){
ordered_set s;
s.insert(10);
s.insert(20);
cout<<s.order_of_key(20);//1
cout<<s.order_of_key(10);//0
cout<<*s.find_by_order(1);//returns iterator
}
