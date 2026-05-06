class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(),j=0;
        int res=n+1;

        for(int i=0;i<n;i++){
            target -= nums[i];
            
            while(target<=0){
                res = min(res,i-j+1);
                target += nums[j++];
            }
        }

        return res%(n+1);
    }
};