class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long long product =1;

        for(auto n:nums){
            product = product*n;
        }

        vector<int>ans;

        for(int i=0;i<nums.size();i++){

            if(nums[i]!=0)
            ans.push_back(product/nums[i]);
            else
            {
                int temp=1;
                for(int j=0;j<nums.size();j++){
                    if(i==j)
                    continue;

                    temp = temp*nums[j];
                }
                ans.push_back(temp);
            }

        }

        return ans;
        
    }
};