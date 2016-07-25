#include<bits/stdc++.h>
using namespace std;
int main(){
string s("Hello");
s.c_str();
cout<<strlen(s);
}
getline(cin,s);
we can use [] with string
http://www.cplusplus.com/reference/string/string/

reverse(v.begin(),v.end());
s.substr(5,6); start at 5 with 6 characters

char buf[1000];
sprintf(buf, "%d %d", p[0].first, p[0].second);
s = buf;

Inputting s string with spaces and converting it to c stype string:char s1[30000];
cin.getline(s1,30000);
string s;
s=string(s1);

inputing an array of numbers till users enter them
while(scanf("%d",&a)){

}

For ex. We want to input numbers separated with hyphen.
Ex:124-244
use scanf("%d-%d",&a,&b);

use to_string and stoll (string to long long)

inputing a string of characters till users enter them
while(scanf("%c",&ch)!=EOF){
    if(ch>=97 && ch<=122 && prev==' ')
        cout<<char(ch-32);
    else
    cout<<ch;
prev=ch;
}
