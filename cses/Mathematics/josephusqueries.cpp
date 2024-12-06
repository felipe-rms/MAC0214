#include <bits/stdc++.h>
using namespace std;

long long calculateRemovedChild(long long totalChildren,
                                long long kthChild)
{
    if (totalChildren == 1)
        return 1;
    if (kthChild <= (totalChildren + 1) / 2)
    {
        if (2 * kthChild > totalChildren)
            return (2 * kthChild) % totalChildren;
        else
            return 2 * kthChild;
    }
    long long temp = calculateRemovedChild(
        totalChildren / 2,
        kthChild - (totalChildren + 1) / 2);
    if (totalChildren % 2 == 1)
        return 2 * temp + 1;
    return 2 * temp - 1;
}

int main(){ 
    int q; cin >> q;
    long long n, k;
    for(int i = 0; i < q; i++){
        cin >> n >> k;
        cout << calculateRemovedChild(n, k) << "\n";
    }
}
