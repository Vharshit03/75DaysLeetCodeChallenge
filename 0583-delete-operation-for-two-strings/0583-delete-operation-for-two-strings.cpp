class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int>dp(m+1,0);

        for(int i=1;i<=n;i++){
            int prev=0,curr;
            for(int j=1;j<=m;j++){

                curr = dp[j];
                if(word1[i-1]==word2[j-1])
                dp[j] = 1 + prev;
                else
                dp[j] = max(dp[j],dp[j-1]);

                prev = curr;
            }
        }

        int del1 = n - dp[m];
        int del2 = m - dp[m];

        return del1+del2;
    }
};