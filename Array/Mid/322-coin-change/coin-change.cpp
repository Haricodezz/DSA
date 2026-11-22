class Solution {
public:
    int solve(vector<int>& arr, int n, int w,vector <vector <int>> & dp) {
        if (w == 0) {
            return 0;
        }
        if (n == 0) {
            return INT_MAX - 1;
        }

if(dp[n][w] != -1){
    return dp[n][w];
}

    
        if (arr[n - 1] <= w) {
            return dp[n][w]= min(1 + solve(arr, n, w - arr[n - 1],dp), solve(arr, n - 1, w,dp));
        } else {
            return dp[n][w]= solve(arr, n - 1, w,dp);
        }
    }


    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

vector <vector <int>> dp(n+1,vector<int>(amount+1,-1));



    int ans =   solve(coins, n, amount,dp);


    return ans >= INT_MAX - 1 ? -1 : ans;
    }

};