class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size();

        string s2 = s;
        reverse(s2.begin(),s2.end());

        vector<int>dp(m+1,0);

        for(int i=1; i<=m;i++){
            int prev,curr=0;
            for(int j=1;j<=m;j++){

                prev = curr;
                curr = dp[j];
                if(s[i-1]==s2[j-1])
                dp[j] = 1 + prev;
                else
                dp[j] = max(dp[j],dp[j-1]);
            }
        }
        

        return dp[m];
    }
};