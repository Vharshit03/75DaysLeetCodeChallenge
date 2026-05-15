class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end = nums.size()-1;
        int mini = INT_MAX;

        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid]>=nums[start]){
                mini = min(mini,nums[start]);
                start = mid+1;
            }
            else if(nums[mid]<mini){
                mini = nums[mid];
                end = mid-1;
            }
            else
            start =  mid+1;
        }

        return mini;
    }
};