class Solution {
public:
    int find(int ind,int amt,vector<int>&coins,vector<vector<int>> &dp){

        if(amt==0)
        return 1;

        if(ind==0)
        return 0;

        if(dp[ind][amt]!=-1)
        return dp[ind][amt];

        int take = 0;

        if(coins[ind-1]<=amt)
        take = find(ind,amt-coins[ind-1],coins,dp);

        int noTake = find(ind-1,amt,coins,dp);

        return dp[ind][amt] =  take + noTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return find(coins.size(),amount,coins,dp);
    }
};