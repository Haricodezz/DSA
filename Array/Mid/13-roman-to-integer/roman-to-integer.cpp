class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int sub = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (sub != 0) {
                ans = ans + mp[s[i]] - sub;
                sub = 0;
                continue;
            }
            if (mp[s[i]] >= mp[s[i + 1]]) {
                ans += mp[s[i]];
            } else {
                sub = mp[s[i]];
            }
        }
        if (sub != 0) {
                ans = ans + mp[s[s.size() - 1]] - sub;
                
            }else{
                ans+=mp[s[s.size() - 1]];
            }
        return ans;
    }
};