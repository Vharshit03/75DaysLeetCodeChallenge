class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int first=0,second=0,third;

        for(int i=n-1;i>-1;i--){

            third = max(nums[i]+second,first);
            second=first;
            first=third;

        }

        return first;
    }
};