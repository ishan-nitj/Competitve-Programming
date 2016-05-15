//// Code borrowed from Shubham Garg//may be he borrowed from someone else
//Here the first term in LCP array is zero

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1000001


using namespace std;
char str[MAX]; //input
int Rank[MAX], suffixArray[MAX]; //output
int cnt[MAX], Next[MAX]; //internal
bool bh[MAX], b2h[MAX];
int Height[MAX];
int Length_of_str;
/*The format for M table where preprocessing value are stored is
M[MAX_STRING_SIZE][logbase2(MAX_STRING_SIZE)].
Also it it observed that Value of logbase2(10^7)= 23.253496664.
Thus always fix logbase2 value to 25.
*/

//int M[MAX][25];

bool smaller_first_char(int a, int b)
{
	return str[a] < str[b];
}
void print(int index)
{
	for(int i=index;i<strlen(str);++i)
	{
		cout<<str[i];
	}
	cout<<endl;
}

void suffixSort(int n)
{
	//sort suffixes according to their first characters
	for (int i=0; i<n; ++i)
	{
		suffixArray[i] = i;
	}
	sort(suffixArray, suffixArray + n, smaller_first_char);
	//{suffixArray contains the list of suffixes sorted by their first character}

	for (int i=0; i<n; ++i)
	{
		bh[i] = i == 0 || str[suffixArray[i]] != str[suffixArray[i-1]];
		b2h[i] = false;
	}

	for (int h = 1; h < n; h <<= 1)
	{
		//{bh[i] == false if the first h characters of suffixArray[i-1] == the first h characters of suffixArray[i]}
		int buckets = 0;
		for (int i=0, j; i < n; i = j)
		{
			j = i + 1;
			while (j < n && !bh[j]) j++;
			Next[i] = j;
			buckets++;
		}
		if (buckets == n) break; // We are done! Lucky bastards!
		//{suffixes are separted in buckets containing strings starting with the same h characters}

		for (int i = 0; i < n; i = Next[i])
		{
			cnt[i] = 0;
			for (int j = i; j < Next[i]; ++j)
			{
				Rank[suffixArray[j]] = i;
			}
		}

		cnt[Rank[n - h]]++;
		b2h[Rank[n - h]] = true;
		for (int i = 0; i < n; i = Next[i])
		{
			for (int j = i; j < Next[i]; ++j)
			{
				int s = suffixArray[j] - h;
				if (s >= 0){
					int head = Rank[s];
					Rank[s] = head + cnt[head]++;
					b2h[Rank[s]] = true;
				}
			}
			for (int j = i; j < Next[i]; ++j)
			{
				int s = suffixArray[j] - h;
				if (s >= 0 && b2h[Rank[s]]){
					for (int k = Rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}
		for (int i=0; i<n; ++i)
		{
			suffixArray[Rank[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	for (int i=0; i<n; ++i)
	{
		Rank[suffixArray[i]] = i;
	}
}
// End of suffix array algorithm

/*
Begin of the O(n) longest common prefix algorithm
Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
Arimura, Setsuo Arikawa, and Kunsoo Park.
*/

/*
Note to say Suffix [i] always means the Ith suffix in LEXOGRAPHICALLY SORTED ORDER
ie Height[i]=LCPs of (Suffix   i-1 ,suffix  i)
*/

void getHeight(int n)
{
	for (int i=0; i<n; ++i) Rank[suffixArray[i]] = i;
	Height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (Rank[i] > 0)
		{
			int j = suffixArray[Rank[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h])
			{
				h++;
			}
			Height[Rank[i]] = h;
			if (h > 0) h--;
		}
	}
}
// End of longest common prefixes algorithm



int main()
{

int Len,x,y;

scanf("%s",&str);
Len=strlen(str);
Length_of_str=Len;

suffixSort(Len);
getHeight(Len);

for(int i=0;i<Len;i++)
    cout<<suffixArray[i]<<" ";///
cout<<endl;
for(int i=0;i<Len;i++)
    cout<<Height[i]<<" ";////Here the first term in LCP array is zero


}
