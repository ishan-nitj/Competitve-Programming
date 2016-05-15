#include <iostream>//In a  map , the values be will be in sorted order according to the key.
//WE CANNOTMODIFY KEYS.// multimap allows duplicates keys.
#include <map>// We can access the key like *it.first and value by *it.second
using namespace std;
int main(){
    map <char,int> mp;
    map <char,int> mymap,mymap1;

    //insert elements individually in map with the combination of key value and value of element
    mp.insert(pair<char,int>('a',2));   //key is 'c' and 2 is value.
    mp.insert(pair<char,int>('b',1));
    mp.insert(pair<char,int>('c',43));

    //inserts elements in range using insert() function in map 'mymap'.
    mymap.insert(mp.begin(),mp.end());

    //declaring iterator for map
    map <char,int>::iterator it;

    //using find() function to return reference of element mapped by key 'b'.
    it = mp.find('b');

    //prints key and element's value.
    cout<<"Key and element's value of map are: ";
    cout<<it->first<<" and "<<it->second<<endl;

    //alternative way to insert elements by mapping with their keys.
    mymap1['x'] = 23;
    mymap1['y'] = 21;

    cout<<"Printing element mapped by key 'b' using at() function : "<<mp.at('b')<<endl;

    //swap contents of 2 maps namely mymap and mymap1.
    mymap.swap(mymap1);

    /* prints swapped elements of mymap and mymap1 by iterating all the elements through
        using   iterator. */
    cout<<"Swapped elements and their keys of mymap are: "<<endl;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"Swapped elements and their keys of mymap1 are: "<<endl;
    for(it=mymap1.begin();it!=mymap1.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;
    }
    //erases element mapped at 'c'.
    mymap1.erase('c');

    //prints all elements of mymap after erasing element at 'c'.

    cout<<"Elements of mymap1 after erasing element at key 'c' : "<<endl;
    for(it=mymap1.begin();it!=mymap1.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;
    }

    //erases elements in range from mymap1
    mymap1.erase(mymap1.begin(),mymap1.end());

    cout<<"As mymap1 is empty so empty() function will return 1 : " << mymap1.empty()<<endl;

    //number of elements with key = 'a' in map mp.
    cout<<"Number of elements with key = 'a' in map mp are : "<<mp.count('a')<<endl;

    //if mp is empty then itmp.empty will return 1 else 0.
    if(mp.empty())
    {
        cout<<"Map is empty"<<endl;
    }
    else
    {
        cout<<"Map is not empty"<<endl;
    }

    return 0;
}
Note: N is the number of elements in map.
Some Member Functions of map:
at( ): Returns a reference to the mapped value of the element identified with key.Its time complexity is O(logN).
count( ): searches the map for the elements mapped by the given key and returns the number of matches.As map stores
each element with unique key, then it will return 1 if match if found otherwise return 0.Its time complexity is O(logN).
clear( ): clears the map, by removing all the elements from the map and leaving it with its size 0.Its time complexity is
 O(N).
begin( ): returns an iterator(explained above) referring to the first element of map.Its time complexity is O(1).
end( ): returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last
element.Its time complexity is O(1).
empty( ): checks whether the map is empty or not. It doesn’t modify the map.It returns 1 if the map is empty otherwise
returns 0.Its time complexity is O(1).
erase( ): removes a single element or the range of element from the map.
find( ): Searches the map for the element with the given key, and returns an iterator to it, if it is present in the map
 otherwise it returns an iterator to the theoretical element which follows the last element of map.Its time complexity is
 O(logN).
insert( ): insert a single element or the range of element in the map.Its time complexity is O(logN), when only element
is inserted and O(1) when position is also given.
