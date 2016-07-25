#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag (ll)1e9
#define mset(x,v) memset(x, v, sizeof(x))
#define inf 1000000000000000000
#define MOD 1000000007
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back

typedef struct node{
    ll data;
    struct node *next;
}node;

bool search(node *head,ll val){
    node* iter=head;
    while(iter!=NULL){
        if(iter->data==val)
            return true;
    }
    return false;
}

node *insertfront(node* head,ll val){
    node *p=(node *)malloc(sizeof(node));
    p->data=val;
    p->next=head;
    return p;
}

node *delbyval(node *head,ll val){
    node *iter=head;
    node *prev;
    if(head->data==val){//first node to be deleted
        node *newhead=head->next;
        free(head);
        return newhead;
    }
    while(iter->data!=val){
        prev=iter;
        iter=iter->next;          
    }
    prev->next=iter->next;
    return head;
}

node *reverse(node *head){
    if(head==NULL || head->next==NULL)
        return head;
    node *curr=head;
    node *prev=NULL,*after;
    while(curr!=NULL){
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    return prev;
}

int main(){
    ll n;cin>>n;
    ll i;
    node *head,*p,*prev;
    head=NULL;
    for(i=0;i<n;i++){
        ll Data;cin>>Data;
        p=new node;
        p->data=Data;
        if (head==NULL){
            head=p;
        }
        else{
            prev->next=p;
        }
        prev=p;
    }
    head=reverse(head);
    node* iter=head;
    while(iter!=NULL){
        cout<<iter->data<<endl;
        iter=iter->next;
    }

}
