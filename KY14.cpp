#include <climits>
#include <iostream>
#define MAX 1e6
using namespace std;

int main() {
    int M, N, stamps[21],
        dp[21][101]; // dp[i][j] 从前i张邮票中取。总值为j的最少张数
    cin >> M >> N;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            dp[i][j] = MAX;
    dp[0][0] = 0;
    for (int i = 1; i  <= N; i++)
        cin >> stamps[i];
    for (int i = 1; i <= N; i++) // 遍历邮票
        for (int j = 0; j <= M; j++) { // 遍历总数
            if (stamps[i] > j)
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - stamps[i]] + 1);
            }
        }
    cout << (dp[N][M] == MAX ? 0 : dp[N][M]);
}
// dp[i][j] = min(dp[i-1][j], dp[i-1][j-stamps[i]]+1)