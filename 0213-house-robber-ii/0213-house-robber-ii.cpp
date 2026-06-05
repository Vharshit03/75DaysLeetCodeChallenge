class Solution {
public:
    int hRob(int ind,int n,vector<int>& nums,vector<int>& dp){
        if(ind>=n) return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        return dp[ind] = max(nums[ind] + hRob(ind+2,n,nums,dp),hRob(ind+1,n,nums,dp));
    }
    
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+2,-1);
        vector<int>dp2(n+2,-1);

        return max(hRob(0,n-1,nums,dp1),hRob(1,n,nums,dp2));
        

    }
};