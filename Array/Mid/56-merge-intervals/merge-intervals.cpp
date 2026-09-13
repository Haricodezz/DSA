class Solution {
public:
  vector<vector<int>>   merge(vector<vector<int>>& intervals) {
       vector<vector<int>> ans; 
        //sort the ARRAY
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int x= intervals[0][0];
        int y= intervals[0][1];
        for(int i=0;i<n;i++){
            int a= intervals[i][0];
            int b=intervals[i][1];
            if(a<=y){
                if(a<x){
                    x=a;
                }
                if(b>y){
                    y=b;
            }
            }
            else{
                vector<int> temp={x,y};
                ans.push_back(temp);
                x=a;
                y=b;
            }
        }
           vector<int> temp={x,y};
                ans.push_back(temp);
   

    return ans; }
};