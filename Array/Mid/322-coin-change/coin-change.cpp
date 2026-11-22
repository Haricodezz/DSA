class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX -1);

   dp[0]=0;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] <= j) {

                    dp[j] = min(1 + dp[j - coins[i - 1]], dp[j]);

                } 

            }
        }

        



        int ans = dp[amount];
        return ans>= INT_MAX -1 ? -1 : ans ;
    }
};