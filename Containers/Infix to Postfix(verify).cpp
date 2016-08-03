#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag (ll)1e9
#define mset(x,v) memset(x, v, sizeof(x))

ll precedence(char ch){
    if(ch=='*' ||ch=='/')
        return 2;
    else 
        return 1;
}

int main(){
    ll i;
    string s;cin>>s;
    string ans;
    stack<char>st;
    for(i=0;i<s.size();i++)
    {
        if(s[i]>=48 && s[i]<=57)
            ans+=s[i];
        else if (s[i]=='(')
            st.push('(');
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {ans+=st.top();
                st.pop();}
            st.pop();
        }
        else{
            while(!st.empty() && st.top()!='('  && precedence(st.top())>=precedence(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
        ans+=st.top();st.pop();

    }
    cout<<ans;
}
