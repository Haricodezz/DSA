class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int longest = 1;
        unordered_set<int> St;

        for(int i =0; i < n;i++){
            St.insert(nums[i]);
        }

        for(auto it: St){
            if(St.find(it-1)== St.end()){
                int x=it;
                int cnt=1;
                while(St.find(x+1)!= St.end()){
                    x++;
                    cnt++;

                }
                longest= max(longest,cnt);
            }
            
        }

        return longest;
    }
};