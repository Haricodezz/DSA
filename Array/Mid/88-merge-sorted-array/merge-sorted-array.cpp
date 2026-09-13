class Solution {
private:
void swapIfGreater(vector<int>& arr1,  vector<int>& arr2,int n, int m){
if(arr1[n]>arr2[m]){
    swap(arr1[n],arr2[m]);
}


}

public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int len=n+m;
        int gap=len/2 + (len%2);

        while(gap>0){
            int left =0;
            int right = left+gap;

            while (right < len){
                //arr1 and arr1
                if(left<n && right<n){
                    swapIfGreater(arr1,arr1,left,right);
                }
                // arr1 and arr2
                else if(left<n && right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
                }
                // arr2 and arr2
                else{
            swapIfGreater(arr2,arr2,left-n,right -n);
                }

           left++;
           right++;
           
            }
if(gap==1)break;
gap = gap / 2 + gap % 2;

        }
        
for(int i=0;i<m;i++){
    arr1[n+i]=arr2[i];
}



    }
};