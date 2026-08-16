class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        int cnt=1;
       int  lastsmaller=INT_MIN;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size();i++){
            if(nums[i]-1 == lastsmaller){
                cnt++;
                lastsmaller=nums[i];
            }
            else if (nums[i]!= lastsmaller){
                
                cnt=1;
                lastsmaller=nums[i];
                

            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};