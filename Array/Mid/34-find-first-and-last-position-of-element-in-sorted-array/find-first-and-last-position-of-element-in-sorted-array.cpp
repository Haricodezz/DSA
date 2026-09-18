class Solution {
public:
    int low(vector<int>& arr, int x) {
        int n = arr.size();
        int ans = n;
        int left = 0;
        int high = n - 1;
        while (left <= high) {
            int mid = left + (high - left) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;

            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    int upp(vector<int>& arr, int x) {
        int n = arr.size();
        int ans = n;
        int left = 0;
        int high = n - 1;
        while (left <= high) {
            int mid = left + (high - left) / 2;

            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;

            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int lb = low(nums, target);
        int ub = upp(nums, target);

        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }

        return {lb,ub-1};
    }
};