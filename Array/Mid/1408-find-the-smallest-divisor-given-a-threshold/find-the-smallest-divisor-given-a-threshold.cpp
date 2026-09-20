class Solution {
public:
    int resultOfDivision(vector<int>& nums, int d) {

        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += (nums[i] + d -1) / d;
        }
        return result;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();
        int Maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            Maxi = max(Maxi, nums[i]);
        }

        int low = 1;

        int high = Maxi;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (resultOfDivision(nums, mid) > threshold) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};