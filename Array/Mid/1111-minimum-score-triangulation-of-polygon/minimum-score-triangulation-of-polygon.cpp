class Solution {

public:
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i+2; j < n; j++) {
                int mn = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost =
                        dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];

                    mn = min(cost, mn);
                }
                dp[i][j] = mn;
            }
        }

        return dp[0][n - 1];
    }
};