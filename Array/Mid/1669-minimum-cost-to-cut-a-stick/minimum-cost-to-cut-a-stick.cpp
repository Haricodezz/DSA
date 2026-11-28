class Solution {
public:
    // int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    //     if (j - i == 1)
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int mn = INT_MAX;

    //     for (int k = i + 1; k < j; k++) {
    //         int cost = solve(i, k, cuts, dp) + solve(k, j, cuts, dp) +
    //         cuts[j] -
    //                    cuts[i];
    //         mn = min(cost, mn);
    //     }

    //     return dp[i][j] = mn;
    // }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        vector<int> temp;
        temp.push_back(0);
        for (auto x : cuts) {
            temp.push_back(x);
        }

        temp.push_back(n);
        int m = temp.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 3; len <= m; len++) {

            for (int i = 0; i + len - 1 < m; i++) {
                int j = i + len - 1;
                int mn = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k] + dp[k][j] + (temp[j] - temp[i]);

                    mn = min(mn, cost);
                }
                dp[i][j] = mn;
            }
        }
        return dp[0][m - 1];
    }
};