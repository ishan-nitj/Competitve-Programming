vector<ll>v;

ll lower_bound(ll x){// when ans is n
    auto it=lower_bound(v.begin(),v.end(),x);
    auto beg=v.begin();
    return -distance(it,beg);
}

ll upper_bound(ll x){//when ans is -1
    auto it=upper_bound(v.begin(),v.end(),x);
    if(it==v.begin())
        return -1;
    it--;
    auto beg=v.begin();
    return -distance(it,beg);
}

