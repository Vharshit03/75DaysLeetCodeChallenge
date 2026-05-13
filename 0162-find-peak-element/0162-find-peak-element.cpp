class Solution {
public:
    int findPeakElement(vector<int>& nums) {
                int n = nums.size();
        int start=0, end = n-1,mid;

        if(n==1)
        return 0;
        if(nums[0]>nums[1])
        return 0;
        if(nums[n-1]>nums[n-2])
        return n-1;
    

        while(start<=end){
            mid = (start+end)/2;

            if(mid>0 && mid<n-1 && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])//Peak one
            return mid;
            else if( mid<n-1 && nums[mid]<nums[mid+1])
            start = mid+1;
            else 
            end = mid-1;
        }

        return -1;
    }
};