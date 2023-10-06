// DP 01背包问题，原题acwing https://www.acwing.com/problem/content/description/2/

// 二维方法
// dp[i][j] 是第i件物品，背包容量为j时的最优解 
// 对于第i件物品，存在两种可能：
// 1.能选 -> j >= v[i]
//  - 1.选，dp[i][j] = dp[i - 1][j - v[i]] + w[i]
//  - 2.不选，dp[i][j] = dp[i - 1][j]
// 2.不能选 -> j < v[i] -> dp[i][j] = dp[i - 1][j]

// 一维方法
// dp[j] 是N件物品，背包容量为j时的最优解
// 状态转移方程: dp[j] = max(dp[j], dp[j - v[i]] + w[i])

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int dp_2d[MAXN][MAXN];
int dp_1d[MAXN];
vector<int> v(MAXN);
vector<int> w(MAXN);
int N, V;

// 二维
void sol_1() {
    clock_t start, finish;
    start = clock();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= V; j++) {
            if(j < v[i]) dp_2d[i][j] = dp_2d[i - 1][j];
            else dp_2d[i][j] = max(dp_2d[i - 1][j], dp_2d[i - 1][j - v[i]] + w[i]);
        }
    }
    finish = clock();
    cout << "the result is: " << dp_2d[N][V] << " used " << (double)(finish - start) / CLOCKS_PER_SEC << " s"<< endl;
}

// 一维
void sol_2() {
    clock_t start, finish;
    start = clock();
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= 0; j--) {
            if (j >= v[i]) dp_1d[j] = max(dp_1d[j], dp_1d[j - v[i]] + w[i]);
        }
    }
    finish = clock();
    cout << "the result is: " << dp_1d[V] << " used " << (double)(finish - start) / CLOCKS_PER_SEC << " s"<< endl;

}

int main() {
    cin >> N >> V;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }
    sol_1();
    sol_2();
    return 0;
}
