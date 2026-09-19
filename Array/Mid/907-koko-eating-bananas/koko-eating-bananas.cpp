class Solution {
public:
    int MaxVal(vector<int>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(arr[i], maxi);
        }

        return maxi;
    }

    long long TotalHr(vector<int>& arr, int hr) {
        int n = arr.size();

       long long hrs = 0;

        for (int i = 0; i < n; i++) {
            hrs +=  (arr[i]+hr-1)/hr;
        }

        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = MaxVal(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (TotalHr(piles, mid) > h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};