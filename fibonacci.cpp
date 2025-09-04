#include <iostream>
#include <vector>
using namespace std;

vector<long long> fibonacciSequence(int n) {
    vector<long long> dp(n);  // dp[i] 表示第 i 项斐波那契数

    if (n <= 0) return dp;
    if (n >= 1) dp[0] = 0;
    if (n >= 2) dp[1] = 1;

    // 动态规划递推：F(i) = F(i-1) + F(i-2)
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    vector<long long> fib = fibonacciSequence(n);

    cout << "First " << n << " terms of Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) {
        cout << fib[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
