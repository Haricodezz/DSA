class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        int n = nums.size();

        if (abs(target) > sum)
            return 0;

        if ((sum + target) % 2 != 0)
            return 0;
        int w = (sum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

        dp[0][0]=1;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < w + 1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][w];
    }
};