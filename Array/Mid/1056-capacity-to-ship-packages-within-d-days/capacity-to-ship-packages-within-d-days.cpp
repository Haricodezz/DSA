class Solution {
public:
    int reqDays(vector<int>& wt, int cap) {
        int n = wt.size();
        int day = 0;
        int load = 0;

        for (int i = 0; i < n; i++) {
            if (load + wt[i] > cap) {
                day++ ;
                load = wt[i];
            } else {
                load += wt[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();
int sum=0,maxi=INT_MIN;
        for (int i = 0; i < n; i++) {

       maxi=max(maxi,weights[i]);
       sum+=weights[i];
        }

int low=maxi;
int high=sum;
while (low<=high ){
int mid = low+(high-low)/2;
if(reqDays(weights,mid)>=days ){
    low= mid+1;
}else{
    high=mid-1;
}

}


return low;


    }
};