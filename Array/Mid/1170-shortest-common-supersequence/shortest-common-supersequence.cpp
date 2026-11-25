class Solution {
public:
    string solve(string& x, string& y, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {

                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int l = m;
        int r = n;
        string s = "";
        while (l > 0 && r > 0) {
            if (x[l - 1] == y[r - 1]) {
                s.push_back(x[l - 1]);
                l--;
                r--;
            } else {

                if (dp[l - 1][r] > dp[l][r - 1]) {
                    s.push_back(x[l - 1]);
                    l--;
                } else {
                    s.push_back(y[r - 1]);
                    r--;
                }
            }
        }

        while (l > 0) {
            l--;
            s.push_back(x[l]);
        }
        while (r > 0) {

            r--;
            s.push_back(y[r]);
        }
        
        reverse(s.begin(), s.end());

        return s;
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.size();
        int n = str2.size();

        string ans = solve(str1, str2, m, n);

        return ans;
    }
};