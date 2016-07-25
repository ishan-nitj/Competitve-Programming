//Reference:http://www.keithschwarz.com/cs106l/fall2010/reference/bitset.html
//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second

int main(){
bitset<12>mybit;
//bitsets cant be resized once created
//it has 0 bsed indexing
//a bitset of size 12 w/ all bits initialised to 0

bitset<12>mask(12);//bitset of size 12 w/ all bits intialized acc. to the value of 12

mask.set(); // All bits set to 1
mask.set(4); // Sets bit 4 to 1
mask.set(4, 0); // Sets bit 4 to zero.
mask.reset(); // All bits set to 0
mask.reset(4); // Sets bit 4 to 0

mask.flip(); // Flips all bits.
mask.flip(4); // Flip bit 4.

mask.any();//returns true if any bit is set
mask.none();//return true if no bit is set
mask.test(1);//return true if 1st bit is set

//Applying Bitwise Operators

mask|=5;
//ly use & ,^ and ~.

mask>>=2 ;//Shifts all bits over four positions to the right.
mask<<=2;//left shift operation

//Some other operations:
cout<<mask.count()<<endl;//returns no of bits set in mask
cout<<mask.size()<<endl;//returns total no of bits in mask
cout<<mask.to_string()<<endl;
unsigned long x=mask.to_ulong();cout<<x<<endl;//we are converting mask to unsigned long
cout<<mask[1]<<endl;//returns bit at specified location
bitset<5>mask("11001"); // A bitset of 5 bits initialized to 11001.
bitset<5>mask("xxxx11001xxxx", 4, 5); // Initializes the bitset based on the five characters in the string, starting at char 4.

//Returns first bit set
return (bit._Find_first());
cout<<mask;v
}
