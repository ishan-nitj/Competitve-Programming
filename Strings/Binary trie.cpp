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
#define maxsize 3

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
root =createnode(0);
insert(5);
insert(1);
cout<<find(1);
}


