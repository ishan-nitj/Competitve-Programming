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

vector<string> func(string s){
vector<string>v;
stack<char>st;
for(int i=0;i<s.size();i++){
if(s[i]==' '){
string temp;
int sz=st.size();
temp.resize(sz);
for(int k=sz-1;k>=0;k--){
temp[k]=st.top();
st.pop();
}
v.push_back(temp);
}
else{
st.push(s[i]);
}
}
string temp;
int sz=st.size();
temp.resize(sz);
for(int k=sz-1;k>=0;k--){
temp[k]=st.top();
st.pop();
}
v.push_back(temp);
return v;
}


int main(){
vector<string>v=func("123 23 44");
for(int i=0;i<v.size();i++)
cout<<v[i];
}
