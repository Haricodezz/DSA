class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        vector<int> freq(2, 0);

        int left = 0;
        int maxi = 0;
        int fr0 = 0;
        int fr1 = 0;
        int maxOne = 0;
        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 1) {
                fr1++;
            }

            maxOne = max(maxOne, fr1);

            while (right - left + 1 - maxOne > k) {
                if (nums[left] == 1) {
                    fr1--;
                } else {
                    fr0--;
                }

                left++;
            }
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};