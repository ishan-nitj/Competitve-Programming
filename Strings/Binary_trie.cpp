//Ishan Bansal
//Binary trie used in exor problems
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 1000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define maxsize 20

typedef struct Node{
    ll isleaf;
    struct Node* child[2];
}node;
node* root;

node* createnode(ll x){
    node* ptr =(node*)malloc(sizeof(node));
    ptr->isleaf=x;
    ptr->child[0]=NULL;
    ptr->child[1]=NULL;
    return ptr;
}

stack<ll> binary(ll n){
    stack<ll>s;
    while(n){
        s.push(n&1);
        n=n>>1;
    }
    while(s.size()<maxsize)
        s.push(0);
    return s;
}

void insert(ll n){
    stack<ll>s=binary(n);
    node* t=root;
    while(!s.empty()){
        ll x=s.top();
        s.pop();
        if(t->child[x]==NULL)
        {
            node* ptr =createnode(0);
            t->child[x]=ptr;
        }
        t=t->child[x];
    }// while end
    t->isleaf=1;
}


ll maxexor(ll no){// for a no x,returns maximum exor of x  with currently existing numbers
    stack<ll>ans;
    stack<ll>s=binary(no);
    node *t=root;
    while(!s.empty()){
        ll x=s.top();    
        s.pop();
        if(t->child[x^1]!=NULL)
        {t=t->child[x^1];ans.push(x^1);}
        else
        {t=t->child[x];ans.push(x);}
    }
    ll maxno=0;
    ll val=1;
    while(!ans.empty()){
        maxno+=val*ans.top();
        ans.pop();
        val*=2;
    }
    return maxno^no;
}


bool find(ll n){
    stack<ll>s=binary(n);
    node* t=root;
    while(!s.empty()){
        ll x=s.top();
        s.pop();
        if(t->child[x]==NULL)
        {
            return false;
        }
        t=t->child[x];
    }
    return(t->isleaf==1);
}

int main(){
    ll t;cin>>t;
    while(t--){
    root =createnode(0);
    ll n,i;sl(n);
    ll arr[n+1];
    vector<ll>subarray;
    ll curr=0;
    for(i=0;i<n;i++){
        ll no;sl(no);
        subarray.push_back(no^curr);
        curr^=no;
    }
    subarray.push_back(0);
    ll ans=0;
    for(i=0;i<subarray.size();i++)
    {
        if(i!=0)
            ans=max(ans,maxexor(subarray[i]));
        insert(subarray[i]);
    }
    pl(ans); 
    printf(" ");
    free(root);
    }

 }
