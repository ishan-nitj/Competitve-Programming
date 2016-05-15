#include<bits/stdc++.h>// A deque is like a double ended vector. It supports all ops of vectors
using namespace std;
int main(){
deque<int>dq;
dq.push_front(2);
dq.push_front(3);
dq.push_front(4);// O(1)
dq.push_front(5);
dq.pop_back();  // O(1)
dq.push_back(2);// O(1)
dq.pop_front();// O(1)
cout<<dq.front()<<dq.back();
}
dq also has dq.begin() and dq.end()
