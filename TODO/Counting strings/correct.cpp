#include <stdio.h>
#include<string.h>
#define ModV 1000000007
#define tp5 100005
 
long long ans;
char inp[tp5];
 
int main()
{
  int i, j, len;
  long long temp=0LL, b;
  scanf("%s", inp);
  len = strlen(inp);
  ans += (long long)('Z' - inp[len-1]);
  for(i=len-1; i>0; i--){
    temp += (long long)('Z' - inp[i]);
    b = (long long)('Z' - inp[i-1]);
    ans += (temp+1LL)*b;
    ans %= ModV;
    temp = (temp*26);
    temp %= ModV;
  }
  printf("%lld\n",ans);
  return 0;
} 
