class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0,n=nums.size();
        for(int it:nums){
            sum += it;
        }

        int nSum = (n*(n+1))/2;

        return nSum-sum;
    }
};