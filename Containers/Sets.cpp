#include<bits/stdc++.h>//BST
using namespace std;
//Sets Sets are containers which store only unique values and permit easy look ups.
//The values in the sets are stored in some specific order (like ascending or descending).
//Elements can only be inserted or deleted, but cannot be modified. We can access and traverse set elements
//using iterators just like vectors.// multiset allows duplicates
//set doenot allow []
int main(){
set<string> s;
s.insert("aa");
s.insert("asad");
s.insert("aaaaas");
set <string>::iterator it;
for(it=s.begin();it!=s.end();it++)
cout<<*it<<endl;
}

set<int> s1;                               // Empty Set
int a[]= {1, 2, 3, 4, 5, 5};
set<int> s2 (a, a + 6);                    // s2 = {1, 2, 3, 4, 5}
set<int> s3 (s2);                          // Copy of s2
set<int> s4 (s3.begin(), s3.end());         // Set created using iterators


Some of the member functions of set are:
begin(): Returns an iterator to the first element of the set. Its time complexity is O(1).
clear(): Deletes all the elements in the set and the set will be empty. Its time complexity is O(N) where N is the size
 of the set.
count(): Returns 1 or 0 if the element is in the set or not respectively. Its time complexity is O(logN) where N is the
size of the set.
empty(): Returns true if the set is empty and false if the set has at least one element. Its time complexity is O(1).
end(): Returns an iterator pointing to a position which is next to the last element. Its time complexity is O(1).
erase(): Deletes a particular element or a range of elements from the set. Its time complexity is O(N) where N is the
 number of element deleted. or


find(): Searches for a particular element and returns the iterator pointing to the element if the element is found
 otherwise it will return the iterator returned by end(). Its time complexity is O(logN) where N is the size of the set.
insert(): insert a new element. Its time complexity is O(logN) where N is the size of the set.
size(): Returns the size of the set or the number of elements in the set. Its time complexity is O(1).
lower_bound(): R Lafore
upper_bound(): R Lafore


s.erase (iterator position);
void erase (iterator first, iterator last);
directly use s.erase(val) (inc case of multiset deletes all the values with given val)

auto it=s.end();
it--; This can be used to access the last element of the set.

auto it=it1+1; This is an invalid statement

instead use auto it=++it1;it1--;
