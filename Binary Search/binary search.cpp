bool binarySearchIter(int A[], int length, int item)
{
    int left = 0, right = length - 1, mid;
    while (left <= right)  //stops when left>right ------------1
    {
        mid = left + (right - left) / 2;    -----------------2    // finding middle index
        if (A[mid] == item)
            return true;                // item found
        else if (item < A[mid])
            right = mid - 1;            // recurse on left sub-array
        else
            left = mid + 1;             // recurse on right sub-array
    }
    return false;                        // item not found
}

Note that in BS we have to tweak 1 and 2 acc. to the question.
We have to take care of the situation such that same value of l and r doesnt cause an infinte loop.

See qn :http://codeforces.com/problemset/gymProblem/101021/A

see:

int main(){
ll l=1,r=1000000;
while(l<r){
ll mid=(l+r+1)/2;
cout<<mid<<endl;
fflush(stdout);
string s;cin>>s;
if(s==">=")
l=mid;
else
r=mid-1;
}
cout<<"! "<<l<<endl;
fflush(stdout);
}


