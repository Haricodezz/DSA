
class Solution {
public:
   
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for(int i =0;i<m+1;i++){
            dp[i][0]=1;
        }
        
        for(int i =1; i < m+1;i++){
            for(int j=1;j<n+1;j++){
                int pick=0;
                int notPick=0;
                if(s[i-1]==t[j-1]){
                    pick=dp[i-1][j-1];
                }

                notPick= dp[i-1][j];

                dp[i][j]= 1LL*notPick + pick;
            }
        }

        return dp[m][n];

    }
};
