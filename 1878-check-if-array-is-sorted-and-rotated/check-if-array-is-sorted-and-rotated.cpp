class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int arr[n];

        vector<int> v(nums);
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int k = 0;
            int flag = 0;
            for (int j = i; j < n; j++) {
                arr[j] = nums[k];
                k++;
            }
            for (int j = 0; j < i; j++) {
                arr[j] = nums[n - i + j];
            }
            for (int j = 0; j < n; j++) {
                if (arr[j] != v[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return true;
            }
        }
        return false;
    }
};