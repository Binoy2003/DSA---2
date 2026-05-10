#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{



    int n;
    cout << "Enter rod length n: ";
    if (!(cin >> n)) return 0;

    vector<long long> price(n + 1, 0);
    cout << "Enter " << n << " prices (p1 to p" << n << "):\n";
    for (int i = 1; i <= n; ++i) cin >> price[i];

    vector<long long> dp(n + 1, LLONG_MIN);

    vector<int> cut(n + 1, 0);

    dp[0] = 0;

    for (int len = 1; len <= n; ++len)
    {
        long long best = LLONG_MIN;
        int bestCut = 0;

        for (int i = 1; i <= len; ++i)
        {
            long long candidate = price[i] + dp[len - i];
            if (candidate > best)
            {
                best = candidate;
                bestCut = i;
            }
        }
        dp[len] = best;
        cut[len] = bestCut;
    }

    cout << "Maximum revenue for rod of length " << n << " = " << dp[n] << "\n";


    cout << "Pieces used: ";
    int L = n;
    bool first = true;
    while (L > 0)
    {
        int c = cut[L];
        if (!first) cout << " + ";
        cout << c;
        first = false;
        L -= c;
    }
    cout << "\n";

    return 0;
}
