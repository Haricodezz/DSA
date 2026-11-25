class Solution {
public:
    int common(vector<int>& x, vector<int>& y, int m, int n,
               vector<vector<int>>& dpcommon) {
        if (n == 0 || m == 0)
            return 0;
        if (dpcommon[m][n] != -1) {
            return dpcommon[m][n];
        }
        if (x[m - 1] == y[n - 1]) {
            return dpcommon[m][n] = 1 + common(x, y, m - 1, n - 1., dpcommon);
        }
        return dpcommon[m][n] = 0;
    }
    int solve(vector<int>& x, vector<int>& y, int m, int n,
              vector<vector<int>>& dpsolve, vector<vector<int>> &dpcommon) {

        if (n == 0 || m == 0)
            return 0;
        if (dpsolve[m][n] != -1) {
            return dpsolve[m][n];
        }

        int com = common(x, y, m, n, dpcommon);
        int skipX = solve(x, y, m - 1, n, dpsolve, dpcommon);
        int skipY = solve(x, y, m, n - 1, dpsolve, dpcommon);

        return dpsolve[m][n] = max({com, skipX, skipY});
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dpsolve(m + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dpcommon(m + 1, vector<int>(n + 1, -1));

        return solve(nums1, nums2, nums1.size(), nums2.size(), dpsolve,
                     dpcommon);
    }
};