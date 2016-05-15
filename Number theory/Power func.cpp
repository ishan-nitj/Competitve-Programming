#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

#define enter printf("\n")
#define space printf(" ")
#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

ll power(ll a,ll n)// This can also be done using recursive approach
{ll res=1;
ll temp=a;
while(n!=0){
    if(n%2==1)
    {
        res=res*(temp);

    }
n=n/2;
temp=temp*temp;
}
return res;
}


int main(){
cout<<power(2,5);
return 0;
}

