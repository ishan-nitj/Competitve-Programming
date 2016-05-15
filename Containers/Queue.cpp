#include<bits/stdc++.h>// All the ops are performed in O(1) time.
using namespace std;
int main(){
queue<int>q;
q.push(2);
q.push(3);
q.pop();
cout<<q.front()<<q.back()<<q.size()<<q.empty();// Size is the no of elements in the stack.
}
