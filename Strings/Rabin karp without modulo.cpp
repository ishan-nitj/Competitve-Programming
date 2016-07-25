// Important questions:2 questions of Rabin Karp +Binary Search from codemonk.
//Finding longest palindromic substring in NLGN time using rabin karp.
//You are given a string S. Find the length of its the longest substring which occurs at least two times.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 1000000 //10^8
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fi first
#define se second
string s;
ll window_size;

ll arr[mag+1],pw[mag+1];

ll val(char ch){
return (ch-'a'+1);
}

void precomputation_of_powers(){
pw[0]=1;
for(ll i=1;i<=mag;i++)
    pw[i]=pw[i-1]*27;//
}

void rabin_karp(){
ll i,sum=0;
for(i=0;i<window_size;i++){
sum=sum*27+val(s[i]);
}

//ll sum1=0;   //proof that by both methods the overflowed value remains the same
//for(i=window_size-1;i>=0;i--){
//sum1+=pw[window_size-1-i]*val(s[i]);
//}
//var_val(sum);
//var_val(sum1);

arr[0]=sum;
for(i=1;i<=(s.size()-window_size);i++){
sum=arr[i-1];
sum=sum-val(s[i-1])*pw[window_size-1];
sum=sum*27+val(s[i+window_size-1]);
arr[i]=sum;
}

}

int main(){
cin>>s;
cin>>window_size;
precomputation_of_powers();
rabin_karp();
for(ll i=0;i<=(s.size()-window_size);i++)
    cout<<arr[i]<<endl;
}
