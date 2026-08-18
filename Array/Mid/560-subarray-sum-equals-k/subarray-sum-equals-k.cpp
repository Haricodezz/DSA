class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> mpp;
        mpp[0]=1;
        int PreSum=0;
        int cnt=0;

        for(int i=0; i <nums.size();i++){

            PreSum+=nums[i];
            int rem=PreSum - k;
            cnt+=mpp[rem];
            mpp[PreSum]++;



        }
return cnt;



    }
};