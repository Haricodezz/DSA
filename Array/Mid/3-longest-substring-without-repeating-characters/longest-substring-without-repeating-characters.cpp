class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int maxi = 1;
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;
        mp[s[0]] = 0;
        for (right = 1; right < s.size(); right++) {

            if (mp.find(s[right]) == mp.end()) {

                mp[s[right]] = right;
                
            } else {
                left = max(left,mp[s[right]] + 1);
                
                mp[s[right]] = right;
            }
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};