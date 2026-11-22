class Solution {
public:

int solve(vector<int>& arr, int n, int sum, int target) {

    if(n == 0) {
        if(sum == target)
            return 1;
        else
            return 0;
    }

    int include = solve(
        arr, n-1, sum + arr[n-1], target
    );

    int exclude = solve(
        arr, n-1, sum - arr[n-1], target
    );

    return include + exclude;
}

    int findTargetSumWays(vector<int>& nums, int target) {
        
return solve(nums,nums.size(),0,target);
        
    }
};