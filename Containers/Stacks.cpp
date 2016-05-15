#include<bits/stdc++.h>// All the ops are performed in O(1) time.
using namespace std;
int main(){
stack <int> S;
S.push(3);
S.push(4);
S.pop();
cout<<S.top()<<S.size()<<S.empty();// Size is the no of elements in the stack.
}
