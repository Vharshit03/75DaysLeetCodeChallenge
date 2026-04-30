class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        if(nums.size()==0)
        return 0;

        int lastsmaller=INT_MIN,count=0,longest=1;
        for(int i=0;i<nums.size(); i++){

            if(nums[i]-1 == lastsmaller){
                count++;
                lastsmaller = nums[i];
            }
            else if(nums[i] != lastsmaller){
                count = 1;
                lastsmaller = nums[i];
            }

            longest = max(longest,count);
        }


        return longest;
    }
};