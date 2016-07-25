#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100
#define inf 1e18
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define vl vector<ll>
#define pb push_back
#define m_p make_pair

class matrix{
public:
    ll a[mag][mag];
    ll r,c;

matrix(ll m,ll n){
r=m;
c=n;
}

void makeme_identity_matrix(){
for(ll i=0;i<r;i++)
    for(ll j=0;j<c;j++)
    if(i==j)
    a[i][j]=1;
}

void operator = (const matrix& m2){
ll i,j;
for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    a[i][j]=m2.a[i][j];
}

};

void operator>>(istream & it,matrix &m){
ll i,j;
for(i=0;i<m.r;i++)
    for(j=0;j<m.c;j++)
        it>>m.a[i][j];

}

void operator<<(ostream & ot,matrix &m){
ll i,j;
for(i=0;i<m.r;i++){
    for(j=0;j<m.c;j++)
         ot<<m.a[i][j]<<" ";
printf("\n");
}
}

//(m3.a[i][j])=(m3.a[i][j]%MOD+((m1.a[i][k])%MOD*(m2.a[k][j])%MOD)%MOD)%MOD;// when using modulo
matrix pro (matrix m1,matrix m2){
matrix m3(m1.r,m2.c);
mset(m3.a,0);
ll i,j,k;
for(i=0;i<m1.r;i++)
    for(j=0;j<m2.c;j++)
        for(k=0;k<m1.c;k++)
            (m3.a[i][j])+=(m1.a[i][k])*(m2.a[k][j]);
return m3;
}

matrix matrix_exponentiation(matrix m,ll power){
 matrix result(m.r,m.c);
 result.makeme_identity_matrix();
 while(power){
    if(power%2==1){
       result=pro(result,m);
    }
    m=pro(m,m);
    power=power/2;
 }
return result;
}

int main()
{
matrix s(1,2);
cin>>s;
matrix m(2,2);
cin>>m;
m=matrix_exponentiation(m,10);
matrix e(1,2);
e=pro(s,m);
cout<<e;
}





