#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int> v; // sequence container//Flexible array
v.push_back(12);//contiguous
v.push_back(11);
v.push_back(13);
cout<<v.size()<<endl;
for(int i=0;i<v.size();i++){
cout<<v[i]<<endl;// we can access element like array(Donot insert element like this)
}
sort(v.begin(),v.end(),greater<int>());//We cant sort a list like this
//We can sort array like this
//stable_sort sorts equal elements in same order
vector<int>::iterator i;// iteratot works like a pointer
 for(i=v.begin();i!=v.end();i++){// Why != and not < ?
cout<<*i<<endl;
}
v. clear();// This function makes vector to contain 0 elements. It does not  make elements zeroes it completely erases
//the container.
if(v.empty()){
cout<<"YES";
}
}
When making nested constructions, make sure that the “brackets” are not directly following one another ,
leave a blank between them.
vector<vector<int>> WrongDefinition; // Wrong: compiler may be confused by 'operator >>'

vector<int> v(10); creates a vector of size 10.
vector<int> v(10,5); creates a vector of size 10 .All 10 ints have value 10.
int arr[4]={1,2,3,4};
vector<int> v(arr,arr+4);

The resize() function makes vector contain the required number of elements. If you require less elements than
 vector already contain, the last ones will be deleted. If you ask vector to grow, it will enlarge its size and fill
 the newly created elements with zeroes.
 Note that if you use push_back() after resize(), it will add elements AFTER the newly allocated size, but not
 INTO it. In the example above the size of the resulting vector is 25, while if we use push_back() in a second loop,
 it would be 30.

 void some_function(const vector<int>& v) { // OK
      // ...
 } // Passing a vector as reference.


 vector<int> v1;
 // ...
 vector<int> v2 = v1; // This can be done later also
 vector<int> v3(v1);

 It should be clear to you now how to create the two-dimensional vector of given size:
int N, N;
// ...
vector< vector<int> > Matrix(N, vector<int>(M, -1));

v1.swap(v2) // Swaps the contents of v1 and v2.

v.insert(v.begin()+2 ,23)// Shifting automatically done;

at(): Returns the reference to the element at a particular position (can also be done using ‘[ ]’ operator).
Its time complexity is O(1).
back(): Returns the reference to the last element. Its time complexity is O(1).
begin(): Returns an iterator pointing to the first element of the vector. Its time complexity is O(1).
clear(): Deletes all the elements from the vector and assign an empty vector. Its time complexity is O(N) where N is
the size of the vector.
empty(): Returns a boolean value, true if the vector is empty and false if the vector is not empty. Its time complexity
is O(1).
end(): Returns an iterator pointing to a position which is next to the last element of the vector. Its time complexity is
O(1).
erase(): Deletes a single element or a range of elements. Its time complexity is O(N + M) where N is the number of the
elements erased and M is the number of the elements moved.
front(): Returns the reference to the first element. Its time complexity is O(1).
insert(): Inserts new elements into the vector at a particular position. ts time complexity is O(N + M) where N is the
number of elements inserted and M is the number of the elements moved .
pop_back(): Removes the last element from the vector. Its time complexity is O(1).
push_back(): Inserts a new element at the end of the vector. Its time complexity is O(1).
resize(): Resizes the vector to the new length which can be less than or greater than the current length. Its time
complexity is O(N) where N is the size of the resized vector.
size(): Returns the number of elements in the vector. Its time complexity is O(1).

distance(it1,it2)

lower_bound(it1,it2,val) for a sorted vector
lower_bound()  returns first element >=
upper_bound()  return first element >

Removes the element present at position.<br>
Ex: v.erase(v.begin()+4); (erases the `$5{th}$` element of the vector v)

Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth element.)

reverse(v.begin(),v.end());

traversing a vector in reverse:
for(auto it=v.rbegin();it!=v.rend();it++)
cout<<*it<<endl;

accesing the last element of a vector:
auto it=v.end();
it--;
