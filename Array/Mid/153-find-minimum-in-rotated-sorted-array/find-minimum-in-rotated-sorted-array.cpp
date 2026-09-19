class Solution {
public:
    int findMin(vector<int>& nums) {
        // int low = 0;
        // int high = nums.size() - 1;
        // int target = INT_MAX;
        // while (low <= high) {

        //     int mid = low + (high - low) / 2;
        //     target = min(nums[mid], target);
        //     if (nums[low] <= nums[mid]) {
        //         if (target <= nums[mid]) {
        //             target = min(nums[low], target);
        //         }

        //         low = mid + 1;
        //     } else {
        //         high = mid - 1;
        //     }
        // }
        // return target;















         int low = 0;
        int high = nums.size() - 1;
        int target = INT_MAX;
        while (low <= high) {
            if (nums[low]<nums[high]){
                target=min(target,nums[low]);
                break;
            }
            int mid = low + (high - low) / 2;
            target = min(nums[mid], target);
            if (nums[low] <= nums[mid]) {
               target = min(target,nums[low]);

                low = mid + 1;
            } else {
                target=min(target,nums[mid]);
                high = mid - 1;
            }
        }
        return target;
    }
};