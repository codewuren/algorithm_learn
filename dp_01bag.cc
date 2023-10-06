// DP 01背包问题，原题acwing https://www.acwing.com/problem/content/description/2/
// dp[i][j] 是第i件物品，背包容量为j时的最优解 
// 对于第i件物品，存在两种可能：
// 1.能选 -> j >= v[i]
//  - 1.选，dp[i][j] = dp[i - 1][j - v[i]] + w[i]
//  - 2.不选，dp[i][j] = dp[i - 1][j]
// 2.不能选 -> j < v[i] -> dp[i][j] = dp[i - 1][j]

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN];
vector<int> v(MAXN);
vector<int> w(MAXN);
int N, V;

// 二维
void sol_1() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= V; j++) {
            if(j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[N][V] << endl;
}


int main() {
    cin >> N >> V;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }
    sol_1();
    return 0;
}
