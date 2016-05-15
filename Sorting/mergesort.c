// why start >=end
#include<stdio.h>
 #include"Basic functions.c"
 void mergesort(int *a,int start,int end){
int mid;
if(start>=end)
return;
else
{
    mid=(start +end)/2;
mergesort(a,start,mid);
mergesort(a,mid+1,end);
merge(a,start,mid,end);
}
}

void merge(int *a,int start,int mid,int end){
int size=end-start+1;
int b[size];
int p,q,i,k;
p=start;q=mid+1;
k= 0;
while(!(p==mid +1 || q==end+1)){
if(a[p]<=a[q]){
b[k]=a[p];
p++;
k++;
}
else
{
b[k]=a[q];
q++;k++;
}
}
if(p==mid+1){
for(i=q;i<=end;i++){
b[k]=a[i];
k++;
}}
if(q==end+1){
for(i=p;i<=mid;i++)
{
  b[k]=a[i];
  k++;
}
}
k=0;
for(i=start;i<=end;i++){
a[i]=b[k];
k++;
}
}
int main(){
int a[]={1,3,5,7,2,4,6,8};
mergesort(a,0,7);
printarray(a,8);
}
