class Solution {

public:
    bool canwe(vector<int>& arr, int k, int m) {

        int cnt = 1;
        int load = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > m) return false;
            if (load + arr[i] > m) {
                load = arr[i];
                cnt++;
            } else {
                load += arr[i];
            }
        }

        if (cnt <= k) {
            return true;
        } else {
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {

        int r = 0;
        int l = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            r +=nums[i];
            l=max(l,nums[i]);
        }
        int low = l;

        int high = r;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canwe(nums, k, mid) == true) {
                 high = mid - 1;
            } else {
               low = mid + 1;
            }
        }

        return low;
    }
};