class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        return nums[0];
 
        int first=0,second=0,ans1,ans2;

        for(int i=n-2;i>-1;i--){
        ans1= max(nums[i]+second,first);
        second = first;
        first = ans1;
        }

        second = first = 0;

        for(int i=n-1;i>0;i--){
        ans2= max(nums[i]+second,first);
        second = first;
        first = ans2;
        }

        return max(ans1,ans2);
    }
};