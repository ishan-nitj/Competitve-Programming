BIT are used to calculate prefix sums efficiently.

Let us consider the following problem to understand Binary Indexed Tree.
We have an array arr[0 . . . n-1]. We should be able to
1 Find the sum of first i elements.
2 Change value of a specified element of the array arr[i] = x where 0 <= i <= n-1.

M1) A simple solution is to run a loop from 0 to i-1 and calculate sum of elements.
To update a value, simply do arr[i] = x. The first operation takes O(n) time and second operation
takes O(1) time.This works well if the number of query operations are small and very large updates.

    M2)Another simple solution is to create another array and store sum from start to i at the i’th index in
this array. Sum of a given range can now be calculated in O(1) time, but update operation takes O(n)
    time now. This works well if the number of query operations are large and very few updates.

    Using Binary Indexed Tree, we can do both tasks in O(Logn) time. The advantages of Binary Indexed Tree
    over Segment are, requires less space and very easy to implement.

    Before starting with binary indexed tree, we need to understand a particular bit manipulation trick.
    Here it goes.
    x&(-x) gives the last set bit in a number x. How?
Example: x = 10(in decimal) = 1010(in binary)
    The last set bit is given by x&(-x) = 0010
    x=11(1011) x&(-x)=0001

    For ease, we make sure our given array is 1-based indexed i.e set a[0]=0;
    int a[12] = {0(for 1 based indexing),2,1,1,3,2,3,4,5,6,7,8,9};
For visualisation see:http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/BITSum.png

Here the size of BIT will be 12.
BIT[0] will be a dummy node.

1)index of parent of x is x-(x&-x).(Just unset the last set bit).
2)To generalize this every index i in the BIT[] array stores the cumulative sum from the index i
to i - (1<<r) + 1 (both inclusive), where r represents the last set bit in the index i.
For e.g. BIT[12]: 12=1100 Range[12,12-4(100)+1]=[12,9].

Note:
{           a[x],                  if x is odd
    BIT[x] =                    a[1] + ... + a[x],     if x is power of 2
}

3)To get the prefix sum till i,return the sum of BIT[i] and all the ancestors of i.

Space Complexity: O(N) for declaring another array of size N

Time Complexity: O(logN) for each operation(update and query as well)

    When to use Binary Indexed Tree?

    Before going for Binary Indexed tree to perform operations over range, one must confirm that the
    operation or the function is:

    Associative. i.e f(f(a, b), c) = f(a, f(b, c)) this is true even for seg-tree

    Has an inverse. eg:

addition has inverse subtraction (this example we have discussed)

    Multiplication has inverse division

    gcd() has no inverse, so we can’t use BIT to calculate range gcd’s

    sum of matrices has inverse

    product of matrices would have inverse if it is given that matrices are degenerate i.e.
    determinant of any matrix is not equal to 0
