#include<bits/stdc++.h>
using namespace std;
int main(){
pair<int,int>p(1,3);
pair<int,int>p1(p);
p1=make_pair(1,30);
cout<<p1.first<<p1.second;
}
// Here the pair is sorted first according to x cooridnate and then according to y coordinate
vector<pair<int,int> >v;
v.push_back(make_pair(12,131));
v.push_back(make_pair(12,133));
v.push_back(make_pair(11,133));
v.push_back(make_pair(12,123));
sort(v.begin(),v.end());
for(int i=0;i<v.size();i++){
cout<<v[i].first<<endl<<v[i].second<<endl;
}
