class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,total=0,n=nums.size();
        int res = n+1;

        for(int r=0; r<n ;r++){
            total += nums[r];

            while(total>=target){
                res = min(r-l+1,res);
                total -= nums[l];
                l +=1;
            }
        }

        return (res==n+1) ?0: res;
    }
};