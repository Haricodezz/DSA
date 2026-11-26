
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        vector<uint64_t> dp(n + 1, 0);
        // for (int i = 0; i < m + 1; i++) {
        //     dp[i][0] = 1;
        // }

        dp[0] = 1;

        for (int i = 1; i < m + 1; i++) {
           uint64_t prevDiagonal = 1;
            for (int j = 1; j < n + 1; j++) {
             uint64_t pick = 0;
               uint64_t notPick = 0;
                if (s[i - 1] == t[j - 1]) {
                    pick = prevDiagonal;
                }

                notPick = dp[j];
                prevDiagonal = dp[j];
                dp[j] = notPick + pick;
            }
        }

        return dp[n];
    }
};
