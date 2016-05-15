#include<bits/stdc++.h>// [] is not defines for lists.i.e There is no random access for lists. To access 5th element ,
// we have to move past first four elements.
using namespace std;
int main(){
list<int>l,l1;
l.push_back(1);
l.push_back(12);
l.push_back(13);
l1=l;
l.reverse();
for(i=l.begin();i!=l.end();i++){// donot use < in place of != for lists
cout<<*i<<endl;
}
//l.merge(l1) merges l1 into l provided both are sorted. The new l is also sorted.
//l.unique() removes duplicates in sorted list.
}
/*begin( ): It returns an iterator pointing to the first element in list.Its time complexity is O(1).
end( ): It returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the
last element.Its time complexity is O(1).
empty( ): It returns whether the list is empty or not.It returns 1 if the list is empty otherwise returns 0.Its time
complexity is O(1).
assign( ): It assigns new elements to the list by replacing its current elements and change its size accordingly.It
time complexity is O(N).
back( ): It returns reference to the last element in the list.Its time complexity is O(1).
erase( ): It removes a single element or the range of element from the list.Its time complexity is O(N).
front( ): It returns reference to the first element in the list.Its time complexity is O(1).
push_back( ): It adds a new element at the end of the list, after its current last element. Its time complexity is O(1).
push_front( ): It adds a new element at the beginning of the list, before its current first element. Its time complexity
 is O(1).
remove( ): It removes all the elements from the list, which are equal to given element. Its time complexity is O(N).
pop_back( ): It removes the last element of the list, thus reducing its size by 1. Its time complexity is O(1).
pop_front( ): It removes the first element of the list, thus reducing its size by 1. Its time complexity is O(1).
insert( ): It insert new elements in the list before the element on the specified position. Its time complexity is O(N).
reverse ( ): It reverses the order of elements in the list. Its time complexity is O(N).
size( ): It returns the number of elements in the list. Its time complexity is O(1).

*/
