// Use this method if MOD*MOD > the range of long long or
//MOD >10^9 

ll mulmod(ll a,ll b,ll c){
 
  ll x=0,y=a%c;
 
  while(b){
 
    if(b&1){
 
      x=(x+y)%c;
 
    }
 
    y=(y*2)%c;
 
    b/=2;
 
  }
 
  return x%c;
}
//modular expo
ll power(ll x, unsigned long long int  y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res=mulmod(res,x,p);
 
        y = y>>1;
        x=mulmod(x,x,p);
    }
    return res%p;
}

