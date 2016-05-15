If we don’t define our own copy constructor, the C++ compiler creates
a default copy constructor for each class which does a member wise
copy between objects.
In C++, a Copy Constructor may be called in following cases:
1. When an object of the class is returned by value(not by reference).
2. When an object of the class is passed (to a function(member func or friend func.)) by value as an
argument.
3. When an object is constructed based on another object of the same class.
4. When compiler generates a temporary object.


Copy constructor vs Assignment Operator
Which of the following two statements call copy constructor and which
one calls assignment operator?
MyClass t1, t2;
MyClass t3 = t1;  // ----> (1)
t2 = t1;          // -----> (2)

Copy constructor is called when a new object is created from an
existing object, as a copy of the existing object. Assignment
operator is called when an already initialized object is assigned a
new value from another existing object. In the above example (1) calls
copy constrictor and (2) calls assignment operator.

Can we make copy constructor private?
Yes, a copy constructor can be made private. When we make a copy
constructor private in a class, objects of that class become
non-copyable. This is particularly useful when our class has
pointers or dynamically allocated resources.

A copy constructor is called when an object is passed by value.
Copy constructor itself is a function. So if we pass argument by
value in a copy constructor, a call to copy constructor would be made
to call copy constructor which becomes a non-terminating chain of
calls. Therefore compiler doesn’t allow parameters to be pass by
value.
