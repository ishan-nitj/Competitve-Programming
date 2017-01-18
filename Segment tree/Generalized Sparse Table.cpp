https://brilliant.org/wiki/sparse-table/  

#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int k = 16;
const int N = 1e5;
const int ZERO = 1e9 + 1; // min(ZERO, x) = min(x, ZERO) = x (for any x)

int table[N][k + 1]; // k + 1 because we need to access table[r][k]
int Arr[N];


int func(int x,int y){
    return min(x,y);
}

int main()
{
    int n, L, R, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> Arr[i]; // between -10^9 and 10^9

    // build Sparse Table
    for(int i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(int j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = func(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    cin >> q; // number of queries
    for(int i = 0; i < q; i++) {
        cin >> L >> R; // boundaries of next query, 0-indexed
        vector<int>v; 
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                v.push_back(table[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
        int answer=v[0];
        for(i=1;i<v.size();i++)
            answer=func(answer,v[i]);
        cout << answer << endl;
    }
    return 0;
}

