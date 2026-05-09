class Solution {
public:
    int minInsertions(string s1) {
        
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int n = s1.size();

       vector<int>dp(n+1,0);

        for(int i=1;i<=n;i++){
            int prev=0,curr;
            for(int j=1;j<=n;j++){

                curr = dp[j];
                if(s1[i-1]==s2[j-1])
                dp[j] = 1 + prev;
                else
                dp[j] = max(dp[j],dp[j-1]);

                prev = curr;
            }
        }

        return n-dp[n];

    }
};