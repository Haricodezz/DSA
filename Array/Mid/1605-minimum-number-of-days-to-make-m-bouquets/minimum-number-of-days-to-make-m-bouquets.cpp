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
int totalBouquet(vector<int> &arr,int k,int days){

    int n = arr.size();
    int bloom = 0;
 int b=0;
    for (int i = 0; i < n; i++) {
        if(arr[i]<=days) bloom++;
        else{
            b+=bloom/k;

           bloom=0;
        }
    }
b+= bloom/k;
    return b;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    
    if (1LL*m * k> bloomDay.size())
        return -1;

    int low = 1;
    int high = MaxVal(bloomDay);
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (totalBouquet(bloomDay, k, mid) < m) {
            low = mid + 1;

        } else {
            high = mid - 1;
        }
    }

    return low;
}
};