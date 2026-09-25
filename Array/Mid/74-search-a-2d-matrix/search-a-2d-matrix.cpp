class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rlow = 0;
        int rhigh = m - 1;

        while (rlow <= rhigh) {
            int rmid = rlow + (rhigh - rlow) / 2;

            if (matrix[rmid][0] <= target && target <= matrix[rmid][n - 1]) {
                int low = 0;
                int high = n - 1;

                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (matrix[rmid][mid] == target) {
                        return true;
                    } else if (matrix[rmid][mid] < target) {
                        low = mid + 1;

                    } else {
                        high = mid - 1;
                    }
                }

                break;
            }
            else if(matrix[rmid][0] < target){
                rlow= rmid+1;
            }else{
                rhigh=rmid-1;
            }
        }
        return false;
    }
};