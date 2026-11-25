class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        if (m < n) {
            swap(nums1, nums2);
            swap(m, n);
        }

        vector<int> dpsolve(n + 1, 0);
        vector<int> dpcommon(n + 1, 0);

        // initialization : already done with 0

        for (int i = 1; i < m + 1; i++) {
            int prevDiagonal = 0;
            for (int j = 1; j < n + 1; j++) {

                // old valuse get stored before its get updated

                int oldcommon = dpcommon[j];
                // common part
                int com = 0;
                if (nums1[i - 1] == nums2[j - 1]) {
                    com = 1 + prevDiagonal;
                }

                dpcommon[j] = com;
                // skip x

                int skipX = dpsolve[j];

                // skip y
                int skipY = dpsolve[j - 1];

                dpsolve[j] = max({com, skipX, skipY});

                prevDiagonal= oldcommon;
            }
        }

        return dpsolve[n];
    }
};