class Solution {
public:
    int find(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){

        if(!i || !j)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i-1]==s2[j-1])
        return dp[i][j] = 1 + find(i-1,j-1,s1,s2,dp);
        else
        return dp[i][j] = max(find(i,j-1,s1,s2,dp),find(i-1,j,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return find(m,n,text1,text2,dp);
    }
};