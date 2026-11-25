
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build LCS DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Construct SCS
        int l = m;
        int r = n;

        string s = "";

        while (l > 0 && r > 0) {

            if (str1[l - 1] == str2[r - 1]) {
                s.push_back(str1[l - 1]);
                l--;
                r--;
            }
            else {
                if (dp[l - 1][r] > dp[l][r - 1]) {
                    s.push_back(str1[l - 1]);
                    l--;
                }
                else {
                    s.push_back(str2[r - 1]);
                    r--;
                }
            }
        }

        // Add remaining characters
        while (l > 0) {
            l--;
            s.push_back(str1[l]);
        }

        while (r > 0) {
            r--;
            s.push_back(str2[r]);
        }

        reverse(s.begin(), s.end());

        return s;
    }
};
