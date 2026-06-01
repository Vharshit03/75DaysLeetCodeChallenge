class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int ind=-1, n=nums.size();

        //find breakpoint- dip
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            ind = i;
            break;
            }
        }

        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //finding next greater but smallest one
        for(int i=n-1;i>=ind;i--){
            if(nums[i]>nums[ind]){
            swap(nums[i],nums[ind]);
            break;
            }
        }

        //make smallest after ind by sorting
        reverse(nums.begin() + ind + 1,nums.end());

    }
};