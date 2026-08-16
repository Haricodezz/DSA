class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       map<int,int> mpp;
       vector<int> ans;
        int mm=nums.size()/3 + 1 ;
       for(int i =0; i <nums.size();i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]] == mm){
            ans.push_back(nums[i]);
        }
       }
       
    //    for(auto it: mpp){
    //     if(it.second>nums.size()/3){
    //         ans.push_back(it.first);
    //     }
    //    } 

       return ans;
    }
};