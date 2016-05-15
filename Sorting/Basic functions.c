/*Here min and max function return the posn. of the firs min and max elements,Swap function pointer variable*/
#include<stdio.h>
void swap(int *,int *);
int min(int *,int);
int max(int *,int);
void swap(int *x,int *y)
{
 int t;
 t=*x;
 *x=*y;
 *y=t;
}
int min(int *a,int n){
int i;
int min=a[0];
int index=0;
for(i=1;i<n;i++){
if (a[i]<min){
min=a[i];
index=i;
}
}
return index;
}

int max(int *a,int n){
    int i;
int index=0;
int max=a[0];
for(i=1;i<n;i++){
if (a[i]>max){
max=a[i];
index=i;
}}
return index;
}


void printarray(int *a,int n){
int i;
for(i=0;i<n;i++){
printf("%d",a[i]);
}
}

