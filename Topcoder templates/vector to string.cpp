string convert(vector<ll>v){
string str;
ll r=0,i,size=0;
for(i=0;i<v.size();i++){
stack<ll>s;

while(v[i]){
s.push(v[i]%10);
v[i]/=10;
}
size+=s.size();
str.resize(size);

while(!s.empty()){
str[r++]=48+s.top();
s.pop();
}

}
return str;
}
