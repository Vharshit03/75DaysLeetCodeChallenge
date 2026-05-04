class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0,cnt1=0;
        int n = nums.size();

        for(int n:nums){
            if(n==0)
            cnt0++;
            else if(n==1)
            cnt1++;
        }

        int i;
        for(i=0;i<cnt0;i++){
            nums[i]=0;
        }

        for( ;i<cnt0+cnt1;i++){
            nums[i]=1;
        }

        for(;i<n;i++)
        nums[i]=2;
    }
};