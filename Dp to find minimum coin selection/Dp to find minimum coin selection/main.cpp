#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 100000;
int dp[101][N];

int func(int in, int amnt, vector<int>& coins) {
    if (amnt == 0) return 1;
    if (in < 0 || amnt < 0) return 0;
    if (dp[in][amnt] != -1) return dp[in][amnt];

    int ways = 0;


    ways += func(in- 1, amnt - coins[in], coins);


    ways += func(in - 1, amnt, coins);

    dp[in][amnt] = ways;

    return ways;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, w;

    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cin >> w;

    int result = func(n - 1, w, coins);
    cout << result << endl;

    return 0;
}
