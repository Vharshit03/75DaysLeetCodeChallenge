class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int>dp(amount+1,0);

        for(int j=1;j<=amount;j++){

            if(j%coins[0]==0)
            dp[j] = j/coins[0];
            else
            dp[j] = INT_MAX-1;
        }

        for(int i=2;i<=n;i++){
            for(int j=coins[i-1];j<=amount;j++){
                dp[j] = min(dp[j-coins[i-1]] + 1, dp[j]);//fewest one
            }
        }

        return (dp[amount]==INT_MAX-1)? -1: dp[amount];
    }
};