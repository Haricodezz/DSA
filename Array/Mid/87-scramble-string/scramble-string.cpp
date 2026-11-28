class Solution {

public:
    bool solve(string a, string b, unordered_map<string, bool>& dp) {

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

            if ((solve(a.substr(0, i), b.substr(n - i, i), dp) &&
                 solve(a.substr(i, n - i), b.substr(0, n - i), dp)) ||
                (solve(a.substr(0, i), b.substr(0, i), dp) &&
                 solve(a.substr(i, n - i), b.substr(i, n - i), dp))) {
                return dp[key] = true;
            }
        }
        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0 && s2.size() == 0)
            return true;

        int freq[26] = {0};

        for (char ch : s1) {
            freq[ch - 'a']++;
        }

        for (char ch : s2) {
            freq[ch - 'a']--;
            if (freq[ch - 'a'] < 0) {
                return false;
            }
        }

        unordered_map<string, bool> dp;

        return solve(s1, s2, dp);
    }
};