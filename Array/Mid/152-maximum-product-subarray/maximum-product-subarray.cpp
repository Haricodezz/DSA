class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = nums[0];
        long long mini = nums[0];
        long long ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0) {
                swap(maxi, mini);
            }

            maxi = max((long long)nums[i], maxi * nums[i]);
            mini = min((long long)nums[i], mini * nums[i]);

            ans = max(ans, maxi);
        }

        return ans;
    }
};