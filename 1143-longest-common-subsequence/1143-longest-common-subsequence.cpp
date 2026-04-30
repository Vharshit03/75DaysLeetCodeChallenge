class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();

        vector<int>dp(n+1,0);

        for(int i=1;i<=m;i++){

            int prev,curr=0;
        for(int j=1;j<=n;j++){

            prev = curr;
            curr = dp[j];
            if(text1[i-1]==text2[j-1])
            dp[j] = 1 + prev;
            else
            dp[j] = max(dp[j],dp[j-1]);
        }
        }
        return dp[n];
    }
};