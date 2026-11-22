class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;

        for(auto x : nums){
            sum+=x;
        }

        if(sum%2 !=0) return false;

        int n = nums.size();

        int w= sum/2;

        vector<vector<bool>> dp(n+1, vector<bool>(w+1,false));

        for(int i=0;i < n+1;i++){
            dp[i][0]=true;
        }
        for(int j = 1 ; j< w+1; j++){
            dp[0][j]= false;
        }

        for(int i =1; i < n+1; i++){
            for(int j =1; j< w+1 ; j++){
                    //include
                if( nums[i-1]<= j){
                    dp[i][j]=  dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                //exclude
                else{
                  dp[i][j]=  dp[i-1][j];
                }
            }
        }


        return dp[n][w];

        
        




    }
};