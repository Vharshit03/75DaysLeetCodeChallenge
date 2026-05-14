class Solution {
public:
    bool subsetSum(vector<int>& nums,int n,int k){

        vector<bool>prev(k+1,0),curr(k+1,0);
        prev[0]=true; curr[0]=true;
        if(nums[0]<=k) prev[nums[0]] = true;

        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notake = prev[target];
                bool take = false;
                if(nums[ind]<=target){
                    take = prev[target-nums[ind]];
                }
                curr[target] = take || notake;
            }
            prev = curr;
        }

        return prev[k];

    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size(),sum=0;
        for(int i=0;i<n;i++)
        sum += nums[i];


        if(sum%2!=0)
        return false;

        return subsetSum(nums,n,sum/2);
    }
};