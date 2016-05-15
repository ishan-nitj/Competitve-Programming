#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 1e8//10^8
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back}
double EPS = 1e-9;  // EPS is short for "epsilon", the funky Greek letter Mathematicians use to formally define continuity in analysis (etc.)

bool equal(double a,double b){
if(fabs(a-b) < EPS)
return true;
return false;
}

bool grthanequal(double a,double b){
return(a > b-EPS);
}

bool grt(double a,double b){
return(a >= b+EPS);
}

bool lessthanequal(double a,double b){
return(a < b-EPS);
}

bool less(double a,double b){
return(a <= b+EPS);
}


//Suppose you needed to find which fraction was larger: a/b or c/d, where a, b, c, d are integers.
//Well, instead of comparing (double)a/b with (double)c/d, you could just as well (and better) compare
//(a*d) with (b*c). No precision required.
//
//Use fabs if you want to calculate the absolute value of a floating point no.

int main(){
double a=1e11;
cout<<scientific<<a;enter;
cout<<fixed<<a;
}
