#include <bits/stdc++.h>
using namespace std;

int LCS( int *X, int *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int max(int a, int b)
{
    return (a > b)? a : b;
}


int main()
{
    int  X[] = {1,2,3,4,5,6,7,8,9,0};
    int  Y[] = {1,2,5,8,9,3,4,6,7,0};

    int m = X.size();
    int n = Y.size();

    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;

    return 0;
}
