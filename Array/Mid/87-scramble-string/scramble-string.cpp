class Solution {

public:
    bool solve(string a, string b,unordered_map<string, bool> &dp) {

        // base condition

        if (a.compare(b) == 0)
            return true;

        if (a.size() <= 1)
            return false;

        string key = a + "#" + b;
        // swap
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int n = a.size();

        for (int i = 1; i < n; i++) {

            if ((solve(a.substr(0, i), b.substr(n - i, i),dp) &&
                 solve(a.substr(i, n - i), b.substr(0, n - i),dp)) ||
                (solve(a.substr(0, i), b.substr(0, i),dp) &&
                 solve(a.substr(i, n - i), b.substr(i, n - i),dp))) {
                return dp[key] = true;
            }
        }
        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        int n;
        if (s1.size() > s2.size()) {
            n = s1.size();

        } else {
            n = s2.size();
        }

        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0 && s2.size() == 0)
            return true;
        unordered_map<string, bool> dp;

        return solve(s1, s2,dp);
    }
};