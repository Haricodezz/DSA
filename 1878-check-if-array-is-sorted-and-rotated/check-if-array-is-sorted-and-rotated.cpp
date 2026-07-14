class Solution {
public:
    bool check(vector<int>& nums) {
       
      //updated 
        int num = nums.size();
        int arr[num];

        vector<int> v(nums);
        sort(v.begin(), v.end());
        for (int i = 0; i < num; i++) {
            int k = 0;
            int flag = 0;
            for (int j = i; j < num; j++) {
                arr[j] = nums[k];
                k++;
            }
            for (int j = 0; j < i; j++) {
                arr[j] = nums[num - i + j];
            }
            for (int j = 0; j < num; j++) {
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