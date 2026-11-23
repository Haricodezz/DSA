class Solution {
public:
    int solve(string& x, string& y, int m, int n, vector<int>& dp) {

     
        dp[0] = 0;

        for (int i = 1; i < m + 1; i++) {
            int prev = 0;
            for (int j = 1; j < n + 1; j++) {
                int temp = dp[j];
                if (x[i - 1] == y[j - 1]) {
                    dp[j] = 1 + prev;

                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        if (m < n) {
            swap(text1, text2);
            swap(m, n);
        }

        vector<int> dp(n + 1, 0);

        return solve(text1, text2, m, n, dp);
    }
};