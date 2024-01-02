#include <iostream>
using namespace std;


int knapsack3D(int profits[], int weights[], int volumes[], int n, int cap, int vCapacity)
{
    int dp[n + 1][cap + 1][vCapacity + 1];


    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= cap; w++)
        {
            for (int v = 0; v <= vCapacity; v++)
            {
                if (i == 0 || w == 0 || v == 0)
                    dp[i][w][v] = 0;
                else if (weights[i - 1] <= w && volumes[i - 1] <= v)
                    dp[i][w][v] = max(dp[i - 1][w][v], dp[i - 1][w - weights[i - 1]][v - volumes[i - 1]] + profits[i - 1]);
                else
                    dp[i][w][v] = dp[i - 1][w][v];
            }
        }
    }

    return dp[n][cap][vCapacity];
}

int main()
{
    int n;
    cout << "items: ";
    cin >> n;

    int profits[n], weights[n], volumes[n];

    cout <<  "profit, weight, and volume:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i] >> weights[i] >> volumes[i];
    }

    int cap, vCapacity;
    cout << " max capacity and volume capacity : ";
    cin >> cap >> vCapacity;

    int maxProfit = knapsack3D(profits, weights, volumes, n, cap, vCapacity);
    cout << "Max profit: " << maxProfit << endl;

    return 0;
}
