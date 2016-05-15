#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);
#define mag 1000000
#define inf 1e18
#define enter printf("\n")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;

vector<int> func(string s){
vector<int>v;
stack<int>st;
for(int i=0;i<s.size();i++){
if(s[i]==' '){
int num=0,r=1;
int sz=st.size();
for(int k=0;k<sz;k++){
num+=(st.top()*r);
st.pop();
r*=10;}
v.push_back(num);
}
else{
st.push(int(s[i]-'0'));
}
}
int num=0,r=1;
int sz=st.size();
for(int i=0;i<sz;i++){
num+=(st.top()*r);
st.pop();
r*=10;}
v.push_back(num);
return v;
}

int main(){
vector<int>v=func("123 23 44");
int i;
print_array(v,v.size());
}
