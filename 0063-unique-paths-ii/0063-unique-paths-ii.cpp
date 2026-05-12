class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
        return 0;

        vector<vector<long long>>dp(m,vector<long long>(n,0));

        dp[m-1][n-1]=1;

        for(int j=n-2;j>=0;j--){
        if(obstacleGrid[m-1][j]==0)
        dp[m-1][j]=1;
        else break;
        }

        for(int i=m-2;i>=0;i--){
            if(obstacleGrid[i][n-1]==0)
            dp[i][n-1]=1;
            else break;
        }

        for(int i=m-2;i>=0;i--)
        for(int j=n-2;j>=0;j--){
            if(obstacleGrid[i][j]==0)
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }

        return (int)dp[0][0];
    }
};