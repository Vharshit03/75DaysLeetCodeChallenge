class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int start,end,index,size=0,mid;
        vector<int>LIS(n,0);
        LIS[0]=nums[0];

        for(int i=1;i<n;i++){

            start=0,end = size;
            index = size+1;
            while(start<=end){ // binary search logN
                int mid = start + (end-start)/2;

                if(LIS[mid]<nums[i])
                start = mid+1;
                else if(LIS[mid]>nums[i]){
                    index = mid;
                    end = mid-1;
                }
                else{
                    index = mid;
                    break;
                }
            }

            LIS[index] = nums[i];
            size = max(index,size);
        }

        return size+1;
    }
};