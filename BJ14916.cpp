// 백준 14916번. 거스름돈. 실버 5. 241002 solved.
// 매우 쉬운 그리디 + DP 문제

#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int dp[1000001];

    dp[0] = -1;
    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 3;
    dp[7] = 2;
    dp[8] = 4;
    dp[9] = 3;
    dp[10] = 2;
    dp[11] = 4;
    dp[12] = 3;

    for(int i = 13; i < n+1; i++) {
        if(dp[i-2] + 1 > dp[i-5] + 1) {
            dp[i] = dp[i-5] + 1;
        } else {
            dp[i] = dp[i-2] + 1;
        }
    }
    
    cout << dp[n];

    return 0;
}