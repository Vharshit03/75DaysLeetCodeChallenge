class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=NULL;

        for(int i=0;i<nums.size(); i++){
            ans = ans^nums[i];
        }

        return ans;
    }
};