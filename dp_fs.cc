// DP 斐波那契数列
// dp[i] = dp[i - 1] + dp[i - 2] (i >= 2)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int num = 0;
    cin >> num;
    if (num <= 2) {
        cout << 1 << endl;
        return 0;
    }
    int dp[num];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < num; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[num - 1] << endl;
    return 0;
}
