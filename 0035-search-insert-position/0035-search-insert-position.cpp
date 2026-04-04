class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start =0,end = nums.size()-1;
        int index,mid;

        while(start<=end){

            mid = start + (end-start)/2;

            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target){
                index = mid;
                end = mid-1;
            }
            else{
                index = mid+1;
                start = mid+1;
            }
        }

        return index;
    }
};