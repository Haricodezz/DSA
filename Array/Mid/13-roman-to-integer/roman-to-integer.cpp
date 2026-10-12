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
    
        int i=0;
        for (i = 0; i < s.size() - 1; i++) {
           
            if (mp[s[i]] >= mp[s[i + 1]]) {
                ans += mp[s[i]];
            } else {
                ans=ans+mp[s[i+1]]- mp[s[i]];
                i++;
            }
        }
        if(i==s.size()-1 )ans+=mp[s[i]];
        
        return ans;
    }
};