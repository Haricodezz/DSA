class Solution {
public:
    int solve(string& x, string& y, int m, int n, vector<vector<int>>& dp) {

        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];

        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(text1, text2, m, n, dp);
    }
};