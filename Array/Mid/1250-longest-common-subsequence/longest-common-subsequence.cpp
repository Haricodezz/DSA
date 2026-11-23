class Solution {
public:

 int solve( string & x, string &y,int m, int n,vector<vector<int>>&dp){
   




    if(dp[m][n]!=-1){
        return dp[m][n];
    }

    if(m==0|| n==0){
    return 0;
}

    if(x[m-1]==y[n-1]){
        return dp[m][n]= 1 + solve ( x, y,m-1,n-1,dp);
    }
    else {
        int first= solve(x,y,m-1,n,dp);
        int second = solve (x,y,m,n-1,dp);
        return dp[m][n]= max(first,second);
    }
 }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n= text2.size();


vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

for(int i = 0 ; i <m+1;i++){
    dp[i][0]=0;


}
for(int j = 0 ; j <n+1;j++){
    dp[0][j]=0;
}




        return solve(text1,text2,m,n,dp);
    }
};